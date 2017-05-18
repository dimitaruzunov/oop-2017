#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include "person.h"
#include "company.h"

class Employee : public Person<Company> {
  string position;

public:

  Employee(const char* name, long egn, Company* provider, const char* position);

  friend ostream& operator<<(ostream& os, const Employee& employee);
};


#endif
