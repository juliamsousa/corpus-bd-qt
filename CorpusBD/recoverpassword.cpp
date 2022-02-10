#include "recoverpassword.h"
#include "ui_recoverpassword.h"
#include <QMessageBox>

RecoverPassword::RecoverPassword(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RecoverPassword)
{
    ui->setupUi(this);
    //ui->bt_confirmar->setEnabled(false);
}

RecoverPassword::~RecoverPassword()
{
    delete ui;
}



void RecoverPassword::on_bt_buscar_clicked()
{
    QString search_name = ui->txt_nome->text();
    query.prepare("select * from corpus_admin where admin_name='"+search_name+"'");
    if(query.exec()){
        if(search_name != ""){
            query.first();
            ui->lb_pergunta->setText(query.value(3).toString());
            if(query.value(1).toString() == search_name)
                ui->bt_confirmar->setEnabled(true);
        }else{
            QMessageBox::warning(this, "ERRO", "Nome não fornecido!");
        }
    }else{
        QMessageBox::warning(this, "ERRO", "Erro ao Validar banco de Dados!");
    }
}


void RecoverPassword::on_bt_confirmar_clicked()
{
    QString answer = ui->txt_resposta->text();

    if(answer == query.value(4).toString()){
        QMessageBox::information(this, "Senha do Usuário", "Sua senha é: "+query.value(2).toString());
        this->close();
    }else{
        QMessageBox::warning(this, "ERRO", "Resposta Incorreta!");
        ui->txt_resposta->clear();
    }
}
