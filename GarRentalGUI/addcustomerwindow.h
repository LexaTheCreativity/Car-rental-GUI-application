#pragma once

#include <QWidget>
#include <QDialog>
#include "databasemanager.h"

namespace Ui {
class AddcustomerWindow;
}

class AddcustomerWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AddcustomerWindow(DatabaseManager *D, QWidget *parent = nullptr);
    ~AddcustomerWindow();

private slots:
    void on_addCustomerButton_clicked();

private:
    Ui::AddcustomerWindow *ui;
    DatabaseManager *dbm;

    int AddcustomerID;
    QString AddphoneNum;
    QString AddfirstName;
    QString AddlastName;
};
