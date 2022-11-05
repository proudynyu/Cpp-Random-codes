#pragma once

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

#include "owner.hpp"

class Account
{
public:
	Account(Owner owner, std::string account_number);
	~Account();

	virtual float tax() = 0;

	void withdraw(float withdrawValue);
	void deposit(float depositValue);

	std::string getAccountOwner() const;
	std::string getAccountCpf() const;

	const float getAccountValue();
	static int getAccountCount();

	void transfer(Account& account, float value);

private:
	Owner owner;
	std::string accNumber;
	float accountValue;

	static int accountCount;
};

#endif
