#define NUM_ATTRIBUTES 18

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

/* Takes a data object, reads in an array of attributes and fills in the 
   attributes of the data object. Keeps track of how many attributes there are
*/
void fillInData(struct data* newData, char** tokenList, int numTokens);
