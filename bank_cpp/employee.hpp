#pragma once

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include "cpf.hpp"
#include "person.hpp"

class Employee : public Person {
  public:
    Employee(CPF cpf, std::string name, float salary);

    virtual float bonification() const = 0;
    float getSalary() const;

  private:
    float salary;
};

#endif