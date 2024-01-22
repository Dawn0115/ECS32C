//A program used to  replace all tabs in a file with arbitrary numbers of spaces
#include<stdio.h>
#include<stdlib.h>
//get how many space we want to use by argument
int main(int argc, char* argv[]){
    //transfer the argument from char to int
    int spaces=atoi(argv[1]);
    // a variable to itrate file
    char lt;
    while((lt=getchar()) != EOF){
        if(lt == '\t'){
            //use for loop to control amount of spaces we need
            for(int i=0;i<spaces;i++){
                putchar(' ');
            }
        } else{
            //move to another character
            putchar(lt);
        } 

    }
    return 0;
}
