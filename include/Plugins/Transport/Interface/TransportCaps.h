//  
//   (c) Copyright 1998-2000, Proksim Inc.
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _TransportCaps_H_
#define _TransportCaps_H_

//Group=Plug-ins

// Summary: The transport should return true if it is an IP based protocol and
// supports contruction of a URL using an IP address and a port number.
#define TRANSPORT_CAPS_IP_BASED						0x1

// Summary: The transport should return true if it is capable of doing network
// broadcasts.
#define TRANSPORT_CAPS_BROADCAST					0x2

// Summary: The transport should return true if it is implementing device emulation
// using the EmulationDevice class provided in the transport interface.
#define TRANSPORT_CAPS_DEVICE_EMULATION				0x3

// Summary: The transport should return true if it is implementing perfomance counting
// using the TransportPerfCounters class provided in the transport interface.
#define TRANSPORT_CAPS_PERF_COUNTERS				0x4

// Summary: The transport should return true if it is supporting EndPoint grouping.
#define TRANSPORT_CAPS_GROUPING						0x5

// Summary: The transport should return true if it supports listening on a well-known 
//contact point, e.g. a static port number for IP based protocols.
#define TRANSPORT_CAPS_WELLKNOWN_LISTEN_SUPPORTED		0x6

// Summary: The transport should return true if it supports listening to an
// arbitrary contact point, e.g. dynamic port numbers for IP based protocols.
#define TRANSPORT_CAPS_ARBITRARY_LISTEN_SUPPORTED		0x7

#endif
