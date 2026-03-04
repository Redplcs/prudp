//  
//   (c) Copyright 1998-2001, Proksim Inc.
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _ConnectionManager_H_
#define _ConnectionManager_H_

#include <ObjDup/ObjDupDecl.h>

#include <Plugins/Transport/Interface/TransportEventHandler.h>
#include <list>
#include <Platform/CriticalSection.h>
#include <ObjDup/DOHandle.h>
#include <Utility/InstanceControl.h>
#include <ObjDup/SessionDescription.h>
#include <ObjDup/DORef.h>

class ConnectionManager: public TransportEventHandler {

	public:
		ConnectionManager();
		virtual ~ConnectionManager();
		
		static ConnectionManager* GetInstance();

		void SetInstanceContext(ICContext icContext) {m_icContext=icContext;}

		DORef GetNewStationRef(DOHandle hStation, DOHandle hAvailableRouting=INVALID_DOHANDLE);

		virtual void Receive(Transport *pTransport, Buffer *pBuffer, StationURL *pStationURL);
		virtual void ReceiveBroadcast(Transport *pTransport, Buffer *pBuffer, StationURL *pStationURL);

		virtual void DeviceDiscovery(Transport *pTransport, TCHAR *szDevice);
		virtual bool ConnectionRequest(Transport *pTransport, StationURL *pStationURL,
									   Buffer *pBuffer, EndPoint *pEndPoint);

		EndPoint *Connect(StationURL *pStationURL, DOHandle hStationHandle);

		void NewPendingEndPoint(EndPoint* pEndPoint, DOHandle hStation);
		EndPoint* FindPendingEndPoint(DOHandle hStation, bool bRemove=false);

		bool Dispatch(Message *pMessage);
		Message* CreateMessage(unsigned long ulMessageType);
		
		static bool EnumerateLANSessions(std::list<SessionDescription*> *pSessionDescriptionList, bool bFilterOnGameTitle, unsigned long ulTimeout);
		Message* CreateProbeRequest();
		void ProcessProbeRequest(Message* pMessage);

		Message* CreateProbeResponse();
		void ProcessProbeResponse(Message* pMessage);

		void SetInitialConnectionPoint(DOHandle hInitialConnectionPoint) {
			m_hInitialConnectionPoint=hInitialConnectionPoint;
		}

		DOHandle FindRoute(DOHandle hStationToReach);

	private:
		std::list<EndPoint*> m_lstPendingEndPoints;
		CriticalSection m_csList;
		ICContext m_icContext;

		std::list<SessionDescription*>	*m_pSessionDescriptionList;
		CriticalSection					m_csSessionDescriptionList;
		bool							m_bFilterOnGameTitle;

		DOHandle m_hInitialConnectionPoint;
};


#endif
