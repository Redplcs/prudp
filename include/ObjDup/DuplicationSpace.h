//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#include <ObjDup/ObjDupDecl.h>
#include <ObjDup/DupSpaceID.h>
#include <ObjDup/MatchOperationTriggers.h>
#include <ObjDup/DOHandle.h>
#include <ObjDup/Collection.h>

class DupSpaceOperation;

// The includes are outside the file protection to solve problems
// related to a circular file inclusion.

#ifndef _DuplicationSpace_H_
#define _DuplicationSpace_H_


class DuplicatedObject;
class IteratorOverDOs;
class DOOperation;
class DOFilter;
class Station;

//{secret}
// Match policy flags.
#define MATCH_PUBLISHER_MASTER		1<<0
#define MATCH_PUBLISHER_DUPLICA		1<<1
#define MATCH_SUBSCRIBER_MASTER		1<<2
#define MATCH_SUBSCRIBER_DUPLICA	1<<3
#define MATCH_PS_MASTER				1<<4
#define MATCH_PS_DUPLICA			1<<5
#define MATCH_CELL_MASTER			1<<6
#define MATCH_CELL_DUPLICA			1<<7

//group=DDL Output

/*
Description: The class DuplicationSpace contains class methods inherited by any 
user-implemented duplication space class.

Remarks: The periodic matching behaviour of $PRODUCTNAME$ is specified via the MatchOperationTriggers 
class using the GetLocalTriggers and GetGlobalTriggers methods. The periodic matching behaviour of 
each space that results in Duplica creation is specified via GetLocalTriggers since a successful 
match within a single duplication space is a sufficient condition for Duplica creation. GetGlobalTriggers 
is used for periodic relevance checks that result in Duplica deletion since non-relevance within one 
duplication space is not a sufficient condition for deletion. The non-relevance within all duplication 
spaces has to be assured prior to Duplica deletion. This policy is set for all duplication spaces 
via the GetGlobalTriggers method.
  
For example, suppose you declare a duplication space in the DDL file as follows:

         dupspace InterestSpace;

You then need to define an InterestSpace class that will ultimately inherit, via the DDL generated 
InterestSpaceDDL.h file, from the DuplicationSpace class. Once a duplication space is defined, you then
need to specify the PSMatch function. It is the PSMatch function that determines whether or not a 
duplicated object will be discovered by another object within the InterestSpace.

         class InterestSpace : public DUPSPACE (InterestSpace) {
            public:
         	virtual bool PSMatch(DuplicatedObject * oPublisher, DuplicatedObject * oSubscriber){
                  // User implementation of the PSMatch function for InterestSpace
                }
            // Other methods   
         }

The DuplicationSpace is instantiated by $PRODUCTNAME$ prior to session creation as a result of a 
DDL dupspace definition.  To access the DuplicationSpace from within your game use the GetInstance method.
For example, if InterestSpace is a DuplicationSpace declared in the DDL file, the following method returns 
a pointer to that DuplicationSpace:

        DuplicationSpace* dupSInterestSpace = InterestSpace::GetInstance();

See Also: DDL File Syntax, MatchOperationTriggers
*/
class DuplicationSpace {
//Group=
	public:

		// This macro is never defined.  It is used only to get around a compilation problem with 
		// DocJet, as _Role cannot be made secret.
		#ifdef FOR_DOC_PURPOSE
		
		#else
		
		// These specific values are important.  Publisher, Subscriber
		// and Cell use different bits, and PS is Publisher or
		// Subscriber.
		typedef enum _Role {Publisher=1, Subscriber=2, Cell=4, PS=3} Role;	

		#endif

//Group=Operations		

/*
Description: The DuplicationSpace is instantiated by $PRODUCTNAME$ before the session is created.

Remarks: A DuplicationSpace should never be directly instantiated. Instead, it is created by $PRODUCTNAME$ 
prior to session creation as a result of a DDL dupspace definition. To access the duplication space from
within your game use the GetInstance method. For example, if InterestSpace is a duplication 
space declared in the DDL file, the following method returns a pointer to that DuplicationSpace:

        DuplicationSpace* dupSInterestSpace = InterestSpace::GetInstance();

See Also: DDL File Syntax
*/
		DuplicationSpace();
		
		/*
		Description: The DuplicationSpace is destroyed by $PRODUCTNAME$ when the session
		is terminated.
		Remarks: A DuplicationSpace should never be directly destroyed.  It is destroyed 
		by $PRODUCTNAME$ when the session is terminated.
		See Also: DDL File Syntax
		*/		
		virtual ~DuplicationSpace();

		
		//{secret}
		DupSpaceID GetID() {return m_id;}
		
