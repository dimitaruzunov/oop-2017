#include <iostream>
#include "dynamic-array.h"

using std::cout;

DynamicArray::DynamicArray() {
  size = 0;
  capacity = 8;
  array = new int[capacity];
}

DynamicArray::~DynamicArray() {
  delete[] array;
}

unsigned DynamicArray::getSize() const {
  return size;
}

bool DynamicArray::isEmpty() const {
  return size == 0;
}

int DynamicArray::get(unsigned index) const {
  return array[index];
}

void DynamicArray::set(unsigned index, int newValue) {
  array[index] = newValue;
}

void DynamicArray::push(int element) {
  insertAt(size, element);
}

int DynamicArray::pop() {
  return removeAt(size - 1);
}

void DynamicArray::insertAt(unsigned index, int element) {
  if (size == capacity) {
    resize();
  }

  for (unsigned i = size; i > index; --i) {
    array[i] = array[i - 1];
  }

  array[index] = element;

  ++size;
}

int DynamicArray::removeAt(unsigned index) {
  int removedElement = array[index];

  for (unsigned i = index; i < size - 1; ++i) {
    array[i] = array[i + 1];
  }

  --size;

  return removedElement;
}

void DynamicArray::print() const {
  for (unsigned i = 0; i < size - 1; ++i) {
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
