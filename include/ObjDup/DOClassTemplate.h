//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  



#ifndef _DOClassTemplate_H_
#define _DOClassTemplate_H_

#include <ObjDup/ObjDupImpl.h>
#include <ObjDup/DuplicatedObject.h>
#include <ObjDup/DuplicationSpace.h>


// Group=Object Duplication Subsystem

template <class DO, class ParentClass, unsigned long CLASSID> class DOClassTemplate: public ParentClass {
	public:
		DOClassTemplate(unsigned long ulClassID=CLASSID): ParentClass(ulClassID){}
		virtual ~DOClassTemplate() {};

		// A few general methods...
        virtual bool SpecificUpdate(DuplicatedObject* pDO, DataSet *pDataset=NULL) {
			//Specific dataset wasn't found
			if (!((DO*)pDO)->SpecificUpdate(pDataset) && pDataset) 
			{
				return false;
			}
			return true;
		}

		virtual bool SpecificRefresh(DuplicatedObject* pDO, DataSet *pDataset=NULL) {
			//Specific dataset wasn't found
			if (!((DO*)pDO)->SpecificRefresh(pDO, pDataset) && pDataset) 
			{
				return false;
			}
			return true;
		}

		virtual void SpecificAddDSToDiscoveryMessage(DuplicatedObject* pDO, Message* pMsg) {
			((DO*)pDO)->SpecificAddDSToDiscoveryMessage(pMsg);
		}


		virtual void SpecificExtractDSFromDiscoveryMessage(DuplicatedObject* pDO, Message* pMsg) {
			((DO*)pDO)->SpecificExtractDSFromDiscoveryMessage(pMsg);
		}

		virtual bool SpecificExtractADataset(DuplicatedObject* pDO, Message* pMsg, unsigned char byDatasetIndex) {
			return ((DO*)pDO)->SpecificExtractADataset(pMsg, byDatasetIndex);
		}

		virtual bool ValidCastTowards(unsigned long ulClassID) {
			if (ulClassID==CLASSID) {
				return true;
			} else {
				return ParentClass::ValidCastTowards(ulClassID);
			}
		}
};

// A few macros used to ease the generation of the specific DOClass code.

#define _DOC_DeclareCallback(CLASS)																			\
  virtual bool ApproveFaultRecovery(DuplicatedObject* pDO);													\
  virtual bool ProcessDOMessage(DuplicatedObject* pDO, Message *pMsg);										\
  virtual bool ApproveEmigration(DuplicatedObject* pDO, unsigned long ulReason);							\
  virtual double GetWeight(DuplicatedObject* pDO);															\
  virtual void Trace(DuplicatedObject* pDO, unsigned long ulTraceFlag);										\
  virtual void InitDO(DuplicatedObject* pDO);	\
  virtual void OperationBegin(DuplicatedObject* pDO, DOOperation* pOperation); \
  virtual void OperationEnd(DuplicatedObject* pDO, DOOperation* pOperation); \
  virtual void DataSetOperationBegin(DuplicatedObject* pDO, DataSetOperation* pOperation); \
  virtual void DataSetOperationEnd(DuplicatedObject* pDO, DataSetOperation* pOperation); \
  virtual unsigned long MsgSendingCapacity(DuplicatedObject* pDO, unsigned long ulNbStations); \
  virtual double ComputeDistance(DuplicatedObject* pDO, DuplicatedObject* pLocalDO);

#define _DOC_ImplementCallback(CLASS)									\
  bool _DOC_##CLASS::ApproveFaultRecovery(DuplicatedObject* pDO) {		\
		return ((CLASS*)pDO)->ApproveFaultRecovery();}					\
  bool _DOC_##CLASS::ProcessDOMessage(DuplicatedObject* pDO, Message *pMsg) {		\
		return ((CLASS*)pDO)->ProcessDOMessage(pMsg);}					\
  bool _DOC_##CLASS::ApproveEmigration(DuplicatedObject* pDO, unsigned long ulReason) {			\
		return ((CLASS*)pDO)->ApproveEmigration(ulReason);}						\
  double _DOC_##CLASS::GetWeight(DuplicatedObject* pDO) {			\
		return ((CLASS*)pDO)->GetWeight();}						\
  void _DOC_##CLASS::Trace(DuplicatedObject* pDO, unsigned long ulTraceFlag) {((CLASS*)pDO)->Trace(ulTraceFlag);} \
  void _DOC_##CLASS::InitDO(DuplicatedObject* pDO) {((CLASS*)pDO)->InitDO();}				\
  void _DOC_##CLASS::OperationBegin(DuplicatedObject* pDO, DOOperation* pOperation) {((CLASS*)pDO)->OperationBegin(pOperation);}				\
  void _DOC_##CLASS::OperationEnd(DuplicatedObject* pDO, DOOperation* pOperation) {((CLASS*)pDO)->OperationEnd(pOperation);}				\
  void _DOC_##CLASS::DataSetOperationBegin(DuplicatedObject* pDO, DataSetOperation* pOperation) {((CLASS*)pDO)->DataSetOperationBegin(pOperation);}				\
  void _DOC_##CLASS::DataSetOperationEnd(DuplicatedObject* pDO, DataSetOperation* pOperation) {((CLASS*)pDO)->DataSetOperationEnd(pOperation);}				\
  unsigned long _DOC_##CLASS::MsgSendingCapacity(DuplicatedObject* pDO, unsigned long ulNbStations) {return ((CLASS*)pDO)->MsgSendingCapacity(ulNbStations);}  \
  double _DOC_##CLASS::ComputeDistance(DuplicatedObject* pDO, DuplicatedObject* pLocalDO) {	\
        return ((CLASS*)pDO)->ComputeDistance(pLocalDO);}


