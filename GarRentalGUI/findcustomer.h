#pragma once

#include <QWidget>
#include <QDialog>
#include "databasemanager.h"

namespace Ui {
class FindCustomer;
}

class FindCustomer : public QDialog
{
    Q_OBJECT

public:
    explicit FindCustomer(DatabaseManager *d, QWidget *parent = nullptr);
    ~FindCustomer();

private slots:
    void on_pushButton_clicked();
    void on_Unassign_clicked();

private:
    Ui::FindCustomer *ui;
    DatabaseManager *dbm;
};
