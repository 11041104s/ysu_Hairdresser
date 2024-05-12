#ifndef TABLELIST_H
#define TABLELIST_H

#include <QWidget>
#include <QTableWidget>
#include <QJsonArray>
#include <qtmaterialdrawer.h>
#include <QJsonArray>
#include <QJsonObject>


class tableList : public QWidget
{
public:
    explicit tableList(QWidget *parent = nullptr,bool drawerOpen=true);
    ~tableList(){};
    void customerShow(QJsonArray jsonarray);
    void customerChange_open();
    void customerChange_close();
    void consumeShow(QJsonArray jsonarray);
    void consumeChange_open();
    void consumeChange_close();
    void employeeShow(QJsonArray jsonarray);
    void employeeChange_open();
    void employeeChange_close();
    void customerHide();
    void consumeHide();
    void employeeHide();


private:
    QTableWidget customerTable;
    QTableWidget consumeTable;
    QTableWidget employeeTable;
    bool isDrawerOpen;
    QWidget* parentWidget;
};

#endif // TABLELIST_H
