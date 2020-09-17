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


/* A record contains a data field, and PULocationID as a key */
struct record;

/* Each node contains a record, but also left, right and list pointers.
   The list pointers allow storage for duplicates. The listEnd pointer
   allows us to keep track of the end of the list. 
*/
struct node;

/* The data field contains all attributes of a record, stored as a string */
struct data;


/* Frees the memory used to make the binary search tree. Takes the root node
   of the tree as input 
*/
void freeTree(struct node* parent);

/* Takes the root of a BST and a new record as arguments. Inserts the new
   record into the BST in order, comparing the PULocationID as a key
*/
struct node* bstInsert(struct node* parent, struct record* record);

/* Print the BST in order, based on key. Useful when debugging */
void printBst(struct node* parent);

/* Free the data struct. Each attribute's malloc'd space should be freed */
void freeData(struct data* data);

/* Free the duplicate records attached to each node as a linked list */
void freeList(struct node* head);

/* Print the duplicate records attached to each node as a linked list */
void printList(struct node* head);