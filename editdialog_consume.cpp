#include "editdialog_consume.h"
#include "ui_editdialog_consume.h"

editdialog_consume::editdialog_consume(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::editdialog_consume)
{
    ui->setupUi(this);
}

editdialog_consume::~editdialog_consume()
{
    delete ui;
}

void editdialog_consume::on_pushButton_clicked()
{

}

