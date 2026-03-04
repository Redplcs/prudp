//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  

#ifndef _Trace_H_
#define _Trace_H_

// General flags - Exposed to user

// Group=System Traces

/*
Description:
Traces marked with this trace flag will never be displayed.
			
Remarks:
This trace flag gives you the ability to disable a trace as a function parameter.  
For example:

         void Dentist::ComputeAvailability(unsigned long ulTraceFlag)
         {
          ...
          TRACE(ulTraceFlag, _T("Trace will not appear if ulTraceFlag is TRACE_NEVER"));
          ...
          }
*/
#define TRACE_NEVER			0

/*
Description:
Traces marked with this trace flag will always be displayed.
			
Remarks:
This trace flag is set by default and cannot be disabled. Therefore, traces
marked with this flag will always be displayed.
*/
#define TRACE_ALWAYS			1

/*
Description:
Set this flag to trace the bootstrap initialization of $PRODUCTNAME$.
			
Remarks:
Set this flag to trace the creation and initialization of the components of
the system, such as the SessionClock, duplication spaces, and well-known objects.
*/
#define TRACE_INIT				(1<<2) 

/*
Description:
Set this flag to trace the updates sent to duplicas by duplication masters.

Remarks:
Set this flag to trace the updates performed on datasets of duplicated objects.

See Also:
DuplicatedObject::Update
*/
#define TRACE_UPDATE			(1<<3)

/*
Description:
Set this flag to trace the runtime operations of $PRODUCTNAME$.
			
Remarks:
Operations are events within the system.  The operations can be related to
duplicated objects, datasets, or duplication spaces.  Setting the TRACE_OPERATION 
flag has the effect of tracing all of the operations.  All of the specific types of operation traces
can then be disabled or enabled using the following methods of their respective classes:
AddToStoreOperation::ClearTraceFlag, AddToStoreOperation::SetTraceFlag, BufferRefreshOperation::ClearTraceFlag,
BufferRefreshOperation::SetTraceFlag, RemoveFromStoreOperation::ClearTraceFlag, RemoveFromStoreOperation::SetTraceFlag,
RoleChangeOperation::ClearTraceFlag, RoleChangeOperation::SetTraceFlag, 
RefreshOperation::ClearTraceFlag, RefreshOperation::SetTraceFlag, MatchOperation::ClearTraceFlag, MatchOperation::SetTraceFlag, 
MasterIDChangeOperation::ClearTraceFlag, MasterIDChangeOperation::SetTraceFlag,
FaultRecoveryOperation::ClearTraceFlag, FaultRecoveryOperation::SetTraceFlag.

For example, the following code will trace all operations except for the MatchOperation:

            TraceOutput::GetInstance()->SetTraceFlag(TRACE_OPERATION);
            MatchOperation::ClearTraceFlag();

See Also:
System Operations, Operation, DOOperation, DataSetOperation, DupSpaceOperation,
AddToStoreOperation, BufferRefreshOperation,
RemoveFromStoreOperation, RoleChangeOperation, RefreshOperation, MatchOperation,
MasterIDChangeOperation, FaultRecoveryOperation

*/
#define TRACE_OPERATION			(1<<4)

/*
Description:
Set this flag to trace the fault tolerance behaviour of the system.

Remarks:
This trace flag is associated with detection of faulty stations and 
the fault recovery of duplicated objects..

See Also:
DuplicatedObject::ApproveFaultRecovery, Fault Tolerance Overview
*/
#define TRACE_FAULT			(1<<5)

/*
Description:
Set this flag to trace the operations related to the duplication spaces of the
$PRODUCTNAME$ application.

Remarks:
This trace flag is reserved for tracing DuplicationSpace operations such as 
DuplicationSpace::MatchAcrossPSRelations.  Set this flag to trace the operations
performed on $PRODUCTNAME$ internal spaces as well as the spaces declared
as a part of your application.

See Also:
DuplicationSpace, Duplication Space Overview
*/
#define TRACE_DUPSPACE			(1<<6)

/*
Description:
Set this flag to trace the load balancing behaviour of the system.

Remarks:
This trace flag is used to trace the load balancing functionality of the system.

See Also:
Load Balancing Overview
*/
#define TRACE_LOADBALANCING		(1<<7)

/*
Description:
Set this flag to trace the dead reckoning behaviour of the system.

Remarks:
Use this trace flag to to trace the values of the extrapolated datasets.

See Also:
Dead Reckoning Overview
*/
#define TRACE_PHBDR			(1<<8)

/*
Description:
Set this flag to trace the messages sent and received by duplicated objects.

Remarks:
Set this flag to trace the exact time, thread, and process of each message sent and received 
between duplicated objects.
*/
#define TRACE_DOPROTOCOL			(1<<9) 

