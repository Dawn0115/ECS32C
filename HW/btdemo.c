#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bintree.h"
void usage(char* cmdName){
	printf("Usage: %s <space separated list of numbers>\n", cmdName);
}

int main(int argc, char** argv){
    if(argc < 2){
		usage(argv[0]);
		exit(1);
	}
    struct node* root = newNode(atoi(argv[1]), NULL, NULL);
    printTree(root);
    printf("\n");
	for(int i = 2; i < argc; i++){
		insert(root, atoi(argv[i]));
		printTree(root);
		printf("\n");
	}
	printTreeReverse(root);
	printf("\n");
	for(int i = 1; i < argc; i++){
		printTree(root);
        printf("\n");
		root = delete(root, atoi(argv[i]));
	}
	return 0;
}

