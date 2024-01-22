#include <stdio.h>
#include <stdlib.h>

struct node{
    int num;
    int den;
    struct node* next;
};

struct node* makeFareyNode(int num, int den, struct node* next){
    struct node* node = malloc(sizeof(struct node));
    node->num=num;
    node->den=den;
    node->next=next;
    return node;
}

void freeup(struct node* head){
    struct node* node;
    while(head){
        node=head;
        head=head->next;
        free(node);
    }
}

void geneFareySequn(int n){
    struct node* head =makeFareyNode(0,1,NULL);
    head->next=makeFareyNode(1,1,NULL);

    for(int i=1;i<n+1;++i){
        struct node* now =head;
        while(now->next!=NULL){
            int a = now->num + now->next->num;
            int b = now->den + now->next-> den;
            if(b==i){
                struct node* node=makeFareyNode(a,b,now->next);
                now->next=node;
            }
            now=now->next;
        }
        struct node* node=head;
            printf("(");
             while(node->next!=NULL){
                printf("%d/%d, ", node->num, node->den);
                node=node->next;
            }
            printf("%d/%d)", node->num, node->den);
    printf("\n");

    
    }
    freeup(head);
}

int main(int argc, char *argv[]){
    if(argc!=2){
        printf("Usage: farey <n> \n       where n >= 1 is the level of the Farey sequence.");
        exit(1);
    }
    int n=atoi(argv[1]);
    if(n<1){
        printf("ERROR: invalid input");
        exit(1);
    }
    geneFareySequn(n);
    return(0);

}