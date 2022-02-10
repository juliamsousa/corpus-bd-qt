#include "loginwindow.h"
#include "ui_loginwindow.h"



static QSqlDatabase bancoDeDados = QSqlDatabase::addDatabase("QSQLITE");

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);

    bancoDeDados.setDatabaseName("/Users/marinalima/Documents/OneDrive/Documentos/UFOP/2019.2/Engenharia de Software/corpusbd/DataBase/corpusDB.db");

    if(!bancoDeDados.open()){
        QMessageBox::warning(this, "ERRO", "Não foi possível conectar ao banco de dados.");
    }
}

LoginWindow::~LoginWindow()
{
    delete ui;
}


void LoginWindow::on_pushButton_clicked()
{
    QString username = ui->txt_name->text();
    QString password = ui->txt_password->text();

    if(!bancoDeDados.isOpen()){
        qDebug() << "Banco de dados não está aberto";
        return;
    }

    QSqlQuery query;
    if(query.exec("select * from corpus_admin where admin_name = '"+username+"' and admin_password = '"+password+"'")){
        int cont = 0;
        while(query.next()){
            cont++;
        }
        if(cont >0){
            this->close();
            mainWindow f_principal;
            f_principal.setModal(true);
            f_principal.exec();
        }
        else{
            QMessageBox::warning(this, "ERRO", "Erro ao validar login");
            ui->txt_name->clear();
            ui->txt_password->clear();
            ui->txt_name->setFocus();
        }
    }else{

        QMessageBox::warning(this, "ERRO", "Erro ao validar login");
    }
}

void LoginWindow::on_pushButton_2_clicked()
{
    registeradmin f_registerAdmin;
    f_registerAdmin.setModal(true);
    f_registerAdmin.exec();

}

void LoginWindow::on_pushButton_3_clicked()
{
    RecoverPassword f_recoverpassword;
    f_recoverpassword.setModal(true);
    f_recoverpassword.exec();
}
