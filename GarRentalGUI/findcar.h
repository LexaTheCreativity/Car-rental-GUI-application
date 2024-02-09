#pragma once

#include <QWidget>
#include "databasemanager.h"
#include <QDialog>

namespace Ui {
class FindCar;
}

class FindCar : public QDialog
{
    Q_OBJECT

public:
    explicit FindCar(DatabaseManager * d, QWidget *parent = nullptr);
    ~FindCar();

private slots:
    void on_AssignButton_clicked();
    void on_UnassignButton_clicked();

private:
    Ui::FindCar *ui;
    DatabaseManager *dbm;
    int FindCarbutton;
};
