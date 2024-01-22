//A program used to calculate lines,spaces and tabs in a c file
#include<stdio.h>

int main(void){
    //intiate three varibles to count times.
    char c;
    int lines = 0, tabs = 0, spaces = 0;

    while((c = getchar()) != EOF) {
        if(c == '\n') {
            lines++;
        } 
        if(c == '\t') {
            tabs++;
        } 
        if(c == ' ') {
            spaces++;
        }
    }

    printf("Lines : %d\n", lines);
    printf("Tabs : %d\n", tabs);
    printf("Spaces : %d\n", spaces);

    return 0;
}
