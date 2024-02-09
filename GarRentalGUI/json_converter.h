#pragma once

#include "json.hpp"
#include "data_defs.h"

using namespace nlohmann;

namespace JsonConverter
{
    // struct -> json

    void Convert(const Car &car, json &j)
    {
        j["Regnum"] = car.regNum.toStdString();
        j["Model"] = car.model.toStdString();
        j["Price"] = car.price;
    }

    void Convert(const Customer &customer, json &j)
    {
        j["CustomerID"] = customer.customerID;
        j["PhoneNum"] = customer.phoneNum.toStdString();
        j["FirstName"] = customer.firstName.toStdString();
        j["LastName"] = customer.lastName.toStdString();
    }

    void Convert(const Rental &rental, json &j)
    {
        j["RegNum"] = rental.regNum.toStdString();
        j["CustomerID"] = rental.customerID;
    }

    // json -> struct

    void Convert(const json &j, Car &car)
    {
        car.regNum = QString::fromStdString(j.at("RegNum"));
        car.model = QString::fromStdString(j.at("Model"));
        car.price = j.at("Price");
    }

    void Convert(const json &j, Customer &customer)
    {
        customer.customerID = j.at("CustomerID");
        customer.phoneNum = QString::fromStdString(j.at("PhoneNum"));
        customer.firstName = QString::fromStdString(j.at("FirstName"));
        customer.lastName = QString::fromStdString(j.at("LastName"));
    }

    void Convert(const json &j, Rental &rental)
    {
        rental.customerID = j.at("CustomerID");
        rental.regNum = QString::fromStdString(j.at("RegNum"));
    }
}
