#include "addcustomerwindow.h"
#include "ui_addcustomerwindow.h"
#include <QMessageBox>

AddcustomerWindow::AddcustomerWindow(DatabaseManager *D, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddcustomerWindow),
    dbm(D)
{
    ui->setupUi(this);
}

AddcustomerWindow::~AddcustomerWindow()
{
    delete ui;
}

void AddcustomerWindow::on_addCustomerButton_clicked()
{
    AddcustomerID = ui->CustomerID->toPlainText().toInt();
    AddphoneNum = ui->TeleNr->toPlainText();
    AddfirstName = ui->Firstname->toPlainText();
    AddlastName = ui->Lastname->toPlainText();

    // Check if any field is empty
    if (AddcustomerID == 0 || AddphoneNum.isEmpty() || AddfirstName.isEmpty() || AddlastName.isEmpty())
    {
        QMessageBox::warning(this, "Incomplete Information", "Please fill in all fields.");
        return;
    }

    dbm->addCustomer(Customer{.customerID = AddcustomerID, .phoneNum = AddphoneNum, .firstName = AddfirstName, .lastName = AddlastName});

    //Clears the text box
    ui->CustomerID->clear();
    ui->TeleNr->clear();
    ui->Firstname->clear();
    ui->Lastname->clear();

    dbm->getAllCustomers();

    close();
}

