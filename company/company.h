#ifndef COMPANY_H
#define COMPANY_H

#include <iostream>

using std::ostream;

class Company {
  char name[100];
  int bulstat;

public:

  Company(const char* name, int bulstat);

  friend ostream& operator<<(ostream& os, const Company& company);
};

#endif