		//{secret}
		virtual bool UsesRegularLocationSet() {return true;}

		//{secret}
        virtual bool UsesBroadcast() {return false;}

	public:
		
		// Returns: true if in this particular space a Duplica of the
		// object has been created.
		//{secret}
		virtual bool IsDuplicatedOn(DuplicatedObject* pPublisher, DOHandle hLocation);

		// Methods that are redefined by specific DuplicationSpaces.
		//{secret}
		virtual const TCHAR* GetClassNameString()=0;
		//{secret}
		virtual IteratorOverDOs* CreateLocationIterator(DuplicatedObject* pPublisher);
		//{secret}
		void ReleaseIterator(IteratorOverDOs* pIt);

		//{secret}
		virtual bool UsesDefaultCells() {return false;}

		//{secret}
		virtual IteratorOverDOs* CreateSubscriberIterator(unsigned int uiPSRelation);
		//{secret}
		IteratorOverDOs* CreateSubscriberIterator() {return CreateSubscriberIterator(m_uiPSRelation);}
		
		//{secret}
		virtual IteratorOverDOs* CreatePublisherIterator(unsigned int uiPSRelation);
		//{secret}
		IteratorOverDOs* CreatePublisherIterator() {return CreatePublisherIterator(m_uiPSRelation);}
		
		//{secret}
		IteratorOverDOs* CreatePSIterator();
		
		//{secret}
		IteratorOverDOs* CreateCellIterator(unsigned int uiCellRelation);
		//{secret}
		IteratorOverDOs* CreateCellIterator() {return CreateCellIterator(m_uiCellRelation);}
		
		//{secret}
		Collection* SelectAppropriateCollection(bool bMaster, bool bDuplica);
		
		//{secret}
		Collection* SelectAppropriateCollection(unsigned int uiAxis,
			unsigned int uiMasterFlag, unsigned int uiDuplicaFlag) {
			return SelectAppropriateCollection((uiAxis & uiMasterFlag)==uiMasterFlag, (uiAxis & uiDuplicaFlag)==uiDuplicaFlag);
		}

		
		//{secret}
		bool IsAPublisher(DuplicatedObject* pDO) {return IsAPublisher(pDO, m_uiPSRelation);}		
		
		
		//{secret}
		bool IsAPublisher(DuplicatedObject* pDO, unsigned int uiPSRelation);
		
		
		//{secret}
		bool IsASubscriber(DuplicatedObject* pDO) {return IsASubscriber(pDO, m_uiPSRelation);}
		
		
		//{secret}
		bool IsASubscriber(DuplicatedObject* pDO, unsigned int uiPSRelation);
		
		
		//{secret}
		bool IsACell(DuplicatedObject* pDO) {return IsACell(pDO, m_uiCellRelation);}
		
		
		//{secret}
		bool IsACell(DuplicatedObject* pDO, unsigned int uiCellRelation);
		
		
		//{secret}
		bool IsAPS(DuplicatedObject* pDO) {return IsAPS(pDO, m_uiCellRelation);}
		
		
		//{secret}
		bool IsAPS(DuplicatedObject* pDO, unsigned int uiCellRelation);

		// Match triggers.
		//{secret}
		virtual void OperationBeginMatchTrigger(DOOperation* pOperation);
		
		//{secret}
		virtual void OperationEndMatchTrigger(DOOperation* pOperation);

		// {secret}
		void SetPSRelation(unsigned int uiNewRelation);
		// {secret}
		void SetCellRelation(unsigned int uiNewRelation);

		
	public:

		// Callbacks.
		
		/*
		Description: Called by $PRODUCTNAME$ whenever a DupSpaceOperation begins.
		Remarks: The method is called at the beginning of a DupSpaceOperation with 
		a reference to the DupSpaceOperation that just began as a parameter. Switch 
		this parameter to find out what kind of operation it is and then implement
		your functionality. 
		
		Parameters:
		pOperation: a pointer to a DupSpaceOperation that has begun.
		
		See Also: OperationEnd, MatchOperation
		*/
		virtual void OperationBegin(DupSpaceOperation* pOperation) {}
		
