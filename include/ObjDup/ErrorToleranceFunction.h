//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _ErrorToleranceFunction_H_
#define _ErrorToleranceFunction_H_

#include <ObjDup/ObjDupDecl.h>
class QualityFactor;

// Group = Dead Reckoning

/* 
 Description:  This value is used to represent the distance between two objects
 when the distance is unknown or undefined.  
 
 Remarks: This value will be used if, for distance-based dead reckoning, the 
 observer or how to calculate the distance between the observer and an object
 is not defined.

See Also:  Dead Reckoning Overview, DuplicatedObject::ComputeDistance, DataSet, Station::RegisterObserver
*/
#define UNKNOWN_DISTANCE		-1.0

#define DEFAULT_PARAMETER		-1.0

/*
 Description: This value is used in the ErrorToleranceFunction::SetParameters
 method to indicate that the error tolerance has no maximum value.

 See Also: ErrorToleranceFunction::SetParameters
*/
#define UNLIMITED_ERROR			-1.0


/*
{group: Dead Reckoning}

 Description:  This function is used to compute the maximum extrapolation error tolerated 
 before the datasets of a Duplica will be updated.

 Remarks: The error tolerance function is used to calculate the maximum extrapolation 
 error tolerated before the datasets of a Duplica will be updated.

 The extrapolation error is defined as the difference between the current
 dataset values of an object, i.e. that of the Duplication master, and the
 extrapolated dataset values of the object, i.e. that of a Duplica. The
 error tolerance may be constant or a function of the distance between 
 the observer and an object, depending on the parameters chosen. The observer 
 is set via the method Station::RegisterObserver. For 
 example, the error tolerance function can be set such that a larger
 error is tolerated for objects displayed a long distance from the 
 observer, i.e. those objects in the background of a scene, and a small
 error is tolerated for those objects closer to the observer, i.e. 
 those in the foreground. When this is the case, extrapolation of the datasets 
 is more precise and therefore, a greater portion of the bandwidth is used for
 objects that are close to the observer. For objects that appear further away from 
 the observer, extrapolation of the datasets is less precise and proportionally 
 less bandwidth is used. $PRODUCTNAME$ does not impose a definition of close or far. It is 
 up to you to implement the method DuplicatedObject::ComputeDistance, which calculates 
 the distance between two duplicated objects.
*/
class ErrorToleranceFunction {
	//group=
	public:

		ErrorToleranceFunction();
		~ErrorToleranceFunction();

		/*
Summary: Defines the parameters of the error tolerance function.

Parameters:

dConstantFactor: Constant factor in the error tolerance function, which is
also equal to the minimum value of the error tolerance.

dLinearFactor: Linear factor in the error tolerance function.

dQuadraticFactor: Quadratic factor in the error tolerance function.

dMaximumError: Maximum value of the error tolerance. This optional 
parameter has a default value of UNLIMITED_ERROR.

Remarks:
The error tolerance function is used by $PRODUCTNAME$ to determine if the
extrapolation error on a dataset is acceptable or not. If the
extrapolation error exceeds the error tolerance the dataset of a Duplica
will be updated from the Duplication master.

The error tolerance may be constant or a function of the distance between
the object and a user-defined observer, which means that the tolerated
error will change according to the location of an object.

The parameters of the error tolerance function are used to compute the
error tolerance using a formula that corresponds to the following
pseudo code:

		double dError=dConstantFactor +
					  dLinearFactor * dDistance +
					  dQuadraticFactor * dDistance * dDistance;
		if (dMaximumError!= UNLIMITED_ERROR && dError>dMaximumError) {
			return dMaximumError;
		} else {
			return dError;
		}


The parameters of the error tolerance function are game
specific. Their selection involves a trade-off between bandwidth used
and precision of the dataset variables extrapolation. A higher error
tolerance leads to lower bandwidth usage.

$PRODUCTNAME$ defines the following defaults:
dConstantFactor=dLinearFactor=dQuadraticFactor=0 and
dMaximumError=UNLIMITED_ERROR.

See Also: DDL File Syntax, SetConstantError, SetLinearError,
SetQuadraticError
*/
		void SetParameters(double dConstantFactor,
						   double dLinearFactor,
						   double dQuadraticFactor,
						   double dMaximumError=UNLIMITED_ERROR);
		
