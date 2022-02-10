#ifndef RECOVERPASSWORD_H
#define RECOVERPASSWORD_H

#include <QDialog>
#include <QtSql>

namespace Ui {
class RecoverPassword;
}

class RecoverPassword : public QDialog
{
    Q_OBJECT
    QSqlQuery query;

public:
    explicit RecoverPassword(QWidget *parent = nullptr);
    ~RecoverPassword();

private slots:

    void on_bt_buscar_clicked();

    void on_bt_confirmar_clicked();

private:
    Ui::RecoverPassword *ui;

};

#endif // RECOVERPASSWORD_H
