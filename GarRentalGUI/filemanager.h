#pragma once

#include <vector>
#include <QFile>
#include "data_defs.h"

namespace FileManager
{
    struct Arrays
    {
        std::vector<Car> cars;
        std::vector<Customer> customers;
        std::vector<Rental> rentals;
    };

    Arrays ImportJson(const QString &filename);
    void ExportJson(const QString &filename, const Arrays &arrays);

    std::vector<Car> ImportCsvCars(const QString &filename);
    std::vector<Customer> ImportCsvCustomers(const QString &filename);
    std::vector<Rental> ImportCsvRentals(const QString &filename);
    void ExportCsv(const QString &filename, const std::vector<Car> &cars);
    void ExportCsv(const QString &filename, const std::vector<Customer> &customers);
    void ExportCsv(const QString &filename, const std::vector<Rental> &rentals);

    Arrays ImportXml(const QString &filename);
    void ExportXml(const QString &filename, const Arrays &arrays);
}
