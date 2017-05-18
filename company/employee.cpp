#include "employee.h"

Employee::Employee(const char* name, long egn,
                   Company* provider, const char* position)
  : Person(name, egn, provider), position(position) {}

ostream& operator<<(ostream& os, const Employee& employee) {
  operator<<(os, (const Employee::Person&) employee);
  return os << employee.position;
}
