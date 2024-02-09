#include "addwindow.h"
#include "ui_addwindow.h"
#include "addcarswindow.h"
#include "addcustomerwindow.h"

addWindow::addWindow(DatabaseManager *D, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addWindow),
    dbm(D)
{
    ui->setupUi(this);
}

addWindow::~addWindow()
{
    delete ui;
}

//add cars -> opens a new window to add cars
void addWindow::on_pushButton_clicked()
{
    AddCarsWindow  AddcarsWin(dbm, this);
    AddcarsWin.setModal(true);
    AddcarsWin.exec();
}

//add customer -> opens a new window to add customer
void addWindow::on_pushButton_2_clicked()
{
    AddcustomerWindow  AddCustWin(dbm, this);
    AddCustWin.setModal(true);
    AddCustWin.exec();
}
