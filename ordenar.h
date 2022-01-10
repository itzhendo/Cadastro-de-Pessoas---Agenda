#ifndef ORDENAR_H
#define ORDENAR_H
#include <dadosdoarquivo.h>
#include <pessoa.h>
#include <time.h>

using namespace chrono;

class Ordenar
{
private:
    Pessoa* dados;
    Pessoa* dados2;
    int tam;
    int contador;
public:
    Ordenar(QString nomeDoArquivoNoDisco);
    Ordenar(Ordenar* dat);
    void insertionSort();
    int buscar(QString elemento);
    void salvarExcluidos();
    void excluir(QString elemento);
    void incluir (QString CPF, QString nome, QString endereco,QString telefone, QString email);
    void alterarCPF(QString elemento, QString dado);
    void alterarNome(QString elemento, QString dado);
    void alterarEndereco(QString elemento, QString dado);
    void alterarTelefone(QString elemento, QString dado);
    void alterarEmail(QString elemento, QString dado);
    Pessoa * getDados()const{return dados;}
    int getTam(){return tam;}
};

#endif // ORDENAR_H
