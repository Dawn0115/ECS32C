#include<stdio.h>
#include<stdlib.h>
struct node* list = NULL;

struct node {
 int value;
 struct node* next;
};

struct node* newNode(int value, struct node* next){
    struct node* node = malloc(sizeof(struct node));
    if(!node){
    return node;
    }
    node -> value = value;
    node -> next = next;
    return node;
}
struct node* prepend(struct node* next, int value){
 return newNode(value, list);
}
struct node* append(struct node* list, int value){
 if(!list){
  return newNode(value, list);
 }
 struct node* last = list;
 while(last -> next){
  last = last -> next;
 }
 last -> next = newNode(value, NULL); 

 return list;
}
void printList(struct node* list){
    while(list != NULL){
        printf("%d",list -> value);
        list = list -> next;
    }
}
int main(int argc, char** argv){
 list = newNode(3, newNode(5, newNode(7, NULL)));
 printList(list);
 list = prepend(list, 11);
 list = append(list, 15);
 printList(list);
}