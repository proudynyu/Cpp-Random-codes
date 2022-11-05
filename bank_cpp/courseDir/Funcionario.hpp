#pragma once
#include "Pessoa.hpp"
#include "Cpf.hpp"
#include "DiaDaSemana.hpp"
#include <string>

class Funcionario : public Pessoa
{
private:
    float salario;
    DiaDaSemana diaDoPagament;

public:
    Funcionario(Cpf cpf, std::string nome, float salario, DiaDaSemana diaDoPagamento);
    std::string recuperaNome() const;
    float recuperaSalario() const;
    virtual float bonificacao() const = 0;
};
