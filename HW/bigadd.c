
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct int_node {
    int value;
    struct int_node *next;
};

void reporterror() {
    printf("bignum <operand one> <operand two>\n");
    exit(1);
}



struct int_node* push(struct int_node *stack, int value) {
  
    struct int_node *node = malloc(sizeof(struct int_node));
    if (node == NULL) {
        reporterror();
    }
    node->value = value;
    node->next = stack;
    return node;
}
int GetVal(struct int_node* stack){
	return stack->value;
}

struct int_node* Buildstack(char *number) {
    struct int_node *numstack = NULL;
    for (int i=0 ;i<=strlen(number)-1; i++) {
        numstack = push(numstack, number[i] - '0');
    }
    return numstack;
}

struct int_node* pop(struct int_node* stack){
	struct int_node* node = stack;
	stack = stack->next;
	free(node);
	return stack;
}


struct int_node* num(struct int_node* num1, struct int_node* num2, struct int_node* stack){
    int carry = 0;
    struct int_node* result = stack;
    while (num1 != NULL || num2 != NULL || carry) {
        int value1 = 0, value2 = 0;
        if (num1 != NULL) {
            value1 = num1->value;
            num1 = pop(num1);
        }
        if (num2 != NULL) {
            value2 = num2->value;
            num2 = pop(num2);
        }

        int sum = value1 + value2 + carry;
        carry = sum / 10;
        result = push(result, sum % 10);
    }

    return result;
}
void PrintList(struct int_node* stack){
	struct int_node* tmp = stack;
	while(tmp->next){
		printf("%d",GetVal(tmp));
		tmp = pop(tmp);
	}
	printf("\n");
	tmp = pop(tmp);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        reporterror();
    }
    
    struct int_node *num1 = Buildstack(argv[1]);
    struct int_node *num2 = Buildstack(argv[2]);
    struct int_node* result = malloc(sizeof(struct int_node));
	result -> value = 0;
	result -> next = NULL;
    result = num(num1, num2,result);
    PrintList(result);
    return 0;
}
