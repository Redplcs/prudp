//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _DataSet_H_
#define _DataSet_H_

#include <ObjDup/ObjDupDecl.h>
#include <Utility/PseudoSingleton.h>
#include <Utility/PseudoGlobalVariable.h>
#include <ObjDup/OperationLock.h>
#include <Platform/Time.h>

class Counter;
class DataSetOperation;
class DuplicatedObject;
class DataSetPerfCounters;
class ErrorToleranceFunction;

// Group=Miscellaneous Types and Macros

/*
Summary: Indicates that there are no maximum update delays.
See Also: DataSet::SetMaximumUpdateDelay, DataSet::GetMaximumUpdateDelay, DEFAULT_MAXIMUM_UPDATE_DELAY
*/
#define NO_MAXIMUM_UPDATE_DELAY 0

/*
Summary: Defines the default value for the maximum update delay.
Remarks: The maximum update delay is the maximum time allowed between the sending of updates 
of a dataset to remote stations. The default value is 2000 ms.
See Also: DataSet::SetMaximumUpdateDelay, DataSet::GetMaximumUpdateDelay, NO_MAXIMUM_UPDATE_DELAY
*/
#define DEFAULT_MAXIMUM_UPDATE_DELAY 2000

//group=DDL Output

/*
description:
Use this macro to generate the name of the base class from
which your own dataset implementation inherits.

For example, lets say a dataset is declared in a DDL file as follows :

      dataset Position {
          float x;
          float y;
          float z;
      };

Then the user-defined /Position/ class is declared as follows :

      class Position : public  DATASET(Position) {
          void Set( float x, float y, float z );
      };

Note that the /Set/ method is part of the user implementation.
*/
#define DATASET(C) _DS_##C

// Group = Dead Reckoning

/*
Summary:  Use this macro to access a dataset extrapolation variable.

Parameters:
	DATASET: A reference to the dataset containing the variable.
	VAR: The variable itself.  

Remarks: For example, if we declare the following in the DDL:

		dataset Position {
			float x;
			float y;
			float z;
		}extrapolation_filter, unreliable;

		dataset Posture {
			double v[3];
		}extrapolation_filter, unreliable;

		doclass $AvatarORInformationObject$ {
			Position m_Pos;
			Posture m_Posture;
		};

Then an object of the class $AvatarORInformationObject$ may use the extrapolation
variables to predict its Position or its Posture 100ms in the future using the following:

		double $AvatarORInformationObject$::PredictX(TimeInterval tiInterval) {
			return m_Pos.PredictValue(MODEL(m_Pos, x),GetTimestamp()+tiInterval);		
		}

		void $AvatarORInformationObject$::PredictPosture(double dv0, double dv1, double dv2) {
			// Predicts the posture in 1 second.
			dv0=m_Posture.PredictValue(MODEL(m_Posture,v[0]),GetTimestamp()+100);
			dv1=m_Posture.PredictValue(MODEL(m_Posture,v[1]),GetTimestamp()+100);
			dv2=m_Posture.PredictValue(MODEL(m_Posture,v[2]),GetTimestamp()+100);
		}

Returns:
This macro is only valid for extrapolated datasets. The error SYSTEMERROR_GEN_INVALID_OPERATION is signalled 
if the macro is call on a dataset that is not extrapolated.
See also: DataSet::SetModel, DataSet::PredictValue, DataSet::PredictRateOfChange,
DataSet::PredictAcceleration
*/
#define MODEL(DATASET, VAR)	(DATASET).GetPHBDRModel()->VAR


// Group=DDL Output

/*
Description: The DataSet class describes data for a duplicated object that must be propagated to
all the stations that belong to the session.
Remarks: A DataSet groups several dataset variables. All of these variables share
an update policy.  This class is at the root of the $gameORapp$ specific
DataSet class hierarchy, generated according to the DDL. 
When the method Update is called on a Duplication master, the data contained in 
all of the datasets of its duplicas will be updated, according to the
update policy specified in the DDL.
See also: DDL File Syntax, Class Generation
*/
class DataSet {
	//group=
	public:
	
		/*
		Summary: Instantiates a dataset. 
		Remarks: Datasets should never be directly instantiated. They are accessible
		as data members of duplicated objects.
		See Also: DuplicatedObject.
		*/
		DataSet();
		