		/*
		Summary: Sets the default distance used to calculate the error tolerance.
		Remarks: This distance is used if the distance between two duplicated objects is unknown 
		(UNKNOWN_DISTANCE) or if the observer on the station being updated has not been defined.
		The initial value for the default distance is 0.
		See also: ValueAt, UNKNOWN_DISTANCE, UNLIMITED_ERROR, DuplicatedObject::ComputeDistance,
		Dead Reckoning, Dead Reckoning Overview, DataSet
		*/
		void SetDefaultDistance(double dDefaultDistance);

		/*
		Summary: Defines a constant error tolerance.
		Parameters:
		dError: The constant tolerated error.

		Remarks:  This methods calls SetParameters and is equivalent to the call
		SetParameters(dError, 0, 0)  
		See Also: SetParameters, SetLinearError, SetQuadraticError, Dead Reckoning Overview, 
		Dead Reckoning
		*/
		void SetConstantError(double dError);
	
/*
Summary:  Defines a linear relationship between the error tolerance and the distance 
between the observer and object.

Parameters: 
dMinimumValue: The minimum tolerated error.
dMaximumValue: The maximum tolerated error.
dDistance: The total distance over which the tolerated error is to vary linearly.  
 
Remarks:  
These three parameters determine the minimum and maximum tolerated error as well as 
the slope of the linear relation between the error tolerance and the distance. The slope is
equal to (dMaximumValue- dMinimumValue)/dDistance.

This methods calls SetParameters and is equivalent to the call 
SetParameters(dMinimumValue, (dMaximumValue- dMinimumValue)/dDistance, 0, dMaximumValue)
 
Returns:
true if the call does not signal an error, false if otherwise.
The error SYSTEMERROR_OBJDUP_INVALID_PARAMETER is signalled if dDistance is less than or equal to 0
or if dMaximumValue is less than dMinimumValue.

See Also:  SetParameters, SetConstantError, SetQuadraticError, DuplicatedObject::ComputeDistance, 
Dead Reckoning, Dead Reckoning Overview.
*/
		bool SetLinearError(double dMinimumValue, double dMaximumValue, double dDistance);

/*
Summary:  Defines a quadratic relationship between the error tolerance and the distance
between the observer and object.

Parameters: 
dMinimumValue: The minimum tolerated error.
dMaximumValue: The maximum tolerated error.
dDistance: The total distance over which the tolerated error is to vary in a quadratic manner.  
 
Remarks:  
These three parameters determine the minimum and maximum tolerated error, as well as 
the quadratic equation of the relation between the error tolerance and the distance.  
The quadratic coefficient is equal to (dMaximumValue- dMinimumValue)/(dDistance*dDistance).

This methods calls SetParameters and is equivalent to the call 
SetParameters(dMinimumValue, 0, (dMaximumValue- dMinimumValue)/(dDistance*dDistance), dMaximumValue)
 
Returns:
true if the call does not signal an error, false if otherwise.
The error SYSTEMERROR_OBJDUP_INVALID_PARAMETER is signalled if dDistance is less than or equal to 0
or if dMaximumValue is less than dMinimumValue.

See Also: SetParameters, SetConstantError, SetLinearError, 
DuplicatedObject::ComputeDistance, Dead Reckoning, Dead Reckoning Overview.
*/
		bool SetQuadraticError(double dMinimumValue, double dMaximumValue, double dDistance);

		/*
		Summary: Returns the error tolerance at a given distance. 
		Parameters: 
		dDistance: Is the distance at which this method will return the error tolerance. 

		Remarks: This method is called internally by $PRODUCTNAME$ to determine if an update
		is required. If the value UNKNOWN_DISTANCE is passed the default distance is used.
		See also: SetDefaultDistance
		*/
		double ValueAt(double dDistance) const;
		// {Secret}
		double SquaredValueAt(double dDistance, QualityFactor* pQuality=NULL) const;

		// {Secret}
		bool DistanceMatters();

#ifdef _TEST_ENABLED
	public:
		// {Secret}
		static bool Test();		
#endif
	private:
		double m_pdParameters[5];
		double m_dDefaultDistance;
		int m_iLastParameterIndex;
		double m_dMaximumQuadraticError;
};

#endif
