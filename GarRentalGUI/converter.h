#pragma once

#include "json.hpp"
#include "rapidcsv.h"
#include "data_defs.h"

using namespace nlohmann;

namespace Converter
{
    // struct -> json

    inline json GetJson(const Car &car)
    {
        json j;
        j["RegNum"] = car.regNum.toStdString();
        j["Model"] = car.model.toStdString();
        j["Price"] = car.price;
        return j;
    }

    inline json GetJson(const Customer &customer)
    {
        json j;
        j["CustomerID"] = customer.customerID;
        j["PhoneNum"] = customer.phoneNum.toStdString();
        j["FirstName"] = customer.firstName.toStdString();
        j["LastName"] = customer.lastName.toStdString();
        return j;
    }

    inline json GetJson(const Rental &rental)
    {
        json j;
        j["RegNum"] = rental.regNum.toStdString();
        j["CustomerID"] = rental.customerID;
        return j;
    }

    // json -> struct

    inline Car GetCar(const json &j)
    {
        Car car;
        car.regNum = QString::fromStdString(j.at("RegNum"));
        car.model = QString::fromStdString(j.at("Model"));
        car.price = j.at("Price");
        return car;
    }

    inline Customer GetCustomer(const json &j)
    {
        Customer customer;
        customer.customerID = j.at("CustomerID");
        customer.phoneNum = QString::fromStdString(j.at("PhoneNum"));
        customer.firstName = QString::fromStdString(j.at("FirstName"));
        customer.lastName = QString::fromStdString(j.at("LastName"));
        return customer;
    }

    inline Rental GetRental(const json &j)
    {
        Rental rental;
        rental.customerID = j.at("CustomerID");
        rental.regNum = QString::fromStdString(j.at("RegNum"));
        return rental;
    }
}
