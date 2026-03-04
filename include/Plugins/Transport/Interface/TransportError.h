//  
//   (c) Copyright 1998-2001, Quazal
//   ALL RIGHTS RESERVED
//  
//  


#ifndef _TransportError_H_
#define _TransportError_H_

//Group = System Errors


/*
{Secret}
Not used.
*/
#define	TRANSPORT_SUCCESS					((unsigned long)0)

/*
{Secret}
Not used.
*/
#define	TRANSPORT_ERROR						((unsigned long)1)

/*
description:
A socket call has failed while trying to initialize the network.
*/
#define TRANSPORT_ERROR_CANNOT_INITIALIZE 	((unsigned long)2)

/*
{Secret}
Not used.
*/
#define TRANSPORT_ERROR_IO_ERROR 			((unsigned long)3)

/*
description:
The destination address could not be resolved.
*/
#define TRANSPORT_ERROR_COULD_NOT_CONNECT 	((unsigned long)4)

/*
description:
A send operation has failed due to the network connection being disconnected.
*/
#define	TRANSPORT_ERROR_NOT_CONNECTED		((unsigned long)5)

/*
{Secret}
Not used.
*/
#define TRANSPORT_ERROR_CONNECTED			((unsigned long)6)

/*
{Secret}
Not used.
*/
#define TRANSPORT_ERROR_INVALID_HANDLE		((unsigned long)7)

/*
description:
The buffer is too large to be sent.
*/
#define TRANSPORT_ERROR_BUFFER_OVERFLOW		((unsigned long)8)

/*
description:
The maximum number of listening ports has been reached.
*/
#define TRANSPORT_ERROR_INVALID_BUFFER		((unsigned long)9)

/*
description: The buffer is corrupted.
*/
#define TRANSPORT_ERROR_INVALID_MESSAGE		((unsigned long)10)

/*
description:
A packet received on the network is invalid.
*/
#define TRANSPORT_ERROR_INVALID_PACKET		((unsigned long)11)

/*
description:
The URL contained in the StationURL is invalid.  The syntax is incorrect.
*/
#define TRANSPORT_ERROR_INVALID_URL			((unsigned long)12)

/*
description:
The URL contained in the StationURL is invalid.  The syntax is incorrect.
*/
#define TRANSPORT_ERROR_INDEX_OUT_OF_RANGE	((unsigned long)13)

/*
description:
The URL contained in the StationURL is invalid.  The syntax is incorrect.
*/
#define TRANSPORT_ERROR_KEY_NOT_FOUND		((unsigned long)14)

/*
*/
#define TRANSPORT_ERROR_INVALID_TRANSPORT_TYPE ((unsigned long)15)

/*
description:
A StationURL was passed to a transport which does not match the transport type
specified by the URL.
*/
#define TRANSPORT_ERROR_NOT_READY			((unsigned long)16 )

/*
description:
The URL contained in the StationURL is invalid.  The syntax is incorrect.
*/
#define TRANSPORT_ERROR_TIMEOUT				((unsigned long)17	)

/*
description:
The URL contained in the StationURL is invalid.  The syntax is incorrect.
*/
#define TRANSPORT_ERROR_EVENT_HANDLER_REGISTERED	((unsigned long)18	)

/*
description:
The URL contained in the StationURL is invalid.  The syntax is incorrect.
*/
#define TRANSPORT_ERROR_NOT_INITIALIZED				((unsigned long)19	)

/*
description:
The URL contained in the StationURL is invalid.  The syntax is incorrect.
*/
#define TRANSPORT_ERROR_INVALID_PARAMETER			((unsigned long)20	)

/*
description:
The URL contained in the StationURL is invalid.  The syntax is incorrect.
*/
#define TRANSPORT_ERROR_CONNECTION_RESET			((unsigned long)21	)

/*
description:
The URL contained in the StationURL is invalid.  The syntax is incorrect.
*/
#define TRANSPORT_ERROR_INTERFACE_NOT_FOUND			((unsigned long)22	)

/*
description: The Station is already connected via another EndPoint.
*/
#define TRANSPORT_ERROR_DUPLICATE_END_POINT			((unsigned long)23)

#endif

