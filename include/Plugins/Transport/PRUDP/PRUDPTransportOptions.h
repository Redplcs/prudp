//  
//   (c) Copyright 1998-2000, Proksim Inc.
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _PRUDPTransportOptions_H_
#define _PRUDPTransportOptions_H_

#include <Plugins/Transport/Interface/TransportOptions.h>

//Group=Plug-ins

/*
Description: Defines the default broadcast behaviour for session LAN enumeration.
Remarks: If set to true, $PRODUCTNAME$ will broadcast on 255.255.255.255 instead
of broadcasting on adresses based on the adapter's broadcast address. 
This option uses the bool value of the UserContext parameter.
*/
#define PRUDP_BROADCAST_EVERYWHERE 				(TRANSPORT_SPECIFIC_OPTIONS)
/*
Description: Defines the maximum retransmission.
Remarks: Defines the maximum number of times a single packet will be retransmitted to a
remote station before it is assumed that the remote station is no longer connected. The default 
value is 20. This option uses the ulong value of the UserContext parameter.
*/
#define PRUDP_MAXRETRANSMISSION					(TRANSPORT_SPECIFIC_OPTIONS+1)	
/*
Description: Defines if the program will trap ICMP generated error messages.
Remarks: By default this option is set to true and the program will trap any generated ICMP 
error messages. This option uses the bool value of the UserContext parameter.
*/
#define PRUDP_TRAPICMPERRORS 					(TRANSPORT_SPECIFIC_OPTIONS+2)
/*
Description: Defines the maximum silence time.
Remarks: Defines the maximum time interval during which no signal is received from a particular station 
before it is assumed that the station is no longer connected. The default value is 5000 
milliseconds. This option uses the ulong value of the UserContext parameter.
*/
#define PRUDP_MAXSILENCETIME 					(TRANSPORT_SPECIFIC_OPTIONS+3)	
/*
Description: Defines the keep alive timeout. 
Remarks: Defines the maximum time allowed between signals sent to other users. If no signal is 
manually sent by the operator within the KeepAliveTimeout, then a signal will be sent 
automatically to all other users (peer stations) to let them know 
that your station is still operating. The default value is 1000 milliseconds.
This option uses the ulong value of the UserContext parameter.
*/
#define PRUDP_KEEPALIVETIMEOUT					(TRANSPORT_SPECIFIC_OPTIONS+4)	
/*
Description: Defines the timeslice.
Remarks: Defines the value of the timeslice, or round trip time, which is the time taken for a command 
to reach another user and the acknowledgement to be received by the sender. The default 
value is 250 milliseconds. This option uses the ulong value of the UserContext parameter.
*/
#define PRUDP_TIMESLICE 						(TRANSPORT_SPECIFIC_OPTIONS+5)
/*
Description: Defines the value of the window size of the reliable UDP protocol.
Remarks: This size represents the maximum number of packets that can be waiting for acknowledgement.
This option uses the ulong value of the UserContext parameter.
*/
#define PRUDP_WINDOW_SIZE	 					(TRANSPORT_SPECIFIC_OPTIONS+6)	


#endif
