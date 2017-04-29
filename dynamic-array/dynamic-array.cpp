#include <algorithm>
#include <iostream>
#include "dynamic-array.h"

using std::max;
using std::cout;

template <typename T>
const int DynamicArray<T>::INITIAL_CAPACITY = 8;

template <typename T>
DynamicArray<T>::DynamicArray() {
  array = new T[INITIAL_CAPACITY];
  size = 0;
  capacity = INITIAL_CAPACITY;
}

template <typename T>
DynamicArray<T>::DynamicArray(const T array[], int elementsCount) {
  int initialCapacity = max(size, INITIAL_CAPACITY);
  this->array = new T[initialCapacity];

  for (int i = 0; i < elementsCount; ++i) {
    this->array[i] = array[i];
  }

  size = elementsCount;
  capacity = initialCapacity;
}

template <typename T>
DynamicArray<T>::DynamicArray(int capacity) {
  array = new T[capacity];
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
  return array[index];
}

template <typename T>
const T& DynamicArray<T>::operator[](int index) const {
  return get(index);
}

template <typename T>
void DynamicArray<T>::set(int index, const T& newValue) {
  array[index] = newValue;
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
    array[i] = array[i - 1];
  }

  array[index] = element;
  ++size;
}

template <typename T>
T DynamicArray<T>::removeAt(int index) {
  T removedElement = array[index];

  for (int i = index; i < size - 1; ++i) {
    array[i] = array[i + 1];
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
void DynamicArray<T>::print() const {
  cout << '[';

  if (!isEmpty()) {
    for (int i = 0; i < size - 1; ++i) {
      cout << array[i] << ", ";
    }
    cout << array[size - 1];
  }

  cout << "]\n";
}

template <typename T>
void DynamicArray<T>::copy(const DynamicArray& other) {
  array = new T[other.capacity];

  for (int i = 0; i < other.size; ++i) {
    array[i] = other.array[i];
  }

  size = other.size;
  capacity = other.capacity;
}

template <typename T>
void DynamicArray<T>::erase() {
  delete[] array;
}

template <typename T>
void DynamicArray<T>::resize() {
  T* oldArray = array;
  array = new T[capacity * 2];

  for (int i = 0; i < size; ++i) {
    array[i] = oldArray[i];
  }
  delete[] oldArray;

  capacity *= 2;
}
