#include <algorithm>
#include <iostream>
#include "dynamic-array.h"

using std::max;
using std::cout;

template <typename T>
const int DynamicArray<T>::INITIAL_CAPACITY = 8;

template <typename T>
DynamicArray<T>::DynamicArray()
  : size(0), capacity(INITIAL_CAPACITY), array(new T[capacity]) {}

template <typename T>
DynamicArray<T>::DynamicArray(const T array[], int elementsCount) {
  size = elementsCount;
  capacity = max(size, INITIAL_CAPACITY);
  this->array = new T[capacity];

  for (int i = 0; i < size; ++i) {
    this->array[i] = array[i];
  }
}

template <typename T>
DynamicArray<T>::DynamicArray(int capacity)
  : size(0), capacity(capacity), array(new T[capacity]) {}

template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray& other) {
  copy(other);
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
DynamicArray<T>::~DynamicArray() {
  erase();
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
void DynamicArray<T>::print() const {
  if (isEmpty()) return;

  for (int i = 0; i < size - 1; ++i) {
    cout << array[i] << ", ";
  }
  cout << array[size - 1] << '\n';
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
void DynamicArray<T>::resize() {
  capacity *= 2;

  T* newArray = new T[capacity];

  for (int i = 0; i < size; ++i) {
    newArray[i] = array[i];
  }

  delete[] array;

  array = newArray;
}

template <typename T>
void DynamicArray<T>::copy(const DynamicArray& other) {
  size = other.size;
  capacity = other.capacity;
  array = new T[capacity];

  for (int i = 0; i < size; ++i) {
    array[i] = other.array[i];
  }
}

template <typename T>
void DynamicArray<T>::erase() {
  delete[] array;
}
