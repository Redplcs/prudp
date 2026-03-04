//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _MulticastControl_H_
#define _MulticastControl_H_

class Station;

class MulticastControl {
	public:

		MulticastControl();		
		virtual ~MulticastControl();

		virtual void StartingMulticast();
		virtual bool ApproveSendMessage(Station* pStation) {return true;}
		virtual void MessageSent(Station* pStation);
		virtual void MessageNotSent(Station* pStation);
		virtual void MulticastComplete() {}

		unsigned int GetNbMessagesSent() {return m_uiNbMessagesSent;}
		unsigned int GetNbMessagesNotSent() {return m_uiNbMessagesNotSent;}
		
	protected:
		unsigned int m_uiNbMessagesSent;
		unsigned int m_uiNbMessagesNotSent;
};

#endif
