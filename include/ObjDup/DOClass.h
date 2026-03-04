//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  



#ifndef _DOClass_H_
#define _DOClass_H_

#include <ObjDup/ObjDupDecl.h>
#include <ObjDup/DOSBP.h>
#include <ObjDup/DOClassID.h>
#include <ObjDup/MethodID.h>
//#include <ObjDup/DOClass.h>
#include <ObjDup/DuplicationSpace.h>
#include <ObjDup/DuplicationSpaceTable.h>
class RMCContext;
class LMCContext;
class DuplicatedObject;
class Message;
class DOOperation;
class DataSet;
class DataSetOperation;

// {Secret}
// This method will be defined in code generated from the classes definition.
void InitDOClasses();

// {Secret}
// This method will be defined in code generated from the DOCore classes definition.
void InitDOCoreClasses();

class MultipleIteratorsIterator;

// {Secret}
class DOClass {
	public:

		DOClass(unsigned long ulClassID);
		virtual ~DOClass();

		// The following methods are called after construction and
		// before destruction, but when the virtual table is set up
		// correctly.
		void CompleteInitialisation(); 
		void PrepareToLeave();  

		virtual void DataSetsOperation(unsigned long ulOp);

		virtual DuplicatedObject* Create()=0;
		virtual void Delete(DuplicatedObject* pDO)=0;

		int GetNbDupSpaces(DuplicationSpace::Role eRole);
		DOClassID GetID() { return m_ulClassID; }
		int FillDupSpacesArray(DuplicationSpace::Role eRole, 
										DupSpaceID* pArray);
		// Callbacks...
		virtual bool ApproveFaultRecovery(DuplicatedObject* pDO)=0;
		virtual bool ApproveEmigration(DuplicatedObject* pDO, unsigned long ulReason)=0;
		virtual double GetWeight(DuplicatedObject* pDO)=0;
		virtual void Trace(DuplicatedObject* pDO, unsigned long ulTraceFlag)=0;
		virtual bool ProcessDOMessage(DuplicatedObject* pDO, Message *pMsg)=0;
		virtual void InitDO(DuplicatedObject* pDO)=0;
		virtual double ComputeDistance(DuplicatedObject* pDO, DuplicatedObject* pLocalDO)=0;
		virtual void OperationBegin(DuplicatedObject* pDO, DOOperation* pOperation)=0;
		virtual void OperationEnd(DuplicatedObject* pDO, DOOperation* pOperation)=0;
		virtual void DataSetOperationBegin(DuplicatedObject* pDO, DataSetOperation* pOperation)=0;
		virtual void DataSetOperationEnd(DuplicatedObject* pDO, DataSetOperation* pOperation)=0;
		virtual unsigned long MsgSendingCapacity(DuplicatedObject* pDO, unsigned long ulNbStations)=0;

		virtual void SpecificAddDSToDiscoveryMessage(DuplicatedObject* pDO, Message* pMsg)=0;
		virtual void SpecificExtractDSFromDiscoveryMessage(DuplicatedObject* pDO, Message* pMsg)=0;
		virtual bool SpecificExtractADataset(DuplicatedObject* pDO, Message* pMsg, unsigned char byDatasetIndex)=0;
		virtual bool SpecificUpdate(DuplicatedObject* pDO, DataSet *pDataset = NULL)=0;
		virtual bool SpecificRefresh(DuplicatedObject* pDO, DataSet *pDataset = NULL)=0;

		virtual bool IsAKindOf(DOClassID idDOCID) {
			if (DuplicatedObject_ClassID == idDOCID) {
				return true;
			} else {
				return false;
			}
		}

		virtual unsigned long GenerateObjectID();
		virtual void InitializeIDGenerationCapabilities();
		virtual void ClearInitialIDRange();
		virtual bool CreateIDFactory();

		virtual const TCHAR* GetClassNameString() const=0;

		// Actions...
		virtual bool DispatchAction(DuplicatedObject* pDO, MethodID idMethod, Message* pMsg) {
			return false;
		}

		// RMCs...
		virtual bool DispatchRMCCall(LMCContext* pLocalContext) {
			return false;
		}
		virtual bool DispatchRMCResult(RMCContext* pContext) {
			return false;
		}

		virtual bool ValidCastTowards(unsigned long ulClassID) {
			// If we get here, it is now a valid cast.
			return false;
		}

		static DOClass* FindDOClass(unsigned long ulClassID);

		bool SetFirstFreeID(unsigned long ulFirst);

	protected:
		virtual void FillDupSpacesInfo(DuplicationSpace::Role eRole, 
									   DupSpaceID* pArray, unsigned int *puiIndex);
		DOHandle m_hIDFactory;
		unsigned long m_ulInitialIDRangeFirst;
		unsigned long m_ulInitialIDRangeLast;
	private:
		unsigned long m_ulClassID;
		
};

// Group = Miscellaneous Types and Macros

/*
Summary: Returns the DOClassID associated to a DOClass. For example, 
DOCLASSID($AvatarORInformationObject$) returns the DOClassID for the DOClass 
$AvatarORInformationObject$.
*/
#define DOCLASSID(DO)	DO##_ClassID

#endif
