#include <stdio.h>

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

const ASCII_SIZE = 255;

int substring_hash(char *s, int begin, int end) {
  
  // TODO: A better hash (or use modulo)

  int hash = 0;
  if (begin > end) return hash;  // or crash and burn
  
  for (i = begin; i <= end; i++) {
    hash += *(s + i);
  }

  return hash; // % ASCII_SIZE;
  
}

int substring_hash(char *s, int size) {

  int hash = 0;

  for (int i = 0; i < size; i++) {
    hash += *(s + i);
  }

  return hash;
}

char *substring(char *s, int begin, int end) {
  // TODO: Check bounds
  size_t n = end - begin + 1; 
  return strndup(s + begin, n);
}

bool is_substring(char *pattern, char *text) {

  bool result = false;

  size_t len_p = strlen(pattern);
  size_t len_t = strlen(text);

  int hash_pattern = substring_hash(pattern, 0, len_p - 1);
  int hash_text = 0;
  
  for (i = 0; i <= len_t - len_p; i++) {

    hash_t = substring_hash(text, i, len_p);

    if (hash_text == hash_pattern) {

      // Check for string equality now that the hashes match
      char *subtext = substring(text, i, len_p);

      if (strcmp(pattern, subtext) == 0) {
        free(subtext);
        return true;
      }
      
    }
  }

  return false;
}


int main(void) {
	
  char *s = "ush", *t = "tushar";
  bool is_it = is_substring(s, t);
	
  printf("The result is: %d\n", is_it);
        
  char *s1 = substring("tushar", 1, 3);
  printf("The substring is: %s\n", s1);
  free(s1);
	
  return 0;
}

