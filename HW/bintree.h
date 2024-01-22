#ifndef BINTREE_H
#define BINTREE_H

struct node {
    int value;
    struct node* left;
    struct node* right;
};

struct node* newNode(int value, struct node* left, struct node* right);
struct node* leaf(int value);
struct node* insert(struct node* t, int value);
struct node* delete(struct node* t, int value);

int rightmostValue(struct node* t);
void freeNodes(struct node* n);
void printTree(struct node* t);
void printTreeReverse(struct node* t);

#endif