#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include "registerwindow.h"
#include "searchwindow.h"

namespace Ui {
class mainWindow;
}

class mainWindow : public QDialog
{
    Q_OBJECT

public:
    explicit mainWindow(QWidget *parent = nullptr);
    ~mainWindow();

private slots:
    void on_btn_register_clicked();

    void on_btn_exit_clicked();

    void on_btn_search_clicked();

private:
    Ui::mainWindow *ui;
};

#endif // MAINWINDOW_H
