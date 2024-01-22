#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "bintree.h"
struct node* newNode(int value, struct node* left, struct node* right){
    struct node* node = malloc(sizeof(struct node));
    node -> value = value;
    node -> left = left;
    node -> right = right;
    return node;
}

struct node* leaf(int value){
    return newNode(value, NULL,NULL);
}
struct node* insert(struct node* t, int value){
    if(!t){
        return leaf(value);
    }
    if(value < t -> value)
		t -> left = insert(t -> left, value);
	if(value > t -> value)
		t -> right = insert(t -> right, value);
	return t;
}
struct node* delete(struct node* t, int value){
    if(!t){
        return t;
    }
    else if(value < t -> value) 
		t -> left = delete(t -> left, value);
	else if(value > t -> value) 
		t -> right = delete(t -> right, value);
	else if(value == t -> value){
		if(!(t -> left && t -> right)){
			struct node* subtree = t -> left ? t -> left : t -> right;
			free(t);
			return subtree;
		}else{
			t -> value = rightmostValue(t -> left);
			t -> left = delete(t -> left, t -> value);
		}
	}
	return t;
}

int rightmostValue(struct node* t){
    if(!t -> right)
		return t -> value;
	else
		return(rightmostValue(t -> right));
}
void freeNodes(struct node* n){
    if (n == NULL) {
        return;
    }
    freeNodes(n->left);
    freeNodes(n->right);
    free(n);

}
void printTree(struct node* t){
    if(!t){
        return;
    }
    printTree(t->left);
    printf("%d ", t -> value);
	printTree(t -> right);

}
void printTreeReverse(struct node* t){
 if(!t){
        return;
    }
    printTreeReverse(t -> right);
    printf("%d ", t -> value);
    printTreeReverse(t -> left);
}
