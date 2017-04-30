#include "vector.h"
#include <stdio.h>



int main(void) {
  
  vector *v = vector_create(2);

  printf("Capacity: %d\n", v->capacity);
  printf("size: %d\n", v->size);

  vector_insert(v, 12);
  vector_insert(v, 13);

  printf("Capacity: %d\n", v->capacity);
  printf("size: %d\n", v->size);

  vector_insert(v, 14);
  vector_insert(v, 15);

  printf("Capacity: %d\n", v->capacity);
  printf("size: %d\n", v->size);

  vector_insert(v, 16);

  vector_insert_at(v, 0, 100);
  vector_insert_at(v, 3, 300);
  vector_insert_at(v, 4, 400);

  vector_insert(v, 160);
  
  for (int i = 0; i < v->capacity; i++) {
    printf("Value at %d: %d\n", i, v->elements[i]);
  }
  
  return 0;
}
