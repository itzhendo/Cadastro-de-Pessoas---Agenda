#ifndef DADOSDOARQUIVO_H
#define DADOSDOARQUIVO_H
#include <pessoa.h>
#include <QStringList>
#include <QFileDialog>
#include <QWidget>
#include<iostream>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QString>
#include <fstream>
#include <time.h>

using namespace std;

class dadosDoArquivo
{
private:
    QString nomeDoArquivoNoDisco;
    int tamanhoDoArquivo;
public:
    dadosDoArquivo(QString nomeDoArquivoNoDisco);
    void adicionarPessoa(QString CPF, QString nome, QString endereco,QString telefone, QString email);
    int getTamanhoDoArquivo()const {return tamanhoDoArquivo;}
    Pessoa* obterDadosDoArquivo();

};

#endif // DADOSDOARQUIVO_H
