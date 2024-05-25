#ifndef TABLELIST_H
#define TABLELIST_H

#include <QWidget>
#include <QTableWidget>
#include <QJsonArray>
#include <qtmaterialdrawer.h>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QFile>
#include <QMessageBox>

class tableList : public QWidget
{
public:
    explicit tableList(QWidget *parent,bool drawerOpen);
    ~tableList(){};
    QJsonDocument readJsonFile(const QString& JsonPathFn);
    void saveJsonArrayToFile(const QJsonArray& jsonArray, const QString& filePath);
    QJsonArray tran_doc_array(QJsonDocument doc);
    QJsonArray customer_info;
    QJsonArray consume_info;
    QJsonArray employee_info;

    void customerShow(QJsonArray jsonarray);
    void customerChange_open();
    void customerChange_close();
    void consumeShow();
    void consumeChange_open();
    void consumeChange_close();
    void employeeShow();
    void employeeChange_open();
    void employeeChange_close();

    void customerHide();
    void consumeHide();
    void employeeHide();

    int getSelected_customer();
    int getSelected_consume();
    int getSelected_employee();


private:
    QTableWidget customerTable;

    QTableWidget consumeTable;

    QTableWidget employeeTable;

    bool isDrawerOpen;
    QWidget* parentWidget;
};

#endif // TABLELIST_H
