#include <stdio.h>
#include <math.h>




int main(void) {
  char *s = "abra";
  int h = hash(s, 3, 101);

  int hh = hash_fromhash(s, 3, h, 101);
  printf("Hash %d\n", h);
  printf("Hash 2 %d\n", hh);  
}
