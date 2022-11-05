#include "employee.hpp"

Employee::Employee(CPF cpf, std::string name, float salary)
  : Person(cpf, name), salary(salary) {}

float Employee::getSalary() const {
  return this->salary;
}