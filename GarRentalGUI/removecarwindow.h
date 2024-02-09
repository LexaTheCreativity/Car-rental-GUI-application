#pragma once

#include <QWidget>
#include <QDialog>
#include "databasemanager.h"

namespace Ui {
class RemoveCarWindow;
}

class RemoveCarWindow : public QDialog
{
    Q_OBJECT

public:
    explicit RemoveCarWindow(DatabaseManager *D, QWidget *parent = nullptr);
    ~RemoveCarWindow();

private slots:
    void on_RemoveCarButton_clicked();

private:
    Ui::RemoveCarWindow *ui;
    DatabaseManager *dbm;
    QString RemoveCar;
};
