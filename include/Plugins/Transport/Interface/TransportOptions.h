//  
//   (c) Copyright 1998-2000, Proksim Inc.
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _TransportOptions_H_
#define _TransportOptions_H_

//Group=Plug-ins

// Summary: The maximum buffer size that can be transmitted unreliably 
// by the transport.
#define TRANSPORT_OPTION_MTU					((unsigned long)0x1)

// Summary: The information that should represent the well-known contact point
// for connecting or listening, e.g. the static port number used by the 
// application for IP based protocols.
#define TRANSPORT_OPTION_WELLKNOWN_INFO		    ((unsigned long)0x2)


#define TRANSPORT_SPECIFIC_OPTIONS				((unsigned long)0x100)

#endif
