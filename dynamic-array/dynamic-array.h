#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

class DynamicArray {
  int* array;
  unsigned size;
  unsigned capacity;

  void resize();

public:

  DynamicArray();

  ~DynamicArray();

  unsigned getSize() const;

  bool isEmpty() const;

  int get(unsigned index) const;

  void set(unsigned index, int newValue);

  void push(int element);

  int pop();

  void insertAt(unsigned index, int element);

  int removeAt(unsigned index);

  void print() const;
};

#endif
