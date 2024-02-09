#pragma once

#include <QWidget>
#include <QDialog>
#include "databasemanager.h"

namespace Ui {
class EditOrRemoveWindow;
}

class EditOrRemoveWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EditOrRemoveWindow(DatabaseManager *D, QWidget *parent = nullptr);
    ~EditOrRemoveWindow();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();

private:
    Ui::EditOrRemoveWindow *ui;
    DatabaseManager *dbm;
};
