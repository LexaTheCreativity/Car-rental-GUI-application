#include "editcustomerwindow.h"
#include "ui_editcustomerwindow.h"
#include <QMessageBox>

editCustomerWindow::editCustomerWindow(DatabaseManager *D, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editCustomerWindow),
    dbm(D)
{
    ui->setupUi(this);
}

editCustomerWindow::~editCustomerWindow()
{
    delete ui;
}

void editCustomerWindow::on_EditCustomerButton_clicked()
{
    EditcustomerID = ui->EditCustomerID->toPlainText().toInt();
    EditphoneNum = ui->EditTeleNr->toPlainText();
    EditfirstName = ui->EditFirstname->toPlainText();
    EditlastName = ui->EditLastname->toPlainText();

    // Check if the car being edited exists
    if (!dbm->searchCustomer(EditcustomerID))
    {
        QMessageBox::warning(this, "Customer Not Found", "The customer you want to edit does not exist.");
        return;
    }

    // Check if any field is empty
    if (EditcustomerID == 0 || EditphoneNum.isEmpty() || EditfirstName.isEmpty() || EditlastName.isEmpty())
    {
        QMessageBox::warning(this, "Incomplete Information", "Please fill in all fields.");
        return;
    }

    dbm->editCustomer(Customer{.customerID = EditcustomerID, .phoneNum = EditphoneNum, .firstName = EditfirstName, .lastName = EditlastName});

    //Clears the text box
    ui->EditCustomerID->clear();
    ui->EditTeleNr->clear();
    ui->EditFirstname->clear();
    ui->EditLastname->clear();

    dbm->getAllCustomers();

    close();
}
