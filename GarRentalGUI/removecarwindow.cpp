#include "removecarwindow.h"
#include "ui_removecarwindow.h"
#include <QMessageBox>

RemoveCarWindow::RemoveCarWindow(DatabaseManager *D, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RemoveCarWindow),
    dbm(D)
{
    ui->setupUi(this);
}

RemoveCarWindow::~RemoveCarWindow()
{
    delete ui;
}

void RemoveCarWindow::on_RemoveCarButton_clicked()
{
    RemoveCar = ui->RemoveCarRegnumText->toPlainText();

    // Check if the car being edited exists
    if (!dbm->searchCar(RemoveCar))
    {
        QMessageBox::warning(this, "Car Not Found", "The car you want to remove does not exist.");
        return;
    }

    // Check if the car is assigned to a customer
    if (dbm->searchRental(RemoveCar))
    {
        QMessageBox::warning(this, "Car can not be removed", "The car you want to remove is assigned to a customer, and can not be removed.");
        return;
    }

    dbm->removeCar(RemoveCar);

    ui->RemoveCarRegnumText->clear();

    close();
}