		/*
		Summary: Destroys the dataset. 
		Remarks: Datasets should never be directly destroyed. When the duplicated object 
		to which they are associated to is destroyed, the dataset is automatically destroyed.
		See Also: DuplicatedObject
		*/
		~DataSet();

		/*
		{Group:System Callbacks}

		Summary: This method is called by the system to decide if an update
		should be sent or not.
		Returns: This callback is used to implement a custom_update_filter.  If this
		callback returns true, this dataset will be updated on all the
		duplicas, otherwise, no update takes place.  The SYSTEMERROR_MISSING_DATASET_CALLBACK
		can be signalled by the call.

Note: This method is obsolete, see System Operations instead.

		See Also: DDL File Syntax, System Operations, DataSet::GetBufferRefreshLock
		*/
		//{secret}
		bool SomeUpdatesRequired();
	
		/*
		{Group:System Callbacks}

		Summary: This method is called by the system when a sequence of
		updates has been completed.
		Returns:  The call can signal an SYSTEMERROR_MISSING_DATASET_CALLBACK.

Note: This method is obsolete, see System Operations instead.

		See Also: DDL File Syntax, System Operations, DataSet::GetBufferRefreshLock
		*/
		//{secret}
		void FinishedAllUpdates();

		//{Group:Operations}
		/*
		Summary: Uses the content of the buffer to refresh the variables of a buffered dataset.
		Remarks: This method must be called on buffered datasets of a Duplica to
		refresh the value of the dataset variables. If an extrapolation filter
		is used, this method will refresh the dataset variables with an
		extrapolation of their value. This method is only valid for the datasets of a Duplica.
		Returns: true if the method is successful, false if the call signals an error.
		Signals SYSTEMERROR_GEN_INVALID_OPERATION if the dataset is not buffered, or
		SYSTEMERROR_OBJDUP_INVALID_ON_MASTER if the method is called on a 
		Duplication master.
		*/
		bool Refresh(DuplicatedObject *pDO = NULL);

#ifdef FOR_DOC_PURPOSE
		/*
{Group:System Callbacks}

		Description: Method called by the system to decide if an update
		should be sent over a reliable channel or not.
		Returns: If this system callback returns true, the next update will be sent 
		over a reliable channel, otherwise it will be sent over an unreliable channel.  
		See Also: DDL File Syntax
		*/
		bool ReliableUpdate() const;
#endif

		/*
{Group:System Callbacks}

		Description: Called by $PRODUCTNAME$ each time a dataset operation begins.
		Remarks: This method is called at the beginning of a DataSetOperation with a 
		reference to the operation that just began as a parameter.  Switch this parameter 
		to find out what kind of operation it is and then implement your functionality.
		The two types of dataset operations are BufferRefreshOperation and RefreshOperation.
		Refer to OperationEnd for an example of the implementation of this method.
		See Also:  System Operations, OperationEnd
		*/
		void OperationBegin(const DataSetOperation* pOperation);
		/*
{Group:System Callbacks}

		Description: Called by $PRODUCTNAME$ each time a dataset operation begins.
		Remarks: This method is called at the end of a DataSetOperation with a reference to 
		the operation that just ended as a parameter.  Switch this parameter to find out what 
		kind of operation it is and then implement your functionality. The two kinds of dataset 
		operations are BufferRefreshOperation and RefreshOperation. For example, to capture 
		when an object has begun to move the following could be used: 

				  void Position::OperationEnd(DataSetOperation* pOperation) {
					switch (pOperation->GetType()) {
						case Operation::BufferRefresh:
							if(poOperation->InitialRefresh()){
								 //Object has began to move
							}
						break;
					}
				}

		See Also: System Operations, OperationBegin
		*/
		void OperationEnd(const DataSetOperation* pOperation);

		// {Secret}
		ExclusiveDenialOperationLock* GetLock() {return NULL;}
		
		// {Secret}
		bool UsesBufferedRefresh() const {return false;}

		// {Secret}
	protected:
		static Time GetTimestamp();

