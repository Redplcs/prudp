//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _ContinuityBreak_H_
#define _ContinuityBreak_H_

#include <ObjDup/ObjDupDecl.h>
#include <ObjDup/SessionClock.h>
class Message;

// {Secret}
#define CONTINUITY_BREAK_NONE		(unsigned char)(0x0)

// Group=Dead Reckoning

/*
Summary: Constant indicates that the values of the dataset members
will jump from one value to another and that no extrapolation should 
be performed between these values.

Remarks:
Assume that a DataSet represents the position of an object. If 
the object is teleported from one position to another, it makes no 
sense to extrapolate between the two positions. A call to 
DataSet::IndicateContinuityBreak (CONTINUITY_BREAK_TELEPORT) can be made before 
a call to DuplicatedObject::Update to help $PRODUCTNAME$ perform a
better extrapolation.

If as a result of the change the value of the dataset directly
changed, the continuity break CONTINUITY_BREAK_TELEPORT should be used
instead of CONTINUITY_BREAK_SUDDEN_CHANGE. For example, assume we have two datasets 
that represent the position and the speed of a Sphere respectively. If the Sphere 
bounces off a wall a continuity break occurs. With respect to the position of the Sphere, the
break that occurs is a CONTINUITY_BREAK_SUDDEN_CHANGE as the direction
of the motion changes but the position itself does not change when the
Sphere hits the wall. However, with respect to the speed of the Sphere the
break that occurs is a CONTINUITY_BREAK_TELEPORT as the value of the
speed vector directly changes.  

See also: DataSet::IndicateContinuityBreak, CONTINUITY_BREAK_SUDDEN_CHANGE, 
CONTINUITY_BREAK_STOP
*/
#define CONTINUITY_BREAK_TELEPORT		(unsigned char)(0x1)

/*
Summary: Constant indicates that the values of the dataset members 
will suddenly stop changing.

Remarks:
Assume that a DataSet represents the position of an object. If the object
suddenly stops moving a call to DataSet::IndicateContinuityBreak (CONTINUITY_BREAK_STOP)
will help $PRODUCTNAME$ perform a better extrapolation. When the object
starts to move again a call to DataSet::IndicateContinuityBreak (CONTINUITY_BREAK_SUDDEN_CHANGE) 
should be made.

See also: DataSet::IndicateContinuityBreak, CONTINUITY_BREAK_SUDDEN_CHANGE, CONTINUITY_BREAK_TELEPORT
*/
#define CONTINUITY_BREAK_STOP			(unsigned char)(0x2)

/*
Summary: Constant indicates that a sudden change will occur in the manner 
in which the values of the dataset members are changing.

Remarks:
Assume that a DataSet represents the position of an object. If the object
rebounds off a wall then a call to DataSet::IndicateContinuityBreak (CONTINUITY_BREAK_SUDDEN_CHANGE) 
will allow $PRODUCTNAME$ to perform a better extrapolation.

If as a result of the change the value of the dataset directly
changed, the continuity break CONTINUITY_BREAK_TELEPORT should be used
instead of CONTINUITY_BREAK_SUDDEN_CHANGE. For example, assume we have two datasets 
that represent the position and the speed of a Sphere respectively. If the Sphere 
bounces off a wall a continuity break occurs. With respect to the position of the Sphere, the
break that occurs is a CONTINUITY_BREAK_SUDDEN_CHANGE as the direction
of the motion changes but the position itself does not change when the
Sphere hits the wall. However, with respect to the speed of the Sphere the
break that occurs is a CONTINUITY_BREAK_TELEPORT as the value of the
speed vector directly changes.  

See also: DataSet::IndicateContinuityBreak, CONTINUITY_BREAK_STOP, CONTINUITY_BREAK_TELEPORT
*/
#define CONTINUITY_BREAK_SUDDEN_CHANGE	(unsigned char)(0x3)

