#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "readsearchkey.h"

/* This function takes a root of a bst in and the name of the outputfile. 
   After scanning in the Pickup date times, each key is searched for in the 
   Binary search tree, using in-order traversal. If a key is either found or
   not found, the result is written to the input file given in the command line
   argument. 
*/
void
readKeys(struct node* root, char* filename){
	char key[MAX_KEY_LENGTH];
	int comparisons;
    // Open the file for reading
    FILE *outfile = fopen(filename, "w+");
    assert(outfile);
	
	
	// Keep track of the node in which we find a match for the key
	struct node* keyroot;
	
	// For every key scanned in, 
	while(scanf("%[^\n]\n", key) == 1){
		comparisons = 0;
		// Search the whole BST for the key
		if((keyroot = searchKey(root, key, &comparisons)) != NULL){
			// If we have found a match, write the details of that node and its 
			// Duplicates linked list into the outputfile and print comparisons
			writeList(keyroot, outfile);
			printf("%s --> %d\n", key, comparisons);
		}else{
			// Otherwise, we have not found a match in the BST :(
			fprintf(outfile, "%s --> NOTFOUND\n", key);
			// Still need comparisons!
			printf("%s --> %d\n", key, comparisons);
		} 
	}
	
	// Close the file
	fclose(outfile);
    outfile = NULL;
}

/* Searches the whole BST for the pick up date time key and then returns a node
   if it finds a match. Counts the number of comparisons at each step.
*/
struct node* 
searchKey(struct node* root, char* key, int* comparisons) { 
	*comparisons += 1;
    // Base Cases: root is null or key is present at root 
    if(root == NULL || !(strcmp(root->record->pickUpKey, key))){ 
		return root; 
	}
    // Key is greater than root's key 
    if(strcmp(root->record->pickUpKey, key) < 0){
		return searchKey(root->right, key, comparisons); 
	}
    // Key is smaller than root's key 
	return searchKey(root->left, key, comparisons); 
} 

/* For a given record, presumably a match, write all that record's information
   in the provided format into the outputfile 
*/

void
writeRecord(struct record* record, FILE* outfilename){
    fprintf(outfilename, "%s --> ", record->pickUpKey);
    fprintf(outfilename, "VendorID: %s || ", record->data->vendorID);
    fprintf(outfilename, "passenger_count: %s || ",
											record->data->passengerCount);
    fprintf(outfilename, "trip_distance: %s || ", record->data->tripDistance);
    fprintf(outfilename, "RatecodeID: %s || ", record->data->ratecodeID);
    fprintf(outfilename, "store_and_fwd_flag: %s || ", 
											record->data->storeAndFwdFlag);
    fprintf(outfilename, "PULocationID: %s || ", record->data->PULocationID);
    fprintf(outfilename, "DOLocationID: %s || ", record->data->DOLocationID);
    fprintf(outfilename, "payment_type: %s || ", record->data->paymentType);
    fprintf(outfilename, "fare_amount: %s || ", record->data->fareAmount);
    fprintf(outfilename, "extra: %s || ", record->data->extra);
    fprintf(outfilename, "mta_tax: %s || ", record->data->mtaTax);
    fprintf(outfilename, "tip_amount: %s || ", record->data->tipAmount);
    fprintf(outfilename, "tolls_amount: %s || ", record->data->tollsAmount);
    fprintf(outfilename, "improvement_surcharge: %s || ",
											record->data->improvementSurcharge);
    fprintf(outfilename, "total_amount: %s || ", record->data->totalAmount);
    fprintf(outfilename, "DOdatetime: %s || ", record->data->DODateTime);
    fprintf(outfilename, "trip_duration: %s ||", record->data->tripDuration);
	fprintf(outfilename, "\n");
}

/* If we find a node that matches with our key, we should check its duplicates
   list as well, as they will also have matches too
*/
void
writeList(struct node* head, FILE* outfilename){
	struct node* temp;
	while(head != NULL){
		temp = head;
		head = head->list;
		writeRecord(temp->record, outfilename);
	}
}