#define _DOC_DeclareGeneralMethods(CLASS)					\
   virtual void DataSetsOperation(unsigned long ulOp);				\
   virtual const TCHAR* GetClassNameString() const;				\
   virtual DuplicatedObject* Create();						\
   virtual void Delete(DuplicatedObject* pDO);				\
   _DOC_##CLASS(unsigned long ulClassID=DOCLASSID(CLASS));			\
   virtual bool IsAKindOf(DOClassID idDOCID);				\
   _DOC_DeclareCallback(CLASS)								\
   virtual bool DispatchAction(DuplicatedObject* pDO, MethodID idMethod, Message* pMsg);		\
   virtual bool DispatchRMCCall(LMCContext* pLocalContext);											\
   virtual bool DispatchRMCResult(RMCContext* pContext);											\
   virtual void FillDupSpacesInfo(DuplicationSpace::Role eRole, DupSpaceID* pArray, unsigned int* puiIndex);

#define _DOC_ImplementSomeGeneralMethods(CLASS)							\
	DuplicatedObject* _DOC_##CLASS::Create() {return fnew CLASS();}		\
	void _DOC_##CLASS::Delete(DuplicatedObject* pDO) {fdelete ((CLASS*)pDO);} \
	const TCHAR* _DOC_##CLASS::GetClassNameString() const {return _T(#CLASS);}		\
	_DOC_ImplementCallback(CLASS)


#define _DOC_InitMethod(METHOD) m_mid##METHOD=MethodIDFactory::AssignID(#METHOD);
#define _DOC_DeclareMethod(METHOD) MethodID m_mid##METHOD;

#define _DOC_DispatchAction(ACTION, DOCLASS)	\
   if (idMethod==m_mid##ACTION) {				\
    TRY_SYS_EXCEPTIONS {									\
		((DOCLASS*)pDO)->Callee##ACTION##Stub(pMsg);			\
	}													\
	 CATCH_USER_SYS_EXCEPTIONS(_T("DuplicatedObject"), _T(#ACTION)); \
    return true;\
    }


#define _DOC_DispatchRMCCall(RMC, DOCLASS)											\
	if (pLocalContext->GetTargetMethodID()==m_mid##RMC) {						\
		TRY_SYS_EXCEPTIONS {													\
			((DOCLASS*)pLocalContext->GetTargetObject())->RMC##Wrapper(pLocalContext);		\
		}																		\
		CATCH_USER_SYS_EXCEPTIONS(_T("DuplicatedObject"), _T(#RMC));			\
		return true;															\
	}

#define _DOC_DispatchRMCResult(RMC, DOCLASS)									\
	if (pContext->GetTargetMethodID()==m_mid##RMC) {						    \
			DOCLASS::RMC##ReturnStub(pContext);									\
			return true;														\
	}

#define _DOC_DeclareAction		_DOC_DeclareMethod
#define _DOC_DeclareRMC			_DOC_DeclareMethod
#define _DOC_InitAction			_DOC_InitMethod
#define _DOC_InitRMC			_DOC_InitMethod

#define _DOC_DupSpaceInfo(R,DS)		if ((eRole & DuplicationSpace::R)==DuplicationSpace::R) {						\
										if (pArray) {pArray[*puiIndex]=DUPSPACEID(DS);}		\
										(*puiIndex)++;											\
									}

#define _DOC_LocationSetUpdate(CLASS,SPACE)						\
	if (idDupSpace==DUPSPACEID(SPACE)) {((CLASS*)pDO)->m_ls##SPACE.Update(hStation, bAdd); return;}

#define _DOC_LocationSet(CLASS,SPACE)						\
	if (idDupSpace==DUPSPACEID(SPACE)) {return &(((CLASS*)pDO)->m_ls##SPACE);}


/*
Calls an action...
*/
#define DoAction(NAME,ARG) NAME ARG; NAME##_OnDuplicas ARG;

#endif
