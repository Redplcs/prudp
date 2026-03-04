//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _DataSetOperation_H_
#define _DataSetOperation_H_

#include <ObjDup/ObjDupDecl.h>
#include <ObjDup/Operation.h>
#include <ObjDup/DuplicatedObject.h>

class DataSet;
//Group = System Operations
/*
Description: A DataSetOperation is an operation performed on a specific dataset. 
Remarks: The two types of DataSetOperations are BufferRefresh and Refresh.
*/
class DataSetOperation: public Operation {
//Group=Operations
	public:
		//{secret}
		DataSetOperation(DataSet* pDataSet, DuplicatedObject *pDO) {
			m_pDataSet=pDataSet;
            m_pDO = pDO;

            if(m_pDO != NULL) {
                m_pDO->CallDataSetOperationBegin(this);
            }
		}
		//{secret}
		virtual ~DataSetOperation() {
            if(m_pDO != NULL) {
                m_pDO->CallDataSetOperationEnd(this);
            }
        }
		
		/*
		Description: Use this method to get a pointer to the DataSet instance that is 
		associated with this operation.
		Returns: A DataSet pointer to the instance that is associated with the operation.
		See Also: DataSet, DuplicatedObject
		*/
		DataSet* GetAssociatedDataSet() {return m_pDataSet;}

		/*
		Description: Use this method to get a pointer to the DuplicatedObject instance that is 
		associated with this operation.
		Returns: A DuplicatedObject pointer to the instance that is associated with the operation.
		See Also: DataSet, DuplicatedObject
		*/
        DuplicatedObject* GetAssociatedDO() {return m_pDO;}

	protected:
		DataSet          *m_pDataSet;
        DuplicatedObject *m_pDO;
};

#endif
