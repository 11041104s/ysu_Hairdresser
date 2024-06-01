#ifndef EDITDIALOG_CONSUME_H
#define EDITDIALOG_CONSUME_H

#include <QDialog>

namespace Ui {
class editdialog_consume;
}

class editdialog_consume : public QDialog
{
    Q_OBJECT

public:
    explicit editdialog_consume(QWidget *parent = nullptr);
    ~editdialog_consume();

private slots:
    void on_pushButton_clicked();

private:
    Ui::editdialog_consume *ui;
};

#endif // EDITDIALOG_CONSUME_H