		/*
		Description: Called by $PRODUCTNAME$ whenever a DupSpaceOperation ends.
		Remarks: The method is called at the end of a DupSpaceOperation with a 
		reference to the DupSpaceOperation that just terminated as a parameter.  
		Switch this parameter to find out what kind of operation it is and then 
		implement your functionality.
		
      	Parameters:
		pOperation: a pointer to a DupSpaceOperation that has ended.
		
		See Also: OperationBegin, MatchOperation
		*/
		virtual void OperationEnd(DupSpaceOperation* pOperation) {}
		
/*
Description:
User implemented function that determines for any given publisher-subscriber pair of duplicated objects in
a duplication space whether or not the Publisher duplicated object is discovered by the subscriber's station.
		
Remarks:
This user implemented function is iterated over the possible pairs of publishers and subscribers in the duplication
space on each station to determine if a discovery is to take place.  The system divides the space into cells
and on each station, for all of the cells for which the station is the master, it matches all of the Publisher 
duplicated objects with all of the duplicas of the Subscriber objects.  

The match decision will typically be based on a computation involving the datasets of the two duplicated objects, 
such as distance, location, 
interest, etc.  If the PSMatch function returns true, a Duplica of the Publisher is created 
on the station where the Duplication master of the Subscriber resides.  The match condition must be written so 
that it will return the same value if it is called on either the Duplication master or the Duplica of a 
Publisher or Subscriber.  
		
The following is an example of the PSMatch implementation for an InterestSpace populated 
with User duplicated objects.  User duplicated objects have an Interest dataset and 
they discover each other only if that Interest is the same.
		
        bool InterestSpace::PSMatch (DuplicatedObject* pPublisher, DuplicatedObject* pSubscriber){
             if (pPublisher->IsAKindOf(DOCLASSID(User)) && pSubscriber->IsAKindOf(DOCLASSID(User))){
	          User *pUserPublisher = (User*) pPublisher;
	          User *pUserSubscriber = (User*) pSubscriber;
	          if (pUserPublisher->mdsInterest.iName == pUserSubscriber->mdsIntrest.iName) {
	                return true;
	          }
             }
            return false;
       }            
		
Parameters:
pPublisher: a pointer to a publishing DuplicatedObject in the DuplicationSpace.
pSubscriber: a pointer to a subscribing DuplicatedObject in the DuplicationSpace.

Return Value:
The function should be defined so as to return true if a Publisher duplicated object is to be 
discovered by the Subscriber duplicated object and false if otherwise.
		
See Also: CellMatch
*/
		virtual bool PSMatch(DuplicatedObject* pPublisher, DuplicatedObject* pSubscriber)=0;
/*
Description:
Function that specifies when a duplicated object belongs to a Cell and when it does not.  

Remarks:
This function has to be redefined only if custom cells are created.  If you create custom cells,
then this is the function that decides when a duplicated object is to belong to a Cell.

The following is an example of a CellMatch implementation for an InterestSpace populated 
with User duplicated objects and split up into InterestArea cells.  User duplicated objects have an 
InterestArea dataset and they belong to a Cell only if that InterestArea is the same as the cell's
InterestAreaDescription:

        bool InterestSpace::CellMatch (DuplicatedObject* pPS, DuplicatedObject* pCell){
             if (pPS->IsAKindOf(DOCLASSID(User)) && pCell->IsAKindOf(DOCLASSID(InterestArea))){
	          User *pUser = (User*) pPS;
	          InterestArea *pCellInterestArea = (InterestArea*) pCell;
	          if (pUser->mdsInterestArea.iName == pCellInterestArea->mdsInterestAreaDesc.iName) {
	                return true;
	          }
             }
            return false;
       }    

Return Value:
The function should be defined so as to return true if a duplicated object belongs to a Cell and 
false if otherwise.
*/
		virtual bool CellMatch(DuplicatedObject* pPS, DuplicatedObject* pCell)=0;

		/*
		Description: This method is called when the DuplicationSpace is constructed. It 
		constructs the cells declared in the DDL file or default $PRODUCTNAME$ cells.
		Remarks: If you do not manually specify cells in your duplication space then you 
		do not need to redefine this virtual function as it will be called by $PRODUCTNAME$ 
		to create default cells. //however, if you did specify cells in the DDL file this is 
		where you should create and publish all of the Cell duplicated objects.  This is also 
		an ideal place to define your match policy, such as MatchOperationTriggers::DisablePeriodicMatch.
		See Also: DuplicatedObject::Create, MatchOperationTriggers, DDL File Syntax
		*/
		virtual void CreateCells()=0;

