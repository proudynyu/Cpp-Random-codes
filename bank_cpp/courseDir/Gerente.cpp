#include "Gerente.hpp"

Gerente::Gerente(Cpf cpf, std::string nome, float salario, DiaDaSemana diaDoPagamento,std::string senha)
    : Funcionario(cpf, nome, salario), Autenticavel(senha), diaDoPagamento(diaDoPagamento)
{
}

float Gerente::bonificacao() const
{
    return recuperaSalario() * 0.5;
}
