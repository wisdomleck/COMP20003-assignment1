#define MAX_LENGTH 256

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

/* Converts a line entry in the csv file and fills in a new record object */
void lineToRecord(char* lineRead, struct record* newRecord);

/* Initialises a new node, and assigns a record to that node */
void initNewNodeFromRecord(struct node* newNode, struct record* record);

/* Prints the record's details - DEBUGGING */
void printRecord(struct record*); 

/* Given a tree's root and a new record to insert, creates a new node
   to house that record and inserts it in the BST according to its
   Pick Up Location date and time */
struct node* bstInsert(struct node* parent, struct record* record);
void freeTree(struct node* parent);