		/*
		Description: Check if a Duplica or all duplicas are still relevantly duplicated.
		Remarks: This method can be called by $PRODUCTNAME$ or the user to check if a particular 
		Duplica should still be duplicated as it is, or if it should be deleted on some station(s).  
		The CheckRelevance call without a specific Duplica to check as a parameter is used by 
		$PRODUCTNAME$ or the user to perform a relevance check for all of the local duplicas.  
		With the default relevance check policy, the method is called by $PRODUCTNAME$ whenever 
		a MasterIDChangeOperation or RemoveFromStoreOperation takes place.
		Return Value: true if the parameter is a valid Duplica, false if otherwise.  If the method 
		is called on a Duplication master, the call returns false and SYSTEMERROR_OBJDUP_INVALID_ON_MASTER 
		is signalled.

		Parameters:
		pDuplicaToCheck:  optional pointer to a DuplicatedObject instance whose relevance needs to be checked.
		*/
		static bool CheckRelevance(DuplicatedObject* pDuplicaToCheck);

		static void CheckRelevance();

		/*
		Description: Matches publishers and subscribers (MatchPSRelationPair) for all of the 
		duplicated objects that belong to the Cell.
		Remarks: The pCell parameter must be a valid Duplication master cell.  The matching is 
		done based on the user implemented PSMatch function.

		Parameters:
		pCell:  a DuplicatedObject pointer to the Duplication master of a Cell that is to perform 
		matching of its publishers and subscribers.

		Return Value: true if pCell is a Duplication master cell, false if pCell is not a valid 
		Duplication master cell.
		*/		
		bool MatchAcrossPSRelation(DuplicatedObject* pCell);

		/*
		Description: Calls MatchAcrossPSRelation for all of the cells for which this station is 
		Duplication master.
		Remarks: This function calls MatchAcrossPSRelation for all of the local station's duplication 
		master cells.
		*/			
		void MatchAcrossPSRelations();

		/*
		Description: The function matches duplicated objects with cells.
		Remarks: The function performs a match between all of  the cells in the duplication space 
		with all duplicated objects.
		*/			
		void MatchAcrossCellRelation();

		/*
		Description: This function is called automatically and periodically by default.  It
		calls MatchAcrossCellRelation and MatchAcrossPSRelation.
		Remarks: This function is performed periodically by default, unless you turn off the 
		periodic match with the MatchOperationTriggers::DisablePeriodicMatch function. The 
		function calls MatchAcrossCellRelation and MatchAcrossPSRelation, which ensures a complete 
		update to the duplication state of the distributed system.
		*/			
		void Match();

		/*
		Description: Function takes a publishing duplicated object and performs MatchPSRelationPair 
		across all of the subscribing duplicated objects in the space.
		Remarks: This function is called automatically by $PRODUCTNAME$ whenever a new publishing 
		duplicated object is added to the duplication space.  Call this function to perform 
		MatchPSRelationPair for a specific Publisher and all subscribers.

		Parameters:
		pPublisher:  DuplicatedObject pointer to the Publisher that is to be matched with all 
		subscribers in the space.

		Return Value: true if the parameter is a valid publishing duplicated object and the call
		signals no error, false if otherwise.
		See Also: MatchPSRelationPair, Match
		*/
		bool MatchAcrossSubscribers(DuplicatedObject* pPublisher);

		/*
		Description: Function takes a Subscriber duplicated object and performs MatchPSRelationPair 
		across all of the publishing duplicated objects in the space.
		Remarks: This function is called automatically by $PRODUCTNAME$ whenever a new subscribing 
		duplicated object is added to the duplication space.  Call this function to perform 
		MatchPSRelationPair for a specific Subscriber and all publishers.

		Parameters:
		pSubscriber:  DuplicatedObject pointer to the Subscriber that is to be matched with all 
		publishers in the space.

		Return Value: true if the parameter is a valid subscribing duplicated object and the call
		signals no error, false if otherwise.
		See Also: MatchPSRelationPair, Match
		*/
		bool MatchAcrossPublishers(DuplicatedObject* pSubscriber);

		/*
		Description: Function takes a Cell duplicated object and performs MatchCellRelationPair 
		across all of the publishing and subscribing duplicated objects in the duplication space.
		Remarks: This function is called automatically by $PRODUCTNAME$ whenever a new subscribing 
		duplicated object is added to the duplication space.  Call this function to perform 
		MatchCellRelationPair for a specific Cell and all publishers and subscribers.

		Parameters:
		pCell:  DuplicatedObject pointer to the Cell that is to be matched with all publishers 
		and subscribers in the space.

		Return Value: true if the parameter is a valid Cell and the call signals no error, false if otherwise.
		See Also: MatchCellRelationPair, CellMatch
		*/
		bool MatchAcrossPS(DuplicatedObject* pCell);

