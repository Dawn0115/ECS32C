struct node{
    int value;
    struct node* prev;
    struct node* next;
};

struct dlList{
    struct node* head;
    struct node* tail;
};

// usage prints program usage with the correct command name
//
void usage(char* cmdName);

// is_empty returns true if the passed in list is empty
//
bool isEmpty(struct dlList* dll);

// connect will connect the the two nodes passed in.
// Note that connect will not fail on empty nodes
// but will make all possible connections
// Think about this carefully!
//
void connect(struct node* prev, struct node* next);

// disconnect will disconnect a node by connecting 
// it's prev and next nodes together.
// Note that unlink will not fail on empty nodes
// Think about this carefully!
//
void disconnect(struct node* n);

// newUnconnectedNode will create a new node
// with the passed in value but will make no
// attempt to connect it to an existing list.
// This is on purpose for this assignment to
// help you make progress one piece at a time.
//
struct node* newUnconnectedNode(int value);

// printList will print the list values inside
// of square brackets in a forward direction. See
// the examples below
//
void printList(struct node* head);

// printListReversed will print the list values inside
// of square brackets in a backwards direction. See
// the examples below
//
void printListReversed(struct dlList* dll);

// findMinimum returns the node that contains
// the minimum value in the list referenced by
// head
// Note that it returns the node, not the value, 
// in addition, it does not unlink the node. Again
// this is on purpose to help you have granular 
// pieces to this puzzle.
//
struct node* findMinimum(struct dlList* dll);

// sortList creates a sorted list. Note that it
// is destructive to the original list, however,
// it does not allocate new memory for the nodes, 
// it simply rearranges the existing nodes as 
// discussed in class today.  
//
void sortList(struct dlList* dll);

// freeList will free all allocated memory for
// the list
//
void freeList(struct dlList* dll);

// makeEmptyList will return a list structure structure
// that does not contain any nodes
//
struct dlList* makeEmptyList();

// appendNode will append a given node to the given list
//
void appendNode(struct dlList* dll, struct node* n);