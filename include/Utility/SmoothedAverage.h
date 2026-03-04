//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _SmoothedAverage_H
#define _SmoothedAverage_H_

#include <Utility/UtilityDecl.h>

template <class Type> class SmoothedAverage {
	public:
		SmoothedAverage(double dNewWeight = 0.1)
		{
			InitData();
			m_dWeight = dNewWeight;
			m_ulMinEntriesForAverage = (unsigned long)(1.0/dNewWeight);
		}


		~SmoothedAverage()
		{
		}


		void InitData()
		{
			m_dAverage = 0.0;
			m_dMin = 0.0;
			m_dMax = 0.0;
			m_ulEntriesTotalNumber = 0;
		}


		void Add(Type tyNewValue, double dWeight)
		{
			m_dAverage = tyNewValue * dWeight + 
						 m_dAverage * (1 - dWeight);

			if((tyNewValue < m_dMin) || (m_ulEntriesTotalNumber == 1)) {
				m_dMin = tyNewValue;
			}
			if((tyNewValue > m_dMax)  || (m_ulEntriesTotalNumber == 1)){
				m_dMax = tyNewValue;
			}
		}

		Type Add(Type tyNewValue)
		{
			m_ulEntriesTotalNumber++;

			// If we don't have enough entries, we give to the new entry a weight that depends on 
			// the actual entries number

			if(m_ulEntriesTotalNumber < m_ulMinEntriesForAverage) {
				Add(tyNewValue, 1.0/m_ulEntriesTotalNumber);
			}
			// Else, we use the weight
			else {
				Add(tyNewValue, m_dWeight);
			}
			return (Type)m_dAverage;
		}

		void SetWeight(double dNewWeight) 
		{
			m_dWeight = dNewWeight;
			m_ulMinEntriesForAverage = (unsigned long)(1.0/dNewWeight);
		}
		

		Type GetAverage()
		{
			return (Type)m_dAverage;
		}


		unsigned long GetNbEntries() 
		{
			return m_ulEntriesTotalNumber;
			
		}
		
		
		Type GetMin()
		{
			return (Type)m_dMin;
		}
		
		
		Type GetMax()
		{
			return (Type)m_dMax;
		}

		void Reset()
		{
			InitData();
			m_dWeight = 0.1;
			m_ulMinEntriesForAverage = (unsigned long)(1.0/m_dWeight);
		}
		

	private:
		double m_dAverage;
		double m_dMin;
		double m_dMax;

		double m_dWeight;
		unsigned long  m_ulMinEntriesForAverage;
		unsigned long  m_ulEntriesTotalNumber;

};


#ifdef _TEST_ENABLED
		bool SmoothedAverageTest();
#endif

#endif

