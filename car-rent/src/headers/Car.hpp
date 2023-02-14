#pragma once
#ifndef CAR_HPP
#define CAR_HPP

#include <string>

#include "Category.hpp"
#include "Specification.hpp"

struct Car {
  std::string name;
  std::string description;
  int id;

  Category category;
  Specification specification;
};

#endif