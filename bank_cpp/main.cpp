#include <iostream>
#include <string>

#include "account.hpp"
#include "owner.hpp"
#include "cpf.hpp"

int main()
{
	Account myAcc(Owner(CPF("11111111111"), "Igor"), "1111.1111.1111.1111");

	myAcc.deposit(200);

	std::cout << myAcc.getAccountValue() << std::endl;
	std::cout << "name: " << myAcc.getAccountOwner() << " cpf: " << myAcc.getAccountCpf() << std::endl;
	std::cout << "Quantidade de contas criadas: " << Account::getAccountCount() << std::endl;

	return 0;
}
