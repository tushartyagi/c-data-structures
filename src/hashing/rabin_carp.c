#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

const int ASCII_SIZE = 255;
const int base = 229;

/**
   This is an O(|s|) operation targeting to create hash values using 
   the multiplication method.

   * @param s      the string 
   * @param begin  the start index
   * @param end    the end index
   * @return       the hash  
*/
int substring_hash(char *s, int begin, int end) {
  
  // TODO: A better hash (or use modulo)

  int hash = 0;
  if (begin > end) return hash;  // or crash and burn
  
  for (int i = begin; i <= end; i++) {
    hash += *(s + i);
  }

  return hash; // % ASCII_SIZE;
  
}

/**
   This is an O(|s|) operation targeting to create hash values using 
   the multiplication method.

   * @param s  the string 
   * @param n  the number of elements to use in hash 
   * @return   the hash  
*/
int substring_nhash(char *s, int n) {

  int hash = 0;

  for (int i = 0; i < n; i++) {
    hash += *(s + i);
  }

  return hash;
}


/**
   This is an O(1) operation targeting to create hash values from previous hash 
   and changing only 2 characters: the first and the last.

   * @param s         the string to be passed
   * @param size      the size of substring for hashing
   * @param prev_hash the value of previous hash
   * @param base      the base of the alphabet, usually a large prime
   * @return          the new hash  
*/
int hash_fromhash(char *s, int size, int prev_hash, int base) {

  char last = *(s + size); // The character to add
  char first = *s;         // The character to remove
  int pow_base = (int)pow(base, size - 1);
  
  int new_hash = base * (prev_hash - (first * pow_base)) + last;
  return new_hash;
  
}


int hash(char *s, int size, int base) {

  int h = 0;
  char c;
  
  for (int i = 0; i < size; i++) {
    c = *(s + i);
    h += c * (int)pow(base, size - i - 1);
  }

  return h;
}

char *substring(char *s, int begin, int end) {
  // TODO: Check bounds

  if (end < begin) return "";
  
  size_t n = end - begin + 1; 
  return strndup(s + begin, n);
}

bool is_substring(char *pattern, char *text) {

  bool result = false;

  size_t len_p = strlen(pattern);
  size_t len_t = strlen(text);

  int hash_pattern = hash(pattern, len_p, base);
  int hash_text = hash(text, len_p, base);

  for (int i = 0; i <= len_t - len_p; i++) {

    hash_text = hash_fromhash(text + i, len_p, hash_text, base);
    printf("Hash for %s is %d\n", substring(text, i, len_p), hash_text);

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

  int is_it = is_substring(s, t);
  printf("result: %d\n", is_it);	
	
  return 0;
}

