//Part 1
#include <stdio.h>
#include <stdlib.h>
void sum3(int a, int b, int c, int* sum){
    if (sum!=NULL){
        *sum = a + b + c;
    }
}

//Part 2
int eachContains(char** strings, char target, unsigned numStrings, char** firstOffending) {
    for (unsigned i = 0; i < numStrings; i=i+1) { // loop times are determined by number of strings
        char *Str = strings[i];
        int found = 0; // a varible to store boolean value

        // use a for loop to go through the current string and compare with target
        for (int j = 0; Str[j] != '\0'; j=j+1) { // i!=to determine whether we iterate to the end of this string
            if (Str[j] == target) {
                found = 1;
                break; // Break out of the inner loop as we found the target
            }
        }

        // Check if we found the target in current stirng
        if (!found) {
            // If found=1 we will change the value of firstoffending to current string
            if (firstOffending != NULL) { //avoiding crush 

                *firstOffending = Str; // change value
            }
            //return 0 when there is a unmatch
            return 0;
        }
    }
    // Target character was found in all strings
    return 1;
}




//Part 4
// check the validity of three inputs
int filterOut(const char* inputFilename, const char* target, const char* outputFilename ){
    if(inputFilename==NULL || target==NULL || outputFilename==NULL){
        return 0;
    }

    FILE* input = fopen(inputFilename, "r");
    FILE* output = fopen(outputFilename, "w");
    if (input == NULL || output == NULL) {
        // Handle file opening errors.
        return 0;
    }

    char input_line[100];
    int len_target = 0;
    while (target[len_target] != '\0') {
        len_target++;
    }

    while(fgets(input_line, sizeof(input_line), input) != NULL){
        int found = 0;
        // Determine the length of the input line
        int len_line = 0;
        while(input_line[len_line] != '\0' && input_line[len_line] != '\n') {
            len_line++;
        }

        // Search for the target string within the current line
        //only check whendidnot find and the target won't pass length of line
        for (int i = 0; i <= len_line - len_target && !found; ++i) {
            int match = 1;
            //compare the target characters with lines input
            for (int j = 0; j < len_target; ++j) {
                if (input_line[i + j] != target[j]) {
                    match = 0;
                    break;
                }
            }
            if (match) {
                found = 1;
            }
        }

        // If the target string was not found, write the line to the output file
        if (!found) {
            fputs(input_line, output);
        }
    }
    //close the file we opened
    fclose(input);
    fclose(output);
    return 1;
}