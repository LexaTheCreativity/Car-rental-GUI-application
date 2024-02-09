#include "databasemanager.h"

#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>

DatabaseManager::DatabaseManager(const QString &path)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(path);

    if(db.open())
        qDebug() << "Database successfully opened";
    else
        qDebug() << "Database failed to open";
}

bool DatabaseManager::addCar(const Car &car)
{
    auto query = QSqlQuery("INSERT INTO Car (RegNum, Model, Price) VALUES (?, ?, ?)");
    query.addBindValue(car.regNum);
    query.addBindValue(car.model);
    query.addBindValue(car.price);
    return query.exec();
}

bool DatabaseManager::addCustomer(const Customer &customer)
{
    auto query = QSqlQuery("INSERT INTO Customer (CustomerID, PhoneNum, FirstName, LastName) VALUES (?, ?, ?, ?)");
    query.addBindValue(customer.customerID);
    query.addBindValue(customer.phoneNum);
    query.addBindValue(customer.firstName);
    query.addBindValue(customer.lastName);
    return query.exec();
}

bool DatabaseManager::editCar(const QString &regNum, const Car &newCar)
{
    auto u = QSqlQuery("UPDATE Car SET RegNum=?, Model=?, Price=? WHERE RegNum=?");
    u.addBindValue(newCar.regNum);
    u.addBindValue(newCar.model);
    u.addBindValue(newCar.price);
    u.addBindValue(regNum);
    return u.exec();
}

bool DatabaseManager::editCustomer(const Customer &customer)
{
    auto u = QSqlQuery("UPDATE Customer SET PhoneNum=?, FirstName=?,\
                        LastName=? WHERE CustomerID=?");
    u.addBindValue(customer.phoneNum);
    u.addBindValue(customer.firstName);
    u.addBindValue(customer.lastName);
    u.addBindValue(customer.customerID);
    return u.exec();
}

bool DatabaseManager::removeCar(const QString &regNum)
{
    auto del = QSqlQuery("DELETE FROM Car WHERE RegNum=?");
    del.addBindValue(regNum);
    return del.exec();
}

bool DatabaseManager::removeCustomer(const int customerID)
{
    auto del = QSqlQuery("DELETE FROM Customer WHERE CustomerID=?");
    del.addBindValue(customerID);
    return del.exec();
}

bool DatabaseManager::assignCar(const QString &regNum, const int customerID)
{
    // Check regnum
    auto q = QSqlQuery("SELECT RegNum FROM Car WHERE Regnum=?");
    q.addBindValue(regNum);

    if(q.exec() && q.next())
    {
        // Check customer
        q = QSqlQuery("SELECT CustomerID FROM Customer WHERE CustomerID=?");
        q.addBindValue(customerID);

        if(q.exec() && q.next())
        {
            // Both customer and car exist in db
            q = QSqlQuery("INSERT INTO Rental (RegNum, CustomerID) VALUES (?, ?)");
            q.addBindValue(regNum);
            q.addBindValue(customerID);
            return q.exec();
        }
    }

    return false;
}

bool DatabaseManager::unassignCar(const QString &regNum, const int customerID)
{
    // Check regnum
    auto q = QSqlQuery("SELECT RegNum FROM Rental WHERE Regnum=?");
    q.addBindValue(regNum);

    if(q.exec() && q.next())
    {
        // Check customer
        q = QSqlQuery("SELECT CustomerID FROM Rental WHERE CustomerID=?");
        q.addBindValue(customerID);

        if(q.exec() && q.next())
        {
            // Both customer and car exist in db
            auto del = QSqlQuery("DELETE FROM Rental WHERE RegNum=? AND CustomerID=?");
            del.addBindValue(regNum);
            del.addBindValue(customerID);
            return del.exec();
        }
    }

    return false;
}

bool DatabaseManager::searchCar(const QString &regNum)
{
    auto q = QSqlQuery("SELECT RegNum FROM Car WHERE Regnum=?");
    q.addBindValue(regNum);
    return q.exec() && q.next();
}

bool DatabaseManager::searchCustomer(const int customerID)
{
    auto q = QSqlQuery("SELECT CustomerID FROM Customer WHERE CustomerID=?");
    q.addBindValue(customerID);
    return q.exec() && q.next();
}

bool DatabaseManager::searchRental(const QString &regNum)
{
    auto q = QSqlQuery("SELECT RegNum FROM Rental WHERE Regnum=?");
    q.addBindValue(regNum);
    return q.exec() && q.next();
}

bool DatabaseManager::searchRental(const int customerID)
{
    auto q = QSqlQuery("SELECT CustomerID FROM Rental WHERE CustomerID=?");
    q.addBindValue(customerID);
    return q.exec() && q.next();
}

std::vector<Car> DatabaseManager::getAllCars()
{
    std::vector<Car> v;
    auto q = QSqlQuery("SELECT * FROM Car");

    while(q.next())
    {
        v.emplace_back(Car{.regNum = q.value(0).toString(),
                           .model = q.value(1).toString(),
                           .price = q.value(2).toInt()});
    }

    return v;
}

std::vector<Customer> DatabaseManager::getAllCustomers()
{
    std::vector<Customer> v;
    auto q = QSqlQuery("SELECT * FROM Customer");

    while(q.next())
    {
        v.emplace_back(Customer{.customerID = q.value(0).toInt(),
                                .phoneNum = q.value(1).toString(),
                                .firstName = q.value(2).toString(),
                                .lastName = q.value(3).toString()});
    }

    return v;
}

std::vector<Rental> DatabaseManager::getAllRentals()
{
    std::vector<Rental> v;
    auto q = QSqlQuery("SELECT * FROM Rental");

    while(q.next())
    {
        v.emplace_back(Rental{.regNum = q.value(0).toString(), .customerID = q.value(1).toInt()});
    }

    return v;
}
