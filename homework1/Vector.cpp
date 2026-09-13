#include "Vector.h"


Vector::Vector()
  : m_source { nullptr }
  , m_capacity{ 0 }
  , m_size{ 0 } {
}

Vector::Vector(size_t initial_capacity)
  : m_source { new int[initial_capacity] }
  , m_capacity{ initial_capacity }
  , m_size{ 0 } {
}

Vector::Vector(const Vector& v)
  : m_source { new int[v.m_capacity] }
  , m_capacity{ v.m_capacity }
  , m_size{ v.m_size } {
  for (size_t i = 0; i < v.m_size; i++) {
    m_source[i] = v.m_source[i];
  }
}

Vector::~Vector() {
  delete[] m_source;
}

void Vector::push (int value) {
  if (m_size >= m_capacity) {
    size_t new_capacity = (m_capacity == 0) ? 1 : m_capacity * 2;
    int *tmp = new int[new_capacity];
    for (size_t i = 0; i < m_size; i++) {
      tmp[i] = m_source[i];
    }
    delete[] m_source;
    m_source = tmp;
    m_capacity = new_capacity;
  }
  m_source[m_size++] = value;
}

