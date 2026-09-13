#include <iostream>
#include "Vector.h"


int main (void) {
  Vector v1, v2;

  for (size_t i = 0; i < 10; i++) {
    v1.push(i);
  }
  
  v2 = v1;
  
  v1.push(13);
  
  for (size_t i = 0; i < v1.getSize(); i++) {
    std::cout << v1.getElement(i) << std::endl;
  }
  std::cout << std::endl;
  for (size_t i = 0; i < v2.getSize(); i++) {
    std::cout << v2.getElement(i) << std::endl; // Не совпадает с v1
  }

  return 0;
}

