#pragma once

#include <QtSql/QSqlDatabase>

struct Car
{
    QString regNum;
    QString model;
    int price;
};

struct Customer
{
    int customerID;
    QString phoneNum;
    QString firstName;
    QString lastName;
};

struct Rental
{
    QString regNum;
    int customerID;
};
