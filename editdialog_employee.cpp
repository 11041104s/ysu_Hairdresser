#include "editdialog_employee.h"
#include "ui_editdialog_employee.h"

editdialog_employee::editdialog_employee(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::editdialog_employee)
{
    ui->setupUi(this);
}

editdialog_employee::~editdialog_employee()
{
    delete ui;
}