		/*
		Description: Function takes a PS duplicated object (Publisher and/or Subscriber) and calls 
		MatchCellRelationPair for all of the cells in the space.
		Remarks: This function is called automatically by $PRODUCTNAME$ whenever a new subscribing duplicated 
		object is added to the duplication space.  Call this function to perform MatchCellRelationPair for 
		a specific  PS and all of the cells in the space.

		Parameters:
		pPS: either a publishing and/or subscribing DuplicatedObject pointer to the duplicated object that is
		to be matched via the CellMatch function.

		Return Value: true if the parameter is a valid duplicated object PS (Publisher and/or Subscriber) 
		and the call signals no error, false if otherwise.
		See Also: CellMatch, MatchCellRelationPair
		*/
		bool MatchAcrossCells(DuplicatedObject* pPS);

		/*
		Description: Calls the appropriate methods to update the duplication space with respect to
		a particular duplicated object.  
		Remarks: Based on the role of the duplicated object in the space as well as the state of 
		the duplication space, one or several of the following methods will be called by $PRODUCTNAME$: 
		CellMatch, MatchAcrossSubscribers, MatchAcrossPublishers, or MatchAcrossPS.

		Parameters:
		pDO: either a publishing and/or subscribing DuplicatedObject pointer to the duplicated object 
		according to which the state of the duplication space is to be updated.

		Return Value: true if the parameter is a valid DuplicatedObject pointer and the call signals 
		no error, false if otherwise.
		See Also: CellMatch, Match, MatchAcrossSubscribers, MatchAcrossPublishers, MatchAcrossPS.
		*/			
		bool MatchSingleObject(DuplicatedObject* pDO);

		/*
		Description: Function calls PSMatch and creates a Duplica if it is necessary.
		Remarks: This function takes a publisher-subscriber pair of DuplicatedObject instances, 
		calls PSMatch to determine if the Subscriber should discover the Publisher, and then creates 
		the apropriate Duplica on the station on which the Subscriber duplicated object has its Duplication master.

		Parameters:
		pPublisher:  the publishing duplicated object instance to be matched with pSubscriber.
		pSubscriber:  the subscribing duplicated object instance that is to be matched with pPublisher.

		Return Value: true if the parameters are valid and the call signals no error, false if otherwise.
		See Also: PSMatch, Match
		*/			
		bool MatchPSRelationPair(DuplicatedObject* pPublisher, DuplicatedObject* pSubscriber);
		
		/*
		Description: Function calls CellMatch and creates a Duplica if it is necessary.

		Remarks: This function takes a PS (Publisher or Subscriber) and a Cell duplicated object and does the
		following:
		(1) Calls CellMatch to determine if the particular duplicated object belongs to the Cell or not, and  
		(2) Creates appropriate duplicas on Subscriber stations in case the PS belongs to the Cell 
		as a previously unpublished Publisher or a previously unsubscribing Subscriber.

		Parameters:
		pPS:  the duplicated object pointer to the PS (Publisher and/or Subscriber) that
		is to be matched in its relation with a pCell.
		pCell:  the Cell duplicated object pointer to the Cell that is to be updated with respect to pPS.

		Return Value: true if the parameters are valid and the call signals no error, false if otherwise.
		See Also: CellMatch, Match
		*/			
		bool MatchCellRelationPair(DuplicatedObject* pPS, DuplicatedObject* pCell);

		//{secret}
		void NoCellRequired();
		
		/*
		Description: Returns the MatchOperationTriggers for this particular duplication space
		Remarks: The MatchOperationTriggers class is used to fine-tune the periodic match behaviour
		that results in Duplica creation.
		Return Value: The MatchOperationTriggers instance returned by this function can be used to control 
		the behaviour of this space's periodic match activities that result in Duplica creation.
		See Also: MatchOperationTriggers
		*/
		MatchOperationTriggers* GetLocalTriggers() {return &m_oLocalTriggers;}
		
		/*
		Description: Returns the global MatchOperationTriggers for all duplication spaces in the session.
		Remarks: The MatchOperationTriggers class instance returned by this method is used to fine-tune 
		the periodic relevance check behaviour that results in Duplica deletion.
		Return Value: A pointer to a MatchOperationTriggers instance that can be used to fine-tune the 
		periodic relevance check activities that result in Duplica deletion.
		See Also: MatchOperationTriggers
		*/
		static MatchOperationTriggers* GetGlobalTriggers();

