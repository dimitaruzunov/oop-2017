#include <iostream>
#include "dynamic-array.h"

using std::cout;
using std::boolalpha;

int main() {
  DynamicArray numbers;
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

  return 0;
}