#ifndef REGISTERADMIN_H
#define REGISTERADMIN_H

#include <QDialog>
#include <QtSql>
#include <QMessageBox>

namespace Ui {
class registeradmin;
}

class registeradmin : public QDialog
{
    Q_OBJECT

public:
    explicit registeradmin(QWidget *parent = nullptr);
    ~registeradmin();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::registeradmin *ui;
};

#endif // REGISTERADMIN_H
