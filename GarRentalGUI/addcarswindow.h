#pragma once

#include <QWidget>
#include <QDialog>
#include "databasemanager.h"

namespace Ui {
class AddCarsWindow;
}

class AddCarsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AddCarsWindow(DatabaseManager *D, QWidget *parent = nullptr);
    ~AddCarsWindow();

private slots:
    void on_button_addCar_clicked();

private:
    Ui::AddCarsWindow *ui;
    DatabaseManager *dbm;
    QString AddRegNum;
    QString AddModel;
    int AddPrice;
};
