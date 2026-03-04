//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  

// This file will be included several times.

#include <ObjDup/PHBDRTimeVector.h>
#include <ObjDup/PHBDRParameters.h>
#include <ObjDup/ContinuityBreak.h>
#include <Platform/Time.h>
#include <queue>

// Group=Object Duplication Subsystem

class PHBDRParameters;

// Description:
//
class PHBDRVar: public PHBDRVarRoot {
	// Group=
	public:
		PHBDRVar(AttributeType x=0);
		~PHBDRVar() {}

		// Accessors...

		void PredictValues(const PHBDRParameters& oParams, const PHBDRTimeVector& t,
						   double* pdValue, double *pdRateOfChange, double *pdAcceleration,
						   Time tFuture, bool bCommitToThisFuture=false);

		// Accessors to add values...
		
		void NewValue(AttributeType x, unsigned long ulPosition=INSERT_VALUE_AT_THE_END);

		AttributeType GetValue(const PHBDRParameters& oParams, const PHBDRTimeVector& t);
		AttributeType PredictValue(const PHBDRParameters& oParams, const PHBDRTimeVector& t,
								   Time tSomeFuture=SessionClock::GetTime());

		void DelayValue(AttributeType x);
		void UseDelayedValue(unsigned long ulPosition);

		void Trace(unsigned long ulTraceFlag=TRACE_ALWAYS);

		// Accessors.

		double GetInitialPosition() const;
		double GetInitialSpeed() const;
		double GetAcceleration() const;

		void SetModel(double dInitialValue, double dRateOfChange, double dAcceleration,
					  Time tTimestamp=SessionClock::GetTime());
		void SetLocalCorrection(double dInitialValue, double dRateOfChange, double dAcceleration,
								Time tTimestamp=SessionClock::GetTime());

		void ComputeParameters(const PHBDRParameters& oParams, PHBDRTimeVector& t,
							   unsigned char byRole, unsigned long ulPos=INSERT_VALUE_AT_THE_END,
							   ContinuityBreak oContinuityBreak=CONTINUITY_BREAK_NONE,
							   Time tNow=SessionClock::GetTime());

	private:

		class ComputationContext {
			public:
				ComputationContext();

				void SetComputationInfo(const PHBDRParameters& oParams,
										const PHBDRTimeVector& t,
										Time tNow);
				void SetResultLocation(Time* ptInitialTime, double *pdInitialPos,
									   double* pdSpeed, double *pdAcceleration,
									   Time* ptNextParametersUpdate);

				// Info to perform the computation...
				const PHBDRParameters* m_pParams;
				const PHBDRTimeVector* m_pTimeVector;
				Time m_tNow;
				// Where to store the result...
				Time* m_ptInitialTime;
				double* m_pdInitialPos;			
				double* m_pdSpeed;
				double* m_pdAcceleration;			
				Time* m_ptNextParametersUpdate;
		};

		// Basic computations.
		
		static double ComputePosition(double dInitialPos, double dSpeed,
									  double dAcceleration, TimeInterval tiElapsed);
		double ComputePosition(TimeInterval tiElapsed) const {
			return ComputePosition(m_dInitialPosition, m_dSpeed, m_dAcceleration, tiElapsed);
		}

		double ComputeEmbraceAngle(const PHBDRTimeVector& t);

		void ComputeTrackingParameters(const ComputationContext& oContext);
		unsigned char SelectTrackingType(const ComputationContext& oContext);
		void ComputeLinearTrackingParam(const ComputationContext& oContext);
		void ComputeNonLinearTrackingParam(const ComputationContext& oContext);
		TimeInterval ComputeCP(const ComputationContext& oContext,
							   Time tNewNextTrackingUpdate,
							   Time* ptCP);
		void ComputeLinearConvergenceParam(const ComputationContext& oContext);
		void ComputeNonLinearConvergenceParam(const ComputationContext& oContext);

#ifdef _TEST_ENABLED
	public:
		static bool Test(bool bHideBug212=false);
#endif

	private:
		AttributeType m_x[3];

		Time m_tInitialTime;
		Time m_tNextParametersUpdate;
		double m_dInitialPosition;
		double m_dSpeed;
		double m_dAcceleration;
		bool m_bLocalCorrection;

		// Delayed info.
		std::queue<AttributeType>	m_queueDelayedValues;
};

