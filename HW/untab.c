#include<stdio.h>
#include<stdlib.h>
int main(int argc, char* argv[]){
    int tabs_needed;
    //check number of arguments
    if(argc != 2){
        return 1; 
    }
    //use atoi to transer in argument to a integer stored in tabs_needed
    tabs_needed = atoi(argv[1]);
    if(tabs_needed<=0 || tabs_needed>12){
        return 1;
    }
    //use a variable to store the current character
    int a;
    int pos=0;
    while ((a = getchar()) != EOF){
        //when we meet a tab
        if( a == '\t'){
            int space = tabs_needed-(pos%tabs_needed);
            for(int i=0; i<space;i++){
                putchar(' ');
                pos++;
            }
            //move the current position backward as how much spaces added
        
        //when we didnot encounter a tab
        }else{
            putchar(a);
            pos = pos + 1;
            //reset the position of character
            if (a == '\n') {
                pos = 0;
              }
        }
    }
    return 0;
}








