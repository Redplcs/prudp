//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _Chrono_H_
#define _Chrono_H_

#include <Utility/UtilityDecl.h>
#include <Platform/Time.h>

/*
X = The function call is not allowed
O = The function call is allowed

State/Function  | Start | Pause | Resume | Check | Stop | Reset | GetState
---------------------------------------------------------------------------
Paused          |   X   |   X   |   O    |   O   |   O   |  O   |    O
Started         |   X   |   O   |   X    |   O   |   O   |  O   |    O
Stopped         |   O   |   X   |   X    |   O   |   X   |  O   |    O
*/


//{secret}
#define CHRONO_IS_STARTED	0

//{secret}
#define CHRONO_IS_PAUSED	1

//{secret}
#define CHRONO_IS_STOPPED	2

//{secret}
#define INVALID_TIME_INTERVAL	-1

//Group = Time Management
/* 
   Description:  An instance of this class measures the elapsed time on the local station
   in the same manner as a stopwatch.

   Remarks:  An instance of this class measures the elapsed time, in milliseconds, on 
   the local station. Use an instance of this class to precisely measure time in the 
   same manner as you would with a stopwatch.
*/
class Chrono {
	
//Group =

		public:

			//Description: Creates an instance of a Chrono, which is a time measurement tool.
			//Remarks:  By default, upon creation the Chrono is stopped. Use Start to start it.
			Chrono();
			virtual ~Chrono();
			
			//Description: Starts the Chrono at an initial time of zero. This method is 
			//equivalent to pushing 'start' on a stopwatch.
			//Remarks:  You can only Start a Chrono that is presently stopped. 
			//Returns: true if the call does not signal an error, false if otherwise.  
			// SYSTEMERROR_GEN_INVALID_OPERATION is signalled if the Chrono is not stopped. 
			bool Start();
			
			//Description: Pauses the Chrono if it was currently running. 
			//Remarks: Pauses the Chrono until you resume it via Resume. You can resume the Chrono 
			//after pausing it, which you cannot do if you Stop the Chrono.  
			//Returns: true if the call does not signal an error, false if otherwise.  
			//SYSTEMERROR_GEN_INVALID_OPERATION is signalled if the Chrono is not started. 
			TimeInterval Pause();

			//Description: Resumes the Chrono if it was temporarily paused.
			//Remarks: Resumes the operation of the Chrono if it was in a paused state. 
			//You can Resume the Chrono after pausing it, which you cannot do if you stop the Chrono.   
			//Returns: true if the call does not signal an error, false if otherwise.  
			//SYSTEMERROR_GEN_INVALID_OPERATION is signalled if the Chrono is not paused.
			bool Resume();

			//Description: Returns the current elapsed time without stopping the Chrono.
			//Remarks:  You can check the Chrono at anytime.
			TimeInterval Check();

			//Description: Stops the chrono and returns the elapsed time since the Chrono was started.
			//Remarks: The time given by the Chrono is the elapsed time since the Chrono 
			//was started excluding the time that the Chrono was paused.  
			//Returns: true if the call does not signal an error, false if otherwise.  
			//SYSTEMERROR_GEN_INVALID_OPERATION is signalled if the method is called on
			//a Chrono that is not started.
			TimeInterval Stop(); 

			//Description:  Resets the Chrono to zero.
			//Remarks: Sets the state of the Chrono to stopped and resets the time to zero. 
			//You may Reset the Chrono at anytime.
			void Reset();
			
			// {secret}
			// Description:  
			// Return the present state of the Chrono.
			// Remarks:  The state if one of: CHRONO_IS_STARTED, CHRONO_IS_STOPPED, CHRONO_IS_PAUSED.
			unsigned long GetState() const;

			
		#ifdef _TEST_ENABLED
			//{secret}
			static bool Test();
		#endif

		private:
			// {secret}
			TimeInterval Elapsed() const;
			
			// {secret}
			void UpdateAccumulatedTime();

		
		private:
			Time m_tInitialTime;
			TimeInterval m_tiAccumulatedTime;

			unsigned long m_ulState;
	};

#endif
