#ifndef MANAGER_H
#define MANAGER_H

#include "employee.hpp"

class Manager final : public Employee {
  private:

  public:
    Manager(CPF cpf, std::string name, float salary);

    float bonification() const;
};

#endif
