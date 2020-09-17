#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "readfile.h"

/* This function takes a filename in and reads the data. Each line in the file
   is presumed to be a record in a csv format, and is processed to extract the 
   information and fill in a new record struct. Once a new record is found, 
   then it is inserted into the BST according to its pickup date time. This
   function then returns the parent node of the whole BST that has been
   created from all these records in the csv file.
*/
struct node*
readfile(char* filename){
    // Open the file for reading
    FILE *file = fopen(filename, "r");
    assert(file);
	
	// Each line has a maximum length of 256 characters
    size_t buffersize = MAX_LENGTH;
    
    char* buffer = malloc(buffersize*sizeof(char));
	assert(buffer);
    
    int linenumber = 0;
	
	// Make a new root of a bst
    struct node* parent = NULL;
	
	// Keep retrieving lines
    while(getline(&buffer, &buffersize, file) != EOF){
		// For each line, represents a new record
        struct record* newRecord = (struct record*)malloc(sizeof(struct record));
		assert(newRecord);
        // We have a new record here, so process a line and fill in that record
        lineToRecord(buffer, newRecord);

		// Make an entry for the newRecord into the bst
		parent = bstInsert(parent, newRecord);

		// Keep track of which line we're up to in the file
        linenumber++;
    }
	

    // Free the malloc'd buffer
    free(buffer);

	// CLOSE THE FILE AS WE ARE DONE !
    fclose(file);
	return parent;
}