/*
Summary: Constant indicates that the model contains more information about 
how the values of the dataset members should change due to the continuity break.

Remarks:
This constant is a flag that can be used with either of the constants
CONTINUITY_BREAK_SUDDEN_CHANGE or CONTINUITY_BREAK_TELEPORT. The use of this 
flag indicates that when a continuity break is signaled, the dataset variables
will be updated using DataSet::SetModel. Providing such information allows $PRODUCTNAME$ 
to perform a better extrapolation.

For example, assume that we define the following in the DDL:

		dataset	Altitude {
			double z;
		};

		doclass JumpingObject {
			Altitude m_dsAltitude;
		};

Now, say that an object jumps in the air. A sudden change occurs to
the value of its Altitude dataset. The Jump method sets the new
vertical speed of the object and provides relevant information to
$PRODUCTNAME$

		unsigned long JumpingObject::Jump(unsigned long ulNewVerticalSpeed) {
			// Sets the object variable used to perform the physic.
			// The value is stored in m/s.  
			m_dNewVerticalSpeed=ulNewVerticalSpeed;

			// Updates the extrapolation model for the altitude
			// dataset. m_dsAltitude.z is a value in meters and
			// m_dNewVerticalSpeed is given in m/s.  The rate of
 			// change of the the variable, in m/ms, is thus
			// m_dNewVerticalSpeed/1000. The JumpingObject physics 
			// applies gravity to the object. The gravity is an
			// acceleration of -9.8 m/(s^2), or -9.8/1000000 m/(ms^2).
			m_dsAltitude.SetModel(MODEL(m_dsAltitude,z),
								  m_dsAltitude.z,
								  m_dNewVerticalSpeed/1000,
								  -9.8/1000000);

			// Indicate the continuity break.  
			m_dsAltitude.IndicateContinuityBreak(CONTINUITY_BREAK_SUDDEN_CHANGE |	
										 CONTINUITY_BREAK_UPDATED_MODEL);

			// Update the object information.
			Update();
			
			return 0;
		}

		

See also: CONTINUITY_BREAK_SUDDEN_CHANGE, CONTINUITY_BREAK_TELEPORT, CONTINUITY_BREAK_STOP, 
DataSet::SetModel, DataSet::IndicateContinuityBreak
*/
#define CONTINUITY_BREAK_UPDATED_MODEL	(unsigned char)(1<<7)


// {Secret}
#define CONTINUITY_BREAK_SUDDEN_CHANGE_2ND_UPDATE	(unsigned char)(0x4)
// {Secret}
#define CONTINUITY_BREAK_SUDDEN_CHANGE_LAST_UPDATE	(unsigned char)(0x5)

// {Secret}
#define CONTINUITY_BREAK_INITIALISATION		CONTINUITY_BREAK_TELEPORT

// {Secret}
#define CONTINUITY_BREAK_HIGHEST_VALUE	(unsigned char)(0x5)

// {Secret}
class ContinuityBreak {
	public:
		ContinuityBreak();
		ContinuityBreak(Message* pMsg);
		ContinuityBreak(unsigned char byState);
		ContinuityBreak(const ContinuityBreak& oBreak);
		
		bool Set(unsigned char byBreak);
		void Transition();

		static bool ValidUserBreak(unsigned char byBreak);
		static bool ValidBreak(unsigned char byBreak);

		// True if this type of continuity break forces an update
		// message to be sent.  Called on the duplication master...
		bool ForceUpdateMessage();
		// True if this type of continuity break forces tracking
		// parameters to be computed, rather than convergence, on the
		// duplica.
		bool ForceTrackingOnDuplica();
		bool UpdatedModel();
		bool NoParameterUpdate(unsigned char byRole);

		void AddSourceTo(Message* pMsg, bool bDiscovery);
		void ExtractFrom(Message* pMsg);
		unsigned char GetState();

#ifdef _TEST_ENABLED
		bool TraverseTransitionsTest();
		static bool Test();
#endif

	private:
		unsigned char m_byState;
};

#endif
