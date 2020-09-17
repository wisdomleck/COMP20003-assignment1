/* Attributes in the data field. The basic information of each taxi record */
struct data{
    char* vendorID;
    char* passengerCount;
    char* tripDistance;
    char* ratecodeID;
    char* storeAndFwdFlag;
    char* PULocationID;
    char* DOLocationID;
    char* paymentType;
    char* fareAmount;
    char* extra;
    char* mtaTax;
    char* tipAmount;
    char* tollsAmount;
    char* improvementSurcharge;
    char* totalAmount;
    char* PUDateTime;
    char* DODateTime;
    char* tripDuration;
};

/* Contains data, and also a key */
struct record{
    char* pickUpKey;
    struct data* data;
};

/* What we're inserting into the BST. Should have a record, and relevant
   pointers to branch off into a tree 
*/
struct node{
    struct record* record;
    struct node* left;
    struct node* right;
    struct node* list;
	struct node* listEnd;
};

/* Takes in a file name as input, reads that file. Then stores every record 
   read into a node, and insert that into a BST based on a key 
*/
struct node* readfile(char* filename);

/* Prints the details of a single record object - DEBUGGING*/
void printRecord(struct record*);

/* Print the whole binary search tree using in-order traversal - DEBUGGING*/
void printBst(struct node* parent);

/* Free the tree of its used memory */
void freeTree(struct node* parent);

/* Takes in a bst root, and a output file name. Call the program with a list
   of zoneIDs to search for. This function will read in those zoneIDs, then attempt
   to search them. The results will be written into the outputfile
*/
void readIDs(struct node* bst, char* outfilename);
