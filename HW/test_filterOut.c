int filterOut(const char* inputFilename, const char* target, const char* outputFilename);
#include <stdio.h> 
int main (void) {
    int retval = filterOut ("foo.txt", "xyz", "bar.txt"); 
    printf ("% d\n", retval);
}