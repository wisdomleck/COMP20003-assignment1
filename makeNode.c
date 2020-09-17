#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "makeNode.h"


/* This function takes in a line (record) from the csv file and turns fills in
   a record with this line of information. The record that will have the data 
   filled in will be input into this function.
*/
void
lineToRecord(char* lineread, struct record* newRecord){
    // Malloc space for the data struct pointer in record. For each record, there is a data field
    struct data* newData = (struct data*)malloc(sizeof(struct data));
    assert(newData);
    
    // Store all the tokens in an array
    char* tokenList[NUM_ATTRIBUTES];
    int tokenNum = 0;
    
    // Start slicing the lineRead by the comma, then storing each element
	// in the array.
    char* token;
    token = strtok(lineread, ",");
	
    while(token != NULL){
		// Malloc a tokencopy, which will store the space of a token 
		// and extra space for a nullbyte at the end to terminate the token
		char* tokencopy = (char*)malloc(strlen(token) + 1);
		assert(tokencopy);
		strcpy(tokencopy, token);
		tokencopy[strlen(token)] = '\0';
		
		// Now add to array, and consider the next token
        tokenList[tokenNum] = tokencopy;
        tokenNum++;
        token = strtok(NULL, ",\n");
		
    }
    
    // Here, tokenList is of size 18, having all the attributes, 
	// each with a token for each attribute, in order. Fill in data
    fillInData(newData, tokenList, tokenNum);
    
    // Let the record hold the filled in data
    newRecord->data = newData;
    
    // Set the key
    newRecord->pickUpKey = newRecord->data->PUDateTime;
	
}

/* Takes a data object, reads in an array of attributes and fills in the 
   attributes of the data object. Keeps track of how many attributes there are.
   Each attribute of the data object will have their own memory allocated.
*/
void fillInData(struct data* newData, char** tokenList, int numTokens){
    int tokenNum = 0;
    //vendorID
	newData->vendorID = (char*)malloc(sizeof(char)*strlen(tokenList[tokenNum]) + 1);
	assert(newData->vendorID);
    strcpy(newData->vendorID, tokenList[tokenNum]);
    tokenNum++;
    
    //passengerCount
    newData->passengerCount = (char*)malloc(sizeof(char)*strlen(tokenList[tokenNum]) + 1);
	assert(newData->passengerCount);
    strcpy(newData->passengerCount, tokenList[tokenNum]);
    tokenNum++;
    
    //tripDistance
    newData->tripDistance = (char*)malloc(sizeof(char)*strlen(tokenList[tokenNum]) + 1);
	assert(newData->tripDistance);
    strcpy(newData->tripDistance, tokenList[tokenNum]);
    tokenNum++;
    
    //ratecodeID
    newData->ratecodeID = (char*)malloc(sizeof(char)*strlen(tokenList[tokenNum]) + 1);
	assert(newData->ratecodeID);
    strcpy(newData->ratecodeID, tokenList[tokenNum]);
    tokenNum++;
    
    //storeAndFwdFlag
    newData->storeAndFwdFlag = (char*)malloc(sizeof(char)*strlen(tokenList[tokenNum]) + 1);
	assert(newData->storeAndFwdFlag);
    strcpy(newData->storeAndFwdFlag, tokenList[tokenNum]);
    tokenNum++;
    
    //PULocationID
    newData->PULocationID = (char*)malloc(sizeof(char)*strlen(tokenList[tokenNum]) + 1);
	assert(newData->PULocationID);
    strcpy(newData->PULocationID, tokenList[tokenNum]);
    tokenNum++;
    
    //DOLocationID
    newData->DOLocationID = (char*)malloc(sizeof(char)*strlen(tokenList[tokenNum]) + 1);
	assert(newData->DOLocationID);
    strcpy(newData->DOLocationID, tokenList[tokenNum]);
    tokenNum++;
    
    //paymentType
    newData->paymentType = (char*)malloc(sizeof(char)*strlen(tokenList[tokenNum]) + 1);
	assert(newData->paymentType);
    strcpy(newData->paymentType, tokenList[tokenNum]);
    tokenNum++;
    
    //fareAmount
    newData->fareAmount = (char*)malloc(sizeof(char)*strlen(tokenList[tokenNum]) + 1);
	assert(newData->fareAmount);
    strcpy(newData->fareAmount, tokenList[tokenNum]);
    tokenNum++;
	
    //extra
    newData->extra = (char*)malloc(sizeof(char)*strlen(tokenList[tokenNum]) + 1);
	assert(newData->extra);
    strcpy(newData->extra, tokenList[tokenNum]);
    tokenNum++;
    
    //mtaTax
    newData->mtaTax = (char*)malloc(sizeof(char)*strlen(tokenList[tokenNum]) + 1);
	assert(newData->mtaTax);
    strcpy(newData->mtaTax, tokenList[tokenNum]);
    tokenNum++;
    
    //tipAmount
    newData->tipAmount = (char*)malloc(sizeof(char)*strlen(tokenList[tokenNum]) + 1);
	assert(newData->tipAmount);
    strcpy(newData->tipAmount, tokenList[tokenNum]);
    tokenNum++;
    
    //tollsAmount
    newData->tollsAmount = (char*)malloc(sizeof(char)*strlen(tokenList[tokenNum]) + 1);
	assert(newData->tollsAmount);
    strcpy(newData->tollsAmount, tokenList[tokenNum]);
    tokenNum++;
	
    //improvementSurcharge
    newData->improvementSurcharge = (char*)malloc(sizeof(char)*strlen(tokenList[tokenNum]) + 1);
	assert(newData->improvementSurcharge);
    strcpy(newData->improvementSurcharge, tokenList[tokenNum]);
    tokenNum++;
    
    //totalAmount
    newData->totalAmount = (char*)malloc(sizeof(char)*strlen(tokenList[tokenNum]) + 1);
	assert(newData->totalAmount);
    strcpy(newData->totalAmount, tokenList[tokenNum]);
    tokenNum++;
        
    //PUDateTime
    newData->PUDateTime = (char*)malloc(sizeof(char)*strlen(tokenList[tokenNum]) + 1);
	assert(newData->PUDateTime);
    strcpy(newData->PUDateTime, tokenList[tokenNum]);
    tokenNum++;
    
    //DODateTime
    newData->DODateTime = (char*)malloc(sizeof(char)*strlen(tokenList[tokenNum]) + 1);
	assert(newData->DODateTime);
    strcpy(newData->DODateTime, tokenList[tokenNum]);
    tokenNum++;
    
    //tripDuration
    newData->tripDuration = (char*)malloc(sizeof(char)*strlen(tokenList[tokenNum]) + 1);
	assert(newData->tripDuration);
    strcpy(newData->tripDuration, tokenList[tokenNum]);
    tokenNum++;
	
	//Free the token list
	for(int i = 0; i < tokenNum; i++){
		free(tokenList[i]);
	}
}

/* Given a new node, initialise the fields of the newnode. Each new node
   should point to a record
*/
void
initNewNodeFromRecord(struct node* newNode, struct record* record){
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->list = NULL;
	newNode->record = record;
}