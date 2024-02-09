#pragma once

#include <QHBoxLayout>
#include <QDebug>
#include <QtSql/QSqlDatabase>
#include <optional>

#include "data_defs.h"

class DatabaseManager
{
public:
    DatabaseManager(const QString &path);

    bool addCar(const Car &car);
    bool addCustomer(const Customer &customer);

    bool editCar(const QString &regNum, const Car &newCar);
    bool editCustomer(const Customer &newCustomer);

    bool removeCar(const QString &regNum);
    bool removeCustomer(const int customerID);

    bool assignCar(const QString &regNum, const int customerID);
    bool unassignCar(const QString &regNum, const int customerID);

    bool searchCar(const QString &regNum);
    bool searchCustomer(const int customerID);

    bool searchRental(const QString &regNum);
    bool searchRental(const int customerID);

    std::vector<Car> getAllCars();
    std::vector<Customer> getAllCustomers();
    std::vector<Rental> getAllRentals();

    QString SearchRegnum;
    int SearchCustomerID;

private:
    QSqlDatabase db;
};
