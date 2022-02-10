#ifndef SEARCHWINDOW_H
#define SEARCHWINDOW_H

#include <QDialog>
#include <QtSql>
#include <QMessageBox>
#include "mainwindow.h"
#include "editwindow.h"

namespace Ui {
class searchwindow;
}

class searchwindow : public QDialog
{
    Q_OBJECT

public:
    explicit searchwindow(QWidget *parent = nullptr);
    ~searchwindow();

private slots:
    void on_btn_exit_clicked();

    void on_btn_search_clicked();

    void on_btn_update_clicked();

    void on_btn_delete_clicked();

private:
    Ui::searchwindow *ui;
};

#endif // SEARCHWINDOW_H
