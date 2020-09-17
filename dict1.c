#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "dict1.h"

/* 
   Created by Alec Yu 993433 (alecy@student.unimelb.edu.au)
   
   This program reads in an input file of taxi records, provided by the
   New York City Taxi & Limousine Commission. This program reads the file
   in, and implements a dictinoary in the form of a Binary Search Tree.
   The key used to implement this is a taxi's Pick up date and time. 
   
   To run the program type into the command line:
   ./dict1 inputfile.csv outputfile.txt < keyfile
   
   Provided you have a dataset of records in a .csv format, as well as a 
   outputfile made. The program feeds in a keyfile, a list of keys to search
   for in the inputfile. The program then searches for and fetches records
   for that given key and writes it into the outputfile
   
*/

/* The main brains of the stage 1 functionality */
int
main(int argc, char* argv[]){
	// Before reading in the file, create a bst root node pointer
	struct node* bst = NULL;
	
    // The file that we want to read will be the first command line
	// argument, outputfile is the second command line argument
    char* filename = argv[1];
	char* outfilename = argv[2];
	
	// Read in the input file, and create a bst for all the records read in
    bst = readfile(filename);
	
	// Read in keys find the keys and count comparisons.
	
	readKeys(bst, outfilename);
	
	// We're done! FREE THE TREE
	freeTree(bst);
    return 0;
}

