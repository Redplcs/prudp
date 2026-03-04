//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _DataSetTemplate_H_
#define _DataSetTemplate_H_

#include <ObjDup/ObjDupImpl.h>
#include <ObjDup/ObjDupProtocol.h>
#include <ObjDup/BufferRefreshOperation.h>
#include <ObjDup/RefreshOperation.h>
#include <Platform/SysExceptionHandler.h>
#include <ObjDup/DataSetFlag.h>

class DataSetOperation;


#define DATASET_OP_REGISTER		0
#define DATASET_OP_UNREGISTER	1

// Group=Object Duplication Subsystem

// This macro is used to invoke a dataset callback in a safe way:
// exceptions in user code will be trapped appropriatly.
#define SAFEDSCALL(CALL,DESCRIPTION)		TRY_SYS_EXCEPTIONS {CALL;} CATCH_USER_SYS_EXCEPTIONS(_T("DataSet"), DESCRIPTION);

template <class SpecificDataSet> class DataSetTemplate: public SpecificDataSet {
	public:

		DataSetTemplate() {
#ifdef _DEBUG_CHECK
			m_pDOContainer=NULL;
#endif
		}

		void RegisterDOContainer(DuplicatedObject* pDOContainer) {
#ifdef _DEBUG_CHECK
			m_pDOContainer=pDOContainer;
#endif
		}

		void UpdateLoop(DuplicatedObject* pDO, unsigned char byIndex, Time tTimestamp=GetTimestamp()) {
			// Called for every DataSet.
#ifdef _DEBUG_CHECK
			SYSTEMCHECK(pDO==m_pDOContainer);
#endif
			unsigned long ulNbSent=0;
			if (SomeUpdatesRequired()) {
				TRACE(TRACE_UPDATE,_T("Updating DataSet index %d of %s %x"),
					  byIndex,
					  pDO->GetClassNameString(), (unsigned long)pDO->GetHandle());	
				// Create the message.
				unsigned char byZero=0;
				unsigned long ulID=pDO->GetHandle();
				Message* pMsg=pDO->GetAssociatedProtocol()->CreateUpdateMessage(&ulID,&byIndex);
				AddSourceTo(pMsg, tTimestamp, false);
							// Since there might eventually be more than one dataset per message,
							// we end with a zero to indicate the end.  
				pMsg->AddData(&byZero);
				{
					// Multicast the message.
					MulticastControl oControl;
					pDO->MulticastMessage(pMsg, &oControl, ReliableUpdate());
					DuplicatedObjectStore::GetInstance()->GetUpdateCounter()->Inc(oControl.GetNbMessagesSent());
					ulNbSent+=oControl.GetNbMessagesSent();
				}
				// Delete it.
				fdelete pMsg;
				FinishedAllUpdates(); 
			}
			s_oPerfDataSet.Update(ulNbSent);
		}

		void AddToDiscoveryMessage(DuplicatedObject* pDO, unsigned char byIndex, Message* pMsg) {
			Time tTimestamp=GetTimestamp();
			AddSourceTo(pMsg, tTimestamp, true);
		}

		void ExtractFrom(Message* pMsg, bool bInitialRefresh, DuplicatedObject *pDO) {
			if (UsesBufferedRefresh()) {				
				BufferRefreshOperation oBufferRefreshOp(this, bInitialRefresh, GetLock(), pDO); 
				_ExtractFrom(pMsg, bInitialRefresh, &oBufferRefreshOp);
			} else {
				RefreshOperation oRefreshOp(this, bInitialRefresh, pDO);
				_ExtractFrom(pMsg, bInitialRefresh, &oRefreshOp);
			}
		}

		// This method is separated from ExtractFrom to solve a
		// compilation error with VC++ related to stack unwinding.
		// (error C2712) - while compiling in ReleaseA.
		void _ExtractFrom(Message* pMsg, bool bInitialRefresh,
						 DataSetOperation* pOperation) {
			SAFEDSCALL(OperationBegin(pOperation),_T("OperationBegin"));
			pOperation->Trace(Operation::Begin);
			SpecificDataSet::ExtractFrom(pMsg);
			SAFEDSCALL(OperationEnd(pOperation),_T("OperationEnd"));
			pOperation->Trace(Operation::End);
		}

		static void Operation(unsigned long ulOp) {
			switch (ulOp) {
				case DATASET_OP_REGISTER:
					if (!s_bDataSetRegistered) {
						s_oPerfDataSet.Register();
						s_bDataSetRegistered=true;
					}
					break;
				case DATASET_OP_UNREGISTER:
					if (s_bDataSetRegistered) {
						s_oPerfDataSet.Unregister();
						s_bDataSetRegistered=false;
					}
					break;
				default:
					SYSTEMCHECK(false);
			}
		}

	private:

		static bool s_bDataSetRegistered;
};

// Macros to implement specific dataset and dataset::buffer.

