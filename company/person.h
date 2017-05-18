#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

using std::string;
using std::ostream;

template <typename T>
class Person {
  string name;
  long egn;
  T* provider;

public:

  Person(const char* name, long egn, T* provider);

  friend ostream& operator<<(ostream& os, const Person<T>& person) {
    return os << person.name << ", " << person.egn << '\n'
              << *person.provider << '\n';
  }
};

#endif
