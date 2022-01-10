#include "ordenar.h"

Ordenar::Ordenar(QString nomeDoArquivoNoDisco):
    dados(0),
    dados2(0),
    tam(0),
    contador(0)
{
  try
  {
      dadosDoArquivo aux(nomeDoArquivoNoDisco);
      dados = aux.obterDadosDoArquivo(); //retorna o vetor de dados do arquivo
      tam = aux.getTamanhoDoArquivo();
      dados2 = aux.obterDadosDoArquivo();

  }
  catch (QString &erro)
  {
      throw erro;
  }
}

Ordenar::Ordenar(Ordenar* dat)
{
    dados=dat->getDados();
    tam=dat->getTam();
    dados2 = dat->getDados();
    //contador = tam/2;
}
int Ordenar::buscar(QString elemento)
{
    for(int i=0;i<tam;i++)
    {
        if(elemento == dados[i].getCPF()) return i;
    }
    return -1;
}
void Ordenar::insertionSort()
{
    {
        int i, j;
        for(i = 1; i < tam; i++)
        {
            Pessoa troca = dados[i];
            for( j = i-1; j >=0  && dados[j].getNome() > troca.getNome(); j--)
                dados[j+1] = dados[j];
            dados[j+1] = troca;
        }
    }
}
void Ordenar::excluir(QString elemento)
{

    for(int i=0;i<tam;i++)
    {
        if(elemento == dados[i].getCPF())
        {
            dados[i].setCPF("ZNULL");
            dados[i].setNome("ZNULL");
            dados[i].setEndereco("ZNULL");
            dados[i].setTelefone("ZNULL");
            dados[i].setEmail("ZNULL");
            tam--;
        }
    }
}

void Ordenar::alterarCPF(QString elemento, QString dado)
{
    for(int i=0;i<tam;i++)
    {
        if(elemento == dados[i].getCPF())
        {
            dados[i].setCPF(dado);
        }
    }
}
void Ordenar::alterarNome(QString elemento, QString dado)
{
    for(int i=0;i<tam;i++)
    {
        if(elemento == dados[i].getCPF())
        {
            dados[i].setNome(dado);
        }
    }
}
void Ordenar::alterarEndereco(QString elemento, QString dado)
{
    for(int i=0;i<tam;i++)
    {
        if(elemento == dados[i].getCPF())
        {
            dados[i].setEndereco(dado);
        }
    }
}
void Ordenar::alterarTelefone(QString elemento, QString dado)
{
    for(int i=0;i<tam;i++)
    {
        if(elemento == dados[i].getCPF())
        {
            dados[i].setTelefone(dado);
        }
    }
}
void Ordenar::alterarEmail(QString elemento, QString dado)
{
    for(int i=0;i<tam;i++)
    {
        if(elemento == dados[i].getCPF())
        {
           dados[i].setEmail(dado);
        }
    }
}
void Ordenar::incluir(QString CPF, QString nome, QString endereco,QString telefone, QString email)
{

    dados[tam].setCPF(CPF);
    dados[tam].setNome(nome);
    dados[tam].setEndereco(endereco);
    dados[tam].setTelefone(telefone);
    dados[tam].setEmail(email);
    tam++;

}

void Ordenar::salvarExcluidos()
{
    ofstream arquivoExcluido("ArquivoPosSalvamento.txt", ios::out);
    for(int i=0; i<tam;i++)
    {

        if(dados[i].getCPF()!="ZNULL")
        {
            QString dadosExcluidos = dados[i].getCPF()+";" + dados[i].getNome() +";" + dados[i].getEndereco() +";" + dados[i].getTelefone() +";" + dados[i].getEmail();
            arquivoExcluido<<dadosExcluidos.toStdString()<<std::endl;
        }
    }

}

