//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _EDataSetTemplate_H_
#define _EDataSetTemplate_H_

#include <ObjDup/ObjDupImpl.h>
#include <ObjDup/UpdateContext.h>
#include <ObjDup/Station.h>
#include <ObjDup/ErrorToleranceFunction.h>
#include <ObjDup/PHBDRVar.h>
#include <ObjDup/OperationDenial.h> 
#include <Plugins/Protocol/Interface/Message.h>


#define DATASET_OP_REGISTER		0
#define DATASET_OP_UNREGISTER	1

// Group=Object Duplication Subsystem

#define IMPLEMENTAPREDICTION(PREDICTION, TYPE)	\
	double Predict##PREDICTION(PHBDRVAR(TYPE)& v, Time tFuture=GetTimestamp()) {	\
		OperationDenial oDenial(GetLock(), _T("Dataset prediction"));						\
		DSCHECK_ROLE_IS_DUPLICA(0);															\
		double dValue, dRateOfChange, dAcceleration;										\
		v.PredictValues(*GetPHBDRParameters(), GetPHBDRModel()->GetTimeVector(),			\
					    &dValue,&dRateOfChange, &dAcceleration, tFuture);					\
		return d##PREDICTION;																\
	}

#define IMPLEMENTPREDICTIONS(PREDICTION)		\
	IMPLEMENTAPREDICTION(PREDICTION, double)	\
	IMPLEMENTAPREDICTION(PREDICTION, float)		\
	IMPLEMENTAPREDICTION(PREDICTION, int)