	public:

#ifdef FOR_DOC_PURPOSE
		/*
		Description: Returns the ExclusiveDenialOperationLock that is associated with the 
		dataset instance.
		Returns: The ExclusiveDenialOperationLock that is associated with this dataset member.
		Remarks: User this OperationLock to prevent the BufferRefreshOperation with the help 
		of the OperationDenial or OperationLock class.
		See Also: OperationDenial, OperationLock, System Operations
		*/
		ExclusiveDenialOperationLock* GetBufferRefreshLock();
#endif

#ifdef FOR_DOC_PURPOSE
		/* 
		Summary: Returns a pointer to the PHBDRParameters for the given dataset class.
		These parameters are used to fine-tune the dead reckoning algorithm. 
		Remarks: This method is only available for extrapolated datasets.  
		Returns: A pointer to the PHBDRParameters for the given dataset or NULL if the
		call signals an error.  SYSTEMERROR_GEN_INVALID_OPERATION is signalled
		if the method is called on a non-extrapolated dataset.
		See Also: DDL File Syntax
		*/
		static PHBDRParameters* GetPHBDRParameters();
		
		/*
		Summary: Returns a pointer to the ErrorToleranceFunction for the given dataset
		class.
		Remarks: This method only makes sense for extrapolated datasets.  If the dataset
		is not extrapolated, the error SYSTEMERROR_GEN_INVALID_OPERATION will
		be thrown.
		Returns: A pointer to the ErrorToleranceFunction for the dataset or NULL if the call signals
		an error.  SYSTEMERROR_GEN_INVALID_OPERATION is signalled if the dataset is not
		extrapolated.
		See Also: DDL File Syntax
		*/
		static ErrorToleranceFunction* GetErrorToleranceFunction();
#endif
		/*
		Description: Returns a pointer to the DataSetPerfCounters for the given dataset class.
		Remarks: This pointer points to the performance counters created by $PRODUCTNAME$ for each DataSet 
		declared in the DDL file. 
		*/
		static DataSetPerfCounters* GetPerformanceCounters();

		// {Secret}
		static bool AcceptableError(double dErrorSquare, double dDistance,
									const ErrorToleranceFunction& oErrorTolerance);

#ifdef FOR_DOC_PURPOSE
		/*
		Summary: Indicates that the next update must be performed.
		Remarks: This method is available for datasets declared with the
		upon_request_filter update qualifier.  When this policy is specified,
		the call to update a dataset (see DuplicatedObject::Update) will
		not generate a message unless it has been requested via
		RequestUpdate.  The method is valid only when called on a Duplication master.
		Returns: SYSTEMERROR_OBJDUP_INVALID_ON_DUPLICA will be signalled when called
		on a Duplica.
		See Also: DDL File Syntax
		*/
		void RequestUpdate();
#endif

#ifdef FOR_DOC_PURPOSE
/*
Summary: Indicates that the dataset values changed in a non-continuous
way.  Indicating continuity breaks helps $PRODUCTNAME$ perform a smoother
dead reckoning.

Parameters:
byBreak: Type of continuity break that occured.  

Remarks: This method is available for datasets declared with the
extrapolation_filter update qualifier.  When the dataset values change
smoothly, in a continuous way, an update message needs to be sent only
when the extrapolation error is higher than the specified threshold (refer to
Dead Reckoning Overview). When a continuity break occurs, the
next few calls to DuplicatedObject::Update will generate an
update of the dataset, regardless of the extrapolation error. 
This is done to provide information about the change to the duplicas.

When a call to ContinuityBreak is made, it will have an effect on the
next few calls to Update.  The type of continuity break
dictates the number of updates that will be affected.  The call only
makes sense on a DataSet that belongs to a Duplication master.

The valid values for continuity breaks are CONTINUITY_BREAK_TELEPORT,
CONTINUITY_BREAK_STOP, and CONTINUITY_BREAK_SUDDEN_CHANGE. The flag
CONTINUITY_BREAK_UPDATED_MODEL can be added to
CONTINUITY_BREAK_TELEPORT and CONTINUITY_BREAK_SUDDEN_CHANGE.

Returns: SYSTEMERROR_GEN_INVALID_OPERATION will be signalled when called on a
dataset that is not declared with the extrapolation_filter update
policy qualifier.  SYSTEMERROR_GEN_OUT_OF_RANGE will be signalled when
called with an invalid value for the continuity break.  SYSTEMERROR_OBJDUP_INVALID_ON_DUPLICA
will be signalled if the method is called on a Duplica.
See Also: DDL File Syntax
*/
		void IndicateContinuityBreak(unsigned char byBreak);
#endif

