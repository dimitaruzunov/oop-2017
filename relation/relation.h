#ifndef RELATION_H
#define RELATION_H

template <typename T>
class Relation {
  void assignArray(T** destination, T* source, int n);
  void copy(const Relation& other);
  void erase();

protected:
  T* xs;
  T* ys;
  int n;

public:

  Relation();
  Relation(T xs[], T ys[], int n);
  Relation(const Relation& other);
  ~Relation();

  Relation& operator=(const Relation& other);

  bool areInRelation(const T& x, const T& y) const;
  bool isSymmetric() const;

  Relation operator+(const Relation& other) const;
};

#endif
