#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

template <typename T>
class DynamicArray {
  T* array;
  int size;
  int capacity;

  static const int INITIAL_CAPACITY;

  void resize();

  void copy(const DynamicArray& other);

  void erase();

public:

  DynamicArray();

  DynamicArray(const T array[], int elementsCount);

  DynamicArray(int capacity);

  DynamicArray(const DynamicArray& other);

  DynamicArray& operator=(const DynamicArray& other);

  ~DynamicArray();

  int getSize() const;

  bool isEmpty() const;

  const T& get(int index) const;

  const T& operator[](int index) const;

  void set(int index, const T& newValue);

  void push(const T& element);

  T pop();

  void insertAt(int index, const T& element);

  T removeAt(int index);

  void print() const;

  DynamicArray& operator+=(const DynamicArray& other);

  DynamicArray operator+(const DynamicArray& other);
};

#endif
