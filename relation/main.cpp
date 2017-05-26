#include <iostream>
#include "nat-function.h"

using std::cout;

int main() {
  int xs[] = {1, 2, 3, 4, 5, 6};
  int ys[] = {1, 2, 3, 4, 5, 6};
  NatFunction natFunction(xs, ys, 6);

  int xs1[] = {6, 8, 9, 10, 11, 12};
  int ys1[] = {6, 3, 4, 5, 6, 7};
  NatFunction natFunction1(xs1, ys1, 6);

  cout << natFunction(4) << '\n';
  cout << natFunction.operator+(natFunction1)(6) << '\n';

  return 0;
}