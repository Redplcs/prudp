//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  

#ifndef _CONTAINEROPERATION_H_
#define _CONTAINEROPERATION_H_

#include <ObjDup/ObjDupDecl.h>

static char* g_pcOpNames[] = {		"NOP_OPCODE",
									"PUSH_OPCODE",
									"POP_OPCODE",
									"EMPTY_OPCODE",
									"BACK_OPCODE",
									"FRONT_OPCODE",
									"SIZE_OPCODE",
									"PUSH_FRONT_OPCODE",
									"PUSH_BACK_OPCODE",
									"POP_FRONT_OPCODE",
									"POP_BACK_OPCODE",
									"INSERT_PX_OPCODE",
									"INSERT_PNX_OPCODE",
									"INSERT_PFL_OPCODE",
									"ERASE_OPCODE",
									"CLEAR_OPCODE",
									"ASSIGN_OPCODE",
									"BRACKET_OPCODE"};


template<class Type>
class ContainerOperation {
public:

	//For "elementless" operations
	ContainerOperation()
	{
		m_bOpCode = NOP_OPCODE;
		m_uiPos = 0;
		m_tElem = 0;
		m_uiRepeat = 0;
	}

	ContainerOperation(unsigned char bCode)
	{
		m_bOpCode = bCode;
		m_uiPos = 0;
		m_tElem = (Type)0;
		m_uiRepeat = 1;
	}

	//Push etc.
	ContainerOperation(unsigned char bCode, Type tElem)
	{
		m_bOpCode = bCode;
		m_uiPos = 0;
		m_uiRepeat = 1;
		m_tElem = tElem;
	}

	ContainerOperation(unsigned char bCode, unsigned long ulPos, Type tElem)
	{
		m_bOpCode = bCode;
		m_uiPos = ulPos;
		m_uiRepeat = 1;
		m_tElem = tElem;
	}

	ContainerOperation(unsigned char bCode, unsigned long ulPos, unsigned long ulRepeat, Type tElem)
	{
		m_bOpCode = bCode;
		m_uiPos = ulPos;
		m_uiRepeat = ulRepeat;
		m_tElem = tElem;
	}

	ContainerOperation(const ContainerOperation& coOp) {
		m_bOpCode = coOp.m_bOpCode;
		m_uiPos = coOp.m_uiPos;
		m_tElem = coOp.m_tElem;
		m_uiRepeat = coOp.m_uiRepeat;
	}

	~ContainerOperation() {}

	unsigned char GetOpCode() {return m_bOpCode;}
	unsigned long GetRepeat() {return m_uiRepeat;}
	unsigned long GetPos() {return m_uiPos;}

	void AddSourceTo(Message *pMsg) {
		*pMsg << m_bOpCode;
		*pMsg << m_uiPos;
		*pMsg << m_tElem;
		*pMsg << m_uiRepeat;
	}

	void ExtractFrom(Message *pMsg) {
		*pMsg >> m_bOpCode;
		*pMsg >> m_uiPos;
		*pMsg >> m_tElem;
		*pMsg >> m_uiRepeat;
	}	

	void Trace(TCHAR* szFormat, unsigned long ulTraceFlag) {
		TCHAR szEntireFormat[128];
		_stprintf(szEntireFormat,_T("%%S : Pos:%%d, Repeat:%%d, Data: %s"), szFormat);
		TRACE(ulTraceFlag, szEntireFormat, g_pcOpNames[m_bOpCode], m_uiPos, m_uiRepeat, m_tElem);
	}

	Type GetData() {return m_tElem;}
	ContainerOperation<Type>* GetPtr() {return this;}



	enum s_OpCodesList {
		/* queue operations */
		NOP_OPCODE=0,
		PUSH_OPCODE,
		POP_OPCODE,
		EMPTY_OPCODE,
		BACK_OPCODE,
		FRONT_OPCODE,
		SIZE_OPCODE, 
		/* list operations */
		PUSH_FRONT_OPCODE,
		PUSH_BACK_OPCODE,
		POP_FRONT_OPCODE,
		POP_BACK_OPCODE,
		INSERT_PX_OPCODE,
		INSERT_PNX_OPCODE,
		INSERT_PFL_OPCODE,
		ERASE_OPCODE,
		CLEAR_OPCODE,
		ASSIGN_OPCODE,
		/* vector-specific operations */
		BRACKET_OPCODE
	};


private:
	unsigned char	m_bOpCode;
	unsigned int	m_uiPos;
	Type m_tElem;
	unsigned int	m_uiRepeat;
};

#endif//_CONTAINEROPERATION_H_
