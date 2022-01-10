#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <pessoa.h>
#include <ordenar.h>
#include <QFileDialog>
#include <QString>
#include <dadosdoarquivo.h>
#include <QMessageBox>
#include <fstream>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonAdicionar_clicked();
    void printLista();
    void on_pushButtonAbrir_clicked();

    void on_pushButtonOrdenar_clicked();

    void on_pushButtonOrdenar_2_clicked();

    void on_pushButtonExcluir_clicked();

    void on_pushButtonSalvar_clicked();

    void on_pushButtonOK_clicked();

    void on_pushButtonLimpar_clicked();

    void on_pushButtonIncluir_clicked();

private:
    Ui::MainWindow *ui;
    dadosDoArquivo *Vetor;
    QString nomeDoArquivo;
    Ordenar *lista;
};
#endif // MAINWINDOW_H
