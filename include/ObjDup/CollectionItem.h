
#ifndef _CollectionItem_H_
#define _CollectionItem_H_

#include <ObjDup/ObjDupDecl.h>

#include <Platform/SystemCheck.h>

class CollectionItem {
	// Group=
	public:
		CollectionItem();
		~CollectionItem();

		typedef enum _Flag {
			MainReferenceDeleted=1<<0,
			ValidConstruction=1<<1,
			OrphanDuplica=1<<2,
		} Flag;

		unsigned int GetRefCount() const;
		void IncreaseRefCount();
		void DecreaseRefCount();

		void SetFlag(unsigned short usFlag);
		void ClearFlag(unsigned short usFlag);
		bool FlagIsSet(unsigned short usFlag) const;

	private:
		unsigned short m_usRefCount;
		unsigned short m_usFlags;
};

#endif
