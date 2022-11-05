#ifndef AUTH_H
#define AUTH_H

#include <string>

class Auth {
  private:
    std::string password;

  public:
    Auth(std::string password);
    bool authUser(std::string password) const;
};

#endif