//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _GameCtrlInterface_H_
#define _GameCtrlInterface_H_

#include <Products/NetZ/Facade/NetZDecl.h>
#include <ObjDup/SessionCtrlInterface.h>

//group=Control Interface

/*
Summary:  GameCtrlInterface is the control interface that provides control over
the game itself.

Remarks:  Like all control interfaces in NetZ, the GameCtrlInterface can be 
subclassed to add custom functionality.  
The constructor builds an instance of GameCtrlInterface (Game Control
Interface).  

See Also:
Interface Overview
*/
class GameCtrlInterface: public SessionCtrlInterface {
	// Group=
	public:

		GameCtrlInterface();

		virtual ~GameCtrlInterface();

		static GameCtrlInterface* GetInstance();

		bool CreateGame();
		bool CreateGame(TCHAR *szGameName);
		bool CreateNonNetworkedGame();
		// These signature are using PRUDP !
		bool CreateGame(unsigned short usPortNumber);
		bool CreateGame(TCHAR *szGameName, unsigned short usPortNumber);

		bool JoinGame(StationURL *pStationURL);
		bool JoinGame(SessionDescription *pGameSignature);
		// This signature uses PRUDP
		bool JoinGame(TCHAR *szMachine);
		bool JoinGame(TCHAR *szMachine, unsigned short usPortNumber);

		unsigned int EnumerateLANGames(unsigned long ulContext,
					void (*pfUserFunction)(unsigned long ulContext, SessionDescription *pSessionDescription), 
					bool bFilterOnGameTitle = true, unsigned long ulTimeout = 1000);
		// This signature uses PRUDP
		unsigned int EnumerateLANGames(unsigned long ulContext,
					void (*pfUserFunction)(unsigned long ulContext, SessionDescription *pSessionDescription), 
					unsigned short usPortNumber, bool bFilterOnGameTitle = true, unsigned long ulTimeout = 1000);

		// {Secret}
		static void FindLANGameCallback(unsigned long ulContext, SessionDescription *pSessionDescription);

		bool FindLANGame(TCHAR *szGameName, SessionDescription *pGameSignature, unsigned long ulTimeout = 1000);
		// This signature uses PRUDP
		bool FindLANGame(TCHAR *szGameName, SessionDescription *pGameSignature, unsigned short usPortNumber, unsigned long ulTimeout = 1000);

		bool IsGameMaster() const;

		bool StartGame();
		bool PauseGame();
		bool ResumeGame();
		bool TerminateGame();
};

#endif
