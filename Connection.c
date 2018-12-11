/*
 *  File name: Connection.c
 *
 *  Authors: Inês Lourenço	nº 75637
 * 			 Maria Casimiro nº 78755
 *
 *
 *  Description: C-Implementation of functions for type Connection
 *
 */


/* Header Inclusions                                              */
#include <stdio.h>
#include <stdlib.h>



/* Include Header File with Data Type and Function Prototypes     */
#include "Connection.h"
#include "LinkedList.h"


/*
 *  Data Type: ConnectionStruct
 *
 *  Description: Structure with:
 *                 1) Departure city
 *                 2) Arrival city
 *                 3) Type of transport used
 *                 4) Duration of the journey
 *                 5) Connection's cost
 *                 6) Time of the fisrt departure
 *                 7) Time of the last departure
 *                 8) Frequency of the transport
 */
struct ConnectionStruct
{
  int initCity;
  int destCity;
  int transport;
  int duration;
  int cost;
  int ti;
  int tf;
  int p;
  
};



/*
 *  Function:
 *    newConnection
 *
 *  Description:
 *    Initializes a new Connection.
 *
 *  Arguments:
 *    initCity
 *    destCity
 *    transport
 *    time
 *    cost
 *    ti
 *    tf
 *    p
 *
 *  Return value:
 *    Returns the pointer to the new connection in case of success, NULL
 *   otherwise.
 */
Connection * newConnection(int init, int dest, int vehicle, int time, 
							int price, int ti, int tf, int p)
{
  Connection * new;

  /* Memory allocation                                            */
  new = (Connection *) malloc(sizeof(Connection));

  /* Check memory allocation errors                               */
  if(new == NULL)
    return NULL;

  /* Fill in connection values                                         */
  new->initCity = init;
  new->destCity = dest;
  new->transport = vehicle;
  new->duration = time;
  new->cost = price;
  new->ti = ti;
  new->tf = tf;
  new->p = p;

  return new;
}



/*
 *  Function:
 *    getInitCityConnection
 *
 *  Description:
 *    Returns initCity of a Connection
 *
 *  Arguments:
 *    Pointer to connection:
 *      (Connection *) connection
 *
 *  Return value:
 *    initCity stored in the Connection
 */
int getInitCityConnection(Connection * connection)
{
  return connection->initCity;
}



int changeinitCityConnection (Connection * connection, int * t){
	
	return (connection->initCity = t);
}


/*
 *  Function:
 *    getDestCityConnection
 *
 *  Description:
 *    Returns destCity of a Connection
 *
 *  Arguments:
 *    Pointer to connection:
 *      (Connection *) connection
 *
 *  Return value:
 *    destCity stored in the Connection
 */
int getDestCityConnection(Connection * connection)
{
  return connection->destCity;
}


/*
 *  Function:
 *    getTransportConnection
 *
 *  Description:
 *    Returns transport a Connection
 *
 *  Arguments:
 *    Pointer to connection:
 *      (Connection *) connection
 *
 *  Return value:
 *    transport stored in the Connection
 */
int getTrasnportConnection(Connection * connection)
{
  return connection->transport;
}


/*
 *  Function:
 *    getDurationConnection
 *
 *  Description:
 *    Returns duration of a Connection
 *
 *  Arguments:
 *    Pointer to connection:
 *      (Connection *) connection
 *
 *  Return value:
 *    duration stored in the Connection
 */
int getDurationConnection(Connection * connection)
{
  return connection->duration;
}


/*
 *  Function:
 *    getCostConnection
 *
 *  Description:
 *    Returns cost of a Connection
 *
 *  Arguments:
 *    Pointer to connection:
 *      (Connection *) connection
 *
 *  Return value:
 *    cost stored in the Connection
 */
int getCostConnection(Connection * connection)
{
  return connection->cost;
}


/*
 *  Function:
 *    getTiConnection
 *
 *  Description:
 *    Returns ti of a Connection
 *
 *  Arguments:
 *    Pointer to connection:
 *      (Connection *) connection
 *
 *  Return value:
 *    ti stored in the Connection
 */
int getTiConnection(Connection * connection)
{
  return connection->ti;
}



/*
 *  Function:
 *    getTfConnection
 *
 *  Description:
 *    Returns tf of a Connection
 *
 *  Arguments:
 *    Pointer to connection:
 *      (Connection *) connection
 *
 *  Return value:
 *    tf stored in the Connection
 */
int getTfConnection(Connection * connection)
{
  return connection->tf;
}



/*
 *  Function:
 *    getPConnection
 *
 *  Description:
 *    Returns p of a Connection
 *
 *  Arguments:
 *    Pointer to connection:
 *      (Connection *) connection
 *
 *  Return value:
 *    p stored in the Connection
 */
int getPConnection(Connection * connection)
{
  return connection->p;
}



/*
 *  Function:
 *    printConnection
 *
 *  Description:
 *    Prints elements of a connection
 *
 *  Arguments:
 *    Pointer to connection:
 *      (Connection *) connection
 *
 *  Return value:
 *    None.
 */
void printConnection(Connection* connection){
	if(connection == NULL)
		return;
	else
		printf("%d %d %d %d %d %d %d %d\n", connection->initCity, connection->destCity,
									connection->transport, connection->duration,
									connection->cost, connection->ti, connection->tf,
									connection->p);
}




/*
 *  Function:
 *    freeConnection
 *
 *  Description:
 *    Frees the memory allocated to an connection
 *
 *  Arguments:
 *    Pointer to connection:
 *      (Connection *) connection
 *
 *  Return value:
 *    None.
 */
void freeConnection(Connection * connection)
{
  free(connection);
}
