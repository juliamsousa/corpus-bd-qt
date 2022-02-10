#include "editwindow.h"
#include "ui_editwindow.h"

static int id;

editwindow::editwindow(QWidget *parent, int id_client) :
    QDialog(parent),
    ui(new Ui::editwindow)
{
    ui->setupUi(this);
    id = id_client;
    QSqlQuery query;
    query.prepare("select * from corpus_client where client_id = "+QString::number(id));
    if(query.exec()){
        query.first();
        ui->txt_name->setText(query.value(1).toString());
        ui->txt_age->setText(query.value(2).toString());
        ui->txt_plan->setText(query.value(3).toString());
        ui->txt_address->setText(query.value(4).toString());
        ui->txt_phone->setText(query.value(5).toString());
        ui->txt_gender->setText(query.value(6).toString());
    }else {
        QMessageBox::warning(this, "ERRO", "Erro ao selecionar contato");
    }
}

editwindow::~editwindow()
{
    delete ui;
}

void editwindow::on_btn_save_clicked()
{
    QString name = ui->txt_name->text();
    QString age = ui->txt_age->text();
    QString plan = ui->txt_plan->text();
    QString address = ui->txt_address->text();
    QString phone = ui->txt_phone->text();
    QString gender = ui->txt_gender->text();

    QSqlQuery query;
    query.prepare("update corpus_client set client_name = '"+name+"', client_age = '"+age+"', client_plan = '"+plan+"',client_address = '"+address+"', client_phone = '"+phone+"', client_gender = '"+gender+"' where client_id = "+QString::number(id));
    if(query.exec()){
        QMessageBox::warning(this, "", "Contato atualizado");
        this->close();
    }else {
        QMessageBox::warning(this, "ERRO", "Erro ao atualizar contato");
    }
}

void editwindow::on_btn_cancel_clicked()
{
    this->close();

}
