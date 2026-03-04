//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _Pacer_H_
#define _Pacer_H_

#include <Utility/UtilityDecl.h>
#include <Platform/Time.h>
#include <Utility/Chrono.h>

class EventHandler;
class Event;

// Group=Time Management

// Summary:  The class Pacer provides an easy way to pace a particular activity
// to ensure that it goes no faster than a specified frequency. 
//
// Remarks:  The class Pacer provides an easy way to pace a particular activity
// to ensure that it goes no faster than a specified frequency. It is important to note
// that the pacer can only sleep to affect the frequency and therefore, can slow down but not 
// speed up processing time.
class Pacer {

// Group=

	public:

		// Description: Constructs a Pacer and calls SetFrequency(dFrequency) on it.
		// Parameters:  dFrequency: The maximum frequency at which you 
		// want the activity to be performed.  
		Pacer(double dFrequency=0);
	
		virtual ~Pacer();

		// Description: Sets the maximum frequency, in Hertz, at which 
		// the paced activity will be performed.
		// 
		// Parameters:
		// dFrequency: Frequency, in Hertz, at which the Pacer runs. If 
		// the value of dFrequency is 0 the Pacer will not delay the calls to Pace.
		// Remarks:  A frequency of 10 Hz (i.e. 10 intervals per second) will cause 
		// the Pacer to remain in the Pace method long enough to ensure that the calls 
		// to perform the paced activity do not occur without at least a 0.1 second 
		// delay (i.e. 1/10). Therefore, if the processing time between two consecutive 
		// calls to Pace is 0.02 seconds, Pace will sleep for 0.08 seconds.	
		// See Also: GetFrequency
	void SetFrequency(double dFrequency);

		// Description: Use this method to obtain the frequency of the Pacer.
		// Returns: The pacer frequency, in HertZ, that was set with SetFrequency.
		// See also: SetFrequency.
		double GetFrequency() const {return m_dFrequency;}

		// Description: Causes the pacer to return immediately from the Pace call.
		// Remarks: This method is called from another thread to cause the thread
		// that called Pace to exit from the method. Use this function to exit 
		// from Pace while it is sleeping to pace an activity's frequency of occurrence.
		void Interrupt();

		// Description: Causes a delay to ensure that the paced activity is called at a rate
		// no faster than a set frequency. This is the main method of the pacer that 
		// actually does the pacing.
		// 
		// Remarks: Assume that the frequency is set via SetFrequency to 10Hz (i.e. 
		// 10 intervals/second or 0.1 seconds/interval). If the delay between two 
		// calls to Pace is 0.06 s, the second call will sleep for 0.04 s to ensure 
		// that the method is called at a rate no faster than the set frequency.
		// 
        // The Pacer also records statistics about the processing time, which is the
		// time between two consecutive calls to the method Pace. For the above 
		// example the processing time is equal to 0.06 s.  
		//
		// Note:  When Pace is called, the thread goes to sleep if a delay shorter 
		// than 1/dFrequency has occured since the last call. If the value of 
		// dFrequency is 0, it returns immediately.
		virtual void Pace();

		// Description: Use this method to obtain the statistics associated with the Pacer. 
		// Returns: The statistics associated with the Pacer. The 
		// statistics are calculated since the last time the method ResetStats 
		// was called, or since the Pacer was created, whichever happened last.
		// Parameters:
		//   ptiTotal: Total elapsed time since the creation of the Pacer or 
		//   since the last call to ResetStats.
		//   ptiTotalProcessing: Total time spent between the calls to Pace.
		//   ptiMinProcessing: Minimum time spent between two calls to Pace.
		//   ptiMaxProcessing: Maximum time spent between two calls to Pace.
		//   pulLoops: The number of times Pace was called since the creation 
		//   of the Pacer or a call to ResetStats.
		//See Also: ResetStats
		void GetStats(TimeInterval* ptiTotal,
					  TimeInterval* ptiTotalProcessing,
					  TimeInterval* ptiMinProcessing,
					  TimeInterval* ptiMaxProcessing,
					  unsigned long *pulLoops) const;
	
		// Description: Resets all the statistics for the Pacer to zero.
		// See Also: GetStats
		void ResetStats();

	public:
#ifdef _TEST_ENABLED
		/* {Secret} */
		static bool Test();
#endif
	

	private:
		double m_dFrequency;
		Chrono m_oChrono;
		bool m_bFirstLoop;
		EventHandler *m_pEventHandler;
		Event *m_pInterruptEvent;

	protected:
		TimeInterval m_tiDesiredLoopTime;
		
		TimeInterval m_tiTotal, m_tiTotalProcessing, m_tiMinProcessing, m_tiMaxProcessing;
		
		unsigned long m_ulLoops;
		bool m_bStatsRecorded;
};

#endif