/*
Description:
Set this flag to trace the plug-ins loaded by the system.
*/
#define TRACE_PLUGIN			(1<<10)

/*
Description:
Use this flag to create one new custom flag.

Remarks:
Use this flag as is, or rename it to trace custom functionality in your application.  
For example, create a new flag called TRACE_DENTIST as follows:
            
            #define TRACE_DENTIST  TRACE_USER
            
*/
#define TRACE_USER			(1<<11)


/*
Description:
Set this flag to trace the teardown of $PRODUCTNAME$.
			
Remarks:
Set this flag to trace the shutdown of $PRODUCTNAME$.
*/
#define TRACE_TEARDOWN			(1<<12) 

/*
Description:
Set this flag to trace all of the available information.
			
Remarks:
Setting this trace flag is equivalent to setting all the trace flags.

*/
#define TRACE_ALL (TRACE_ALWAYS|TRACE_INIT|TRACE_UPDATE|TRACE_OPERATION|TRACE_FAULT|TRACE_DUPSPACE|TRACE_LOADBALANCING|TRACE_PHBDR|TRACE_DOPROTOCOL|TRACE_PLUGIN|TRACE_USER|TRACE_TEARDOWN)


// Internal Dev Traces are prefixed with 'D_'

//{secret}
#define D_TRACE_DEBUG				(1<<16)
//{secret}
#define D_TRACE_DOPROPERTY			(1<<17)
//{secret}
#define D_TRACE_MIGRATION			(1<<18)
//{secret}
#define D_TRACE_REFCOUNT			(1<<19)
//{secret}
#define D_TRACE_THREADS				(1<<20)
//{secret}
#define D_TRACE_LOCK				(1<<21)
//{secret}
#define D_TRACE_WAIT				(1<<22)
//{secret}
#define D_TRACE_USAGELOG			(1<<23)
//{secret}
#define D_TRACE_TIME_SYNC			(1<<24)
//{secret}
#define D_TRACE_TRANSPORT_CONNECT	(1<<25)
//{secret}
#define D_TRACE_TRANSPORT_MSG 		(1<<26)
//{secret}
#define D_TRACE_TRANSPORT_PROTO		(1<<27)
//{secret}
#define D_TRACE_TRANSPORT         (D_TRACE_TRANSPORT_CONNECT | D_TRACE_TRANSPORT_MSG)
//{secret}
#define D_TRACE_TREE_CREATION 		(1<<28)
//{secret}
#define D_TRACE_PROFILING			(1<<29)
//{secret}
#define D_TRACE_TEST				(1<<30)
//{secret}
#define D_TRACE_TECHSUPPORT			(1<<31)
//{secret}
#define D_TRACE_ALL		0xFFFFFFFF

// A few special flags.
// This flags is used to trace information just before a SYSTEMCHECK
// would fail.
//{secret}
#define TRACE_SYSTEMCHECK	TRACE_ALWAYS

//{secret}
#define NO_DEVICE			0
//{secret}
#define CONSOLE_DEVICE		1
//{secret}
#define DEBUGOUTPUT_DEVICE	2
//{secret}
#define FILE_DEVICE		3

#ifdef TRACE
#undef TRACE
#endif

#define BOOL2STR(C)	((C))?_T("true"):_T("false")


//{secret}
#define TRACE_PTR(F,V)		{TRACE(F,_T("%s=%x"),_T(#V),V);}
//{secret}
#define TRACE_UINT(F,V)		{TRACE(F,_T("%s=%d"),_T(#V),V);}
//{secret}
#define TRACE_INT(F,V)		{TRACE(F,_T("%s=%d"),_T(#V),V);}
//{secret}
#define TRACE_DOUBLE(F,V)	{TRACE(F,_T("%s=%f"),_T(#V),V);}
//{secret}
#define TRACE_ULONG(F,V)	{TRACE(F,_T("%s=%d"),_T(#V),V);}
//{secret}
#define TRACE_STRING(F,V)	{TRACE(F,_T("%s=\"%s\""),_T(#V),V);}

/*
Description:
Macro for creating a trace message.

Remarks:
For example, the following two lines of code are equivalent:

            TraceOutput::GetInstance()->Trace(TRACE_ALWAYS, _T("Hello World"));
            TRACE(TRACE_ALWAYS, _T("Hello World"));

See Also:
TraceOutput::Trace, DuplicatedObject::Trace, DuplicatedObjectStore::Trace
*/
#define TRACE			TraceOutput::GetInstance()->Trace

