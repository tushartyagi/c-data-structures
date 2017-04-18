#include <stdio.h>
#include <stdbool.h>

bool all_vowels(char chars[])
{
  char c;
  int i = 0;

  while ((c = chars[i++]) != '\0') {
    //printf("The char is %c\n", c);
    if (!(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')) {
      return false;
    }
  }
  return true;
}

int main(void) {

  int numbers[] = {1, 2, 3, 4, 5, 6};
  int *number = &numbers[0];
  
  const int N = 6;
  
  //for (int i = 0; i < N; i++) {
  //    printf("%d\n", numbers[i]);
  //}

  printf("The number is: %d\n", *number);
  number++;

  printf("The number is: %d\n", *number);
  
  bool validity = all_vowels("aoeaoeuaoeu");
  printf("The validity: %d\n", validity);  
  
  return 0;
}

