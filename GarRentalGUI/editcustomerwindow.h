#pragma once

#include <QWidget>
#include <QDialog>
#include "databasemanager.h"

namespace Ui {
class editCustomerWindow;
}

class editCustomerWindow : public QDialog
{
    Q_OBJECT

public:
    explicit editCustomerWindow(DatabaseManager *D, QWidget *parent = nullptr);
    ~editCustomerWindow();

private slots:
    void on_EditCustomerButton_clicked();

private:
    Ui::editCustomerWindow *ui;
    DatabaseManager *dbm;

    int EditcustomerID;
    QString EditphoneNum;
    QString EditfirstName;
    QString EditlastName;
};
