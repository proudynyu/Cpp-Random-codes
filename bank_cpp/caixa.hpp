#ifndef CAIXA_H
#define CAIXA_H

#include "employee.hpp"
#include "cpf.hpp"

class Caixa final: public Employee
{
private:

public:
  Caixa(CPF cpf, std::string name, float salary);

  float bonification() const;
};

#endif