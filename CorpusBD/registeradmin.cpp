#include "registeradmin.h"
#include "ui_registeradmin.h"

registeradmin::registeradmin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registeradmin)
{
    ui->setupUi(this);
}

registeradmin::~registeradmin()
{
    delete ui;
}

void registeradmin::on_pushButton_2_clicked()
{
    this->close();
}

void registeradmin::on_pushButton_clicked()
{
    QString name = ui->txt_name->text();
    QString password = ui->txt_password->text();
    QString question = ui->txt_question->text();
    QString answer = ui->txt_answer->text();

    QSqlQuery query;
    query.prepare("insert into corpus_admin (admin_name, admin_password, admin_question, admin_answer) values"
                  "('"+name+"','"+password+"','"+question+"','"+answer+"')");
    if(query.exec()){
        QMessageBox::information(this,"","Registro gravado com sucesso");
        this->close();

    }else{
        qDebug() << "Erro ao inserir registro";
    }

}
