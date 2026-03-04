//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _PHBDRParameters_H_
#define _PHBDRParameters_H_

#include <ObjDup/ObjDupDecl.h>
#include <Platform/Time.h>

// {group: Dead Reckoning}
//Summary: The angle supplied as a parameter to the function is in radians.
//See Also: PHBDRParameters::SetTrackingAngleThreshold, PHBDRParameters::SetConvergenceAngleThreshold, 
//ANGLE_IN_DEGREES
#define ANGLE_IN_RADIANS		1

// {group: Dead Reckoning}
// Summary:  The angle supplied as a parameter to the function is in degrees.
//See Also:   PHBDRParameters::SetTrackingAngleThreshold,  PHBDRParameters::SetConvergenceAngleThreshold, 
//ANGLE_IN_RADIANS
#define ANGLE_IN_DEGREES	2

/* {group: Dead Reckoning}
Summary:  This class holds the parameters used to fine-tune the Position History-Based 
Dead Reckoning algorithm. 
Remarks: This class holds the parameters used to fine-tune the dead reckoning algorithm.  
Do not directly instantiate these but use DataSet::GetPHBDRParameters.
*/
class PHBDRParameters {
	public:
//Group=

		PHBDRParameters();
		~PHBDRParameters();

	public:

		/*
		Summary:  Defines the postdate update delay.  Use this function to delay updates
		sent to duplicas and therefore, create a delayed but more accurate reflection of the 
		Duplication master.
		Parameters:
		tiDelay: Value for the delay in milliseconds.

		Remarks: The postdate update delay is used to change the timestamp on an update 
		message when the message is received, i.e. if t is the initial timestamp on the 
		message, with postdate update the value used would be t+tiDelay.
		*/
		static void PostdateUpdates(TimeInterval tiDelay);

		/*
Summary:  Signals whether or not a convergence algorithm will be used.

Parameters:
bFlag: A Boolean flag that when set to true indicates that a convergence algorithm will
be used. This is the default behaviour of $PRODUCTNAME$. Set this parameter to false if 
you wish to use a tracking algorithm.

Remarks:
A convergence algorithm is used by default.  If a convergence algorithm
is used and an update message is received, the dataset extrapolation
value will smoothly change from the old value to the new one.

The convergence delay is the time required to converge from the old
value to the new value on the predicted path.  $PRODUCTNAME$ uses several
heuristics to compute an adequate convergence time, but the minimum and
maximum delay for the convergence can be defined using the method
SetConvergenceDelay.

If a tracking algorithm is used and an update message is
received, the dataset extrapolation value directly changes from the
previous extrapolated value to the new one.  For example, if the
extrapolated dataset is a position the object will appear to jump from
one position to another.

See also:  SetConvergenceDelay
*/
		void ApplyConvergence(bool bFlag);

/*
Summary: Defines the minimum and maximum values for the convergence delay.

Parameters:

tiMinCPDelay:  Minimum convergence delay in milliseconds.
tiMaxCPDelay:  Maximum convergence delay in milliseconds.

Remarks:

$PRODUCTNAME$ uses several heuristics to compute an adequate convergence time,
but the minimum and maximum value for the convergence can be defined
using the method SetConvergenceDelay. The default values for the convergence 
delay is a minimum of 250 ms and a maximum of 1000 ms. 
 
The convergence delay should be set so that the variable converges to the predicted 
path before the next update is received. If this is not the case the extrapolation 
will appear irregular.

Returns: 
true if the call does not signal an error, false if otherwise.
SYSTEMERROR_GEN_OUT_OF_RANGE is signalled if the values are negative or if the
maximum is less than or equal to the minimum.
*/
		bool SetConvergenceDelay(TimeInterval tiMinCPDelay, TimeInterval tiMaxCPDelay);

		//Summary: Returns the minimum convergence delay in milliseconds.
		//See also: SetConvergenceDelay, GetMaxCP
		TimeInterval GetMinCP() const;
		
