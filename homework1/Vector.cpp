#include "Vector.h"


Vector::()
  : m_capacity{ 0 }
  , m_size{ 0 } {
  m_source = nullptr;
}

Vector::(size_t initial_capacity)
  : m_capacity{ initial_capacity }
  , m_size{ 0 } {
  m_source = new int[initial_capacity];
}

Vector::(const Vector& v)
  : m_capacity{ v.m_capacity }
  , m_size{ v.m_size } {
  m_source = new int[v.m_capacity];
  
  for (size_t i = 0; i < v.m_size; i++) {
    m_source[i] = v.m_source[i];
  }
}

Vector::~Vector() {
  delete[] m_source;
}

