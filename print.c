#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "print.h"


/* Prints out the Binary Search Tree with records - DEBUGGING */
void
printBst(struct node* node){
    if(node != NULL){
        printBst(node->left);
		printRecord(node->record);
		printList(node->list);
		printBst(node->right);
    }
}

/* Prints out the details of a node's record, as well as any duplicates
   of that same record key. Each duplicate is stored as a linked list
   - DEBBUGGING
*/
void
printList(struct node* head){
	struct node* temp;
	while(head != NULL){
		temp = head;
		head = head->list;
		printRecord(temp->record);
	}
}

/* Prints out a specific record, and all of its attributes */
void
printRecord(struct record* record){
    printf("%s -->", record->pickUpKey);
    printf("VendorID: %s || ", record->data->vendorID);
    printf("passengercount: %s || ", record->data->passengerCount);
    printf("tripdistance: %s || ", record->data->tripDistance);
    printf("RatecodeID: %s || ", record->data->ratecodeID);
    printf("storeandfwdflag: %s || ", record->data->storeAndFwdFlag);
    printf("PULocationID: %s || ", record->data->PULocationID);
    printf("DOLocationID: %s || ", record->data->DOLocationID);
    printf("paymenttype: %s || ", record->data->paymentType);
    printf("fareamount: %s || ", record->data->fareAmount);
    printf("extra: %s || ", record->data->extra);
    printf("mtatax: %s || ", record->data->mtaTax);
    printf("tipamount: %s || ", record->data->tipAmount);
    printf("tollsamount: %s || ", record->data->tollsAmount);
    printf("improvementsurcharge: %s || ", record->data->improvementSurcharge);
    printf("totalamount: %s || ", record->data->totalAmount);
    printf("DOdatetime: %s || ", record->data->DODateTime);
    printf("tripduration: %s ||", record->data->tripDuration);
	printf("\n");
}