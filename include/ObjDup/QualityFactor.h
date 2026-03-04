//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _QualityFactor_H_
#define _QualityFactor_H_

#include <ObjDup/ObjDupDecl.h>
#include <Platform/PerfCounter.h>
#include <ObjDup/DOHandle.h>
class EndPoint;


/*
{group: Dead Reckoning}

Description: The quality factor is used by $PRODUCTNAME$ to dynamically adjust the error tolerance 
during runtime.

Remarks: The quality factor is used to dynamically adjust the error tolerance 
during runtime to optimize the appearance of the application on each user's station. 
To use the quality factor function, distance-based dead reckoning must be enabled and
the error tolerance set via the class ErrorToleranceFunction.

When the quality factor is enabled, if the available bandwidth increases, then 
$PRODUCTNAME$ will increase the quality factor, which leads to a decrease in the 
error tolerance. When this occurs the datasets of the duplicas will be refreshed 
more frequently which will improve the appearance of the application. If the available
bandwidth decreases, the inverse will occur.
 
The quality factor set on the local station will affect how accurately the duplicas, which
are on a remote station, of all the duplication masters on the local station are shown. 
The quality factor should be set the same on all connected stations to maintain 
consistency in the accuracy at which objects of the same class are shown on each station.
*/
class QualityFactor {
	//group=
	public:

		//{secret}
		QualityFactor();
		//{secret}
		~QualityFactor();

		//{secret}
		void AssociateEndPoint(EndPoint* pEndPoint, DOHandle hStation);
		//{secret}
		void UnassociateEndPoint();
		
		//{secret}
		static void AdjustAllWhenRequired();

		//{secret}
		void ToggleSlowIncrease(bool bSlow);

		//{secret}
		double GetValue();

		//{secret}
		void Trace(unsigned long ulFlag);
/*
 Description: Sets the range of the quality factor.

 Remarks:
 The quality factor is used to dynamically adjust the error tolerance 
 during runtime to optimize the appearance of the application on each user's station. 
 To use the quality factor function, distance-based dead reckoning must be enabled and
 the error tolerance set via the class ErrorToleranceFunction.

 When the quality factor is enabled, if the available bandwidth increases, then 
 $PRODUCTNAME$ will increase the quality factor, which leads to a decrease in the 
 error tolerance. When this occurs the datasets of the duplicas will be refreshed 
 more frequently which will improve the appearance of the application. If the available
 bandwidth decreases, the inverse will occur.
 
 The range of the quality factor can take any non-zero, positive value. The default range
 is equal to zero as the default values for dMin and dMax are both 1. Therefore, by default 
 $PRODUCTNAME$ does not use the quality factor to adjust the error tolerance.

 When automatically adjusting the quality factor, $PRODUCTNAME$ uses the packet drop probability 
 to determine if a remote station is being flooded and therefore, dropping packets. 
 It is set via the method InputEmulationDevice::SetPacketDropProbability. When the packet drop 
 probability increases above the tolerated level, $PRODUCTNAME$ will decrease the quality factor and 
 therefore, the number of packets being sent to a station, until the ratio decreases below 
 the set value.

 Parameters:
 dMin: The minimum value of the quality factor. This value must be greater than 0. A value
 of 1, which is the default value, has no effect on the error tolerance.
 
 dMax: The maximum value of the quality factor. This value must be greater than 0 and dMin. A
 value of 1, which is the default value, has no effect on the error tolerance.
  
 Returns:  true if the call did not signal an error, false if otherwise. The error 
 SYSTEMERROR_OBJDUP_INVALID_PARAMETER is signalled if dMin is greater than dMax or 
 if either dMin or dMax is less than or equal to 0.

 See Also: Dead Reckoning
*/
		static bool SetRange(double dMin, double dMax);

		//{secret}
		PerfCounter* GetPerfCounter() {return m_pcQualityFactor;}
		
	private:

		//{secret}
		void AdjustValue(double dPercentageChange, int imode);

		//{secret}
		void AdjustValue(double dPercentageChange);

		//{secret}
		void Adjust();

	private:
		//{secret}
		DOHandle m_hStation;

		//{secret}
		double m_dQualityFactor;

		//{secret}
		bool m_bSlowIncrease;

		//{secret}
		EndPoint* m_pAssociatedEndPoint;

		//{secret}
		static double s_dMinimumQualityFactor;
		//{secret}
		static double s_dMaximumQualityFactor;

		//{secret}
		static double s_dAdjustSpeed;

		//{secret}
		static double s_dExpDecreaseCoeff;

		//{secret}
		static double s_dLinIncreaseCoeff;

		//{secret}
		static double s_dlogIncreaseCoeff;

		// {secret}
		static TimeInterval s_tiDelayBetweenAdjustments;

		//{secret}
		static Time s_tLastAdjust;
		
		// TODO... This is a hack.
		// {secret}
		PerfCounter* m_pcQualityFactor;

		enum
		{
            LOGARITHMICALLY = 0,
			LINEARLY,
		    EXPONENTIALLY
		};
};

#endif
