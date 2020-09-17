#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "bst.h"

/* Takes the root of a BST and a new record as arguments. Inserts the new
   record into the BST in order, comparing the PULocationID as the key.
   Algorithm was inspired by the Week 4 Workshop material from the University
   Of Melbourne, in COMP20003 Algorithms and Data Structures.
*/
struct node *bstInsert(struct node *parent, struct record* record){
	// Keep track of where to insert the new record
    struct node **insertLocation = &parent;

    while(*insertLocation){
		// If record is lesser, so should go left and look for space to insert
        if(strcmp(record->pickUpKey, 
									(*insertLocation)->record->pickUpKey) < 0 ){
            insertLocation = &((*insertLocation)->left);
        }
		// If record is bigger, so should go right and look for space to insert
        else if (strcmp(record->pickUpKey,
									(*insertLocation)->record->pickUpKey) > 0){
            insertLocation = &((*insertLocation)->right);
        }
		// Otherwise means record is equal, should start linked list for duplicate
		else{
			// Case of no linked list (duplicates) started yet. Should initialise LL
			if((*insertLocation)->list == NULL){
				// Malloc the new node and initialise values
				struct node* temp = (struct node*)malloc(sizeof(struct node));
				assert(temp);
				temp->left = NULL;
				temp->right = NULL;
				temp->list = NULL;
				temp->listEnd = NULL;
				temp->record = record;

				// Start the linked list, starting from the original node
				(*insertLocation)->list = temp;
				(*insertLocation)->listEnd = temp;
			}
			// Case of a linked list already existing. Append to end and repoint listEnd
			else{
				// Malloc the new node and initialise values
				struct node* temp = (struct node*)malloc(sizeof(struct node));
				assert(temp);
				temp->left = NULL;
				temp->right = NULL;
				temp->list = NULL;
				temp->listEnd = NULL;
				temp->record = record;

				// Continue the linked list, append to end and reassign listEnd
				(*insertLocation)->listEnd->list = temp;
				(*insertLocation)->listEnd = temp;

			}
			return parent;
		}
    }

	// If no duplicate is found, then we should insert the record
    *insertLocation = (struct node *) malloc(sizeof(struct node));
    assert(*insertLocation);

	// Initialise the node's values, assign the new record
    (*insertLocation)->left = NULL;
    (*insertLocation)->right = NULL;
    (*insertLocation)->record = record;
	(*insertLocation)->list = NULL;
	(*insertLocation)->listEnd = NULL;
    return parent;
}

/* Frees the memory used to make the binary search tree. Takes the root node
   of the tree as input. Uses a post-order traversal
*/
void freeTree(struct node* parent){
    if(!parent){
        return;
    }
    // Go left, then right before freeing
    freeTree(parent->left);
    freeTree(parent->right);

	// For each node, free the data, then free the whole record
	// and then the  duplicates list, then itself
    freeData(parent->record->data);
	free(parent->record->data);
	free(parent->record);
	freeList(parent->list);
	free(parent);
}

/* Free the duplicate records attached to each node as a linked list. If
   there are no duplicates attached to the node, should do nothing
*/
void
freeList(struct node* head){
	struct node* temp;
	// Traverse the linked list
	while(head != NULL){
		temp = head;
		head = head->list;
		// Free the node thoroughly
		freeData(temp->record->data);
		free(temp->record->data);
		free(temp->record);
		free(temp);
	}
}

/* Free the data struct. Each attribute's malloc'd space should be freed */
void freeData(struct data* data){
	free(data->vendorID);
	free(data->passengerCount);
	free(data->tripDistance);
	free(data->ratecodeID);
	free(data->storeAndFwdFlag);
	free(data->PULocationID);
	free(data->DOLocationID);
	free(data->paymentType);
	free(data->fareAmount);
	free(data->extra);
	free(data->mtaTax);
	free(data->tipAmount);
	free(data->tollsAmount);
	free(data->improvementSurcharge);
	free(data->totalAmount);
	free(data->PUDateTime);
	free(data->DODateTime);
	free(data->tripDuration);
}
