#include "caixa.hpp"

Caixa::Caixa(CPF cpf, std::string name, float salary): Employee(cpf, name, salary) {

}

float Caixa::bonification() const {
  return this->getSalary() * 0.1;
}