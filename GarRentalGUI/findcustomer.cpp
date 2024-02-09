#include "findcustomer.h"
#include "ui_findcustomer.h"
#include <QMessageBox>

FindCustomer::FindCustomer(DatabaseManager * D, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FindCustomer),
    dbm(D)
{
    ui->setupUi(this);
}

FindCustomer::~FindCustomer()
{
    delete ui;
}

//on button assign
void FindCustomer::on_pushButton_clicked()
{
    dbm->SearchRegnum = ui ->Assgincarreg->toPlainText();

    if(!dbm->searchCar(dbm->SearchRegnum))
    {
        QMessageBox::warning(this, "Car not found", "The car you want to assign does not exist");
        return;
    }

    if(dbm->searchRental(dbm->SearchRegnum))
    {
        QMessageBox::warning(this, "Can not assign", "Can not assign a car to more than one customer");
        return;
    }

    dbm->assignCar(dbm->SearchRegnum, dbm->SearchCustomerID);

    ui->Assgincarreg->clear();

    close();
}

//on button unassign
void FindCustomer::on_Unassign_clicked()
{
    dbm->SearchRegnum = ui->UnassignRegText->toPlainText();

    if(!dbm->searchCar(dbm->SearchRegnum))
    {
        QMessageBox::warning(this, "Car not found", "the car you want to unassign does not exist");
        return;
    }

    dbm->unassignCar(dbm->SearchRegnum, dbm->SearchCustomerID);

    ui->UnassignRegText->clear();

    close();
}
