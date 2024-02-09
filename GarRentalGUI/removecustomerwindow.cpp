#include "removecustomerwindow.h"
#include "ui_removecustomerwindow.h"
#include <QMessageBox>

RemoveCustomerWindow::RemoveCustomerWindow(DatabaseManager *D, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RemoveCustomerWindow),
    dbm(D)
{
    ui->setupUi(this);
}

RemoveCustomerWindow::~RemoveCustomerWindow()
{
    delete ui;
}

void RemoveCustomerWindow::on_removepushButton_clicked()
{
    remcus = ui ->removecustomertext->toPlainText().toInt();

    // Check if the car being edited exists
    if (!dbm->searchCustomer(remcus))
    {
        QMessageBox::warning(this, "Customer Not Found", "The customer you want to remove does not exist.");
        return;
    }

    // Check if the customer is assigned to a car
    if (dbm->searchRental(remcus))
    {
        QMessageBox::warning(this, "Customer can not be removed", "The customer you want to remove is assigned to a car, and can not be removed.");
        return;
    }

    dbm ->removeCustomer(remcus);

    ui ->removecustomertext->clear();

    close();
}
