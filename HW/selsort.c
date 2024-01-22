#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "selsort.h"

int main(int argc, char** argv){
    struct dlList* list = makeEmptyList();
    if(argc<2){
        usage(argv[0]);
        exit(1);
    };

    if(strcmp(argv[1], "-s")==0){
        for(int i =2; i< argc; ++i){
            int value = atoi(argv[i]);
            appendNode(list, newUnconnectedNode(value));
        }
    }else{
        for(int i =1; i< argc; ++i){
            int value = atoi(argv[i]);
           
            appendNode(list, newUnconnectedNode(value));
    }
    }
    printf("Frwd:   ");
    printList(list->head);
    printListReversed(list);
     if (argc > 2 && strcmp(argv[1], "-s") == 0) {
        sortList(list);
        printf("Srtd:   ");
	    printList(list -> head);
    }

    freeList(list);
    return 0;
}
    


void usage(char* cmdName){
   printf("Usage: %s [-s] <space separated list of numbers>\n", cmdName);
}

// is_empty returns true if the passed in list is empty
//
bool isEmpty(struct dlList* dll){
    return dll->head == NULL;
}

// connect will connect the the two nodes passed in.
// Note that connect will not fail on empty nodes
// but will make all possible connections
// Think about this carefully!
//
void connect(struct node* prev, struct node* next){
    if (prev) prev->next = next;
    if (next) next->prev = prev;
}

// disconnect will disconnect a node by connecting 
// it's prev and next nodes together.
// Note that unlink will not fail on empty nodes
// Think about this carefully!
//
void disconnect(struct node* n){
    if(n->prev){
        n->prev->next=n->next;
    }
    if (n->next){
        n->next->prev=n->prev;
    }

}

// newUnconnectedNode will create a new node
// with the passed in value but will make no
// attempt to connect it to an existing list.
// This is on purpose for this assignment to
// help you make progress one piece at a time.
//
struct node* newUnconnectedNode(int value){
    struct node*node = malloc(sizeof(struct node));
    node->value = value;
    node->next = NULL;
    node->prev=NULL;
    return node;

}

// printList will print the list values inside
// of square brackets in a forward direction. See
// the examples below
//
void printList(struct node* head){
 
    printf("[ ");
    struct node*node=head;
    while(node!=NULL){
        printf ("%d ", node-> value);
        node = node->next;
    }
    printf("]\n");
}

// printListReversed will print the list values inside
// of square brackets in a backwards direction. See
// the examples below
//
void printListReversed(struct dlList* dll){
    struct node* temp = dll->tail;
    printf("Rrsd:   [ ");
    while(temp!=NULL){
        printf("%d ", temp->value);
        temp=temp->prev;
    }
    printf("]\n");
}

// findMinimum returns the node that contains
// the minimum value in the list referenced by
// head
// Note that it returns the node, not the value, 
// in addition, it does not unlink the node. Again
// this is on purpose to help you have granular 
// pieces to this puzzle.
//
struct node* findMinimum(struct dlList* dll){
   
    struct node* node=dll->head;
    struct node* min = node;
    while(node){
        if ( node->value < min->value){
            min=node;
        }
        node=node->next;
    }
    return min;
}

// sortList creates a sorted list. Note that it
// is destructive to the original list, however,
// it does not allocate new memory for the nodes, 
// it simply rearranges the existing nodes as 
// discussed in class today.  
//
void sortList(struct dlList* dll){
    struct dlList* sdll=makeEmptyList();	
	while(dll->head){
		struct node* min = findMinimum(dll);
		disconnect(min);
		if(dll->head==min){
			dll->head=min->next;
		}
		appendNode(sdll,min);
	}

	dll->head=sdll->head;
	dll->tail=sdll->tail;
	free(sdll);
}


// freeList will free all allocated memory for
// the list
//
void freeList(struct dlList* dll){
    struct node* current = dll->head;
    while (current) {
        struct node* next = current;
        current=current->next;
        free(next);
    }
    free(dll);
}


// makeEmptyList will return a list structure structure
// that does not contain any nodes
//
struct dlList* makeEmptyList(){
    struct dlList* dll=malloc(sizeof (struct dlList));
	dll->head=NULL;
	dll->tail=NULL;
	return dll;
}


// appendNode will append a given node to the given list
//
void appendNode(struct dlList* dll, struct node* n){
    if(isEmpty(dll)){
		dll->head=dll->tail=n;  // original empty
	}
	else{
		n->prev = dll->tail;
		dll->tail->next=n;
		dll->tail=n;
	}
}

