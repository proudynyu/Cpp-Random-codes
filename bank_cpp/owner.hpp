#pragma once

#ifndef OWNER_H
#define OWNER_H

#include <string>
#include "cpf.hpp"
#include "person.hpp"
#include "auth.hpp"

class Owner : public Person, Auth
{
  public:
    Owner(CPF cpf, std::string name, std::string password);
    std::string getOwnerName() const;
    CPF getOwnerCpf() const;
};

#endif