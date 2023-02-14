#pragma once
#ifndef CATEGORY_HPP
#define CATEGORY_HPP

#include <string>
#include <fstream>

class Category {
  public:
    Category();
    ~Category();

    bool CreateCategory(std::string name, std::string description);
    bool UpdateCategory(std::string name);
    std::ofstream ListCategories();
};

#endif