template <typename SpecificDataSet> class EDataSetTemplate: public DataSetTemplate<SpecificDataSet> {
	public:


        //---------------------------------------------------------------------------------------
		UpdateContext* LocateUCIfRequired(Station* pStation, DuplicatedObject* pDO, unsigned char byIndex) {
			if (UsesUpdateContext()) {
				UpdateContext* pUC=pStation->GetUpdateContextMapRef().Find(pDO->GetHandle(), byIndex);
				if (!pUC) {
					pUC=CreateUpdateContext();
					pStation->GetUpdateContextMapRef().Create(pDO->GetHandle(), byIndex, pUC);
				}
				SYSTEMCHECK(pUC!=NULL);
				return pUC;
			} else {
				return NULL;
			}
		}

        //---------------------------------------------------------------------------------------
		bool UsesUpdateContext() {return s_erFunction.DistanceMatters();}

        //---------------------------------------------------------------------------------------
		bool MaximumUpdateDelayExpired(UpdateContext* pUC) {
			if (s_tiMaximumUpdateDelay>0 &&
				  ((PHBDRModel*)pUC)->CurrentUpdateDelay()>s_tiMaximumUpdateDelay) {
				return true;
			} else {
				return false;
			}
		}

        //---------------------------------------------------------------------------------------
		UpdateContext* CreateUpdateContext() {return (UpdateContext*) fnew typename SpecificDataSet::Buffer;}
		
        //---------------------------------------------------------------------------------------
		bool SomeUpdatesRequired() {												
			if (m_oBreak.ForceUpdateMessage()) {
				return true;
			}
			if (s_erFunction.DistanceMatters()) {
				return true;
			}
			if (ComputeExtrapolationSquaredError((typename SpecificDataSet::Buffer*)&m_dsBuffer)>s_erFunction.SquaredValueAt(UNKNOWN_DISTANCE)) {
				return true;					
			}
			if (!ReliableUpdate() && MaximumUpdateDelayExpired(&m_dsBuffer)) {
				return true;
			}
			return false;
		}
		
        //---------------------------------------------------------------------------------------
		void FinishedAllUpdates(Time tTimestamp) {
			UpdateModel((typename SpecificDataSet::Buffer*)&m_dsBuffer, tTimestamp);
			m_oBreak.Transition();
			DataSetTemplate<SpecificDataSet>::FinishedAllUpdates(); 
		}
		
        //---------------------------------------------------------------------------------------
		//void FinishedAnUpdate(Station* pStation, UpdateContext* pUC, DuplicatedObject* pDO, Time tTimestamp) {
		void FinishedAnUpdate(UpdateContext* pUC, Time tTimestamp) {
			if (pUC) {UpdateModel((typename SpecificDataSet::Buffer*)pUC, tTimestamp);}
		}
		
        //---------------------------------------------------------------------------------------
		bool UpdateRequired(Station* pStation, UpdateContext* pUC, DuplicatedObject* pDO) {
			// Several conditions for an update...
			if (m_oBreak.ForceUpdateMessage()) {
				return true;
			}
			if (!pUC) {  // pUC == NULL
				return true;
			}
			if (ComputeExtrapolationSquaredError((typename SpecificDataSet::Buffer*) pUC)>
				  s_erFunction.SquaredValueAt(pStation->GetObserverPtr()->GetDistanceTo(pDO->GetHandle()), pStation->GetQualityFactor())) {
				return true;
			}
			if (!ReliableUpdate() && MaximumUpdateDelayExpired(pUC)) {
				return true;
			}
			return false;
		}

        //---------------------------------------------------------------------------------------
		void InnerUpdateLoop(DuplicatedObject* pDO, unsigned char byIndex, Time tTimestamp=GetTimestamp()) {
			// Called for every DataSet.
			unsigned long ulNbSent=0;
            bool bBroadcast = false;

			if (SomeUpdatesRequired()) {
				IteratorOverDOs* pItStationToUpdate=DuplicationSpaceTable::GetInstance()->CreateMulticastIterator(pDO, &bBroadcast);

                // If bBroadcast is true,  then pItStationToUpdate will be NULL
                // If bBroadcast is false, then pItStationToUpdate will not be NULL
                SYSTEMCHECK((bBroadcast && !pItStationToUpdate) || (!bBroadcast && pItStationToUpdate));

				TRACE(TRACE_UPDATE,_T("Updating DataSet index %d of DO %s %x"), 
					  byIndex,
					  pDO->GetClassNameString(), pDO->GetObjectID());	

                // Found if all station are using the same update model.

                if(bBroadcast) {
                    // BROADCAST : All stations can be updated because the object is global

                    Selection  oStationsToExcludeSelection(Selection::AutomaticRemoval);

                    // Create an selection of the station that we have a duplica
                    Station::SelectionIterator itKnownStation(DUPLICA);

                    while(!itKnownStation.EndReached()) {
                        UpdateContext  *pUC=LocateUCIfRequired(itKnownStation.GetDOPtr(), pDO, byIndex);
                        // A Station has a UpdateContext, so all the station has a different update context
                        if(UpdateRequired(itKnownStation.GetDOPtr(), pUC, pDO)) {
						    FinishedAnUpdate(pUC, tTimestamp);
                        } else {
                            oStationsToExcludeSelection.Acquire(itKnownStation->GetHandle());
                        }
                        itKnownStation++;
                    }

                    // We don't we to broadcast the current station
                    oStationsToExcludeSelection.Acquire(Station::GetLocalStation());

                    Message    *pMsg = BuildUpdateMessage(pDO, byIndex, tTimestamp);
                    MulticastPolicy::GetInstance()->BroadcastMessage(pMsg, &oStationsToExcludeSelection, pDO, ReliableUpdate());
                    fdelete pMsg;  

                } else {
                    // MULTICAST : Some stations can be updated MULTICAST
                    Selection  oStationsToIncludeSelection(Selection::AutomaticRemoval);
                    bool       bUpdateRequired = false;

                    pItStationToUpdate->GotoStart();
                    while(!pItStationToUpdate->EndReached()) {
                        Station::Ref refStation(pItStationToUpdate->GetHandle());
                        if(refStation.IsValid()) {
                            UpdateContext  *pUC=LocateUCIfRequired(*refStation, pDO, byIndex);
                            // If a station has a UpdateContext, so all the station has a different update context
                            if(UpdateRequired(*refStation, pUC, pDO)) {
                                oStationsToIncludeSelection.Acquire(pItStationToUpdate->GetHandle());
            				    FinishedAnUpdate(pUC, tTimestamp);
                                bUpdateRequired = true;
                            }
                        } 

                        (*pItStationToUpdate)++;
                    }

                    if(bUpdateRequired) {
                        Message         *pMsg = BuildUpdateMessage(pDO, byIndex, tTimestamp);
                        MulticastPolicy::GetInstance()->MulticastMessage(pMsg, &oStationsToIncludeSelection, pDO, ReliableUpdate());
                        fdelete pMsg;  
                    }
                }
				
                DuplicationSpaceTable::GetInstance()->ReleaseIterator(pItStationToUpdate);
                FinishedAllUpdates(tTimestamp); // Only called if at least an update was performed...

                ulNbSent++;

			}
			s_oPerfDataSet.Update(ulNbSent);
		}

        //---------------------------------------------------------------------------------------
		void UpdateLoopWithUpdatedModel(DuplicatedObject* pDO, unsigned char byIndex, Time tTimestamp) {
			for (int i=0; i<3; i++) {
				AddPredictedPoint(tTimestamp+TimeInterval(i));
				InnerUpdateLoop(pDO, byIndex, tTimestamp+TimeInterval(i));
			}
		}

        //---------------------------------------------------------------------------------------
		void UpdateLoop(DuplicatedObject* pDO, unsigned char byIndex, Time tTimestamp=GetTimestamp()) {
#ifdef _DEBUG_CHECK
			SYSTEMCHECK(pDO==m_pDOContainer);
#endif
			if (m_oBreak.UpdatedModel()) {
				UpdateLoopWithUpdatedModel(pDO, byIndex, tTimestamp);
			} else {
				InnerUpdateLoop(pDO, byIndex, tTimestamp);
			}
		}


        //---------------------------------------------------------------------------------------
        Message* BuildUpdateMessage(DuplicatedObject *pDO, unsigned char byIndex, Time tTimestamp) {
            // Build the Update Message
            Message *pMsg;
        	unsigned long ulID=pDO->GetHandle();
		    unsigned char byZero=0;
            pMsg=pDO->GetAssociatedProtocol()->CreateUpdateMessage(&ulID,&byIndex);

			AddSourceTo(pMsg, tTimestamp, false);
			// Since there might eventually be more than one dataset per message,
			// we end with a zero to indicate the end.  
			pMsg->AddData(&byZero); 
            return pMsg;
        }


		// Updated API

        //---------------------------------------------------------------------------------------
		bool IndicateContinuityBreak(unsigned char byBreak) {
			DSCHECK_ROLE_IS_DM(false);
			return m_oBreak.Set(byBreak);
		}

        //---------------------------------------------------------------------------------------
		bool SetModel(PHBDRVAR(double)& v, double dValue, double dRateOfChange, double dAcceleration,
					  Time tTimestamp=GetTimestamp()) {
			DSCHECK_ROLE_IS_DM(false);
			v.SetModel(dValue, dRateOfChange, dAcceleration, tTimestamp);
			return true;
		}

        //---------------------------------------------------------------------------------------
        bool SetModel(PHBDRVAR(int)& v, double dValue, double dRateOfChange, double dAcceleration,
					  Time tTimestamp=GetTimestamp()) {
			DSCHECK_ROLE_IS_DM(false);
			v.SetModel(dValue, dRateOfChange, dAcceleration, tTimestamp);
			return true;
		}

        //---------------------------------------------------------------------------------------
        bool SetModel(PHBDRVAR(float)& v, double dValue, double dRateOfChange, double dAcceleration,
					  Time tTimestamp=GetTimestamp()) {
			DSCHECK_ROLE_IS_DM(false);
			v.SetModel(dValue, dRateOfChange, dAcceleration, tTimestamp);
			return true;
		}

        //---------------------------------------------------------------------------------------
		bool SetLocalCorrection(PHBDRVAR(double)& v, double dValue, double dRateOfChange, double dAcceleration,
					  Time tTimestamp=GetTimestamp()) {
			OperationDenial oDenial(GetLock(), _T("Dataset SetLocalCorrection"));
			DSCHECK_ROLE_IS_DUPLICA(false);
			v.SetLocalCorrection(dValue, dRateOfChange, dAcceleration, tTimestamp);
			return true;
		}
		
        //---------------------------------------------------------------------------------------
        bool SetLocalCorrection(PHBDRVAR(int)& v, double dValue, double dRateOfChange, double dAcceleration,
					  Time tTimestamp=GetTimestamp()) {
			OperationDenial oDenial(GetLock(), _T("Dataset SetLocalCorrection"));
			DSCHECK_ROLE_IS_DUPLICA(false);
			v.SetLocalCorrection(dValue, dRateOfChange, dAcceleration, tTimestamp);
			return true;
		}
		
        //---------------------------------------------------------------------------------------
        bool SetLocalCorrection(PHBDRVAR(float)& v, double dValue, double dRateOfChange, double dAcceleration,
					  Time tTimestamp=GetTimestamp()) {
			OperationDenial oDenial(GetLock(), _T("Dataset SetLocalCorrection"));
			DSCHECK_ROLE_IS_DUPLICA(false);
			v.SetLocalCorrection(dValue, dRateOfChange, dAcceleration, tTimestamp);
			return true;
		}

		IMPLEMENTPREDICTIONS(Value);
		IMPLEMENTPREDICTIONS(RateOfChange);
		IMPLEMENTPREDICTIONS(Acceleration);
};


