#include <iostream.h>
#include "Vector.h"


int main (int argc, char *argv[]) {
  Vector v1;

  for (size_t i = 0; i < 10; i++) v1.push(i);
  
  for (size_t i = 0; i < v1.get_size(); i++) {
    printf("%d ", v1.get_element(i));
  }
  printf("\n");

  return 0;
}