#include <Platform/PlatformDecl.h>

// Group=System Traces
/*
Description:
Use an instance of this class to trace the runtime functionality of your $PRODUCTNAME$ application.

Remarks:
To acquire a reference to the TraceOutput instance, use the GetInstance method.  For example,

          TraceOutput::GetInstance()->SetTraceFlag(TRACE_FAULT);
          
The above will have the effect of displaying traces for System Operations, fault-tolerance behaviour, as well as
any traces in the user code flagged with TRACE_USER.  The TRACE_OPERATION flag allows for more fine tuning of
which operations are traced and which are not, through the System Operations classes such as AddToStoreOperation, BufferRefreshOperation,
RemoveFromStoreOperation, RoleChangeOperation, RefreshOperation, MatchOperation, MasterIDChangeOperation, and FaultRecoveryOperation.
All of these classes contain both the SetTraceFlag and ClearTraceFlag methods.  
          
See Also: System Operations, DuplicatedObject::Trace, DuplicatedObjectStore::Trace    

*/
	class TraceOutput {

		// Group=
		
		public:
			TraceOutput();
			~TraceOutput();
			
			/*
			Description: Returns a pointer to the TraceOutput instance.
						
			Remarks: Use the reference returned by this function to control which information is to be
			traced and how.  For example:
						
				  TraceOutput::GetInstance()->SetTraceFlag(TRACE_OPERATION);
				  TraceOutput::GetInstance()->TraceLocalTime(false);
									
			Returns: A pointer to the TraceOutput instance.
			*/
			static TraceOutput* GetInstance();
			
			
			
			//{secret}
			static void SetTheTraceOutput(TraceOutput* pTheTraceOutput);
			
			/*
			Description: Use this method to define a trace message.
						
			Parameters:
			ulFlags:  The flag that is to be associated with this trace message.
			szFormat:  A reference to the trace message.

			Remarks: You can also use the TRACE macro.  The following two instructions
			are equivalent:
						
					 TRACE(TRACE_ALWAYS, _T("HelloWorld."));
					 TraceOutput::GetInstance()->Trace(TRACE_ALWAYS, _T("Hello World."));
							  
			*/
			void Trace(unsigned long ulFlags, TCHAR* szFormat, ... );
			
			/*
			Description: Sets a trace flag as an active trace flag for $PRODUCTNAME$.
					
			Parameters:
			ulFlag:  The trace flag that is to be set.
					
			Remarks: The only default trace flag is TRACE_ALWAYS.  Use this method to 
			set more trace flags active.
			*/
			void SetTraceFlag(unsigned long ulFlag);
			
			/*
			Description: Reset a trace flag as inactive for $PRODUCTNAME$.
						
			Parameters:
			ulFlag:  Optional trace flag that is to be reset.
						
			Remarks: Use this method to reset a trace flag to inactive.   If you do 
			not supply the parameter, $PRODUCTNAME$ resets the trace flag
			to the default TRACE_ALWAYS.
						
			See Also: SetTraceFlag			
			*/
			void ClearTraceFlag(unsigned long ulFlag);
			
			/*
			Description: Reset all trace flags as inactive except for TRACE_ALWAYS.
			Remarks: Use this method to reset all trace flags, except for TRACE_ALWAYS, to inactive.   
			See Also: SetTraceFlag, ClearTraceFlag			
			*/
			void ClearTraceFlags();

			/*
			Description: Use this method to turn trace numbering on or off.
						
			Parameters:
			bDoIt:  Optional Boolean parameter that sets whether or not the traces will be numbered.
						
			Remarks: By default, the traces are not numbered.  If the bDoIt parameter of this method is true,
			the traces will be numbered.   If the bDoIt parameter is false, the traces will not be numbered.
			*/
			void NumberTraces(bool bDoIt=true);
			
			/*
			Description: Use this method to turn on or off the output of the process number along with each trace.
						
			Parameters:
			bDoIt:  Optional Boolean parameter that sets whether or not the process ID should be printed
			along with each trace.
						
			Remarks: By default, the process ID is not included with each trace.  If the bDoIt parameter of this method is true,
			the process ID that generated the trace message will be included.   If the bDoIt parameter is false, 
			the traces will not include the process ID.
			*/
			void TraceProcessID(bool bDoIt=true);
			
			/*
			Description: Use this method to turn on or off the output of the thread number along with each trace.
						
			Parameters:
			bDoIt:  Optional Boolean parameter that sets whether or not the thread ID should be printed
			along with each trace.
						
			Remarks: By default, the thread ID is not included with each trace.  If the bDoIt parameter of this method is true,
			the thread ID that generated the trace message will be included.   If the bDoIt parameter is false, 
			the traces will not include the thread ID.
			*/
			void TraceThreadID(bool bDoIt=true);
			
			/*
			Description: Use this method to turn on or off the output of the local time along with each trace.
						
			Parameters:
			bDoIt:  Optional Boolean parameter that sets whether or not the local time should be printed
			along with each trace.
						
			Remarks: By default, the local time is not included with each trace.  If the bDoIt parameter of this method is true,
			the local time of the trace message will be included.   If the bDoIt parameter is false, 
			the traces will not include the time of the trace.  The time is the time since initialization.
			*/
			void TraceLocalTime(bool bDoIt=true);


			/*
			{secret}

			Description: Use this method to turn on or off the output of the thread name along with each trace.

			Parameters:
			bDoIt:  Optional Boolean parameter that sets whether or not the thread
			name should be printed
			along with each trace.

			Remarks: Each time a new thread is created by $PRODUCTNAME$, the thread is given a name according to
			its functionality.  The name "User Thread" is given to threads created due to user application code.
			By default, the thread name is not included with each trace.  If the bDoIt parameter of this method is true,
			the the thread name will be included.   If the bDoIt parameter is false, 
			the traces will not include the thread name of the trace.
			*/
			void TraceSystemThreadName(bool bDoIt=true);

			/*
			Description: Use this method to turn on or off the output of the Station DOHandle along with each trace.

			Parameters:
			bDoIt:  Optional Boolean parameter that sets whether or not the local Station DOHandle should be printed
			along with each trace.

			Remarks: By default, the local Station DOHandle is not included with each trace.  If the bDoIt parameter of this method is true,
			the Station DOHandle will be included with each trace.   If the bDoIt parameter is false, 
			the traces will not include the local Station DOHandle.
			*/
			void TraceLocalStationHandle(bool bDoIt=true);


			// {secret}
            void TraceCurrentContext(bool bDoIt=true);

			/*
			Description: Sets the output device for the TraceOutput to be the console.
			Remarks: Use this method to have the traces appear on the console.  This is the default output device
			for the TraceOutput.
			*/
			void SelectConsoleDevice();
			
			/*
			Description: Sets the output device for the TraceOutput to be a file.
						
			Remarks: All traces following a call to this method will be written to the specified file.  The file 
			will be created.   If the file can not be created, the change is not applied, the 
			previous output device continues to be used, and SYSTEMERROR_GEN_IO_ERROR is signalled.
						
			Parameters:
			szFileName:  Optional filename of file to be created.  The default filename is "trace.txt".

			See Also: SelectConsoleDevice, SelectDebugOutputDevice
			*/
			bool SelectFileDevice(TCHAR* szFileName=_T("trace.txt"));
			
			/*
			Description: Sets the output device for the TraceOutput to be the debug console.
			Remarks: Use this method to have the traces appear on the debug console.  
			See Also: SelectFileDevice, SelectConsoleDevice
			*/
			void SelectDebugOutputDevice();


			// {secret}
			void RegisterStationHandleResolver(unsigned long (*pfStationHandleResolver)()) {
				m_pfStationHandleResolver=pfStationHandleResolver;				
			}
				
			 //{secret}
			void RegisterThreadNameResolver(TCHAR* (*pfThreadNameResolver)()) {
				m_pfThreadNameResolver=pfThreadNameResolver;				
			}		

             //{secret}
			void RegisterCurrentContextResolver(unsigned int (*pfCurrentContextResolver)()) {
				m_pfCurrentContextResolver=pfCurrentContextResolver;				
			}		


		private:
			//{secret}
			void SelectOutputDevice(int iDevice);
			
			
		private:
			
			//{secret}
			int m_iDebugOutputDevice;
			//{secret}
			unsigned long m_ulTraceFlags;
			//{secret}
			void* m_fpDebugFile;
			//{secret}
			static TraceOutput* s_poTheTraceOutput;
			//{secret}
			static TraceOutput s_oTheTraceOutput;
			//{secret}
			unsigned long m_ulTraceNumber;
			//{secret}
			bool m_bTraceThreadID;
			//{secret}
			bool m_bTraceProcessID;
			//{secret}
			bool m_bTraceLocalTime;
			//{secret}
			bool m_bTraceSystemThreadName;
			//{secret}
			bool m_bTraceLocalStationHandle;
  			//{secret}
			bool m_bTraceCurrentContext;


			unsigned long (*m_pfStationHandleResolver)();
			TCHAR* (*m_pfThreadNameResolver)();
            unsigned int  (*m_pfCurrentContextResolver)();

			unsigned long m_ulInitTime;
	};

#endif
