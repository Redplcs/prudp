//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _ObjDupProtocol_H_
#define _ObjDupProtocol_H_

#include <Platform/AtomicValue.h>
#include <Platform/EventHandler.h>
#include <Platform/Event.h>
#include <Platform/ObjectThread.h>
#include <Utility/PseudoGlobalVariable.h>
#include <Plugins/Transport/Interface/EndPointEventHandler.h>
#include <Plugins/Transport/Interface/EndPoint.h>
#include <Plugins/Encryption/Interface/EncryptionAlgorithm.h>
#include <Plugins/Compression/Interface/CompressionAlgorithm.h>
#include <Plugins/Protocol/Interface/Protocol.h>
#include <ObjDup/ObjDupDecl.h>
#include <ObjDup/DOSID.h>
#include <ObjDup/MulticastControl.h>
#include <ObjDup/DuplicatedObject.h>
#include <ObjDup/DuplicatedObjectStore.h>
#include <ObjDup/Collection.h>
#include <ObjDup/CallRegister.h>
#include <ObjDup/Authentication.h>
#include <ObjDup/ConnectionManager.h>

class Message;
class DuplicatedObjectStore;
class IteratorOverDOs;
class FetchContext;
class MigrationContext;
class RMCContext;
class LMCContext;
class Fault;


class ObjDupProtocol: public EndPointEventHandler {
	public:

		ObjDupProtocol(DuplicatedObjectStore* pDOS);
		~ObjDupProtocol();

		static ObjDupProtocol* GetInstance();

		virtual void Receive(EndPoint *pEndPoint, Buffer *pBuffer);
		virtual void FaultDetection(EndPoint *pEndPoint, unsigned long ulFault);
		virtual void FloodDetection(EndPoint *pEndPoint);
		virtual void PeerDisconnected(EndPoint *pEndPoint);

		Message* CreateMessage(unsigned long ulMessageType);
		
		bool Dispatch(Message *pMessage);

		void ProcessMessage(void (ObjDupProtocol::*pMethod)(Message*), Message* pMessage);

		unsigned long SendMessage(EndPoint *pEndPoint, Message *pMessage, unsigned long ulFlags);

		bool JoinSession(StationURL *pStationURL);

		Message* CreateJoinRequest();
		void ProcessJoinRequest(Message* pMessage);

		Message* CreateJoinResponse(unsigned char ucDetails);
		void ProcessJoinResponse(Message* pMessage);

		void WelcomeNewStation(EndPoint* pSourceEndPoint);
		
		Message* CreateUpdateMessage(unsigned long* pulID, unsigned char* pbyIndex);
		void ProcessUpdateMessage(Message *pMessage);
		void CheckUpdateCoherence(DuplicatedObject* pDO);
		
		Message* CreateDiscoverMessage(DuplicatedObject* pDO, bool bPromote = false, MigrationContext* pContext = NULL);
		void ProcessDiscoverMessage(Message* pMessage);

		Message* CreateDeleteMessage(unsigned long* pulID);
		void ProcessDeleteMessage(Message* pMessage);

		Message* CreateActionMessage(DOHandle* pidDO, MethodID* pidMethod);
		void ProcessActionMessage(Message* pMessage);

		Message* CreateDOMessage(DOHandle hDODest);
		void ProcessDOMessage(Message *pMessage);

		Message* CreateRMCCall(RMCContext* pContext);
		void ProcessRMCCall(Message* pMessage);

		Message* CreateRMCResponse(LMCContext* pContext);
		void ProcessRMCResponse(Message* pMessage);

		Message* CreateRouteMessage(DOHandle hTargetStation, Message* pMessageToRoute);
		void ProcessRouteMessage(Message* pMessage);

		Message* CreateFetchRequest(FetchContext* pFetchContext);
		void ProcessFetchRequest(Message* pMessage);

		Message* CreateMigrationMessage(MigrationContext* pFetchContext);
		void ProcessMigrationMessage(Message* pMessage);
        void ProcessMigration(DOHandle hTargetObject, DOHandle hSourceStation, DOHandle hTargetStation, CallContext::ID idCall);

		Message* CreateCallOutcomeMessage(CallContext::ID idCall, CallContext::Outcome uOutcome);
		void ProcessCallOutcomeMessage(Message* pMessage);

		Message* CreateEOSMessage(DOHandle hStation);
		void QueueEOS(DOHandle hStation);
		void ProcessEOSMessage(Message* pMessage);

        void WaitForAllDispatch();

		bool GetLocalURLs(Station *pStation);

		CallRegister& CallRegisterRef() {return m_oCallRegister;}

		bool ListenOnArbitrary();
		void ListenOnWellKnownIfRequired(unsigned long ulNbAttempts=1);
		
		void StopToListen();
		
		bool IsListening() const;
		bool IsListeningOnWellKnown() const;
		bool IsListeningOnArbitrary() const;
		
		void QueueMessage(Message *pMessage);
		ICContext GetInstanceContext() const {return m_icContext;};

		void Trace(unsigned long ulTraceFlags=TRACE_ALWAYS);
		void TraceFaultProcessingInProgress(unsigned long ulTraceFlags=TRACE_ALWAYS);

    private:
        bool SetPluginObject(PluginObject **pPluginObject, TCHAR *szGUID, unsigned long ulPluginType);
        void ReleasePluginObject(PluginObject **pPluginObject);

	private:
		bool ShouldGrabWellKnown();
		bool ListenOnWellKnown();
		void DispatchThread(ICContext icThreadContext);
		
	private:
		
		bool m_bListeningOnArbitrary;
		bool m_bListeningOnWellKnown;
		
		DuplicatedObjectStore* m_pDOS;
		CallRegister m_oCallRegister;

		AtomicValue m_avDispatchInProgress;

		unsigned char m_ucJoinResponse;

	public:
		Authentication* GetAuthenticationInfo();

		ConnectionManager& GetConnectionManagerRef() {return m_oConnectionManager;}
		static Protocol *GetProtocol();

		void FaultProcessingBegins(Fault* pFault);
		void FaultProcessingEnds(Fault* pFault);
		int GetNbFaultProcessing();
		
		void WaitForAllFaultProcessing();

	private:
		EndPoint* m_poBootstrapEndPoint; // This EndPoint is used during the bootstrap...
		
		Authentication 	m_oAuthenticationInfo;
		Protocol			m_oProtocol;
		ConnectionManager m_oConnectionManager;
		ObjectThread<ObjDupProtocol, ICContext>	*m_pMessageDispatcherThread;
		EventHandler						*m_pEventHandler;
		Event								*m_pWakeUpEvent;
		bool				m_bProtocolLeaving;
		std::list<Message*>	m_oMsgQueue;
		CriticalSection		m_csMsgQueue;
		ICContext			m_icContext;

		CriticalSection		m_csFaultProcessingList;
		std::list<Fault*>	m_lstFaultProcessingList;

};


#endif
