//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  

#ifndef _ItemRegister_H_
#define _ItemRegister_H_

#include <Utility/UtilityDecl.h>

#include <Platform/CriticalSection.h>
#include <map>

template<class Item> class ItemRegister {
	public:
		ItemRegister() {};
		~ItemRegister() {
			// The derived class is responsible to Clear itself upon
			// destruction.  The method clears calls virtual methods -
			// if we call it here, then the default method would end up
			// beeing called.
			SYSTEMCHECK(m_mapItems.size()==0);
		};

		void Clear() {
			ScopedCS oCS(m_csMap);
			std::map<Item::ID, Item*>::iterator it;
			while (m_mapItems.size()!=0) {
				it=m_mapItems.begin();
				Unregister(it->second);
			}
		}

		// Access to static variables.
		CriticalSection& MapCSRef() {return m_csMap;}

		// We register the item.  We assume the Item has a correct ID
		// at this point.  A particular Register could do a little bit more.
		virtual void Register(Item* pItem) {
			ScopedCS oCS(m_csMap);
			SYSTEMCHECK(Find(pItem->GetID())==NULL);
			m_mapItems[pItem->GetID()]=pItem;
			SYSTEMCHECK(Find(pItem->GetID())!=NULL);
			SYSTEMCHECK(Find(pItem->GetID())->GetID()==pItem->GetID());
		}

		// We unregister the item.  We assume the Item has a correct ID
		// at this point.  A particular Register could do a little bit more.
		virtual void Unregister(Item* pItem) {
			ScopedCS oCS(m_csMap);	

			std::map<Item::ID, Item*>::iterator it=m_mapItems.find(pItem->GetID());
			SYSTEMCHECK(it!=m_mapItems.end());	
			m_mapItems.erase(it);
			SYSTEMCHECK(Find(pItem->GetID())==NULL);
		}
		
		// Access to this method must be protected via the MapCSRef.
		Item* Find(const typename Item::ID idItemToFind) {
			std::map<Item::ID, Item*>::iterator it=m_mapItems.find(idItemToFind);
			if (it!=m_mapItems.end()) {
				SYSTEMCHECK(it->second->GetID()==idItemToFind);
				return it->second;
			} else {
				return NULL;
			}
		}

		void Trace(unsigned long ulTraceFlags=TRACE_ALWAYS) {
			std::map<Item::ID, Item*>::iterator it=m_mapItems.begin();			
			while (it!=m_mapItems.end()) {
				it->Trace(ulTraceFlags);
				it++;
			}			
		}

	protected:
		// With appropriate locking, the map can be access directly by subclasses.  
		std::map<typename Item::ID, Item*> m_mapItems;
		typedef std::map<typename Item::ID, Item*>::iterator iterator;
	private:
		CriticalSection m_csMap;
};

#endif
