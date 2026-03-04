

#ifndef _CallbackList_H_
#define _CallbackList_H_

#include <Utility/UtilityDecl.h>
#include <Utility/CallbackRoot.h>
#include <Platform/ScopedCS.h>
#include <list>

// List of CallbackRoot element. The list is sorted by priority order.

template<class ArgumentType> class CallbackList {
	public:
        CallbackList() {}
        virtual ~CallbackList() {}

        CallbackList(const CallbackList& oCallbackList) {
            ScopedCS oCS(m_csList);
            std::list<CallbackRoot<ArgumentType> *>::iterator it;
            it = oCallbackList.GetList()->begin();
    
            // Clear the current list to be sure that there is no element
            m_oList.clear();

            while(it != oCallbackList.GetList()->end())
            {
                Add(*it);
                it++;
            }              
        }

        // Add an element to the list, ordered by priority
        void Add(CallbackRoot<ArgumentType> *pCallback) {
            ScopedCS oCS(m_csList);
            std::list<CallbackRoot<ArgumentType> *>::iterator it;
            it = m_oList.begin();

            while(it != m_oList.end() && pCallback->GetPriority() > (*it)->GetPriority())
            {
                it++;
            }

            if(it == m_oList.end())
                m_oList.push_back(pCallback);
            else
                m_oList.insert(it, pCallback);
        }

        // Remove an element from the list.
        void Remove(CallbackRoot<ArgumentType> *pCallback) {
            ScopedCS oCS(m_csList);
            m_oList.remove(pCallback);
        }

        // This method calls Call() method for all element 
        // in the list.
        void Call(ArgumentType arg) {
            ScopedCS oCS(m_csList);
            std::list<CallbackRoot<ArgumentType> *>::iterator it;
            it = m_oList.begin();

            while(it != m_oList.end())
            {
                (*it)->SetCallbackArgument(arg);
                (*it)->Call();
                it++;
            }                 
        }

        std::list<CallbackRoot<ArgumentType> *>* GetList() const {
            return (std::list<CallbackRoot<ArgumentType> *>*) &m_oList;
        }

        CallbackList<ArgumentType>& operator=(const CallbackList<ArgumentType> &oCallbackList)
        {
            ScopedCS oCS(m_csList);
            std::list<CallbackRoot<ArgumentType> *>::iterator it;
            it = oCallbackList.GetList()->begin();
    
            // Clear the current list to be sure that there is no element
            m_oList.clear();

            while(it != oCallbackList.GetList()->end())
            {
                Add(*it);
                it++;
            }              
            return *this;
        }

		
	private:

        std::list<CallbackRoot<ArgumentType> *> m_oList;
        CriticalSection m_csList;
};

#ifdef _TEST_ENABLED
bool CallbackListTest();
#endif


#endif
