#pragma once
#ifndef SPECIFICATION_HPP
#define SPECIFICATION_HPP

#include <string>

class Specification {
  public:
    Specification();
    ~Specification();

    bool CreateSpecification(std::string name);
};

#endif