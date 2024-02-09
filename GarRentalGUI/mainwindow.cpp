#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addwindow.h"
#include "editorremovewindow.h"
#include <QMessageBox>
#include "findcar.h"
#include "findcustomer.h"
#include "filemanager.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
    dbm("C:/Users/maren/Arle_er_Mongo/car_rental.sqlite")
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//add button on mainwindow -> opens a new add window
void MainWindow::on_pushButton_clicked()
{
    addWindow newAddWindow(&dbm, this);
    newAddWindow.setModal(true);
    newAddWindow.exec();
}

//"Find car" button on mainwindow -> shows the car with the reg number
void MainWindow::on_pushButton_2_clicked()
{
    dbm.SearchRegnum = ui->CarRegnumText->toPlainText();

    if(!dbm.searchCar(dbm.SearchRegnum))
    {
        QMessageBox::warning(this, "Car not found", "Try antoher car registration number");
        return;
    }

    FindCar newFindCarwindow(&dbm, this);
    newFindCarwindow.setModal(true);
    newFindCarwindow.exec();
}

//EditorRemove button on mainwindow -> opens a new edit or remove window
void MainWindow::on_pushButton_3_clicked()
{
    EditOrRemoveWindow newEditorRemovewindow(&dbm, this);
    newEditorRemovewindow.setModal(true);
    newEditorRemovewindow.exec();
}

//"Find customer" button on mainwindow -> shows the customer
void MainWindow::on_pushButton_4_clicked()
{
    dbm.SearchCustomerID = ui ->CustomerIDText->toPlainText().toInt();

    if(!dbm.searchCustomer(dbm.SearchCustomerID))
    {
        QMessageBox::warning(this, "Customer not found", "Try antoher customer ID");
        return;
    }

    FindCustomer newFindCustomer(&dbm, this);
    newFindCustomer.setModal(true);
    newFindCustomer.exec();
}

//Import JSON file into database
void MainWindow::on_ImportJSONbtn_clicked()
{
    auto [cars, customers, rentals] = FileManager::ImportJson("CarnRental.json");

    for (auto &car : cars)
        dbm.addCar(car);

    for (auto &customer : customers)
        dbm.addCustomer(customer);

    for (auto &rental : rentals)
        dbm.assignCar(rental.regNum, rental.customerID);
}

//Export JSON file with information from the database
void MainWindow::on_ExportJSONbtn_clicked()
{
    FileManager::Arrays arrays;
    arrays.cars = dbm.getAllCars();
    arrays.customers = dbm.getAllCustomers();
    arrays.rentals = dbm.getAllRentals();
    FileManager::ExportJson("CarRental.json", arrays);
}
