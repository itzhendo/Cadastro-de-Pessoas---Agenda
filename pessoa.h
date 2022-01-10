#ifndef PESSOA_H
#define PESSOA_H
#include <QString>
#include <iostream>

class Pessoa
{
private:
    QString CPF;
    QString telefone;
    QString nome;
    QString endereco;
    QString email;

public:
    Pessoa();
    QString getCPF() const;
    void setCPF(QString value);
    QString getTelefone() const;
    void setTelefone(QString value);
    QString getNome() const;
    void setNome(const QString &value);
    QString getEndereco() const;
    void setEndereco(const QString &value);
    QString getEmail() const;
    void setEmail(const QString &value);
};

#endif // PESSOA_H
