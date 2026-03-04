//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _DataSetPerfCounters_H_
#define _DataSetPerfCounters_H_

#include <ObjDup/ObjDupDecl.h>
#include <Platform/PerfCounter.h>

/*
{group: Performance Fine Tuning}

description: This counter records the frequency at which calls to 
update the dataset are made. A call to update the dataset occurs each time
a DuplicatedObject that contains the dataset calls its DuplicatedObject::Update method.
*/
#define PERF_DATASET_UPDATES	0

/*
{group: Performance Fine Tuning}

description: This counter records the frequency of update calls that 
triggered at least one update message. 

Remarks: If an update generates several messages since it has been discovered
by several stations, this counts as just one update multicast. The frequency 
of this counter cannot be higher than the frequency of the PERF_DATASET_UPDATES.
*/
#define PERF_DATASET_UPDATE_MULTICASTS	1

/*
{group: Performance Fine Tuning}

description: This counter records the frequency at which update messages are sent.

Remarks: When only two stations belong to the session, the frequency of 
this counter is identical to the PERF_DATASET_UPDATE_MULTICASTS frequency.
When two or more stations belong to the session, the frequency of this
counter will typically be higher as some calls to DuplicatedObject::Update
will result in a multicast update message sent to several stations.
*/
#define PERF_DATASET_UPDATE_MESSAGES	2

// {Secret}
#define PERF_DATASET_HIGHEST_ID		2

/*
{group: Performance Fine Tuning}

description: This class contains the performance counters associated to a dataset
class. 

Remarks: A DataSetPerfCounters class is created by $PRODUCTNAME$ for every
DataSet declared in the DDL file. The performance counters class can
be accessed using the static method DataSet::GetPerformanceCounters.

For example, if the following DataSet is declared in the DDL:

$ifdef NETZ$
		dataset Speed {
			double sx;
			double sy;
		};

Then, in the C++ code the following call can be made to access the
performance counters associated with the Speed dataset:

		DataSetPerfCounters*
			pSpeedPerfCounters=Speed::GetPerformanceCounters();

$endif$

$ifdef TSIS$
		dataset RateOfChange {
			double dx;
		};

Then, in the C++ code, the following call can be made to access the
performance counters associated with the RateOfChange dataset:

		DataSetPerfCounters*
			pSpeedPerfCounters=RateOfChange::GetPerformanceCounters();

$endif$

See also: DataSet::GetPerformanceCounters
*/
class DataSetPerfCounters {
	//group=
	public:
		//Remarks: The constructor is called automatically by $PRODUCTNAME$.
		DataSetPerfCounters(TCHAR* strDataSet);
		//Remarks: The destructor is called automatically by $PRODUCTNAME$.
		~DataSetPerfCounters();

		// {Secret}
		void Register();
		// {Secret}
		void Unregister();		

		// {Secret}
		void Update(unsigned long ulNbSent);

		//Summary: Traces the dataset performance counters values to the TraceOutput.
		//{Secret} for now - until TraceOutput is documented.
		void Trace();
		
		//Summary: Resets all the dataset performance counters to zero.
		void Reset();

		/*
		Summary: Returns a performance value.

		Parameters:
		iCounterID: Queried performance counter
		iValue: Requested value.

		Returns: 0 if an error occurs and sets SYSTEMERROR_GEN_OUT_OF_RANGE.
		Throws:  SYSTEMERROR_GEN_OUT_OF_RANGE
		Remarks: The following counters are available: PERF_DATASET_UPDATES,
		PERF_DATASET_UPDATE_MULTICASTS and PERF_DATASET_UPDATE_MESSAGES. For 
		each counter, the following values can be queried: PERF_FREQUENCY_LAST, 
		PERF_FREQUENCY_AVERAGE, PERF_FREQUENCY_MIN, PERF_FREQUENCY_MAX and PERF_COUNT_TOTAL.
		*/
		int GetValue(int iCounterID, int iValue);

	private:
        void RegisterCounter(PerfCounter** ppCounter, TCHAR* strName);
		PerfCounter* GetCounter(int iCounterID);

	private:

		TCHAR* m_strDataSet;
		PerfCounter* m_ppcPerfCounter[3];
		bool m_bRegistered;
};

#endif
