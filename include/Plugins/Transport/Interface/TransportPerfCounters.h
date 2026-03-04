//  
//   (c) Copyright 1998-2000, Proksim Inc.
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _TransportPerfCounters_H_
#define _TransportPerfCounters_H_

#include <Plugins/Transport/Interface/TransportDecl.h>
#include <Platform/PerfCounter.h>

/*
{group: Performance Fine Tuning}

description: This counter records the number of bits per second 
sent via the transport protocol to peer nodes. 
Remarks: This counter will not account for any overhead added 
by the underlying transport protocol (e.g. UDP header, IP header,
PPP encapsulation.)
*/
#define PERF_TRANSPORT_BPS_SENT	0

/*
{group: Performance Fine Tuning}

description: This counter records the number of bits per second
received by the transport protocol from peer nodes.
Remarks: This counter will not account for any overhead added 
by the underlying transport protocol (e.g. UDP header, IP header, 
PPP encapsulation.)
*/
#define PERF_TRANSPORT_BPS_RECV	1

/*
{group: Performance Fine Tuning}

description: This counter records the number of packets sent per 
second via the transport protocol to peer nodes.
*/
#define PERF_TRANSPORT_PACKETS_SENT	2

/*
{group: Performance Fine Tuning}

description: This counter records the number of packets received 
per second by the transport protocol from peer nodes.
*/
#define PERF_TRANSPORT_PACKETS_RECV	3

/*
{group: Performance Fine Tuning}

description: This counter records the number of packets lost per 
second by the transport protocol from peer nodes.
*/
#define PERF_TRANSPORT_PACKETS_LOST	4

// {Secret}
#define PERF_TRANSPORT_HIGHEST_ID		4

/*
{group: Performance Fine Tuning}

description: This class contains the performance counters associated 
with the transport protocol and can be accessed via Transport::GetPerfCounters.

Remarks: This class contains the performance counters associated with the
transport protocol. The class can be accessed via Transport::GetPerfCounters.
It should be noted that some transport protocol plug-ins may not support all 
the tansport performance counters available.

See also: Transport::GetPerfCounters
*/
class TransportPerfCounters {
	//group=
	public:
		//Description: The constructor is called automatically by $PRODUCTNAME$.
		TransportPerfCounters();
		//Description: The destructor is called automatically by $PRODUCTNAME$.
	    ~TransportPerfCounters();

		//Summary: Traces the values of the transport performance counters to the TraceOutput.
		void Trace();
		
		//Summary: Resets all the transport performance counters to zero.
		void Reset();

		/*
		Summary: Returns a performance value.

		Parameters:
		iCounterID: Queried performance counter
		iValue: Requested value.

		Remarks: The following counters are available: PERF_TRANSPORT_BPS_SENT,
		PERF_TRANSPORT_BPS_RECV, PERF_TRANSPORT_PACKETS_SENT, 
		PERF_TRANSPORT_PACKETS_LOST, and PERF_TRANSPORT_PACKETS_RECV. For each counter, 
		the following values can be queried: PERF_FREQUENCY_LAST, PERF_FREQUENCY_AVERAGE, 
		PERF_FREQUENCY_MIN, PERF_FREQUENCY_MAX and PERF_COUNT_TOTAL.

		Returns: 0 if an error occurs and sets SYSTEMERROR_GEN_OUT_OF_RANGE
		*/
		unsigned long GetValue(int iCounterID, int iValue);
		
		//{secret}
		void Inc(int iCounterID, int iValue);

		// {Secret}
		PerfCounter* GetCounter(int iCounterID);

	private:
		PerfCounter m_aPerfCounters[PERF_TRANSPORT_HIGHEST_ID+1];
};

#endif