		// A few methods for dead reckoning...

#ifdef FOR_DOC_PURPOSE

/*
Summary: Sets the maximum delay between updates of a dataset.

Parameters:
tiMaximumUpdateDelay: Maximum update delay in milliseconds.  

Remarks: The maximum update delay is the maximum time allowed between updates for a dataset. 
If a dataset is not updated within the maximum delay time, then an update of the dataset
is automatically sent to the remote stations, even if the value of the dataset has not changed
since the previous update.
 
The initial value for the maximum update delay, of 2000 ms, is given by
DEFAULT_MAXIMUM_UPDATE_DELAY. The constant 
NO_MAXIMUM_UPDATE_DELAY can
be used to indicate that a message is never sent as a result of an
expired update delay.

When an extrapolated dataset uses unreliable communication, the loss of a
message may cause a significant drift in the value of the dataset. The maximum update
delay provides a solution to this by periodically sending messages to
the remote station even if the local prediction model is correct. If reliable 
communication is used, the maximum update delay has no effect.

The maximum update delay is a static dataset variable.  All instances
of a single dataset class share the same value however, datasets of different classes
may have different maximum update delays.

Returns: The error SYSTEMERROR_GEN_INVALID_OPERATION is signalled when this method is 
called on a dataset that has not been extrapolated.
See also: GetMaximumUpdateDelay, DEFAULT_MAXIMUM_UPDATE_DELAY, NO_MAXIMUM_UPDATE_DELAY, 
ReliableUpdate
*/
		static void SetMaximumUpdateDelay(TimeInterval tiMaximumUpdateDelay);
#endif

#ifdef FOR_DOC_PURPOSE

