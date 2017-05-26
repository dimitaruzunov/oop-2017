#include "relation.h"

template <typename T>
Relation<T>::Relation(): xs(nullptr), ys(nullptr), n(0) {}

template <typename T>
Relation<T>::Relation(T xs[], T ys[], int n) {
  assignArray(&this->xs, xs, n);
  assignArray(&this->ys, ys, n);
  this->n = n;
}

template <typename T>
Relation<T>::Relation(const Relation& other) {
  copy(other);
}

template <typename T>
Relation<T>::~Relation() {
  erase();
}

template <typename T>
Relation<T>& Relation<T>::operator=(const Relation &other) {
  if (this != &other) {
    erase();
    copy(other);
  }

  return *this;
}

template <typename T>
bool Relation<T>::areInRelation(const T& x, const T& y) const {
  for (int i = 0; i < n; ++i) {
    if (xs[i] == x && ys[i] == y) {
      return true;
    }
  }

  return false;
}

template <typename T>
bool Relation<T>::isSymmetric() const {
  for (int i = 0; i < n; ++i) {
    if (!areInRelation(ys[i], xs[i])) {
      return false;
    }
  }

  return true;
}

template <typename T>
Relation<T> Relation<T>::operator+(const Relation& other) const {
  T* resultXs = new T[n + other.n];
  T* resultYs = new T[n + other.n];

  for (int i = 0; i < n; ++i) {
    resultXs[i] = xs[i];
    resultYs[i] = ys[i];
  }
  int resultN = n;

  for (int i = 0; i < other.n; ++i) {
    if (!areInRelation(other.xs[i], other.ys[i])) {
      resultXs[resultN] = other.xs[i];
      resultYs[resultN] = other.ys[i];
      ++resultN;
    }
  }

  Relation result(resultXs, resultYs, resultN);
  delete[] resultXs;
  delete[] resultYs;

  return result;
}

template <typename T>
void Relation<T>::assignArray(T** destination, T* source, int n) {
  *destination = new T[n];
  for (int i = 0; i < n; ++i) {
    (*destination)[i] = source[i];
  }
}

template <typename T>
void Relation<T>::copy(const Relation& other) {
  assignArray(&xs, other.xs, other.n);
  assignArray(&ys, other.ys, other.n);
  n = other.n;
}

template <typename T>
void Relation<T>::erase() {
  delete[] xs;
  delete[] ys;
}
