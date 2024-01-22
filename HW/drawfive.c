# include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Max_value 10
int* scores=NULL;
struct node{
    int data;
    struct node* next;
};
struct node* top = NULL; 
int num_players=0;
//report an error
void fatal(char* msg){
    fprintf(stderr, "%s\n", msg);
    exit(EXIT_FAILURE);
}
//hint
void usage(){
    printf("drawfive <number of players> [list of cards]\n");
    
}
//populate card stack
void push(int value){
    struct node* n= malloc(sizeof(struct node));
    if (n==NULL){
        fatal("Unable to push data to a node\n");
    }
    n->data=value;
    n->next=top;
    top=n;
    
}
//pop the first card in stack
int pop(void){
    if (top){
        struct node* poped = top;
        int ret=poped->data;
        top = top->next;
        free(poped);
        return ret;
    }else{
    fatal("Error: Stack is empty!");}
    exit(1);
}
//fill the card stack with array of number
void fillStack(int argc, char** argv){
    
    for(int i = 2; i<argc; i++){
        int card = atoi(argv[i]);
        if(card<1||card>10){
            fatal("Card value not in range");
        }
    push(card);
    }
}
// fill card stack with random numbers
void fillStackWithRandomNumbers(int nPlayers){
    for(int i=0; i<nPlayers*5;i++){
        int card= (rand()%10)+1;
        push(card);
    }
    
}
// show stack for debug
void showStack(){
    struct node* show = top;
    while(show){
        printf("%d", show->data);
        show = show->next;
        printf("\n");

    }
}
// print each players score
void showScores(int nPlayers){
    for(int i=0;i<nPlayers;i++){
        printf("Player %d scored %d \n", i+1, scores[i]);
    }
}
// execute game
void runGame(int nPlayers){
    scores = (int*)calloc(nPlayers, sizeof(int));
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < nPlayers; j++) {
            int card = pop();
            scores[j] += card;
            printf("Player %d draws %d as %d of 5 cards\n", j + 1, card, i + 1);
        }
    }
}
// print winnier
void showWinners(int nPlayers){
    int max = -1;
    for (int i = 0; i < nPlayers; i++) {
        if (scores[i] > max) {
            max = scores[i];
        }
    }

    int winners[nPlayers];
    int numw = 0;
    for (int i = 0; i < nPlayers; i++) {
        if (scores[i] == max) {
            winners[numw] = i + 1;
            numw++;
        }
    }

    if (numw == 1) {
        printf("Player %d won with a score of %d\n", winners[0], max);
    } else if (numw == 2) {
        printf("Player %d and %d tied with a score of %d\n", winners[0], winners[1], max);
    } else {
        printf("Players ");
        for (int i = 0; i < numw - 1; i++) {
            printf("%d, ", winners[i]);
        }
        printf("and %d tied with a score of %d\n", winners[numw - 1], max);
    }
}
// avoid stack over flow
void freeStack() {
    while (top != NULL) {
        struct node* temp = top;
        top = top->next;
        free(temp);
    }
}
// main
int main( int argc, char* argv[]){

    
    int totplayers = atoi(argv[1]);
	srand(time(NULL));
    if(argc<2){
        usage();
        exit(EXIT_FAILURE);
    }
    
	else if(argc == 2){
		if(atoi(argv[1]) < 2){
			usage();
			fatal("         The number of players must be at least 2");
		}
		else{
			fillStackWithRandomNumbers(totplayers);
			runGame(totplayers);
            printf("\n");
            showScores(totplayers);
            printf("\n");
            showWinners(totplayers);
			free(scores);
			scores = NULL;
		}
	}else if(argc > 2){
		fillStack(argc, argv);
		runGame(totplayers);
        printf("\n");
        showScores(totplayers);
        printf("\n");
        showWinners(totplayers);
        free(scores);
        scores = NULL;
	}
    freeStack();
    free(scores);
    return EXIT_SUCCESS;
		
}

// type in this commond:"ulimit -s unlimited" after compile this program to pass the last test with 10million players