#define _DS_ARRAY_OP(OP, SIZE)				{int i; for (i=0; i<SIZE; i++) {OP;}}


#define _DS_IMPLEMENT(DS)											\
		DataSetPerfCounters DATASET(DS)::s_oPerfDataSet(_T(#DS));	\
	    bool DataSetTemplate<DS>::s_bDataSetRegistered=false;

#define _DS_GENERAL_DECLARATIONS()									\
		static DataSetPerfCounters s_oPerfDataSet;					\
		static DataSetPerfCounters* GetPerformanceCounters() {return &s_oPerfDataSet;}


#define _DS_DECLARE_VAR(type,name)					type name
#define _DS_DECLARE_VECTOR(type,name)				MemberVector<type> name; \
													typedef MemberVector<type>::Iterator name##Iterator;
#define _DS_DECLARE_LIST(type,name)					MemberList<type> name;    \
													typedef MemberList<type>::Iterator name##Iterator;
#define _DS_DECLARE_QUEUE(type,name)				MemberQueue<type> name;
													
#define _DS_DECLARE_EXTRAPOLATION_VAR(type,name)	PHBDRVAR(type) name;

#define _DS_DECLARE_ARRAY(type,name,size)			type name[size];
#define _DS_DECLARE_EXTRAPOLATION_ARRAY(type,name,size)	PHBDRVAR(type) name[size];

#define _DS_EXTRACT_TIMESTAMP()				Time tTimeStamp; pMsg->Extract(&tTimeStamp); PHBDRParameters::ApplyPostdateDelay(&tTimeStamp);
#define _DS_EXTRACT_BREAK()					ContinuityBreak oContinuityBreak(pMsg);
#define _DS_EXTRACT_VAR(name)				pMsg->Extract(&name);
#define _DS_EXTRACT_OBJECT(name)			name.ExtractFrom(pMsg);

#define _DS_EXTRACT_OBJECT_ARRAY(name,size)	_DS_ARRAY_OP(_DS_EXTRACT_OBJECT(name[i]), size)
#define _DS_EXTRACT_ARRAY(name,size)		pMsg->Extract(name,size);

#define _DS_UPDATE_TIME(T)					unsigned long ulPosition=m_vectorTime.NewValue(T, oContinuityBreak);

#define _DS_UPDATE_VAR(name)				Buffer::name.NewValue(name, ulPosition);  \
											Buffer::name.ComputeParameters(s_oPHBDRParameters, m_vectorTime, byRole, ulPosition, oContinuityBreak);

#define _DS_UPDATE_ARRAY(name,size)			{for (int i=0; i<size; i++) {_DS_UPDATE_VAR(name[i]);}}

#define _DS_READY_TO_USE()	m_vectorTime.DelayedValueReadyToUse()
#define _DS_DELAYED_UPDATE_TIME()								\
	unsigned char byDelayedContinuityBreak;					\
	unsigned long ulPosition=m_vectorTime.UseDelayedValue(&byDelayedContinuityBreak);
#define _DS_DELAYED_UPDATE_VAR(name)								\
	Buffer::name.UseDelayedValue(ulPosition);		\
	Buffer::name.ComputeParameters(s_oPHBDRParameters, m_vectorTime, DUPLICA, ulPosition, byDelayedContinuityBreak);
#define _DS_DELAYED_UPDATE_ARRAY(name,size) {for (int i=0; i<size; i++) {_DS_DELAYED_UPDATE_VAR(name[i]);}}

#define _DS_ADD_TIMESTAMP()					*pMsg << tTimestamp;
#define _DS_ADD_BREAK()						m_oBreak.AddSourceTo(pMsg, bDiscovery);
#define _DS_ADD_VAR(VAR)					pMsg->AddData(&VAR);
#define _DS_ADD_OBJECT(VAR, COMPLETE_UPDATE)					VAR.AddSourceTo(pMsg, COMPLETE_UPDATE);

#define _DS_ADD_OBJECT_ARRAY(VAR,SIZE,COMPLETE_UPDATE)		_DS_ARRAY_OP(_DS_ADD_OBJECT(VAR[i], COMPLETE_UPDATE), SIZE)

#define _DS_ADD_ARRAY(VAR,size)				pMsg->AddData(VAR,size);

#define _DS_REFRESHVARS(DS)					bool Refresh(DATASET(DS)* pDS)
#define _DS_COPY_VAR(VAR)					pDS->VAR=VAR
#define _DS_EXTRAPOLATE_VAR(VAR)			pDS->VAR=GetValue(s_oPHBDRParameters, VAR)

#define _DS_COPY_ARRAY(VAR,SIZE)			_DS_ARRAY_OP(_DS_COPY_VAR(VAR[i]), SIZE)
#define _DS_EXTRAPOLATE_ARRAY(VAR,SIZE)		_DS_ARRAY_OP(_DS_EXTRAPOLATE_VAR(VAR[i]), SIZE)

#define _DS_PREDICT_NEWPOINT_VAR(VAR)		VAR=m_dsBuffer.VAR.PredictValue(s_oPHBDRParameters, m_dsBuffer.GetTimeVector(), tTimestamp);
#define _DS_PREDICT_NEWPOINT_ARRAY(VAR,size) {for (int i=0; i<size; i++) {_DS_PREDICT_NEWPOINT_VAR(VAR[i]);}}

#define _DS_ADDESE_VAR(VAR)					dESE+=pBuffer->ComputeESE(s_oPHBDRParameters, VAR, pBuffer->VAR);
#define _DS_ADDESE_ARRAY(VAR,SIZE)			_DS_ARRAY_OP(_DS_ADDESE_VAR(VAR[i]),SIZE)

// Dataset type...

#define _DS_DECLARE_CONSTANT()				bool SomeUpdatesRequired() {return false;}
#define _DS_IMPLEMENT_CONSTANT(DS)

#define _DS_DECLARE_VARIABLE()				
#define _DS_IMPLEMENT_VARIABLE(DS)

// Buffered...

#define _DS_DECLARE_BUFFERED()				Buffer m_dsBuffer;	OperationLock<EREWLock> m_oLock;	\
											ExclusiveDenialOperationLock* GetLock() {return &m_oLock;}	 \
											ExclusiveDenialOperationLock* GetBufferRefreshLock() {return &m_oLock;}	\
											void ExtractFrom(Message* pMsg) {m_dsBuffer.ExtractFrom(pMsg);} \
											void _Refresh(RefreshOperation* pOp) {SAFEDSCALL(OperationBegin(pOp),_T("OperationBegin")); pOp->Trace(Operation::Begin); m_dsBuffer.Refresh(this); SAFEDSCALL(OperationEnd(pOp),_T("OperationEnd")); pOp->Trace(Operation::End);} \
                                            bool Refresh(DuplicatedObject *pDO=NULL) {OperationDenial oDenial(GetLock(), _T("User call to refresh")); DSCHECK_ROLE_IS_DUPLICA(false); RefreshOperation oRefreshOp(this, false, pDO); _Refresh(&oRefreshOp); return true;}	\
											bool UsesBufferedRefresh() const {return true;}
#define _DS_IMPLEMENT_BUFFERED(DS)

// Reliability...

#define _DS_DECLARE_RELIABLE()				bool ReliableUpdate() {return true;}
#define _DS_IMPLEMENT_RELIABLE(DS)

#define _DS_DECLARE_UNRELIABLE()			bool ReliableUpdate() {return false;}
#define _DS_IMPLEMENT_UNRELIABLE(DS)

#define _DS_DECLARE_CUSTOM_RELIABILITY()
#define _DS_IMPLEMENT_CUSTOM_RELIABILITY(DS)

// The following macros are used to check if the role of the
// DuplicatedObject that contains the dataset is appropriate for the
// operation beeeing called.  These checks can only be performed in
// DEBUG mode, where an extra variable is kept.

#ifdef _DEBUG_CHECK

#define DSCHECK_ROLE_IS_DUPLICA(ERROR) {if (m_pDOContainer && m_pDOContainer->IsADuplicationMaster()) {SIGNAL_SYSTEMERROR(SYSTEMERROR_OBJDUP_INVALID_ON_MASTER,0); return ERROR;}}
#define DSCHECK_ROLE_IS_DM(ERROR) {if (m_pDOContainer && m_pDOContainer->IsADuplica()) {SIGNAL_SYSTEMERROR(SYSTEMERROR_OBJDUP_INVALID_ON_DUPLICA,0); return ERROR;}}

#else

#define DSCHECK_ROLE_IS_DUPLICA(ERROR)
#define DSCHECK_ROLE_IS_DM(ERROR)

#endif


// Update filter...
// Dataset default's behavior is no update filter.

#define _DS_DECLARE_NO_FILTER()
#define _DS_IMPLEMENT_NO_FILTER(DS)


#define _DS_DECLARE_UPON_REQUEST_FILTER()									\
		DataSetFlag m_dsUpdateRequestFlag;									\
		bool SomeUpdatesRequired() {										\
			if (m_dsUpdateRequestFlag.GetFlag()) {							\
				m_dsUpdateRequestFlag.ResetFlag(); return true;				\
			} else {														\
				return false;												\
			}																\
		}																	\
		bool RequestUpdate();
#define _DS_IMPLEMENT_UPON_REQUEST_FILTER(DS)								\
		bool DATASET(DS)::RequestUpdate() {DSCHECK_ROLE_IS_DM(false); m_dsUpdateRequestFlag.SetFlag(); return true;}

// Nothing special needs to be done.  The code will call two methods,
// that must be redefined by the user: bool SomeUpdatesRequired() and
// void FinishedAllUpdates().
#define _DS_DECLARE_CUSTOM_FILTER()
#define _DS_IMPLEMENT_CUSTOM_FILTER(DS)

#endif
