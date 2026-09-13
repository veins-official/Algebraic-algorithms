#include <iostream>
#include "Vector.h"


int main (void) {
  Vector v1;

  for (size_t i = 0; i < 10; i++) v1.push(i);
  
  for (size_t i = 0; i < v1.getSize(); i++) {
    printf("%d ", v1.getElement(i));
  }
  printf("\n");

  return 0;
}

