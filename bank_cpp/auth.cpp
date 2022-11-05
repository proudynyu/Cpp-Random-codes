#include "auth.hpp"

Auth::Auth(std::string password) : password(password)
{
}

bool Auth::authUser(std::string password) const
{
  return this->password == password;
}