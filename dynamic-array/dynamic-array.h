#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

class DynamicArray {
  int* array;
  int size;
  int capacity;

  static const int INITIAL_CAPACITY;

  void resize();

  void copy(const DynamicArray& other);

  void erase();

public:

  DynamicArray();

  DynamicArray(const int array[], int elementsCount);

  DynamicArray(const DynamicArray& other);

  DynamicArray& operator=(const DynamicArray& other);

  ~DynamicArray();

  int getSize() const;

  bool isEmpty() const;

  int get(int index) const;

  void set(int index, int newValue);

  void push(int element);

  int pop();

  void insertAt(int index, int element);

  int removeAt(int index);

  void print() const;
};

#endif
