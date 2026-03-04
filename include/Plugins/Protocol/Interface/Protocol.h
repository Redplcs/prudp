//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _Protocol_H_
#define _Protocol_H_

#include <Plugins/Transport/Interface/Transport.h>
#include <Plugins/Transport/Interface/TransportTable.h>
#include <Plugins/Encryption/Interface/EncryptionAlgorithm.h>
#include <Plugins/Compression/Interface/CompressionAlgorithm.h>
#include <Plugins/Protocol/Interface/Protocol.h>

class Message;
class PluginObject;

//Group=Plug-ins

//Description: Use this class to set and retrieve specific information about the transport protocol used by $PRODUCTNAME$.
//Remarks: This class is used to set and retrieve specific information about the transport protocol used by $PRODUCTNAME$.
class Protocol {
//Group=
	public:

		Protocol();
		~Protocol();

		/*
		Description: Returns a pointer to the Protocol instance.
		Returns: A reference to the Protocol object.
		Remarks: Use the reference returned by this method to control the transport protocol used.
		For example, get the number of transports used as follows:

			Protocol::GetInstance()->GetNbTransports();

		*/
		static 	Protocol* GetInstance();

	public: // AND EXPOSED
		
		/*
		Description:  Use this method to retrieve the specified transport protocol currently used by $PRODUCTNAME$.
		Returns: A pointer to the specified transport protocol.
		See Also: GetTransport, GetNbTransports
		*/
		Transport*              FindTransport(TCHAR *szTransportType);
		Transport*              FindTransport(StationURL *pStationURL);
		
		/*
		Description: Use this method to determine the number of transport protocols currently used by $PRODUCTNAME$. 
		Returns: The number of transport protocols currently used by $PRODUCTNAME$.
		See Also: GetTransport, FindTransport
		*/
		unsigned long           GetNbTransports();
		
		/*
		Description: Use this method to return a specific transport protocol currently used by $PRODUCTNAME$.
		Returns: A pointer to the specified transport.
		Remarks: Transport protocols are numbered sequentially from 0 to GetNbTansports-1.
		See Also: GetNbTransports, FindTransport
		*/
		Transport*              GetTransport(unsigned long ulIndex);

		/*
		Description: Selects the compression plug-in that $PRODUCTNAME$ will use.
		Returns: true if the specified plug-in was sucessfully activated, false if it was not.
		Remarks: The compression plug-in selected must be currently on the activation list. The 
		LZSS algorithm is enabled by default. If you wish to disable compression pass NULL as the 
		variable for this method.
		See Also: GetCompressionAlgorithm, PluginManager::GetActivationListItem
		*/
		bool					SelectCompressionPlugin(TCHAR *szCompressionGUID);

		/*
		Description: Returns the compression algorithm that $PRODUCTNAME$ will use during the session.
		Returns: A pointer to the compression algorithm selected via SelectCompressionPlugin 
		or NULL if no compression algorithm is currently loaded.
		Remarks: The LZSS compression algorithm is enabled by default. Use SelectCompressionPlugin to
		change the plugin used.
		See Also: SelectCompressionPlugin
		*/
		CompressionAlgorithm*   GetCompressionAlgorithm();

		/*
		Description: Selects the encryption plug-in that $PRODUCTNAME$ will use.
		Returns: true if the specified plug-in was sucessfully activated, false if it was not.
		Remarks: The encryption plug-in selected must be currently on the activation list. The 
		RC4 algorithm is enabled by default. If you wish to disable encryption pass NULL as the 
		variable for this method.
		See Also: GetEncryptionAlgorithm, PluginManager::GetActivationListItem
		*/
		bool					SelectEncryptionPlugin(TCHAR *szEncryptionGUID);
		
		/*
		Description: Returns the encryption algorithm that $PRODUCTNAME$ is use during the session.
		Returns: A pointer to the encryption algorithm selected via SelectEncryptionPlugin 
		or NULL if no encryption algorithm is currently loaded.
		Remarks: The RC4 encryption algorithm is enabled by default. Use SelectEncryptionPlugin to
		change the plugin used.
		See Also: SelectEncryptionPlugin
		*/
		EncryptionAlgorithm*    GetEncryptionAlgorithm();

	public: 
		//{secret}
		void					InitTransports();
		//{secret}
		void					DestroyTransports();
        //{secret}
		Message*                CreateMessage();
        Message*                CreateMessage(Buffer *pBuffer);
		//{secret}
		void					ReleaseMessage(Message *pMessage);
        //{secret}
		Buffer*                 CreateBuffer(Message *pMessage);
		//{secret}
		void					ReleaseBuffer(Buffer *pBuffer);

	public:
		//{secret}
		static void	 			SetInstanceResolver(Protocol *(*fnInstanceResolver)());

    private:
        bool SetPluginObject(PluginObject **pPluginObject, TCHAR *szGUID, unsigned long ulPluginType);
        void ReleasePluginObject(PluginObject **pPluginObject);

		TransportTable& GetTransportTableRef() {return m_oTransportTable;}

		TransportTable	        m_oTransportTable;

        CompressionAlgorithm    *m_pCompressionAlgorithm;
        EncryptionAlgorithm     *m_pEncryptionAlgorithm;

		static Protocol*		(*s_fnInstanceResolver)();
};


#endif
