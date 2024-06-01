#ifndef EDITDIALOG_EMPLOYEE_H
#define EDITDIALOG_EMPLOYEE_H

#include <QDialog>

namespace Ui {
class editdialog_employee;
}

class editdialog_employee : public QDialog
{
    Q_OBJECT

public:
    explicit editdialog_employee(QWidget *parent = nullptr);
    ~editdialog_employee();

private:
    Ui::editdialog_employee *ui;
};

#endif // EDITDIALOG_EMPLOYEE_H