		// {secret}
		virtual bool IsDuplicaRelevant(DuplicatedObject *pDO);

		// This macro is never defined.  It is only used to create a dummy method where the 
		// documentation for GetInstance can be located.
		#ifdef FOR_DOC_PURPOSE
		/*
		Description: Returns a pointer to the DuplicationSpace instance.
		Returns: A pointer to the DuplicationSpace.
		Remarks: Use the reference returned by this method to access the DuplicationSpace.
		For example, get the local triggers as follows:

			DuplicationSpace::GetInstance()->GetLocalTriggers();

		*/
		static DuplicationSpace* GetInstance() {
			SYSTEMCHECK(false);
		}
		#endif

	protected:
		// Default cells implementation.

		void CreateDefaultCells();
		bool DefaultCellMatch(DuplicatedObject* pPS, DuplicatedObject* pCell);

	private:
		void MatchDOPair(DuplicatedObject* pA, DuplicatedObject* pB, bool bCellMatch);
		
		virtual bool IsADiscovery(DuplicatedObject* pPublisher, DOHandle hLocation);

		DOHandle GetLocation(DuplicatedObject* pDO);

		void IndicateDiscovery(DuplicatedObject* pPublisher, DuplicatedObject* pSubscriber);


	private:
		// This class is allowed to manipulate the list.
		//{secret}
		friend class DuplicationSpaceTable;
		void SetID(DupSpaceID id) {m_id=id;}

		// After a call to this method, the methods IsAPublisher,
		// Subscriber or Cell will return correct values, and the
		// CreatePublisherIterator, ... methods will also return
		// correct values.
		//{secret}
		void AddDOClassToFilter(DOFilter** ppFilter, DOClassID id);
		void InitFilter(DOFilter** ppFilter, Role iRole);
		void InitRelationToDOClasses();
		void DestroyRelationToDOClasses();

		DupSpaceID m_id;

		static DuplicationSpace* s_pFirstDupSpace;
		DuplicationSpace* m_pNextDupSpace;

		// An instance can be registered several times, if several
		// facades are used in a process.
		//{secret}
		int m_iNbRegistration;

		DOFilter *m_pfCellFilter;
		DOFilter *m_pfPublisherFilter;
		DOFilter *m_pfSubscriberFilter;
		DOFilter *m_pfPSFilter;

		// Match policy.
		//{secret}
		MatchOperationTriggers m_oLocalTriggers;
		
		bool m_bCellRequired;
		unsigned int m_uiPSRelation;
		unsigned int m_uiCellRelation;
};

//group=DDL Output

/*
description: Use this macro to generate the name of the base class from
which your own duplication space implementation inherits.

For example, if a duplicated object is declared in a DDL file as follows:

      dupspace InterestSpace;

The user-defined InterestSpace class is then declared as follows:

      class InterestSpace : public DUPSPACE(InterestSpace) {
          // User specific variables and methods including PSMatch definition
          virtual bool DuplicationSpace::PSMatch(DuplicatedObject * pPublisher, DuplicatedObject * pSubscriber) {
          	//User Implementation of PSMatch function for this space
          }
      };
*/
#define DUPSPACE(USERSPACE)	_DUPSPACE_##USERSPACE

#define DUPSPACEID(USERSPACE)	_DUPSPACE_##USERSPACE::GetDupSpaceID()

#define _DUPSPACE_DeclareGeneralMethods(SPACE)		\
	virtual const TCHAR* GetClassNameString();			\
	static DupSpaceID GetDupSpaceID();				\
	static SPACE* GetInstance();												

#define _DUPSPACE_ImplementGeneralMethods(SPACE)										\
    SPACE g_o##SPACE##Instance;															\
    const TCHAR* _DUPSPACE_##SPACE::GetClassNameString() {return _T(#SPACE);}					\
	DupSpaceID _DUPSPACE_##SPACE::GetDupSpaceID() {return g_o##SPACE##Instance.GetID();}	\
	SPACE* _DUPSPACE_##SPACE::GetInstance() {return (SPACE*)&g_o##SPACE##Instance;}

#define _DUPSPACE_NoUserCells()														\
	virtual bool CellMatch(DuplicatedObject* pPS, DuplicatedObject* pCell) {		\
		return DefaultCellMatch(pPS, pCell);										\
	}																				\
    virtual void CreateCells() {CreateDefaultCells();}								\
	virtual bool UsesDefaultCells() {return true;}

#endif
