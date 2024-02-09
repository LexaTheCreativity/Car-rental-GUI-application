#include "filemanager.h"
#include "converter.h"
#include <QFile>
#include <QTextStream>
#include "rapidcsv.h"

namespace FileManager
{
    const auto CSV_SEPARATOR = ',';

    Arrays ImportJson(const QString &filename)
    {
        QFile f = QFile(filename);
        Arrays arrays{};

        if(f.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            auto fileContents = f.readAll();
            auto data = json::parse(fileContents.data());

            for (auto &object : data["Cars"])
                arrays.cars.emplace_back(Converter::GetCar(object));

            for (auto &object : data["Customers"])
                arrays.customers.emplace_back(Converter::GetCustomer(object));

            for (auto &object : data["Rentals"])
                arrays.rentals.emplace_back(Converter::GetRental(object));

            f.close();
        }

        return arrays;
    }

    void ExportJson(const QString &filename, const Arrays &arrays)
    {
        QFile f = QFile(filename);

        if(f.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            json data;

            for (auto &row : arrays.cars)
                data["Cars"].emplace_back(Converter::GetJson(row));

            for (auto &row : arrays.customers)
                data["Customers"].emplace_back(Converter::GetJson(row));

            for (auto &row : arrays.rentals)
                data["Rentals"].emplace_back(Converter::GetJson(row));

            f.write(data.dump(4).c_str());
            f.close();
        }
    }

    std::vector<Car> ImportCsvCars(const QString &filename)
    {
        std::vector<Car> cars;
        auto doc = rapidcsv::Document(filename.toStdString(), rapidcsv::LabelParams(0, -1));

        const auto regNums = doc.GetColumn<std::string>(0);
        const auto models = doc.GetColumn<std::string>(1);
        const auto prices = doc.GetColumn<int>(2);

        for (size_t i = 0; i < doc.GetRowCount(); ++i)
        {
            Car car;
            car.regNum = QString::fromStdString(regNums[i]);
            car.model = QString::fromStdString(models[i]);
            car.price = prices[i];
            cars.emplace_back(car);
        }

        return cars;
    }

    std::vector<Customer> ImportCsvCustomers(const QString &filename)
    {
        std::vector<Customer> customers;
        auto doc = rapidcsv::Document(filename.toStdString(), rapidcsv::LabelParams(0, -1));

        const auto customerIDs = doc.GetColumn<int>(0);
        const auto firstNames = doc.GetColumn<std::string>(1);
        const auto lastNames = doc.GetColumn<std::string>(2);
        const auto phoneNums = doc.GetColumn<std::string>(3);

        for (size_t i = 0; i < doc.GetRowCount(); ++i)
        {
            Customer customer;
            customer.customerID = customerIDs[i];
            customer.firstName = QString::fromStdString(firstNames[i]);
            customer.lastName = QString::fromStdString(lastNames[i]);
            customer.phoneNum = QString::fromStdString(phoneNums[i]);
            customers.emplace_back(customer);
        }

        return customers;
    }

    std::vector<Rental> ImportCsvRentals(const QString &filename)
    {
        std::vector<Rental> rentals;
        auto doc = rapidcsv::Document(filename.toStdString(), rapidcsv::LabelParams(0, -1));

        const auto regNums = doc.GetColumn<std::string>(0);
        const auto customerIDs = doc.GetColumn<int>(1);

        for (size_t i = 0; i < doc.GetRowCount(); ++i)
        {
            Rental rental;
            rental.regNum = QString::fromStdString(regNums[i]);
            rental.customerID = customerIDs[i];
            rentals.emplace_back(rental);
        }

        return rentals;
    }

    void ExportCsv(const QString &filename, const std::vector<Car> &cars)
    {
        auto f = QFile(filename);

        if(f.open(QFile::WriteOnly))
        {
            QTextStream out(&f);
            out << "RegNum" << CSV_SEPARATOR << "Model" << CSV_SEPARATOR << "Price" << "\n";

            for (auto &car : cars)
            {
                out << car.regNum << CSV_SEPARATOR << car.model << CSV_SEPARATOR << car.price << "\n";
            }
        }
    }

    void ExportCsv(const QString &filename, std::vector<Customer> &customers)
    {
        auto f = QFile(filename);

        if(f.open(QFile::WriteOnly))
        {
            QTextStream out(&f);
            out << "CustomerID" << CSV_SEPARATOR << "FirstName" << CSV_SEPARATOR << "LastName" << CSV_SEPARATOR << "PhoneNum" << "\n";

            for (auto &customer : customers)
            {
                out << customer.customerID << CSV_SEPARATOR << customer.firstName << CSV_SEPARATOR << customer.lastName << CSV_SEPARATOR << customer.phoneNum << "\n";
            }
        }
    }

    void ExportCsv(const QString &filename, std::vector<Rental> &rentals)
    {
        auto f = QFile(filename);

        if(f.open(QFile::WriteOnly))
        {
            QTextStream out(&f);
            out << "RegNum" << CSV_SEPARATOR << "CustomerID" << "\n";

            for (auto &rental : rentals)
            {
                out << rental.regNum << CSV_SEPARATOR << rental.customerID << "\n";
            }
        }
    }

    Arrays ImportXml(const QString &filename);

    void ExportXml(const QString &filename, const Arrays &arrays);
}
