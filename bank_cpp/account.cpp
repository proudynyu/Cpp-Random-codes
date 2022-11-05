#include "account.hpp"

int Account::accountCount = 0;

Account::Account(Owner owner, std::string account_number) : owner(owner), accNumber(account_number), accountValue(0)
{
  accountCount++;
}

Account::~Account()
{
  accountCount--;
}

void Account::deposit(float depositValue)
{
  accountValue += depositValue;
}

void Account::withdraw(float withdrawValue)
{
  float withdrawTax = withdrawValue * 0.05;
  float realWithdrawValue = withdrawValue + withdrawTax;

  if (realWithdrawValue < 0.0f || realWithdrawValue > accountValue)
    return;

    accountValue -= realWithdrawValue;
}

const float Account::getAccountValue()
{
  return accountValue;
}

int Account::getAccountCount()
{
  return accountCount;
}

std::string Account::getAccountOwner() const
{
  return this->owner.getOwnerName();
}

std::string Account::getAccountCpf() const
{
  return this->owner.getOwnerCpf().getCpf();
}

void Account::transfer(Account& account, float value) {
  this->withdraw(value);
  account.deposit(value); 
}