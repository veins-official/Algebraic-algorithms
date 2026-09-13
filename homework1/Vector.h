#ifndef VECTOR_H
#define VECTOR_H

#include <cstddef>

class Vector {
private:
  int *m_source;
  size_t m_capacity;
  size_t m_size;
public:
  Vector ();
  Vector (size_t initial_capacity);
  Vector (const Vector& v);
  
  int push (int value);
  
  int getElement (size_t index) { return m_source[index]; } // По хорошему, возвращать ошибку при out of bounds
  size_t getSize () const { return m_size; }
  size_t getCapacity () const { return m_capacity; }

  ~Vector();
};

#endif

