#include "person.h"

template <typename T>
Person<T>::Person(const char* name, long egn, T* provider)
  : name(name), egn(egn), provider(provider) {}
