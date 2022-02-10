#include "registerwindow.h"
#include "ui_registerwindow.h"

registerwindow::registerwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registerwindow)
{
    ui->setupUi(this);
}

registerwindow::~registerwindow()
{
    delete ui;
}

//fala que slavou com successo mesmo se não tiver digitado nada, consertar isso no futuro
void registerwindow::on_btn_save_clicked()
{
    QString name = ui->txt_name->text();
    QString age = ui->txt_age->text();
    QString plan = ui->txt_plan->text();
    QString address = ui->txt_address->text();
    QString phone = ui->txt_phone->text();
    QString gender = ui->txt_gender->text();

    QSqlQuery query;
    query.prepare("insert into corpus_client (client_name, client_age, client_plan, client_address, client_phone, client_gender) values"
                  "('"+name+"','"+age+"','"+plan+"','"+address+"','"+phone+"','"+gender+"')");
    if(query.exec()){
        QMessageBox::information(this,"","Registro gravado com sucesso");
        ui->txt_name->clear();
        ui->txt_age->clear();
        ui->txt_plan->clear();
        ui->txt_address->clear();
        ui->txt_phone->clear();
        ui->txt_gender->clear();
        ui->txt_name->setFocus();

    }else{
        qDebug() << "Erro ao inserir registro";
    }

}

void registerwindow::on_btn_cancel_clicked()
{
    this->close();
    mainWindow f_principal;
    f_principal.setModal(true);
    f_principal.exec();
}
