//prims100.c is a program that is used to print out first 100 prims in order in a 10*10 table.
//auhtor: Yangcheng
#include <stdio.h>
//check whether a number is prime or not
int whether_prime(int N){
    for(int i=2; i<=N/2;i++){
        if(N%i==0)
            return 0;
        }
        return 1;
    }

int main(){
    int prime_arrary[100];
    int number = 2;
    int count=0;
// we need first 100 prims
    while (count<100){
        //if it is prime , we add this number to arrary
        if (whether_prime(number)){
            prime_arrary[count] = number;
        count=count+1;
        }
        number=number+1;
    }
    //Line up these 100 numbers neatly
    for(int i=0; i<100;i++){
        printf("%d\t",prime_arrary[i]);
        if((i+1)%10==0){
            printf("\n");
        }
    }
    return 0;

}
