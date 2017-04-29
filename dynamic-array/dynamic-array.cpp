#include <algorithm>
#include <iostream>
#include "dynamic-array.h"

using std::max;
using std::cout;

template <typename T>
const int DynamicArray<T>::INITIAL_CAPACITY = 8;

template <typename T>
DynamicArray<T>::DynamicArray() {
  elements = new T[INITIAL_CAPACITY];
  size = 0;
  capacity = INITIAL_CAPACITY;
}

template <typename T>
DynamicArray<T>::DynamicArray(const T elements[], int elementsCount) {
  int initialCapacity = max(size, INITIAL_CAPACITY);
  this->elements = new T[initialCapacity];

  for (int i = 0; i < elementsCount; ++i) {
    this->elements[i] = elements[i];
  }

  size = elementsCount;
  capacity = initialCapacity;
}

template <typename T>
DynamicArray<T>::DynamicArray(int capacity) {
  elements = new T[capacity];
  size = 0;
  this->capacity = capacity;
}

template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray& other) {
  copy(other);
}

template <typename T>
DynamicArray<T>::~DynamicArray() {
  erase();
}

template <typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray& other) {
  if (this != &other) {
    erase();
    copy(other);
  }

  return *this;
}

template <typename T>
int DynamicArray<T>::getSize() const {
  return size;
}

template <typename T>
bool DynamicArray<T>::isEmpty() const {
  return size == 0;
}

template <typename T>
const T& DynamicArray<T>::get(int index) const {
  return elements[index];
}

template <typename T>
const T& DynamicArray<T>::operator[](int index) const {
  return get(index);
}

template <typename T>
bool DynamicArray<T>::includes(const T& element) const {
  for (int i = 0; i < size; ++i) {
    if (elements[i] == element) {
      return true;
    }
  }

  return false;
}

template <typename T>
void DynamicArray<T>::set(int index, const T& newValue) {
  elements[index] = newValue;
}

template <typename T>
void DynamicArray<T>::push(const T& element) {
  insertAt(size, element);
}

template <typename T>
T DynamicArray<T>::pop() {
  return removeAt(size - 1);
}

template <typename T>
void DynamicArray<T>::insertAt(int index, const T& element) {
  if (size == capacity) {
    resize();
  }

  for (int i = size; i > index; --i) {
    elements[i] = elements[i - 1];
  }

  elements[index] = element;
  ++size;
}

template <typename T>
T DynamicArray<T>::removeAt(int index) {
  T removedElement = elements[index];

  for (int i = index; i < size - 1; ++i) {
    elements[i] = elements[i + 1];
  }

  --size;

  return removedElement;
}

template <typename T>
DynamicArray<T>& DynamicArray<T>::operator+=(const DynamicArray& other) {
  for (int i = 0; i < other.size; ++i) {
    push(other[i]);
  }

  return *this;
}

template <typename T>
DynamicArray<T> DynamicArray<T>::operator+(const DynamicArray& other) {
  DynamicArray<T> result = *this;
  return result += other;
}

template <typename T>
DynamicArray<T>& DynamicArray<T>::operator-=(const DynamicArray& other) {
  return *this = *this - other;
}

template <typename T>
DynamicArray<T> DynamicArray<T>::operator-(const DynamicArray& other) {
  DynamicArray<T> result;

  for (int i = 0; i < size; ++i) {
    if (!other.includes(elements[i])) {
      result.push(elements[i]);
    }
  }

  return result;
}

template <typename T>
void DynamicArray<T>::print() const {
  cout << '[';

  if (!isEmpty()) {
    for (int i = 0; i < size - 1; ++i) {
      cout << elements[i] << ", ";
    }
    cout << elements[size - 1];
  }

  cout << "]\n";
}

template <typename T>
void DynamicArray<T>::copy(const DynamicArray& other) {
  elements = new T[other.capacity];

  for (int i = 0; i < other.size; ++i) {
    elements[i] = other.elements[i];
  }

  size = other.size;
  capacity = other.capacity;
}

template <typename T>
void DynamicArray<T>::erase() {
  delete[] elements;
}

template <typename T>
void DynamicArray<T>::resize() {
  T* oldElements = elements;
  elements = new T[capacity * 2];

  for (int i = 0; i < size; ++i) {
    elements[i] = oldElements[i];
  }
  delete[] oldElements;

  capacity *= 2;
}
