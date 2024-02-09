#pragma once

#include <QWidget>
#include <QDialog>
#include "databasemanager.h"

namespace Ui {
class RemoveCustomerWindow;
}

class RemoveCustomerWindow : public QDialog
{
    Q_OBJECT

public:
    explicit RemoveCustomerWindow(DatabaseManager *D, QWidget *parent = nullptr);
    ~RemoveCustomerWindow();

private slots:
    void on_removepushButton_clicked();

private:
    Ui::RemoveCustomerWindow *ui;
    DatabaseManager *dbm;
    int remcus;
};
