#include "mainwindow.h"
#include "ui_mainwindow.h"
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabela->setStyleSheet("QTableView {selection-background-color:lightgreen}");
    ui->pushButtonExcluir->setStyleSheet("background-color: indianred");
    ui->pushButtonSalvar->setStyleSheet("background-color: lightgreen");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::printLista()
{
    for (int i = lista->getTam(); i >= 0; i--)
        ui->tabela->removeRow(i);

    int linha = 0;

    for (int i = 0; i < lista->getTam(); i++, linha++)
    {
        ui->tabela->insertRow(linha);
        Pessoa n = lista->getDados()[i];
        ui->tabela->setItem(linha,0,new QTableWidgetItem(QString::number(i+1)));
        ui->tabela->setItem(linha,1,new QTableWidgetItem(n.getCPF()));
        ui->tabela->setItem(linha,2,new QTableWidgetItem(n.getNome()));
        ui->tabela->setItem(linha,3,new QTableWidgetItem(n.getEndereco()));
        ui->tabela->setItem(linha,4,new QTableWidgetItem(n.getTelefone()));
        ui->tabela->setItem(linha,5,new QTableWidgetItem(n.getEmail()));
   }
}
void MainWindow::on_pushButtonAdicionar_clicked()
{
    try
    {
        QString CPF = ui->lineEditCPF->text();
        QString nome = ui->lineEditNome->text();
        QString endereco = ui->lineEditEndereco->text();
        QString telefone = ui->lineEditTelefone->text();
        QString email = ui->lineEditEmail->text();
        Vetor->adicionarPessoa(CPF,nome,endereco,telefone,email);
        throw QString ("Adicionado com Sucesso.");

    }
    catch (QString &erro)
    {
        QMessageBox::information(this,"ERRO",erro);
    }
 }

void MainWindow::on_pushButtonAbrir_clicked()
{
    try
    {
            nomeDoArquivo = QFileDialog::getOpenFileName(this,"Abrir Arquivo",QDir::currentPath(),"Arquivos Textos (*.csv *.txt)");
            if(nomeDoArquivo.isEmpty()) throw QString("Arquivo nao foi selecionado");

            ui->tabela->setColumnCount(6);
            //definir o cabecalho da tabela
            QStringList cabecalhos = {"","CPF", "Nome", "Endereco", "Telefone", "Email"};
            ui->tabela->setHorizontalHeaderLabels(cabecalhos);
            //nao poder editar os itens da tabela
            ui->tabela->setEditTriggers(QAbstractItemView::NoEditTriggers);
            //selecionar a linha toda
            ui->tabela->setSelectionBehavior(QAbstractItemView::SelectRows);
            //sumir com a linha ao lado
            ui->tabela->verticalHeader()->setVisible(false);

          //definir tamanho das colunas
            ui->tabela->setColumnWidth(0,50);//Pos
            ui->tabela->setColumnWidth(1,100);//CPF
            ui->tabela->setColumnWidth(2,250);//Nome
            ui->tabela->setColumnWidth(3,200);//Endereco
            ui->tabela->setColumnWidth(4,100);//Telefone
            ui->tabela->setColumnWidth(5,250);//Email
            lista = new Ordenar(nomeDoArquivo);
            printLista();


    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO",erro);
    }

}

void MainWindow::on_pushButtonOrdenar_clicked()
{
    try
    {
        lista = new Ordenar(lista);
        lista->insertionSort();
        printLista();
    }
    catch (QString &erro)
    {
        QMessageBox::information(this,"ERRO",erro);
    }

}

void MainWindow::on_pushButtonOrdenar_2_clicked()
{
    try
    {
        lista = new Ordenar(lista);
        QString elemento = ui->lineEditElemento->text();
        int n = lista->buscar(elemento);
        if(n==-1)throw QString("Não encontrado");
        else ui->tabela->selectRow(n);
    }
    catch (QString &erro)
    {
        QMessageBox::information(this,"ERRO",erro);
    }

}

void MainWindow::on_pushButtonExcluir_clicked()
{
    try
    {
        QString elemento = ui->lineEditElemento->text();
        lista = new Ordenar(lista);
        lista->excluir(elemento);
        printLista();
    }
    catch (QString &erro)
    {
        QMessageBox::information(this,"ERRO",erro);
    }


}

void MainWindow::on_pushButtonSalvar_clicked()
{
    try
    {
        lista = new Ordenar(lista);
        lista->salvarExcluidos();
        throw QString("Arquivo salvo com sucesso.");
    }
    catch (QString &erro)
    {
        QMessageBox::information(this,"ERRO",erro);
    }


}

void MainWindow::on_pushButtonOK_clicked()
{
    lista = new Ordenar(lista);
    QString elemento = ui->lineEditElemento->text();
    QString dado = ui->lineEditAlterar->text();
    if(ui->comboBox->currentIndex()==0)
    {
        lista->alterarCPF(elemento,dado);
        printLista();
    }
    else
    if(ui->comboBox->currentIndex()==1)
    {
         lista->alterarNome(elemento,dado);
         printLista();
    }
    else
    if(ui->comboBox->currentIndex()==2)
    {
         lista->alterarEndereco(elemento,dado);
         printLista();
    }
    else
    if(ui->comboBox->currentIndex()==3)
    {
         lista->alterarTelefone(elemento,dado);
         printLista();
    }
    else
    if(ui->comboBox->currentIndex()==4)
    {
         lista->alterarEmail(elemento,dado);
         printLista();
    }

}

void MainWindow::on_pushButtonLimpar_clicked()
{
    ui->lineEditCPF->clear();
    ui->lineEditNome->clear();
    ui->lineEditEndereco->clear();
    ui->lineEditTelefone->clear();
    ui->lineEditEmail->clear();

}

void MainWindow::on_pushButtonIncluir_clicked()
{
    try
    {
        lista = new Ordenar(lista);
        QString CPF = ui->lineEditCPF->text();
        QString nome = ui->lineEditNome->text();
        QString endereco = ui->lineEditEndereco->text();
        QString telefone = ui->lineEditTelefone->text();
        QString email = ui->lineEditEmail->text();
        lista->incluir(CPF,nome,endereco,telefone,email);
        throw QString ("Adicionado com Sucesso.");
        printLista();

    }
    catch (QString &erro)
    {
        QMessageBox::information(this,"ERRO",erro);
    }

}
