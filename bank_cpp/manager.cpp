#include "manager.hpp"

Manager::Manager(CPF cpf, std::string name, float salary) : Employee(cpf, name, salary) {}

float Manager::bonification() const {
	return this->getSalary() * 0.5;
}
