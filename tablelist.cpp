#include "tablelist.h"

tableList::tableList(QWidget *parent,bool drawerOpen) : QWidget(parent), isDrawerOpen(drawerOpen){
    customerTable.setParent(parent);
    customerTable.setGeometry(20, 55, 984, 565);
    customerTable.setStyleSheet("background-color:#ffffff;");
    customerTable.hide();
    customerChange_open();

    consumeTable.setParent(parent);
    consumeTable.setGeometry(20, 55, 984, 565);
    consumeTable.setStyleSheet("background-color:#ffffff;");
    consumeTable.hide();

    employeeTable.setParent(parent);
    employeeTable.setGeometry(20, 55, 984, 565);
    employeeTable.setStyleSheet("background-color:#ffffff;");
    employeeTable.hide();

    if (isDrawerOpen){
        customerChange_open();
        consumeChange_open();
        employeeChange_open();
    }
    else{
        customerChange_close();
        consumeChange_close();
        employeeChange_close();
    }
    if (parent != nullptr) {
        this->setParent(parent);
    }
}
void tableList::customerChange_open(){
    customerTable.setGeometry(170, 55, 834, 565);
}
void tableList::consumeChange_open(){
    consumeTable.setGeometry(170, 55, 834, 565);
}
void tableList::employeeChange_open(){
    employeeTable.setGeometry(170, 55, 834, 565);
}
//close
void tableList::customerChange_close(){
    customerTable.setGeometry(20, 55, 984, 565);
}
void tableList::consumeChange_close(){
    consumeTable.setGeometry(20, 55, 984, 565);
}
void tableList::employeeChange_close(){
    employeeTable.setGeometry(20, 55, 984, 565);
}
void tableList::customerShow(QJsonArray jsonarray){
    customerTable.show();
    consumeTable.hide();
    employeeTable.hide();
    // 清空表格内容
    customerTable.clearContents();
    customerTable.setRowCount(0);

    // 添加表头
    QStringList headerLabels;
    headerLabels << "会员卡号" << "姓名" << "性别"<<"手机号"; // 替换为你的属性名称
    customerTable.setColumnCount(headerLabels.size());
    customerTable.setHorizontalHeaderLabels(headerLabels);

    // 遍历 QJsonArray
    for (int i = 0; i < jsonarray.size(); ++i) {
        QJsonObject jsonObject = jsonarray.at(i).toObject();

        // 获取每个属性的值
        QString property1 = jsonObject.value("属性1").toString(); // 替换为你的属性名称
        QString property2 = jsonObject.value("属性2").toString();
        QString property3 = jsonObject.value("属性3").toString();
        QString property4 = jsonObject.value("属性4").toString();

        // 在表格中插入新行
        int row = customerTable.rowCount();
        customerTable.insertRow(row);

        // 将属性值添加到表格中
        customerTable.setItem(row, 0, new QTableWidgetItem(property1));
        customerTable.setItem(row, 1, new QTableWidgetItem(property2));
        customerTable.setItem(row, 2, new QTableWidgetItem(property3));
        customerTable.setItem(row, 3, new QTableWidgetItem(property3));
        // 如果有更多属性，继续添加到表格中
    }
}
void tableList::consumeShow(QJsonArray jsonarray){
    customerTable.hide();
    consumeTable.show();
    employeeTable.hide();
}
void tableList::employeeShow(QJsonArray jsonarray){
    customerTable.hide();
    consumeTable.hide();
    employeeTable.show();
}

void tableList::customerHide(){
    customerTable.hide();
}
void tableList::consumeHide(){
    consumeTable.hide();
}
void tableList::employeeHide(){
    employeeTable.hide();
}
