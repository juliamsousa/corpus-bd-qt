#ifndef REGISTERWINDOW_H
#define REGISTERWINDOW_H

#include <QDialog>
#include <QtSql>
#include <QMessageBox>
#include "mainwindow.h"

namespace Ui {
class registerwindow;
}

class registerwindow : public QDialog
{
    Q_OBJECT

public:
    explicit registerwindow(QWidget *parent = nullptr);
    ~registerwindow();

private slots:
    void on_btn_save_clicked();

    void on_btn_cancel_clicked();

private:
    Ui::registerwindow *ui;
};

#endif // REGISTERWINDOW_H
