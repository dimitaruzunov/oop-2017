#include "company.h"
#include <cstring>

Company::Company(const char* name, int bulstat) {
  strcpy(this->name, name);
  this->bulstat = bulstat;
}

ostream& operator<<(ostream& os, const Company& company) {
  return os << company.name << ", " << company.bulstat;
}
