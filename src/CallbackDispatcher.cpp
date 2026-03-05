#include "CallbackDispatcher.h"

#include <Platform/ScopedCS.h>
#include <Platform/SystemCheck.h>
#include <Platform/SystemError.h>

struct CallbackData {
	unsigned long m_ulContext;
	CallbackDispatcher::Callback m_pfCallback;
};

static void InvokeCallback(CallbackData *pCallback, unsigned long ulContext)
{
	SYSTEMCHECK(pCallback->m_pfCallback != NULL);
	pCallback->m_pfCallback(ulContext, pCallback->m_ulContext);
}

CallbackDispatcher::CallbackDispatcher(unsigned long ulContext)	: ObjectThread<CallbackDispatcher, void*>(_T("CallbackDispatcher"))
{
	m_bStopRequested = false;
	m_ulContext = ulContext;

	m_pEventHandler = new EventHandler(10);
	m_pWakeupEvent = m_pEventHandler->CreateEventObject(0, 0);
	m_pCallbackEvent = m_pEventHandler->CreateEventObject(1, 0);

	m_pSyncEventHandler = new EventHandler(1);
	m_pSyncDoneEvent = m_pSyncEventHandler->CreateEventObject(2, 0);

	m_pTimeSliceCallback = NULL;

	bool bLaunched = Launch(this, &CallbackDispatcher::DispatcherThread, (void *)NULL);
	if (!bLaunched) {
		SYSTEMCHECK(false);
	}
}

CallbackDispatcher::~CallbackDispatcher()
{
	UnregisterTimeSliceCallback();
	Stop(5000);

	m_pEventHandler->DeleteEventObject(m_pCallbackEvent);
	m_pEventHandler->DeleteEventObject(m_pWakeupEvent);
	m_pSyncEventHandler->DeleteEventObject(m_pSyncDoneEvent);

	if (m_pEventHandler != NULL) {
		delete m_pEventHandler;
	}

	if (m_pSyncEventHandler != NULL) {
		delete m_pSyncEventHandler;
	}
}

void CallbackDispatcher::SetPriority(unsigned long ulPriority)
{
	ObjectThreadRoot::SetPriority(ulPriority);
}

void CallbackDispatcher::RegisterTimeSliceCallback(Callback pfCallback, unsigned long ulContext, long lTimeout)
{
	if (m_pTimeSliceCallback != NULL) {
		delete m_pTimeSliceCallback;
		m_pTimeSliceCallback = NULL;
	}

	CallbackData *pCallback = new CallbackData;
	if (pCallback != NULL) {
		pCallback->m_pfCallback = pfCallback;
		pCallback->m_ulContext = ulContext;
	}

	m_pTimeSliceCallback = pCallback;
	m_lTimeSliceTimeout = lTimeout;

	m_pWakeupEvent->Set();
}

void CallbackDispatcher::UnregisterTimeSliceCallback()
{
	if (m_pTimeSliceCallback != NULL) {
		delete m_pTimeSliceCallback;
		m_pTimeSliceCallback = NULL;
	}
}

bool CallbackDispatcher::Stop(unsigned long ulTimeout)
{
	if (Launched()) {
		m_bStopRequested = true;
		m_pWakeupEvent->Set();
		return ObjectThreadRoot::Wait(ulTimeout);
	}
	return true;
}

Event *CallbackDispatcher::CreateCallbackEvent(Callback pfCallback, unsigned long ulContext)
{
	CallbackData *pCallback = new CallbackData;
	if (pCallback != NULL) {
		pCallback->m_pfCallback = pfCallback;
		pCallback->m_ulContext = ulContext;
		return m_pEventHandler->CreateEventObject(1, (unsigned long)pCallback);
	}

	return m_pEventHandler->CreateEventObject(1, 0);
}

void CallbackDispatcher::DeleteCallbackEvent(Event *pEvent)
{
	SYSTEMCHECK(pEvent != NULL);

	CallbackData *pCallback = (CallbackData *)pEvent->GetContext();
	m_pEventHandler->DeleteEventObject(pEvent);

	SYSTEMCHECK(pCallback != NULL);
	if (pCallback != NULL) {
		delete pCallback;
	}
}

void CallbackDispatcher::CallInContext(Callback pfCallback, unsigned long ulContext)
{
	ScopedCS lock(m_cs);

	CallbackData *pCallback = new CallbackData;
	if (pCallback != NULL) {
		pCallback->m_pfCallback = pfCallback;
		pCallback->m_ulContext = ulContext;
	}

	if (GetCurrentThreadID() == GetThreadId()) {
		InvokeCallback(pCallback, m_ulContext);
	} else {
		m_pSyncDoneEvent->Reset();
		m_pCallbackEvent->SetContext((unsigned long)pCallback);
		m_pCallbackEvent->Set();

		Event *pEvent = NULL;
		m_pSyncEventHandler->WaitForEvent(WAIT_INFINITE, &pEvent);
	}

	if (pCallback != NULL) {
		delete pCallback;
	}
}

void CallbackDispatcher::DispatcherThread(void *pParam)
{
	Event *pEvent = NULL;

	while (true) {
		if (m_bStopRequested) {
			m_pSyncDoneEvent->Set();
			return;
		}

		pEvent = NULL;

		if (m_pTimeSliceCallback == NULL) {
			bool bError = m_pEventHandler->WaitForEvent(WAIT_INFINITE, &pEvent);
			if (bError) {
				SystemError::TraceLast(1);
			}
		} else {
			bool bSignaled = m_pEventHandler->WaitForEvent(m_lTimeSliceTimeout, &pEvent);
			if (!bSignaled) {
				unsigned long ulError = SystemError::GetLast();
				if (ulError == 0) {
					SystemError::TraceLast(1);
				} else {
					InvokeCallback(m_pTimeSliceCallback, m_ulContext);
				}
			}
		}

		if (pEvent != NULL) {
			pEvent->Reset();
			unsigned long ulType = pEvent->GetType();

			if (ulType == 0) {
				// wakeup event
			} else if (ulType == 1) {
				CallbackData *pCallback = (CallbackData *)pEvent->GetContext();
				SYSTEMCHECK(ISGOODPTR(pCallback));
				InvokeCallback(pCallback, m_ulContext);

				if (pEvent == m_pCallbackEvent) {
					m_pSyncDoneEvent->Set();
				}
			} else {
				SYSTEMCHECK(false);
			}
		}
	}
}
