#include "owner.hpp"

Owner::Owner(CPF cpf, std::string name, std::string password)
  : Person(cpf, name), Auth(password) {}

CPF Owner::getOwnerCpf() const 
{
  return this->cpf;
}

std::string Owner::getOwnerName() const 
{
  return this->name;
}