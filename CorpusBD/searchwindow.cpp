#include "searchwindow.h"
#include "ui_searchwindow.h"

searchwindow::searchwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::searchwindow)
{
    ui->setupUi(this);
    int contCustomers = 0;
    double faturamento = 0;
    QSqlQuery query;
    query.prepare("select * from corpus_client");
    if(query.exec()){
        int cont = 0;
        ui->tw_clients->setColumnCount(7);
        while(query.next()){
            ui->tw_clients->insertRow(cont);
            contCustomers++;
            for(int i = 0; i < 7; i++)
            {
                ui->tw_clients->setItem(cont,i,new QTableWidgetItem(query.value(i).toString()));
            }
            ui->tw_clients->setRowHeight(cont,20);
            cont++;
            switch(query.value(3).toInt()){
                case 1:
                    faturamento+=50;
                break;
                case 2:
                    faturamento+=60;
                break;
                case 3:
                    faturamento+=70;
                break;
                case 4:
                    faturamento+=80;
                break;
                case 5:
                    faturamento+=100;
                break;
                default:
                    faturamento+=0;
                break;
            }
        }
        ui->tw_clients->setColumnWidth(0,30);
        ui->tw_clients->setColumnWidth(1,220);
        ui->tw_clients->setColumnWidth(2,100);
        ui->tw_clients->setColumnWidth(3,100);
        ui->tw_clients->setColumnWidth(4,340);
        ui->tw_clients->setColumnWidth(5,170);
        ui->tw_clients->setColumnWidth(6,170);

        QStringList cabecalhos = {"ID","Nome","Idade","Plano","Endereço","Telefone","Sexo"};
        ui->tw_clients->setHorizontalHeaderLabels(cabecalhos);
        ui->tw_clients->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->tw_clients->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->tw_clients->verticalHeader()->setVisible(false);
        ui->tw_clients->setStyleSheet("QTableView {selection-background-color:blue}");
    }else{
        QMessageBox::warning(this,"ERRO","Erro ao pesquisar na tabela de clientes");
    }
    QString s = QString::number(faturamento);
    ui->txt_totalcustomers->setValue(contCustomers);
    ui->txt_faturamento->setText(s+".00");
}

searchwindow::~searchwindow()
{
    delete ui;
}

void searchwindow::on_btn_exit_clicked()
{
    this->close();
    mainWindow f_principal;
    f_principal.setModal(true);
    f_principal.exec();
}

//ainda não pesquisa
void searchwindow::on_btn_search_clicked()
{
    if(ui->btn_search->text() == "Pesquisar"){
    QString search_name = ui->txt_name->text();
    QSqlQuery query;
    query.prepare("select * from corpus_client where client_name='"+search_name+"'");
    if(query.exec()){
        if(search_name != ""){
        ui->tw_clients->clearContents();
        query.first();
        for(int i = 0; i < 6; i++){
            ui->tw_clients->setItem(0,i,new QTableWidgetItem(query.value(i).toString()));
        }
        ui->tw_clients->setRowHeight(0,20);
        ui->btn_search->setText("Limpar Pesquisa");
        }

    }else{
        QMessageBox::warning(this,"ERRO", "Não foi possivel buscar o contato");
    }
    }else{
        ui->tw_clients->clearContents();
        ui->btn_search->setText("Pesquisar");
        ui->tw_clients->clear();
        QSqlQuery query2;
        query2.prepare("select * from corpus_client");
        if(query2.exec()){
            int cont = 0;
            ui->tw_clients->setColumnCount(7);
            while(query2.next()){
                for(int i = 0; i < 7; i++)
                {
                    ui->tw_clients->setItem(cont,i,new QTableWidgetItem(query2.value(i).toString()));
                }
                ui->tw_clients->setRowHeight(cont,20);
                cont++;
            }
            QStringList cabecalhos = {"ID","Nome","Idade","Plano","Endereço","Telefone","Sexo"};
            ui->tw_clients->setHorizontalHeaderLabels(cabecalhos);
            ui->tw_clients->setEditTriggers(QAbstractItemView::NoEditTriggers);
            ui->tw_clients->setSelectionBehavior(QAbstractItemView::SelectRows);
            ui->tw_clients->verticalHeader()->setVisible(false);
            ui->tw_clients->setStyleSheet("QTableView {selection-background-color:blue}");
        }
        ui->txt_name->clear();
    }

}

void searchwindow::on_btn_update_clicked()
{
    int linha = ui->tw_clients->currentRow();
    int id = ui->tw_clients->item(linha,0)->text().toInt();
    int plano = ui->tw_clients->item(linha,3)->text().toInt();
    double faturamento = ui->txt_faturamento->text().toDouble();
    editwindow f_editarcontato(this, id);
    f_editarcontato.exec();
    QSqlQuery query;
    query.prepare("select * from corpus_client where client_id = "+QString::number(id));
    if(query.exec()){
        query.first();
        for(int i = 1; i < 7; i++)
        {
            ui->tw_clients->setItem(linha,i,new QTableWidgetItem(query.value(i).toString()));
        }
        if(query.value(3).toInt() != plano){

            switch(plano){
                case 1:
                    faturamento-=50;
                break;
                case 2:
                    faturamento-=60;
                break;
                case 3:
                    faturamento-=70;
                break;
                case 4:
                    faturamento-=80;
                break;
                case 5:
                    faturamento-=100;
                break;
                default:
                    faturamento-=0;
                break;
            }

            switch(query.value(3).toInt()){
                case 1:
                    faturamento+=50;
                break;
                case 2:
                    faturamento+=60;
                break;
                case 3:
                    faturamento+=70;
                break;
                case 4:
                    faturamento+=80;
                break;
                case 5:
                    faturamento+=100;
                break;
                default:
                    faturamento+=0;
                break;
            }
            QString s = QString::number(faturamento);
            ui->txt_faturamento->setText(s+".00");
        }
    }

}

void searchwindow::on_btn_delete_clicked()
{
    int linha = ui->tw_clients->currentRow();
    int id = ui->tw_clients->item(linha,0)->text().toInt();
    int plano = ui->tw_clients->item(linha,3)->text().toInt();
    QSqlQuery query;
    query.prepare("delete from corpus_client where client_id = "+QString::number(id));
    if(query.exec()){
        ui->tw_clients->removeRow(linha);
        QMessageBox::information(this, "", "Registro excluido");
    }else{
        QMessageBox::warning(this, "ERRO", "Erro ao excluir registro");
    }
    ui->txt_totalcustomers->setValue(ui->txt_totalcustomers->value()-1);
    double faturamento = ui->txt_faturamento->text().toDouble();

    switch(plano){
        case 1:
            faturamento-=50;
        break;
        case 2:
            faturamento-=60;
        break;
        case 3:
            faturamento-=70;
        break;
        case 4:
            faturamento-=80;
        break;
        case 5:
            faturamento-=100;
        break;
        default:
            faturamento-=0;
        break;
    }

    QString s = QString::number(faturamento);
    ui->txt_faturamento->setText(s+".00");
}
