/*
 *  File name: Connection.h
 *
 *Authors: Inês Lourenço	nº 75637
 * 			Maria Casimiro	nº 78755
 *
 *  Description: Header file for type connection, definition and
 * functions.
 */


/* Prevent multiple inclusions                                      */
#ifndef ConnectionHeader
#define ConnectionHeader

typedef struct ConnectionStruct Connection;

Connection * newConnection(int init, int dest, int vehicle, int time, 
							int price, int ti, int tf, int p);

int getInitCityConnection(Connection * connection);

int getDestCityConnection(Connection * connection);

int getTrasnportConnection(Connection * connection);

int getDurationConnection(Connection * connection);

int getCostConnection(Connection * connection);

int getTiConnection(Connection * connection);

int getTfConnection(Connection * connection);

int getPConnection(Connection * connection);

void printConnection(Connection * connection);

void freeConnection(Connection * connection);


int changeinitCityConnection (Connection * connection, int t);

/* End of: Protect multiple inclusions                              */
#endif
