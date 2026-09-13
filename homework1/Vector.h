#ifndef VECTOR_H
#define VECTOR_H

class Vector {
private:
  int *source;
  size_t mSize;
  size_t mCapacity;
public:
  Vector ();
  Vector (size_t initial_capacity);
  Vector (Vector& v);
  
  int push (int value);
  
  ~Vector();

  int getElement (size_t index);
  size_t getSize ();
  size_t getCapacity ();
}

#endif

