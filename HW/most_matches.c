//most_maches.c is used to check which is the most frequent letter that in first sentence appears in firsr sentence

#include<stdio.h>
#include<string.h>

int main(int argc, char* argv[]){
    //get the length of two arguments
    char* str1 = argv[1];
    char* str2 = argv[2];
    int len1=strlen(str1);
    int len2 = strlen(str2);
    
    int times_max=0;
    char letter;
    //use a nested loop to iterate two argument and use times to count times
    for(int i=0;i<=len1;i++){
        int times=0;
        for(int j=0; j<=len2;j++){
            if(str1[i]==str2[j]){
                times++;
            }


        }
        //replace letter that appears more times.
        if(times>times_max){
            times_max=times;
            letter = str1[i];
        }
    }
    printf("Most often : %c No. times: %d\n", letter, times_max );

    return 0;
}