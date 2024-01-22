#include <stdio.h>
// Here, `extern` means the function is defined in another file.
extern int between(char lowerBound, char upperBound, char target);
int main()
{
printf("%d\n", between('C', 'R', 'M'));
printf("%d\n", between('E', 'W', 'D'));
printf("%d\n", between('T', 'Z', 'Y'));
printf("%d\n", between('T', 'W', 'W'));
printf("%d\n", between('t', 'Z', 'Y'));
printf("%d\n", between('T', 'B', 'W'));
}
