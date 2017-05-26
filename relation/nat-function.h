#ifndef NAT_FUNCTION_H
#define NAT_FUNCTION_H

#include "relation.h"

class NatFunction : Relation<int> {
  bool hasUniqueY(int x, int xs[], int n) const;

  NatFunction(const Relation& relation);

public:

  NatFunction(int xs[], int ys[], int n);

  NatFunction operator+(const NatFunction& other) const;
  int operator()(int x) const;

  bool isInjection() const;
};

#endif
