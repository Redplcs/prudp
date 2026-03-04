//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//

#ifndef _MatchOperationTriggers_H_
#define _MatchOperationTriggers_H_

#include <ObjDup/ObjDupDecl.h>
#include <Platform/Time.h>

class DuplicationSpace;

//Group = System Operations
/*
Description:
Specify the periodic matching behaviour of a DuplicationSpace via this class

Remarks: Use this class to specify the periodic match and relevance check behaviour of 
a duplication space.

See Also: DuplicationSpace
*/
class MatchOperationTriggers {
	public:
/*
Description: This class should not be instantiated directly. Use 
DuplicationSpace::GetLocalTriggers and DuplicationSpace::GetGlobalTriggers instead.

See Also: DuplicationSpace
*/
		MatchOperationTriggers();
/*
Description:
When $PRODUCTNAME$ destroys the DuplicationSpace it also destroys its triggers.
*/		
		~MatchOperationTriggers();

/*
Description:
This function enables the default matching activities of the duplication space.

Remarks:
The default trigger implies enabled periodic matching with a MatchPeriod of 250ms.
Enabled periodic match implies that DuplicationSpace::Match method is called periodically 
by $PRODUCTNAME$ with a time delay that you can set with EnablePeriodicMatch.    

See Also: DisableDefaultTriggers
*/
		void EnableDefaultTriggers();
		
/*
Description:
This function disables the default matching activities of the duplication space.

Remarks:
The default trigger implies enabled periodic matching with a MatchPeriod of 250ms.
Enabled periodic match implies that DuplicationSpace::Match method is called periodically 
by $PRODUCTNAME$ with a time delay that you can set with EnablePeriodicMatch. Disabling the 
default triggers also disables periodic match.

See Also: DisablePeriodicMatch
*/
		void DisableDefaultTriggers();

/*
Description:
Returns whether or not the default triggers are enabled.

Remarks:
The default trigger implies enabled periodic matching with a MatchPeriod of 250ms.
Periodic match implies that  DuplicationSpace::Match method is called periodically by 
$PRODUCTNAME$ with a time delay that you can set with EnablePeriodicMatch.    

See Also:
EnableDefaultTriggers, DisableDefaultTriggers, EnablePeriodicMatch
*/
		bool DefaultTriggersEnabled() const {return m_bDefaultTriggersEnabled;}
		
/*
Description:
Enables the periodic match activities of the DuplicationSpace.

Remarks:
Periodic match implies that DuplicationSpace::Match method is called periodically by 
$PRODUCTNAME$ with a time delay that you provide as a parameter.  The default trigger 
implies periodic matching is enabled with a MatchPeriod of 250ms.

Parameters:
tiPeriod:  the TimeInterval between consecutive DuplicationSpace::Match operations called by $PRODUCTNAME$

See Also: DuplicationSpace, DisablePeriodicMatch
*/
		void EnablePeriodicMatch(TimeInterval tiPeriod);

/*
Description:
Turns off the periodic DuplicationSpace::Match that is called by $PRODUCTNAME$ 

Remarks:
The  method DuplicationSpace::Match is called periodically by $PRODUCTNAME$ with a time delay that you
can set with EnablePeriodicMatch. DisablePeriodicMatch turns off this default periodic match activity.  

See Also: EnablePeriodicMatch		
*/
		void DisablePeriodicMatch();

/*
Description:
Returns whether or not the periodic DuplicationSpace::Match is enabled.

Return Value: true if the periodic matching activity for a DuplicationSpace is enabled, false if otherwise.
*/
		bool PeriodicMatchEnabled() const {return m_bPeriodicMatchEnabled;}
		
/*
Description:
Returns the TimeInterval between consecutive DuplicationSpace::Match operations performed periodically.

Remarks: The default MatchPeriod is 250ms.  Use the DisableDefaultTriggers method to turn off the default behaviour.

Return Value: The TimeInterval between consecutive DuplicationSpace::Match operations performed periodically.
*/
		TimeInterval GetMatchPeriod() const {return m_tiPeriod;}

		// {secret}
		bool PeriodicMatchRequired();

		// {secret}
		void ResetLastPeriodicMatch();

	private:
		bool m_bDefaultTriggersEnabled;

		bool m_bPeriodicMatchEnabled;
		TimeInterval m_tiPeriod;
		Time m_tLastPeriodicMatch;
};

#endif
