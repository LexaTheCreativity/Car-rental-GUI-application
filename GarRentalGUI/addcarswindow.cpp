#include "addcarswindow.h"
#include "ui_addcarswindow.h"
#include <QMessageBox>

AddCarsWindow::AddCarsWindow(DatabaseManager *D, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddCarsWindow),
    dbm(D)
{
    ui->setupUi(this);
}

AddCarsWindow::~AddCarsWindow()
{
    delete ui;
}

//on button add car
void AddCarsWindow::on_button_addCar_clicked()
{
    AddRegNum = ui->Regnum_text->toPlainText();
    AddModel = ui->model_text->toPlainText();
    AddPrice = ui->price_text->toPlainText().toInt();

    // Check if any field is empty
    if (AddRegNum.isEmpty() || AddModel.isEmpty() || AddPrice == 0)
    {
        QMessageBox::warning(this, "Incomplete Information", "Please fill in all fields.");
        return;
    }

    //ui ->statusbar->showMessage("Car added", 5000);
    dbm ->addCar(Car{.regNum = AddRegNum, .model = AddModel, .price = AddPrice});

    //Clears the text box
    ui->price_text->clear();
    ui->Regnum_text->clear();
    ui->model_text->clear();

    dbm->getAllCars();

    close();
}
