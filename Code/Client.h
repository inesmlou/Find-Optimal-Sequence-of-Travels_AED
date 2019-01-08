/*
 *  File name: Client.h
 *
 *Authors: Inês Lourenço	nº 75637
 * 			Maria Casimiro	nº 78755
 *
 *  Description: Header file for type client, definition and
 * functions.
 */


/* Prevent multiple inclusions                                      */
#ifndef ClientHeader
#define ClientHeader

typedef struct ClientStruct Client;

Client * newClient(int nClients, int depcity, int destcity, int time, 
							int choice, int n_restric, int restricA, int restricB,
							int paramA, int paramB);

int getNClients(Client * client);

int getDepCityClient(Client * client);

int getArrivalCityClient(Client * client);

int getDepTime(Client * client);

int getPreference(Client * client);

int getNRestrictions(Client * client);

int getRestrictionA(Client * client);

int getSpecA(Client * client);

int getRestrictionB(Client * client);

int getSpecB(Client * client);

void freeClient(Client * client);

int changeDepTime(Client *client, int t);

/* End of: Protect multiple inclusions                              */
#endif
