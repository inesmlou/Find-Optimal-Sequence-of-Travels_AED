/*************************************
 * 
 * File Name: istravel.c
 * 
 * Authors: Inês Lourenço	nº 75637
 * 			Maria Casimiro	nº 78755
 * 
 * DESCRIPTION
 * 
 * 
 * 
 * ***********************************/
 
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 
 #include "LinkedList.h"
 #include "Connection.h"
 #include "Client.h"
 #include "PQ.h"
 
 #define PLANE 1
 #define TRAIN 2 
 #define BOAT 3
 #define BUS 4
 
 #define TIME 1
 #define COST 2
 
 
 LinkedList ** readFile2LinkedList(FILE* fp, int* n_cities, int* n_connections){
	 
	 LinkedList ** graph;
	 Connection * connection;
	 LinkedList* node;
	 int i, k;
	 int initcity, destcity, time, carrier, cost, ti, tf, p;
	 char vehicle[10];
	
	/* determine number of cities and connections */
	fscanf(fp, "%d %d", n_cities, n_connections);
	
	/* allocate memory for linkedlist */
	graph = (LinkedList**)malloc((*n_cities)*sizeof(LinkedList*));
	if(graph == NULL){
		printf("Not enough space for graph\n");
		exit(-1);
	}
	/* initialize linkedlist */
	for(i = 0; i < (*n_cities); i++){
		graph[i] = initLinkedList();
	}
	
	/* insert connections */
	while(fscanf(fp, "%d %d %s %d %d %d %d %d",&initcity, &destcity, vehicle, &time, &cost, &ti, &tf, &p) == 8){
		if(strcmp(vehicle, "aviao") == 0)
			carrier = 1;
		else if(strcmp(vehicle, "comboio") == 0)
			carrier = 2;
			else if(strcmp(vehicle, "barco") == 0)
				carrier = 3;
				else if(strcmp(vehicle, "autocarro") == 0)
					carrier = 4;
		connection = newConnection(initcity, destcity, carrier, time, cost, ti, tf, p);
		graph[initcity] = insertLinkedList(graph[initcity], (Item)connection);
		graph[destcity] = insertLinkedList(graph[destcity], (Item)connection);
	}
	
	/* verify data */
	k = 0;
	for(i = 0; i < (*n_cities); i++){
		node = graph[i];
		while(node != NULL){
			printConnection((Connection*)getItemLinkedList(node));
			node = getNextNodeLinkedList(node);
			k++;
		}
	}
	printf("%d\n", k);
	
	return graph;
}
 

int shortPath(LinkedList ** graph, int n_cities, Client * client, Connection * connection, int st[], int wt[]){      /* int ?  */

	int v;
	//int tempo;
	int MaxDist=5000;
	Item t;
	
	PQInit(n_cities);
	for(v=0; v<n_cities; v++){
	
		st[v]=-1;
		wt[v]=MaxDist;   /*MAX DIST*/
		PQInsert(v+1);
		
	}
	wt[getDepCityClient(client)]=0;
	
	PQdec(getDepCityClient(client), wt);
	//tempo = getDepTime(client);
	while(!isEmpty()){
	
		if(wt[v=PQdelMin()] != MaxDist){
		
			for(t=graph[v]; t!=NULL; t=getNextNodeLinkedList(t)){
				
				if(getNRestrictions(client) ==0){
				
					if(getPreference(client) ==1){	/*tempo*/
					
						if(wt[getDestCityConnection((Connection*)getItemLinkedList(t))] > wt[getDestCityConnection((Connection*)getItemLinkedList(t))]+t){
						
							wt[getDestCityConnection((Connection*)getItemLinkedList(t))] = wt[getDestCityConnection((Connection*)getItemLinkedList(t))]+t;
							PQdec(getDestCityConnection((Connection*)getItemLinkedList(t)), wt);
							st[getDestCityConnection((Connection*)getItemLinkedList(t))]=v;
						}
					}else{			/*Custo*/
						
						if(wt[getDestCityConnection((Connection*)getItemLinkedList(t))] > wt[getDestCityConnection((Connection*)getItemLinkedList(t))] + getCostConnection(connection)){
								
							wt[getDestCityConnection((Connection*)getItemLinkedList(t))] = wt[getDestCityConnection((Connection*)getItemLinkedList(t))] + getCostConnection(connection);
							PQdec(getDestCityConnection((Connection*)getItemLinkedList(t)), wt);
							st[getDestCityConnection((Connection*)getItemLinkedList(t))] =v;				
						}
					}
				}
			}
		}
	}
}
	
int tempo_viagem(Client* client, Connection * connection){						
	
	int k=0;
	int t=0;
	
	while( k * getPConnection(connection) + getTiConnection(connection) < (getDepTime(client))){
		k++;
	}
	
	t= getTiConnection(connection)  + k * getPConnection(connection) - (getDepTime(client)) + getDurationConnection(connection);
	changeDepTime(client, t) ;
	
	return t;      /*novo tic*/
}									
									
							

 
 int main (int argc, char* argv[]){
	 
	 LinkedList** graph; /* graph with all the cities and connections */
	 FILE *map, *cli; /* input files */
	 
	 char *fileNameIn, *fileNameOut; /* names of the input and output files */
	 char *extOut = ".sol"; /* extension of the output file */
	 
	 int i; /* variable to use in cicles */
	 int n_cities; /* number of cities */
	 int n_connections; /* number of connections */
	 
	 
	 
	/* check number of arguments */
	if(argc < 2) {
		fprintf(stderr, "Not enough arguments.\n");
		exit(-1);
	}
	
	/* open input file .map and create data structure*/
	fileNameIn = argv[1];
	map = fopen(fileNameIn, "r");
	if(map == NULL){
		printf("Error opening .map file\n");
		exit(-1);
	}else{
		graph = readFile2LinkedList(map, &n_cities, &n_connections);
	}
	
	/* open input file .cli and create data structure*/
	fileNameIn = argv[2];
	cli = fopen(fileNameIn, "r");
	if(cli == NULL){
		printf("Error opening .cli file\n");
		exit(-1);
	}else{
		/*readFile2Vector();*/
	}
	
	
	/* allocate memory for fileNameOut */
	fileNameOut = (char*)malloc((strlen(fileNameIn)+1)*sizeof(char));
	if(fileNameOut == NULL){
		printf("Error: not enough memory for fileNameOut\n");
		exit(-1);
	}
	
	/* copy file .cli's name for output file */
	strncpy(fileNameOut, fileNameIn, strlen(fileNameIn)-4);
	fileNameOut[strlen(fileNameIn)-4] = '\0';
	strcat(fileNameOut, extOut);
	printf("%s\n", fileNameOut);
	
	
	
	/* close open files */
	fclose(map);
	fclose(cli);
	
	/* free allocated memory */
	free(fileNameOut);
	
	for(i = 0; i < n_cities; i++)
		freeLinkedList(graph[i]);
	free(graph);

	return 0;
}
