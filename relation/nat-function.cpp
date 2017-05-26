#include "nat-function.h"

NatFunction::NatFunction(const Relation& relation): Relation(relation) {}

NatFunction::NatFunction(int xs[], int ys[], int n) {
  int* filteredXs = new int[n];
  int* filteredYs = new int[n];
  int filteredN = 0;

  for (int i = 0; i < n; ++i) {
    if (hasUniqueY(xs[i], xs, n)) {
      filteredXs[filteredN] = xs[i];
      filteredYs[filteredN] = ys[i];
      ++filteredN;
    }
  }

  *this = Relation(filteredXs, filteredYs, filteredN);

  delete[] filteredXs;
  delete[] filteredYs;
}

NatFunction NatFunction::operator+(const NatFunction& other) const {
  NatFunction united = Relation::operator+(other);
  return NatFunction(united.xs, united.ys, united.n);
}

int NatFunction::operator()(int x) const {
  for (int i = 0; i < n; ++i) {
    if (xs[i] == x) {
      return ys[i];
    }
  }

  return 0;
}

bool NatFunction::isInjection() const {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      if (xs[i] != xs[j] && ys[i] == ys[j]) {
        return false;
      }
    }
  }

  return true;
}

bool NatFunction::hasUniqueY(int x, int xs[], int n) const {
  int count = 0;

  for (int i = 0; i < n; ++i) {
    if (xs[i] == x) {
      ++count;
    }
  }

  return count == 1;
}
