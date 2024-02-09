#include "editorremovewindow.h"
#include "ui_editorremovewindow.h"
#include "editcarwindow.h"
#include "removecarwindow.h"
#include "editcustomerwindow.h"
#include "removecustomerwindow.h"

EditOrRemoveWindow::EditOrRemoveWindow(DatabaseManager *D, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditOrRemoveWindow),
    dbm(D)
{
    ui->setupUi(this);
}

EditOrRemoveWindow::~EditOrRemoveWindow()
{
    delete ui;
}

//edit car -> opens a new window to indentify the car thats gonna be edtied
void EditOrRemoveWindow::on_pushButton_clicked()
{
    EditCarWindow newEditcarWIn(dbm, this);
    newEditcarWIn.setModal(true);
    newEditcarWIn.exec();
}

//remove car -> opens a new window
void EditOrRemoveWindow::on_pushButton_2_clicked()
{
    RemoveCarWindow newRemovecarWin(dbm, this);
    newRemovecarWin.setModal(true);
    newRemovecarWin.exec();
}

void EditOrRemoveWindow::on_pushButton_3_clicked()
{
    editCustomerWindow newEditCustomerWin(dbm, this);
    newEditCustomerWin.setModal(true);
    newEditCustomerWin.exec();
}

void EditOrRemoveWindow::on_pushButton_4_clicked()
{
    RemoveCustomerWindow newRemvoeCustomerWin(dbm, this);
    newRemvoeCustomerWin.setModal(true);
    newRemvoeCustomerWin.exec();
}
