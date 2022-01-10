#include "dadosdoarquivo.h"

dadosDoArquivo::dadosDoArquivo(QString nomeDoArquivoNoDisco):
nomeDoArquivoNoDisco(nomeDoArquivoNoDisco)
{
    std::ifstream arquivoDados;
    arquivoDados.open(nomeDoArquivoNoDisco.toStdString().c_str());
    if(!arquivoDados.is_open()) throw QString("Erro na Abertura do Arquivo");
    std::string linha;
    std::getline(arquivoDados,linha);
    for(tamanhoDoArquivo = 0; !arquivoDados.eof(); tamanhoDoArquivo++){std::getline(arquivoDados,linha);}
    arquivoDados.close();
}

Pessoa* dadosDoArquivo::obterDadosDoArquivo()
{
    try
    {
        int pos = 0;

        std::ifstream arquivoDados;

        arquivoDados.open(nomeDoArquivoNoDisco.toStdString().c_str());
        if(!arquivoDados.is_open() ) throw QString("Erro na Abertura do Arquivo");
        std::string linha;
        Pessoa* vetor =  new Pessoa[tamanhoDoArquivo+tamanhoDoArquivo];
        std::getline(arquivoDados,linha);
        while(!arquivoDados.eof())
        {

            QString linhaAux=QString::fromStdString(linha);
            QStringList lista = linhaAux.split(';');
                Pessoa Pessoa;
                vetor[pos].setCPF(lista[0]);
                vetor[pos].setNome(lista[1]);
                vetor[pos].setEndereco(lista[2]);
                vetor[pos].setTelefone(lista[3]);
                vetor[pos].setEmail(lista[4]);
                std::getline(arquivoDados,linha);
                pos++;
        }
    arquivoDados.close();
    return vetor;
    }
    catch (QString &erro)
    {
        throw erro;
    }
    catch(std::bad_alloc&)
    {
        throw QString("Estrutura de dados vector nao criada");
    }
}
ofstream arquivo("ArquivoPessoa.txt", ios::out);
void dadosDoArquivo::adicionarPessoa(QString CPF, QString nome, QString endereco,QString telefone, QString email)
{
    QString dados = CPF+";"+nome+";"+endereco+";"+telefone+";"+email;
    arquivo<<dados.toStdString().c_str()<<std::endl;
}



