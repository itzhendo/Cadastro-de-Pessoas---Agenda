#include "pessoa.h"

QString Pessoa::getCPF() const
{
    return CPF;
}

void Pessoa::setCPF(QString value)
{
    CPF = value;
}

QString Pessoa::getTelefone() const
{
    return telefone;
}

void Pessoa::setTelefone(QString value)
{
    telefone = value;
}

QString Pessoa::getNome() const
{
    return nome;
}

void Pessoa::setNome(const QString &value)
{
    nome = value;
}

QString Pessoa::getEndereco() const
{
    return endereco;
}

void Pessoa::setEndereco(const QString &value)
{
    endereco = value;
}

QString Pessoa::getEmail() const
{
    return email;
}

void Pessoa::setEmail(const QString &value)
{
    email = value;
}

Pessoa::Pessoa()
{

}
