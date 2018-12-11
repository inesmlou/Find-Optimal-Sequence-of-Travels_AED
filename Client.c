/*
 *  File name: Client.c
 *
 *  Authors: Inês Lourenço	nº 75637
 * 			 Maria Casimiro nº 78755
 *
 *
 *  Description: C-Implementation of functions for type Client
 *
 */


/* Header Inclusions                                              */
#include <stdio.h>
#include <stdlib.h>



/* Include Header File with Data Type and Function Prototypes     */
#include "Client.h"



/*
 *  Data Type: ClientStruct
 *
 *  Description: Structure with:
 *                 1) Number of client
 *                 2) Departure city
 *                 3) Arrival city
 *                 4) Departure availability time
 *                 5) Client's preference: time or cost
 *                 6) Numer of restrictions
 *                 7) Type of restriction A
 *                 8) Specification of the restriction A
 *                 9) Type of restriction B
 *                10) Specification of the restriction B
 */
struct ClientStruct
{
  int n_clients;
  int depCity;
  int arrivalCity;
  int depTime;
  int preference;
  int n_restrictions;
  int restrictionA;
  int specA;
  int restrictionB;
  int specB;
};



/*
 *  Function:
 *    newClient
 *
 *  Description:
 *    Initializes a new Client.
 *
 *  Arguments:
 *    nClients
 *    depcity
 *    destcity
 *    time
 *    choice
 *    n_restrict
 *    restrictA
 *    restrictB
 *    paramA
 *    paramB
 *
 *  Return value:
 *    Returns the pointer to the new client in case of success, NULL
 *   otherwise.
 */
Client * newClient(int nClients, int depcity, int destcity, int time, 
				int choice, int n_restric, int restricA, int restricB,
							int paramA, int paramB)
{
  Client * new;

  /* Memory allocation                                            */
  new = (Client *) malloc(sizeof(Client));

  /* Check memory allocation errors                               */
  if(new == NULL)
    return NULL;

  /* Fill in connection values                                    */
  new->n_clients = nClients;
  new->depCity = depcity;
  new->arrivalCity = destcity;
  new->depTime = time;
  new->preference = choice;
  new->n_restrictions = n_restric;
  new->restrictionA = restricA;
  new->specA = paramA;
  new->restrictionB = restricB;
  new->specB = paramB;

  return new;
}



/*
 *  Function:
 *    getNClients
 *
 *  Description:
 *    Returns the number of clients
 *
 *  Arguments:
 *    Pointer to client:
 *      (Client*) client
 *
 *  Return value:
 *    number of clients stored in the Client
 */
int getNClients(Client * client)
{
  return client->n_clients;
}



/*
 *  Function:
 *    getDepCityClient
 *
 *  Description:
 *    Returns departure city of a Client
 *
 *  Arguments:
 *    Pointer to client:
 *      (Client *) client
 *
 *  Return value:
 *    depCity stored in the Client
 */
int getDepCityClient(Client * client)
{
  return client->depCity;
}


/*
 *  Function:
 *    getArrivalCityClient
 *
 *  Description:
 *    Returns transport a Client
 *
 *  Arguments:
 *    Pointer to client:
 *      (Client *) client
 *
 *  Return value:
 *    arrivalCity stored in the Client
 */
int getArrivalCityClient(Client * client)
{
  return client->arrivalCity;
}


/*
 *  Function:
 *    getDepTime
 *
 *  Description:
 *    Returns depTime of a Client
 *
 *  Arguments:
 *    Pointer to client:
 *      (Client *) client
 *
 *  Return value:
 *    depTime stored in the Client
 */
int getDepTime(Client * client)
{
  return client->depTime;
}


/*
 *  Function:
 *    getPreference
 *
 *  Description:
 *    Returns preference of a Client
 *
 *  Arguments:
 *    Pointer to client:
 *      (Client *) client
 *
 *  Return value:
 *    preference stored in the Client
 */
int getPreference(Client * client)
{
  return client->preference;
}

/*
 *  Function:
 *    getNRestrictions
 *
 *  Description:
 *    Returns n_restrictions of a Client
 *
 *  Arguments:
 *    Pointer to client:
 *      (Client *) client
 *
 *  Return value:
 *    n_restrictions stored in the Client
 */
int getNRestrictions(Client * client)
{
  return client->n_restrictions;
}

/*
 *  Function:
 *    getrestrictionA
 *
 *  Description:
 *    Returns restrictionA of a Client
 *
 *  Arguments:
 *    Pointer to client:
 *      (Client *) client
 *
 *  Return value:
 *    restrictionA stored in the Client
 */
int getRestrictionA(Client * client)
{
  return client->restrictionA;
}


/*
 *  Function:
 *    getSpecA
 *
 *  Description:
 *    Returns specA of a Client
 *
 *  Arguments:
 *    Pointer to client:
 *      (Client *) client
 *
 *  Return value:
 *    specA stored in the Client
 */
int getSpecA(Client * client)
{
  return client->specA;
}

/*
 *  Function:
 *    getRestrictionB
 *
 *  Description:
 *    Returns restrictionB of a Client
 *
 *  Arguments:
 *    Pointer to client:
 *      (Client *) client
 *
 *  Return value:
 *    restrictionB stored in the Client
 */
int getRestrictionB(Client * client)
{
  return client->restrictionB;
}

/*
 *  Function:
 *    getSpecB
 *
 *  Description:
 *    Returns specB of a Client
 *
 *  Arguments:
 *    Pointer to client:
 *      (Client *) client
 *
 *  Return value:
 *    specB stored in the Client
 */
int getSpecB(Client * client)
{
  return client->specB;
}


int changeDepTime(Client *client, int t){
	
	return (client->depTime=t);
}
/*
 *  Function:
 *    freeClient
 *
 *  Description:
 *    Frees the memory allocated to a client
 *
 *  Arguments:
 *    Pointer to client:
 *      (Client *) client
 *
 *  Return value:
 *    None.
 */
void freeClient(Client * client)
{
  free(client);
}
