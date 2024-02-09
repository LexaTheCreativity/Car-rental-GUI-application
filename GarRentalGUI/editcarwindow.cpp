#include "editcarwindow.h"
#include "ui_editcarwindow.h"
#include <QMessageBox>

EditCarWindow::EditCarWindow(DatabaseManager *D, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditCarWindow),
    dbm(D)
{
    ui->setupUi(this);
}

EditCarWindow::~EditCarWindow()
{
    delete ui;
}

void EditCarWindow::on_button_editCar_clicked()
{
    EditRegNum = ui->RegnumEdit_text->toPlainText();
    EditModel = ui->modelEdit_text->toPlainText();
    EditPrice = ui->priceEdit_text->toPlainText().toInt();

    // Check if the car being edited exists
    if (!dbm->searchCar(EditRegNum))
    {
        QMessageBox::warning(this, "Car Not Found", "The car you want to edit does not exist.");
        return;
    }

    // Check if any field is empty
    if (EditRegNum.isEmpty() || EditModel.isEmpty() || EditPrice == 0)
    {
        QMessageBox::warning(this, "Incomplete Information", "Please fill in all fields.");
        return;
    }

    dbm->editCar(EditRegNum, Car{.regNum = EditRegNum, .model = EditModel, .price = EditPrice});

    //Clears the text box
    ui->RegnumEdit_text->clear();
    ui->modelEdit_text->clear();
    ui->priceEdit_text->clear();

    dbm->getAllCars();

    close();
}
