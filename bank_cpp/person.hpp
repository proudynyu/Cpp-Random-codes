#pragma once
#ifndef PERSON_H
#define PERSON_H

#include "cpf.hpp"
#include <string>

class Person {
  protected:
    CPF cpf;
    std::string name;
  
  public:
    Person(CPF cpf, std::string name): cpf(cpf), name(name) {};
};

#endif