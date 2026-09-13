#ifndef VECTOR_H
#define VECTOR_H

class Vector {
private:
  int *m_source;
  size_t m_size;
  size_t m_capacity;
public:
  Vector ();
  Vector (size_t initial_capacity);
  Vector (const Vector& v);
  
  int push (int value);
  
  ~Vector();

  int getElement (size_t index);
  size_t getSize ();
  size_t getCapacity ();
}

#endif