		//Summary: Returns the maximum convergence delay in milliseconds.
		//See also: SetConvergenceDelay, GetMinCP
		TimeInterval GetMaxCP() const;
		// {Secret}
		TimeInterval ComputeCP(TimeInterval tiLastInterval) const;

		/*
		Summary:  Sets the amount of time in milliseconds for which local corrections to 
		an extrapolation MODEL using DataSet::SetLocalCorrection will last.
		Remarks: This method sets the local correction expiration delay for an entire class 
		of duplicas at a time.
		
		Parameters:
		tiLocalCorrectionExpirationDelay: The amount of time (as a TimeInterval) for which
		local corrections to a duplica's dataset are applied.
		*/
		void SetLocalCorrectionExpirationDelay(TimeInterval tiLocalCorrectionExpirationDelay);


		friend class PHBDRVar_int;
		friend class PHBDRVar_double;
		friend class PHBDRVar_float;
		friend class PHBDRModel;

		
		bool ApplyConvergence() const;
		// {Secret}
		static void ApplyPostdateDelay(Time* ptTime);

		// {Secret}
		TimeInterval GetLocalCorrectionExpirationDelay() const;

		// {Secret}
		void ForceLinearTracking();
		// {Secret}
		void ForceNonLinearTracking();
		// {Secret}
		void ForceLinearConvergence();
		// {Secret}
		void ForceNonLinearConvergence();

		/* 
		Summary:  Sets the tracking angle threshold that is used to determine if a 
		linear or non-linear prediction algorithm is used. 
		
		Remarks:  The threshold, given in radians or degrees is set for each dataset using this method.  
		If the angle of embrace calculated with the last three dataset values is less than the tracking 
		threshold angle, then a linear tracking algorithm is used. If the angle of embrace is larger, then a 
		non-linear tracking algorithm is used. To ensure coherence between the datasets of objects on different 
		stations, the tracking angle threshold must be set the same on each station across the network.

		Parameters:
		dAngle:  The threshold angle that decides if a linear or non-linear tracking algorithm is used.  If the
		actual angle of embrace is less than this angle, a linear tracking algorithm is used.  If the actual angle
		of embrace is larger than this angle, a non-linear tracking algorithm will be used.
		byAngleUnit:  Specifies if the angle supplied is in radians (ANGLE_IN_RADIANS) or degrees (ANGLE_IN_DEGREES).
		*/
		void SetTrackingAngleThreshold(double dAngle, unsigned char byAngleUnit=ANGLE_IN_RADIANS);
		
		/* 
		Summary:  Sets the convergence angle threshold that is used to determine if a 
		linear or non-linear convergence algorithm is used. 
		
		Remarks:  The threshold, given in radians or degrees, is set for each dataset via this method.
		If the angle of embrace is less than the convergence threshold angle, then a non-linear tracking 
		algorithm is used. If the angle of embrace is larger, then a linear tracking algorithm is used. As the
		convergence algorithm is only implemented on the local station 
		each station across the network may set a different convergence angle threshold.
		
		Parameters:
		dAngle:  The threshold angle that dictates if a linear or non-linear convergence is used.  If the
		actual angle of embrace is less than this angle, a non-linear convergence algorithm is used.  If the actual angle
		of embrace is larger than this angle, a linear convergence algorithm is used.
		byAngleUnit:  Specifies if the angle supplied is in radians (ANGLE_IN_RADIANS) or degrees (ANGLE_IN_DEGREES).
		*/
		void SetConvergenceAngleThreshold(double dAngle, unsigned char byAngleUnit=ANGLE_IN_RADIANS);

	private:

		double m_dTrackingAngleThreshold;
		double m_dConvergenceAngleThreshold;

		TimeInterval m_tiMaxCPDelay;
		TimeInterval m_tiMinCPDelay;
		bool m_bApplyConvergence;
		TimeInterval m_tiLocalCorrectionExpirationDelay;
		
		static TimeInterval s_tiPostdateDelay;
};

#endif

