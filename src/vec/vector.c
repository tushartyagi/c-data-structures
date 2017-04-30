#include "vector.h"

int vector_size(vector *v) {
  return v->size;
}

int vector_capacity(vector *v) {
  return v->capacity;
}

int *vector_elements(vector *v) {
  return v->elements;
}

vector *vector_create(int capacity) {
  vector *v = malloc(sizeof(vector));
  
  int *elements = malloc(capacity * sizeof(int));
  v->elements = elements;

  v->size = 0;
  v->capacity = capacity;

  return v;
}

void vector_change_size(vector *v, int capacity) {

  int new_capacity = capacity;
  int *new_elements = malloc(new_capacity * sizeof(int));
  int *elements = v->elements;
  int size = v->size;

  for (int i = 0; i < size; i++) {
    new_elements[i] = elements[i];
  }

  v->capacity = new_capacity;
  v->elements = new_elements;

  free(elements);

}

void vector_expand(vector *v) {
  int new_capacity = v->capacity * 2;
  vector_change_size(v, new_capacity);
}


void vector_shrink(vector *v) {
  int new_capacity = v->capacity / 2;
  vector_change_size(v, new_capacity);
}

void vector_insert(vector *v, int element) {

  if (v->size == v->capacity) {
    vector_expand(v);
  }
  
  v->elements[v->size++] = element;

}

void vector_insert_at(vector *v, int index, int element) {

  if (v->size == v->capacity) {
    vector_expand(v);
  }

  for (int i = (v->size) - 1; i >= index; i--) {
    v->elements[i + 1] = v->elements[i];
  }

  v->elements[index] = element;
  v->size += 1;

}

int vector_delete(vector *v) {

  int element = v->elements[v->size - 1];
  v->size--;

  if (v->size < (v->capacity / 4)) {
    vector_shrink(v);
  }

  return element;

}

int vector_delete_at(vector *v, int index) {

  int element = v->elements[index];
  
  for (int i = index; i < v->size; i++) {
    v->elements[i] = v->elements[i + 1];
  }

  v->size--;

  if (v->size < (v->capacity / 4)) {
    vector_shrink(v);
  }

  return element;
}

bool vector_contains(vector *v, int element) {

  for (int i = 0; i < v->size; i++) {
    if (v->elements[i] == element)
      return true;
  }

  return false;
}
