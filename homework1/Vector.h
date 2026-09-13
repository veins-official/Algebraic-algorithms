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
  
  int getElement (size_t index) { return m_source[index]; }
  size_t getSize () { return m_size; }
  size_t getCapacity () { return m_capacity; }

  ~Vector();
}

#endif

