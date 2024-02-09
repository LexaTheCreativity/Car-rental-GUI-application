#include "findcar.h"
#include "ui_findcar.h"
#include <QMessageBox>

FindCar::FindCar(DatabaseManager *D, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FindCar),
    dbm(D)
{
    ui->setupUi(this);
}

FindCar::~FindCar()
{
    delete ui;
}

void FindCar::on_AssignButton_clicked()
{
    dbm->SearchCustomerID = ui->AssignCusIDText->toPlainText().toInt();

    if(!dbm->searchCustomer(dbm->SearchCustomerID))
    {
        QMessageBox::warning(this, "Customer not found", "The customer you want to assign does not exist");
        return;
    }

    if(dbm->searchRental(dbm->SearchRegnum))
    {
        QMessageBox::warning(this, "Can not assign", "Can not assign a car to more than one customer");
        return;
    }

    dbm->assignCar(dbm->SearchRegnum, dbm->SearchCustomerID);

    ui->AssignCusIDText->clear();

    close();
}

void FindCar::on_UnassignButton_clicked()
{
    dbm->SearchCustomerID = ui->UnassignCusIDText->toPlainText().toInt();

    if(!dbm->searchCustomer(dbm->SearchCustomerID))
    {
        QMessageBox::warning(this, "Customer not found", "The customer you want to unassign does not exist");
        return;
    }

    dbm ->unassignCar(dbm->SearchRegnum, dbm->SearchCustomerID);

    ui->UnassignCusIDText->clear();

    close();
}
