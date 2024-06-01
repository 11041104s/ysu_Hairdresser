#ifndef EDITDIALOG_H
#define EDITDIALOG_H

#include <QDialog>
#include <QAbstractButton>
#include "mainwindow.h"
#include "customer.h"

namespace Ui {
class EditDialog;
}

class EditDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditDialog(QWidget *parent = nullptr);
    ~EditDialog();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();


private:
    Ui::EditDialog *ui;
};

#endif // EDITDIALOG_H
