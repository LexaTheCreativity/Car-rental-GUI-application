#pragma once

#include <QMainWindow>
#include "databasemanager.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    //Add button
    void on_pushButton_clicked();

    //find car
    void on_pushButton_2_clicked();

    //edit or remove
    void on_pushButton_3_clicked();

    //find customer
    void on_pushButton_4_clicked();

    //import JSON
    void on_ImportJSONbtn_clicked();

    //export JSON
    void on_ExportJSONbtn_clicked();

private:
    Ui::MainWindow *ui;
    DatabaseManager dbm;
};
