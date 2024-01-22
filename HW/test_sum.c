#include <stdio.h>
void sum3 ( int a, int b, int c, int * sum ); 

int main (void) {
  int s;
  sum3 (4, 10, -1, &s);
  printf ("%d\n", s);
  sum3 (0, 2, -10, &s);
  printf ("%d\n", s);
}



