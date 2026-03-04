//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _DataSetFlag_H_
#define _DataSetFlag_H_

class DataSetFlag {
	//group=
	public:
		DataSetFlag() {m_bFlag=false;}
		~DataSetFlag() {};

		bool GetFlag() {return m_bFlag;}
		void SetFlag() {m_bFlag=true;}
		void ResetFlag() {m_bFlag=false;}

	private:
		bool m_bFlag;
};

#endif
