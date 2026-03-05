#include "AsyncIOContext.h"

AsyncIOContext::AsyncIOContext()
{
    m_ulIOSize = 0;
    m_ulReturnCode = 0;
    m_pEvent = 0;
}

void AsyncIOContext::SetEvent(Event *pEvent)
{
    m_pEvent = pEvent;
    m_overlapped.hEvent = pEvent->GetPlatformSpecificEvent();
}

Event *AsyncIOContext::GetEvent()
{
    return m_pEvent;
}

void AsyncIOContext::SignalEvent()
{
    if (m_pEvent != nullptr) {
        m_pEvent->Set();
    }
}

void AsyncIOContext::ResetEvent()
{
    if (m_pEvent != nullptr) {
        m_pEvent->Reset();
    }
}

void AsyncIOContext::SetIOSize(unsigned long ulSize)
{
    m_ulIOSize = ulSize;
}

unsigned long AsyncIOContext::GetIOSize()
{
    return m_ulIOSize;
}

unsigned long AsyncIOContext::GetReturnCode()
{
    return m_ulReturnCode;
}

void AsyncIOContext::SetReturnCode(unsigned long ulReturnCode)
{
    m_ulReturnCode = ulReturnCode;
}

OVERLAPPED *AsyncIOContext::GetOverlapped()
{
    return &m_overlapped;
}
