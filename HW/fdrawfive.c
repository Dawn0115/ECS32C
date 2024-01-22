# include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define Max_value 10

const char* suits[] = {"Clubs","Diamonds","Spades","Hearts"};
const char* ranks[] = {"Ace","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Jack","Queen","King"};

struct card {
    char rank[7];
    char suit[9];
    int value;
};

int* scores=NULL;
struct node{
    struct card* data;
    struct node* next;
};
struct node* top = NULL; 
int num_players=0;
void fatal(char* msg){
    fprintf(stderr, "%s\n", msg);
    exit(1);
}
void usage(){
    printf("drawfive <number of players> [list of cards]\n");
    
}
void push(int value){
    struct node* n= malloc(sizeof(struct node));
    struct card* newcard = malloc(sizeof(struct card));
    if (n==NULL){
        fatal("Unable to push data to a node\n");
    }
    int suitindex=((value-1)/13);
    int rankindex=((value-1)%13);
    strcpy(newcard->rank, ranks[rankindex]);
    strcpy(newcard->suit, suits[suitindex]);
    newcard->value = rankindex + 1;
    n->data = newcard;
    n->next=top;
    top=n;


}
struct card* pop(void){
    if (top){
    
        struct node* popednode = top;
        struct card* popedcard = popednode->data;
        top = top->next;
        free(popednode);
        return popedcard;
    }else{
        fatal("Error: Stack is empty!");
        exit(1);
    }
}
void fillStack(int argc, char** argv){
    for(int i=2; i<argc;i++){
        if(i-1>atoi(argv[1])*5){
            fatal("Error: Stack is full!");
        }
        if(atoi(argv[i]) > 52 || atoi(argv[i]) < 1){
                  	fatal("Error: Invalid card index");
		}
        push(atoi(argv[i]));

    }
    
}
void fillStackWithRandomNumbers(int nPlayers){
    for(int i=0; i<nPlayers*5;i++){
        int card= (rand()%52)+1;
        push(card);
    }
    
}
void showStack(){
    struct node* show = top;
    while(show){
        struct card* showcard = show->data;
        printf("%d, %s, %s\n ", showcard -> value, showcard -> rank, showcard-> suit);
        show = show -> next;
        printf("\n");

    }
}

void showScores(int nPlayers){
    for(int i=0;i<nPlayers;i++){
        printf("Player %d scored %d \n", i+1, scores[i]);
    }
}

void runGame(int nPlayers){
    scores = (int*)calloc(nPlayers, sizeof(int));
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < nPlayers; j++) {
            struct card *card= pop();
            printf("Player %d draws %s of %s with value %d as %d of 5 cards\n", j+1, card -> rank, card -> suit, card -> value, i+1);
            scores[j]+=card->value;  
            free(card);
        }
    }
}

void showWinners(int nPlayers){
    int max = 0;
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
void freeStack() {
    while (top != NULL) {
        struct node* temp = top;
        top = top->next;
        free(temp->data);
        free(temp);
    }
}
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
			fatal("         The number of players must be greater than 2");
		}
		else{
			fillStackWithRandomNumbers(totplayers);
			runGame(totplayers);
            printf("\n");
            showScores(totplayers);
            printf("\n");
            showWinners(totplayers);
			free(scores);
            freeStack();
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
        freeStack();
        scores = NULL;
	}
    freeStack();
    free(scores);
    return EXIT_SUCCESS;
		
}