#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* head = NULL; 

void push(int value){
    struct node* n= malloc(sizeof(struct node));
    if (n==NULL){
        fprintf(stderr, "Unable to push data to a node\n");
        exit(EXIT_FAILURE);

    }
    n->data=value;
    n->next=head;
    head=n;
}

int pop(struct node* head){
    if (head){
        struct node* n =head;
        head=head->next;
        int ret=n->data;
        free(n);
        return ret;
    }else{
        printf("Erro:Stack empty on");
        exit(1);
    }
}
