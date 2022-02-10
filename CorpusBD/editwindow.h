#ifndef EDITWINDOW_H
#define EDITWINDOW_H

#include <QDialog>
#include <QtSql>
#include <QMessageBox>
#include "searchwindow.h"

namespace Ui {
class editwindow;
}

class editwindow : public QDialog
{
    Q_OBJECT

public:
    explicit editwindow(QWidget *parent = nullptr, int id_client = 0);
    ~editwindow();

private slots:
    void on_btn_save_clicked();

    void on_btn_cancel_clicked();

private:
    Ui::editwindow *ui;
};

#endif // EDITWINDOW_H
