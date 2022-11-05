#include "account.hpp"

class CheckingAccount : public Account {
  public:
    float tax() override;
}