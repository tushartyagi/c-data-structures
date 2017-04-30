#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct {
  int size;
  int capacity;
  int *elements;
} vector;

// The following 3 gets the data inside a vector
int vector_size(vector *v);
int vector_capacity(vector *v);
int vector_elements(vector *v);

// Create a new vector of given capacity
// O(1)
vector *vector_create(int capacity);

// Change a vector's size as per the capacity.
// Used by vector_expand and vector_shrink functions
void vector_change_size(vector *v, int capacity);

// Double a vector's capacity
// Amortized O(1)
void vector_expand(vector *v);

// Half the vector's array if the size goes less than
// one-third of the capacity.
// Amortized O(1)
void vector_shrink(vector *v);

// Insert the given element at the end
// O(1)
void vector_insert(vector *v, int element);

// Insert the given element at the given index and adjusts the
// elements coming after the index
// O(n)
void vector_insert_at(vector *v, int index, int element);

// Delete the last element from the give vector
// O(1)
void vector_delete(vector *v);

// Delete the element at the given index and adjust the elements
// coming after the deleted elements.
// O(n)
void vector_delete_at(vector *v, int index);

// Does the vector contains this element?
bool vector_contains(vector *v, int element);

#endif // VECTOR_H
