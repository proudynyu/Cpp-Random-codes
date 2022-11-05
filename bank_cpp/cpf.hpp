#pragma once

#ifndef CPF_H
#define CPF_H

#include <string>

class CPF {
  public:
    CPF(std::string cpf);
    std::string getCpf() const;

  private:
    std::string cpf;
    void validateCpf() const;
};

#endif