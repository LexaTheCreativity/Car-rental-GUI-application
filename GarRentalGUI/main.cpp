#include "mainwindow.h"
#include "databasemanager.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    // The code below streams the database contents to qDebug

    auto dbm = DatabaseManager("C:/Users/maren/Arle_er_Mongo/car_rental.sqlite");

    auto cars = dbm.getAllCars();
    auto customers = dbm.getAllCustomers();
    auto rentals = dbm.getAllRentals();

    qDebug() << "Cars:";
    for (auto &car : cars)
        qDebug() << car.regNum << " - " << car.model << " - " << car.price;

    qDebug() << "Customers:";
    for (auto &customer : customers)
        qDebug() << customer.customerID << " - " << customer.phoneNum << " - " << (customer.firstName + " " + customer.lastName);

    qDebug() << "Rentals:";
    for (auto &rental : rentals)
        qDebug() << rental.regNum << " - " << rental.customerID;

    return a.exec();
}
