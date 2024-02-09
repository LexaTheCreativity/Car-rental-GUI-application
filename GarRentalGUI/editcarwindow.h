#pragma once

#include <QWidget>
#include <QDialog>
#include "databasemanager.h"

namespace Ui {
class EditCarWindow;
}

class EditCarWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EditCarWindow(DatabaseManager *D, QWidget *parent = nullptr);
    ~EditCarWindow();

private slots:
    void on_button_editCar_clicked();

private:
    Ui::EditCarWindow *ui;
    DatabaseManager *dbm;
    QString EditRegNum;
    QString EditModel;
    int EditPrice;
};
