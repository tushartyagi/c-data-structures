#include <stdio.h>
#include <assert.h>

#include "vector.h"

void test_vector_create() {

  int capacity = 12;
  vector *v = vector_create(capacity);

  assert(v != NULL);
  assert(v->size == 0);
  assert(v->capacity == capacity);
  assert(v->elements != NULL);

  vector_free(v);
}

void test_vector_expand() {
  int capacity = 2;

  vector *v = vector_create(capacity);
  assert(v->size == 0);
  assert(v->capacity == capacity);

  vector_insert(v, 12);
  assert(v->size == 1);
  assert(v->capacity == capacity);

  vector_insert(v, 13);
  assert(v->size == 2);
  assert(v->capacity == capacity);

  vector_insert(v, 14);
  assert(v->size == 3);
  assert(v->capacity == capacity * 2);

  vector_free(v);
}

void test_vector_shrink() {
  int capacity = 2;

  vector *v = vector_create(capacity);

  // Expand 2 -> 4 -> 8 -> 16
  for (int i = 1; i <= 16; i++) {
    vector_insert(v, i);
  }
  
  assert(v->size == 16);
  assert(v->capacity == 16);

  // Half the size when the number of elements decrease to a quarter of the
  // capacity.
  for (int i = 1; i <= 13; i++) {
    vector_delete(v);
  }

  assert(v->size == 3);
  assert(v->capacity == 8);

  vector_free(v);
}


void test_vector_insert_at() {
  int capacity = 2;

  vector *v = vector_create(capacity);

  for (int i = 1; i <= 5; i++) {
    vector_insert(v, i);
  }
  
  assert(v->size == 5);
  assert(v->capacity == 8);

  vector_insert_at(v, 0, 0);
  
  assert(v->size == 6);
  assert(v->capacity == 8);

  for (int i = 0; i <= 5; i++) {
    assert(v->elements[i] == i);
  }

  vector_free(v);
}

void test_vector_delete_at() {
  int capacity = 2;

  vector *v = vector_create(capacity);

  for (int i = 0; i <= 5; i++) {
    vector_insert(v, i);
  }
  
  assert(v->size == 6);
  assert(v->capacity == 8);

  vector_delete_at(v, 0);
  
  assert(v->size == 5);
  assert(v->capacity == 8);

  for (int i = 1; i <= 5; i++) {
    assert(v->elements[i - 1] == i);
  }

  vector_free(v);
}

void test_vector_contains() {
  int capacity = 2;

  vector *v = vector_create(capacity);

  for (int i = 1; i <= 5; i++) {
    vector_insert(v, i);
  }
  
  vector_insert_at(v, 0, 0);
  
  assert(v->size == 6);
  assert(v->capacity == 8);

  for (int i = 0; i <=5 ; i++) {
    assert(vector_contains(v, i));
  }

  assert(!vector_contains(v, 99));

  vector_free(v);
}

int run_all_tests(void) {
  
  test_vector_create();
  test_vector_expand();
  test_vector_shrink();
  test_vector_insert_at();
  test_vector_delete_at();
  test_vector_contains();
  
  return 0;
  
}

int main(void) {
  run_all_tests();

  return 0;
}
