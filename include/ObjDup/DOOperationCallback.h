


#ifndef _DOOperationCallback_H_
#define _DOOperationCallback_H_

#include <ObjDup/ObjDupDecl.h>
#include <Utility/Callback.h>
#include <ObjDup/AddToStoreOperation.h>
#include <ObjDup/RemoveFromStoreOperation.h>
#include <ObjDup/FaultRecoveryOperation.h>
#include <ObjDup/MasterIDChangeOperation.h>
#include <ObjDup/RoleChangeOperation.h>

// Group=Utility Subsystem
template<class TargetClass> class DOOperationCallback : public Callback<TargetClass, DOOperation*>
{
	// Group=
	public:
		DOOperationCallback(TargetClass* pTargetObject,
				            void (TargetClass::*pMethod)(DOOperation* pOperation),
                            Operation::Type  operationType,
                            Operation::Event operationEvent,
                            DOFilter *pFilter,
                            long lPriority = 0) : Callback<TargetClass, DOOperation*>(pTargetObject, pMethod, lPriority)
        {

			m_pTargetObject=pTargetObject;
			m_pMethod=pMethod;
            m_pFilter = pFilter;

            m_operationType  = operationType;
            m_operationEvent = operationEvent;

            switch(m_operationType)
            {
            case Operation::AddToStore :
                AddToStoreOperation::RegisterCallback(this, GetEvent());
                break;
            case Operation::RemoveFromStore:
                RemoveFromStoreOperation::RegisterCallback(this, GetEvent());
                break;
            case Operation::RoleChange:
                RoleChangeOperation::RegisterCallback(this, GetEvent());
                break;
            case Operation::MasterIDChange:
                MasterIDChangeOperation::RegisterCallback(this, GetEvent());
                break;
            case Operation::FaultRecovery:
                FaultRecoveryOperation::RegisterCallback(this, GetEvent());
                break;
            }
        }

		virtual ~DOOperationCallback() {

            if(m_pFilter)
                fdelete m_pFilter;

            switch(m_operationType)
            {
            case Operation::AddToStore :
                AddToStoreOperation::UnregisterCallback(this, GetEvent());
                break;
            case Operation::RemoveFromStore:
                RemoveFromStoreOperation::UnregisterCallback(this, GetEvent());
                break;
            case Operation::RoleChange:
                RoleChangeOperation::UnregisterCallback(this, GetEvent());
                break;
            case Operation::MasterIDChange:
                MasterIDChangeOperation::UnregisterCallback(this, GetEvent());
                break;
            case Operation::FaultRecovery:
                FaultRecoveryOperation::UnregisterCallback(this, GetEvent());
                break;
            }
		}

        virtual void Call()
        {
            DOOperation *pOperation = GetCallbackArgument();
            if(pOperation != NULL)
            {
                DuplicatedObject *pDO = pOperation->GetAssociatedDO();
                if(pDO != NULL)
                {
                    if(m_pFilter->Filter(pDO))
                        Callback<TargetClass, DOOperation*>::Call();                        
                }
            }
        }

        Operation::Type GetType() { return m_operationType; }    
        
        Operation::Event GetEvent() { return m_operationEvent; }    

	private:

	private:
		TargetClass* m_pTargetObject;
		void (TargetClass::*m_pMethod)(DOOperation* pOperation);

        Operation::Type  m_operationType;
        Operation::Event m_operationEvent;
        DOFilter *m_pFilter;

		//friend bool CallbackTest();
};

#ifdef _TEST_ENABLED
//bool CallbackTest();
#endif

#endif