#define _DS_DECLARE_ERRORTOLERANCE() \
		static ErrorToleranceFunction s_erFunction;	\
		static ErrorToleranceFunction* GetErrorToleranceFunction() {return &s_erFunction;}

#define _DS_IMPLEMENT_ERRORTOLERANCE(DS) ErrorToleranceFunction DATASET(DS)::s_erFunction;

#define _DS_DECLARE_PHBDRPARAMETERS()			\
		static PHBDRParameters s_oPHBDRParameters;  \
		static PHBDRParameters* GetPHBDRParameters() {return &s_oPHBDRParameters;}	\
		Buffer* GetPHBDRModel() {return &m_dsBuffer;}

#define _DS_DECLARE_MAXUPDATEDELAY()			\
		static TimeInterval s_tiMaximumUpdateDelay;	\
		static void SetMaximumUpdateDelay(TimeInterval tiMaximumUpdateDelay) {s_tiMaximumUpdateDelay=tiMaximumUpdateDelay;}	\
		static TimeInterval GetMaximumUpdateDelay() {return s_tiMaximumUpdateDelay;}

#define _DS_IMPLEMENT_MAXUPDATEDELAY(DS)	\
		TimeInterval DATASET(DS)::s_tiMaximumUpdateDelay=DEFAULT_MAXIMUM_UPDATE_DELAY;


#define _DS_IMPLEMENT_PHBDRPARAMETERS(DS)	\
		PHBDRParameters DATASET(DS)::s_oPHBDRParameters;

#define _DS_DECLARE_CONTINUITY_BREAKS()		\
		ContinuityBreak m_oBreak;

#define _DS_DECLARE_EXTRAPOLATION_FILTER() 	\
		_DS_DECLARE_MAXUPDATEDELAY()		\
		_DS_DECLARE_CONTINUITY_BREAKS() 	\
		_DS_DECLARE_ERRORTOLERANCE();		\
		_DS_DECLARE_PHBDRPARAMETERS();


#define _DS_IMPLEMENT_EXTRAPOLATION_FILTER(DS)		\
		_DS_IMPLEMENT_MAXUPDATEDELAY(DS);			\
		_DS_IMPLEMENT_ERRORTOLERANCE(DS);			\
		_DS_IMPLEMENT_PHBDRPARAMETERS(DS);			



#endif
