#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "readsearchid.h"

/* This function takes a root of a bst in and the name of the outputfile. 
   After scanning in the Pick Up Zone Id's, each ID is searched for in the 
   Binary search tree, using in-order traversal. If a key is either found or
   not found, the result is written to the input file given in the command line
   argument. 
*/
void
readIDs(struct node* root, char* outfilename){
	int zoneId;
	int comparisons;
    // Open the file for reading
    FILE *outfile = fopen(outfilename, "w+");
    assert(outfile);
	
	// Flag to keep track of whether we have found the key or not
	int foundID = 0;
	
	// Scan the zone Id's in one by one
	while(scanf("%d\n", &zoneId) == 1){
		foundID = 0;
		comparisons = 0;
		// For each zone Id, search the BST if it exists or not
		searchID(root, zoneId, &comparisons, outfile, &foundID);
		printf("%d --> %d\n", zoneId, comparisons);
		if(!foundID){
			fprintf(outfile, "%d --> NOTFOUND\n", zoneId);
		}
	}
	
	// Close the file
	fclose(outfile);
    outfile = NULL;
}

/* Traverse the whole list. At every node, check if its ZoneID matches with
   the ID, and also check its list nodes.
*/
void
searchID(struct node* node, int zoneId, int* comparisons, 
						    FILE* outfilename, int* foundID) { 
    if(node != NULL){
        searchID(node->left, zoneId, comparisons, outfilename, foundID);
		
		//Check the node, and its list
		checkIdOfNode(node, zoneId, comparisons, outfilename, foundID);
		
		searchID(node->right, zoneId, comparisons, outfilename, foundID);
    }
} 

/* This function takes in a node and traverses its duplicates linked list
   to try find a match for an input zoneId. If a match occurs, a flag is
   set and it is reported into the outputfile. A counter for comparisons
   is also involved.
*/
void
checkIdOfNode(struct node* node, int zoneId, int* comparisons,
								 FILE* outfilename, int* foundID){
		struct node* temp = node;
		while(temp != NULL){
			// We're about to do a comparison!
			*comparisons += 1;
			// If the PULocationID of the node matches with the key, then should write it down
			if(atoi(temp->record->data->PULocationID) == (int)zoneId){
				*foundID = 1;
				fprintf(outfilename, "%d --> %s\n", zoneId, temp->record->pickUpKey);
			}
			
			temp = temp->list;
		}
	
}