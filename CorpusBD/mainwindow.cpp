#include "mainwindow.h"
#include "ui_mainwindow.h"

mainWindow::mainWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mainWindow)
{
    ui->setupUi(this);
}

mainWindow::~mainWindow()
{
    delete ui;
}

void mainWindow::on_btn_register_clicked()
{
    this->close();
    registerwindow f_novocontato;
    f_novocontato.setModal(true);
    f_novocontato.exec();
}

void mainWindow::on_btn_exit_clicked()
{
    this->close();
}

void mainWindow::on_btn_search_clicked()
{
    this->close();
    searchwindow f_searchwindow;
    f_searchwindow.setModal(true);
    f_searchwindow.exec();

}
