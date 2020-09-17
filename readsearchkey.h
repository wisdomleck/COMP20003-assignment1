#define MAX_KEY_LENGTH 21

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

struct record;
struct node;

/* Search the BST for a given key count comparisons */
struct node* searchKey(struct node* root, char* key, int* comparisons);

/* Write the information of the node and its duplicates list into the output
   file 
*/
void writeList(struct node* head, FILE* outfilename);

/* For a given record, write its information in the given format to the 
   output file 
*/
void writeRecord(struct record* record, FILE* outfilename);