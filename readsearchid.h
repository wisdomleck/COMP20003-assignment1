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

/* Read in a stream of input zoneIds to be checked for, from an idsfile.
   The input BST is searched in a in-order traversal, and findings are
   reported.
*/
void readIDs(struct node* root, char* filename);

/* Traverse the linked list to find a node for a zoneId match. */
void searchID(struct node* root, int zoneId, int* comparisons, FILE* outfilename, int* foundID);

/* As every node may have a duplicates linked list, check the given node for
   its zoneId, then traverse its linked list and check every node there
*/
void checkIdOfNode(struct node* node, int zoneId, int* comparisons, FILE* outfilename, int* foundID);