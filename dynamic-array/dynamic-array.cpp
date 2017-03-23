#include <algorithm>
#include <iostream>
#include "dynamic-array.h"

using std::max;
using std::cout;

const int DynamicArray::INITIAL_CAPACITY = 8;

DynamicArray::DynamicArray()
  : size(0), capacity(INITIAL_CAPACITY), array(new int[capacity]) {}

DynamicArray::DynamicArray(const int array[], int elementsCount) {
  size = elementsCount;
  capacity = max(size, INITIAL_CAPACITY);
  this->array = new int[capacity];

  for (int i = 0; i < size; ++i) {
    this->array[i] = array[i];
  }
}

DynamicArray::DynamicArray(const DynamicArray& other) {
  copy(other);
}

DynamicArray& DynamicArray::operator=(const DynamicArray& other) {
  if (this != &other) {
    erase();
    copy(other);
  }

  return *this;
}

DynamicArray::~DynamicArray() {
  erase();
}

int DynamicArray::getSize() const {
  return size;
}

bool DynamicArray::isEmpty() const {
  return size == 0;
}

int DynamicArray::get(int index) const {
  return array[index];
}

void DynamicArray::set(int index, int newValue) {
  array[index] = newValue;
}

void DynamicArray::push(int element) {
  insertAt(size, element);
}

int DynamicArray::pop() {
  return removeAt(size - 1);
}

void DynamicArray::insertAt(int index, int element) {
  if (size == capacity) {
    resize();
  }

  for (int i = size; i > index; --i) {
    array[i] = array[i - 1];
  }

  array[index] = element;

  ++size;
}

int DynamicArray::removeAt(int index) {
  int removedElement = array[index];

  for (int i = index; i < size - 1; ++i) {
    array[i] = array[i + 1];
  }

  --size;

  return removedElement;
}

void DynamicArray::print() const {
  for (int i = 0; i < size - 1; ++i) {
    cout << array[i] << ", ";
  }
  cout << array[size - 1] << '\n';
}

void DynamicArray::resize() {
  capacity *= 2;

  int* newArray = new int[capacity];

  for (int i = 0; i < size; ++i) {
    newArray[i] = array[i];
  }

  delete[] array;

  array = newArray;
}

void DynamicArray::copy(const DynamicArray& other) {
  size = other.size;
  capacity = other.capacity;
  array = new int[capacity];

  for (int i = 0; i < size; ++i) {
    array[i] = other.array[i];
  }
}

void DynamicArray::erase() {
  delete[] array;
}
