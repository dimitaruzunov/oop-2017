#include <iostream>
#include "dynamic-array.h"

using std::cout;
using std::boolalpha;

void testBasicOperations() {
  DynamicArray<int> numbers;
  cout << boolalpha << numbers.isEmpty() << '\n'; // true

  numbers.push(1);
  cout << boolalpha << numbers.isEmpty() << '\n'; // false

  numbers.insertAt(1, 2);
  cout << numbers.getSize() << '\n'; // 2
  cout << numbers.get(0) << '\n'; // 1

  cout << numbers.pop() << '\n'; // 2

  numbers.push(42);
  numbers.push(21);

  cout << numbers.removeAt(0) << '\n'; // 1
  cout << numbers.get(0) << '\n'; // 42
  cout << numbers.get(1) << '\n'; // 21

  numbers.set(1, 42);

  numbers.print(); // 42, 42
}

void testArrayConstructor() {
  int arrayOfNumbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  DynamicArray<int> numbers(arrayOfNumbers, 10);

  numbers.print();
}

void testCopyConstructor() {
  int arrayOfNumbers[] = {1, 2, 3, 4, 5};
  DynamicArray<int> numbers(arrayOfNumbers, 5);

  DynamicArray<int> otherNumbers = numbers;
  otherNumbers.print();
  otherNumbers.push(6);
  otherNumbers.print();

  numbers.print();
  numbers.removeAt(1);
  numbers.print();

  otherNumbers.print();
}

void testTypeConversionConstructor() {
  DynamicArray<int> numbers = 30;

  for (int i = 1; i <= 15; ++i) {
    numbers.push(i);
  }

  numbers.print();
}

void testAssignmentOperator() {
  int arrayOfNumbers[] = {1, 2, 3, 4, 5};
  DynamicArray<int> numbers(arrayOfNumbers, 5);

  DynamicArray<int> otherNumbers;
  otherNumbers.push(1);
  otherNumbers.print();

  otherNumbers = numbers;
  otherNumbers.print();
  otherNumbers.push(6);
  otherNumbers.print();

  numbers.print();
  numbers.removeAt(1);
  numbers.print();

  otherNumbers.print();
}

void testArrayOfObjects() {
  int arrayOfNumbers[] = {1, 2, 3, 4, 5};

  DynamicArray<int> dynamicArrays[] = {
    DynamicArray<int>(),
    DynamicArray<int>(arrayOfNumbers, 5),
    5
  };

  for (int i = 0; i < 3; ++i) {
    dynamicArrays[i].print();
  }
}

void testDynamicallyAllocatedObjects() {
  int arrayOfNumbers[] = {1, 2, 3, 4, 5};
  DynamicArray<int>* numbers = new DynamicArray<int>(arrayOfNumbers, 5);
  numbers->print();

  DynamicArray<int>* dynamicArraysOfNumbers = new DynamicArray<int>[3];
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j <= i; ++j) {
      dynamicArraysOfNumbers[i].push(j);
    }
    dynamicArraysOfNumbers[i].print();
  }

  delete numbers;
  delete[] dynamicArraysOfNumbers;
}

void testTemporaryObjects() {
  int arrayOfNumbers[] = {1, 2, 3, 4, 5};
  DynamicArray<int>(arrayOfNumbers, 5).print();
}

void testOperators() {
  int firstArrayOfNumbers[] = {1, 2, 3, 4, 5};
  DynamicArray<int> firstNumbers(firstArrayOfNumbers, 5);

  int secondArrayOfNumbers[] = {6, 7, 8, 9, 10};
  DynamicArray<int> secondNumbers(secondArrayOfNumbers, 5);

  cout << firstNumbers[2] << '\n';

  (firstNumbers + secondNumbers).print();
  firstNumbers.print();
  secondNumbers.print();

  firstNumbers += secondNumbers;
  firstNumbers.print();
  secondNumbers.print();

  (firstNumbers - secondNumbers).print();
  (firstNumbers -= secondNumbers).print();
  secondNumbers.print();
}

int main() {
  testBasicOperations();
  testArrayConstructor();
  testCopyConstructor();
  testAssignmentOperator();
  testTypeConversionConstructor();
  testArrayOfObjects();
  testDynamicallyAllocatedObjects();
  testTemporaryObjects();
  testOperators();

  return 0;
}
