#include <iostream>
#include "cpf.hpp"

CPF::CPF(std::string cpf) : cpf(cpf)
{
  this->validateCpf();
}

void CPF::validateCpf() const
{
  if (this->cpf.size() > 11)
  {
    std::cout << "Invalid CPF" << std::endl;
    exit(0);
  }
}

std::string CPF::getCpf() const
{
  return this->cpf;
}