		/*
		Summary: Returns the current maximum update delay in milliseconds.
		Returns:  The current maximum update delay in milliseconds or NULL if the call 
		signals an error. The error SYSTEMERROR_GEN_INVALID_OPERATION is signalled when 
		this method is called on a dataset that has not been extrapolated.
		See also: SetMaximumUpdateDelay
		*/
		static TimeInterval GetMaximumUpdateDelay();
#endif


#ifdef FOR_DOC_PURPOSE

/*
Summary: Sets a new extrapolation model via the Duplication master.

Parameters:

v: Dataset extrapolation variable for which the extrapolation model is
changed.  This value is obtained using the MODEL macro.

dValue: Value of the variable, at time tTimestamp.

dRateOfChange: Rate of change of the variable, in units per millisecond, at time tTimestamp.

dAcceleration: Acceleration of the variable, in units per millisecond^2, at time tTimestamp.

tTimestamp: Base time for the new model, in milliseconds.

Remarks: This method is called on a Duplication master when a sudden change occurs to a dataset to provide $PRODUCTNAME$ 
with additional information about the sudden change.  It is then used in conjunction with the continuity 
break flag CONTINUITY_BREAK_UPDATED_MODEL. The method may be used to temporarily correct an inaccurate extrapolation.  

$ifdef NETZ$

For example, when a ball hits a wall, 
due to network latency extrapolation of the position of the ball on the duplicas may lead to the 
ball being displayed past the wall. The SetModel method can be used to temporarily adjust the model 
on the duplicas, taking into account the effect of the collision.  For example, if you used IndicateContinuityBreak 
to signal a CONTINUITY_BREAK_TELEPORT, then the dupica will displace itself to the new position 
immediately (without interpolation) but
will remain stopped until it receives the next three updates, which can last 2 frames.
You can recover the 2 frames and ensure that the Duplica will move correctly
with the right velocity and acceleration immediately after the teleport by using SetModel.

$endif$

$ifdef TSIS$

For example, when an object experiences a collision, 
due to network latency extrapolation of the position of the object on the duplicas may lead to the 
object being displayed incorrectly. The SetModel method can be used to temporarily adjust the model 
on the duplicas, taking into account the effect of the collision. For example, if you used IndicateContinuityBreak 
to signal a CONTINUITY_BREAK_TELEPORT, 
then the dupica will displace itself to the new position immediately (without interpolation) but
will remain stopped until it receives the next three updates, which can last 2 frames.
You can recover the 2 frames and ensure that the Duplica will move correctly
with the right velocity and acceleration immediately after the teleport by using SetModel.

$endif$

Returns: The error SYSTEMERROR_GEN_INVALID_OPERATION is signalled when this method is 
called on a dataset that has not been extrapolated.
SYSTEMERROR_OBJDUP_INVALID_ON_DUPLICA is signalled if the method is called on a 
Duplica.
See also: MODEL, IndicateContinuityBreak
*/
		void SetModel(PHBDRVar_double& v, double dValue, double dRateOfChange, double dAcceleration,
					  Time tTimestamp=GetTimestamp()) {
			SYSTEMCHECK(false);
		}
		void SetModel(PHBDRVar_float& v, double dValue, double dRateOfChange, double dAcceleration,
					  Time tTimestamp=GetTimestamp()) {
			SYSTEMCHECK(false);
		}
		void SetModel(PHBDRVar_int& v, double dValue, double dRateOfChange, double dAcceleration,
					  Time tTimestamp=GetTimestamp()) {
			SYSTEMCHECK(false);
		}
#endif
		

#ifdef FOR_DOC_PURPOSE

/*
Summary: Sets a new extrapolation model locally on a Duplica.

Parameters:

v: Dataset extrapolation variable for which the extrapolation model is
changed.  This value is obtained using the MODEL macro.

dValue: Value of the variable, at time tTimestamp.

dRateOfChange: Rate of change of the variable, in units per millisecond, at time tTimestamp.

dAcceleration: Acceleration of the variable, in units per millisecond^2, at time tTimestamp.

tTimestamp: Base time for the new model, in milliseconds.

Remarks:

$ifdef NETZ$

This method is only called on an individual Duplica. The method may be 
used to temporarily correct an inaccurate extrapolation.  For example, when a ball hits a wall 
due to network latency, extrapolation of the position of the ball on a Duplica may lead to the 
ball being displayed past the wall. The SetLocalCorrection method can be used to temporarily 
adjust the model on the individual Duplica, taking into account the effect of the collision.  
As a result, updates from the Duplication master are ignored and the new local extrapolation
model is used for the amount of time you specified with 
PHBDRParameters::SetLocalCorrectionExpirationDelay.

$endif$

$ifdef TSIS$

This method is only called on an individual Duplica. The method may be 
used to temporarily correct an inaccurate extrapolation.  For example, when an object hits a wall 
due to network latency, extrapolation of the position of the object on a Duplica may lead to it 
being displayed incorrectly. The SetLocalCorrection method can be used to temporarily 
adjust the model on the individual Duplica, taking into account the effect of the collision.  
As a result, updates from the Duplication master are ignored and the new local extrapolation
model is used for the amount of time you specified with 
PHBDRParameters::SetLocalCorrectionExpirationDelay.

$endif$

Returns: The error SYSTEMERROR_GEN_INVALID_OPERATION is signalled when this method is 
called on a dataset that has not been extrapolated.
SYSTEMERROR_OBJDUP_INVALID_ON_MASTER is signalled if the method is called on a 
Duplication master
See also: MODEL, IndicateContinuityBreak, SetModel, PHBDRParameters::SetLocalCorrectionExpirationDelay
*/
		void SetLocalCorrection(PHBDRVar_double& v, double dValue, double dRateOfChange, double dAcceleration,
					  Time tTimestamp=GetTimestamp()) {
			SYSTEMCHECK(false);
		}
		void SetLocalCorrection(PHBDRVar_float& v, double dValue, double dRateOfChange, double dAcceleration,
					  Time tTimestamp=GetTimestamp()) {
			SYSTEMCHECK(false);
		}
		void SetLocalCorrection(PHBDRVar_int& v, double dValue, double dRateOfChange, double dAcceleration,
					  Time tTimestamp=GetTimestamp()) {
			SYSTEMCHECK(false);
		}
#endif

#ifdef FOR_DOC_PURPOSE

/*
Summary: Predicts the value of an extrapolated variable based on current information.

Parameters:

v: Dataset extrapolation variable for which prediction is done.  This
value is obtained using the MODEL macro.

tPredictionTime: Prediction time in milliseconds.  If the time is not specified, the method
will predict the value at the current time.

Remarks: This method can only be called on a Duplica. A dead reckoning prediction is always 
based on the current value of a dataset. Predictions change as new values are received from 
the Duplication master.
Returns: This method returns 0 and signals the error SYSTEMERROR_OBJDUP_INVALID_ON_MASTER when 
it is called on a Duplication master. The error SYSTEMERROR_GEN_INVALID_OPERATION is signalled 
when this method is called on a dataset that is not extrapolated.
See also: MODEL, PredictRateOfChange, PredictAcceleration
*/
		void PredictValue(PHBDRVar_double& v, Time tPredictionTime=GetTimestamp()) {
			SYSTEMCHECK(false);
		}
		void PredictValue(PHBDRVar_float& v, Time tPredictionTime=GetTimestamp()) {
			SYSTEMCHECK(false);
		}
		void PredictValue(PHBDRVar_int& v, Time tPredictionTime=GetTimestamp()) {
			SYSTEMCHECK(false);
		}
#endif


#ifdef FOR_DOC_PURPOSE

/*
Summary: Predicts the rate of change of an extrapolated variable based on current information.  

Parameters:

v: Dataset extrapolation variable for which prediction is done.  This
value is obtained using the MODEL macro.

tPredictionTime: Prediction time in milliseconds.  If the time is not specified, the method
will predict the rate of change at the current time.

Remarks: This method predicts the rate of change, expressed in units per millisecond, of an 
extrapolated variable, based on current information. The method can only be called on a Duplica.
A dead reckoning prediction is always based on the current value of a dataset.
Predictions change as new values are received from the duplication
master.
Returns: The error SYSTEMERROR_GEN_INVALID_OPERATION is signalled when this method is 
called on a dataset that has not been extrapolated. SYSTEMERROR_OBJDUP_INVALID_ON_MASTER is 
signalled when the method is called on a Duplication master.
See also: MODEL, PredictValue, PredictAcceleration
*/
		void PredictRateOfChange(PHBDRVar_double& v, Time tPredictionTime=GetTimestamp()) {
			SYSTEMCHECK(false);
		}
		void PredictRateOfChange(PHBDRVar_float& v, Time tPredictionTime=GetTimestamp()) {
			SYSTEMCHECK(false);
		}
		void PredictRateOfChange(PHBDRVar_int& v, Time tPredictionTime=GetTimestamp()) {
			SYSTEMCHECK(false);
		}
#endif

#ifdef FOR_DOC_PURPOSE

/*
Summary: Predicts the acceleration of an extrapolated variable based on current information.

Parameters:

v: Dataset extrapolation variable for which prediction is done.  This
value is obtained using the MODEL macro.

tPredictionTime: Prediction time in milliseconds.  If the time is not specified, the method
will predict the acceleration at the current time.

Remarks: This method predicts the acceleration, expressed in units per millisecond^2, of an 
extrapolated variable based on current information. The method can only be called on a Duplica.

A dead reckoning prediction is always based on the current value of a dataset.
Predictions change as new values are received from the Duplication master.

$PRODUCTNAME$ uses a first or second order function to predict variable
values and therefore, the acceleration is constant.  However, when convergence
occurs, at the point where the convergence curve meets the tracking
curve a change in acceleration may occur. 

Returns: The error SYSTEMERROR_GEN_INVALID_OPERATION is signalled when this method is 
called on a dataset that has not been extrapolated. SYSTEMERROR_OBJDUP_INVALID_ON_MASTER is 
signalled when the method is called on a Duplication master.
See also: MODEL, PredictValue, PredictRateOfChange
*/
		void PredictAcceleration(PHBDRVar_double& v, Time tPredictionTime=GetTimestamp()) {
			SYSTEMCHECK(false);
		}
		void PredictAcceleration(PHBDRVar_float& v, Time tPredictionTime=GetTimestamp()) {
			SYSTEMCHECK(false);
		}
		void PredictAcceleration(PHBDRVar_int& v, Time tPredictionTime=GetTimestamp()) {
			THROW_EXCEPTION(SYSTEMERROR_GEN_INVALID_OPERATION,0);
		}
#endif

	protected:

#ifdef _DEBUG_CHECK
		DuplicatedObject* m_pDOContainer;
#endif
};

#endif
