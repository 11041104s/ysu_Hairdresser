#include "tablelist.h"
#include "customer.h"
#include "consume.h"
#include "employee.h"
#include "hairdressing.h"
#include <QHeaderView>

tableList::tableList(QWidget *parent,bool drawerOpen) : QWidget(parent), isDrawerOpen(drawerOpen){
    QFont font("song", 12, QFont::Bold);

    customerTable.setParent(parent);
    customerTable.setGeometry(20, 55, 984, 565);
    customerTable.setStyleSheet("background-color:#ffffff;");
    customerTable.setEditTriggers(QAbstractItemView::NoEditTriggers);
    customerTable.setSelectionBehavior(QAbstractItemView::SelectRows);
    customerTable.horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    customerTable.horizontalHeader()->setFont(font);
    customerTable.hide();


    consumeTable.setParent(parent);
    consumeTable.setGeometry(20, 55, 984, 565);
    consumeTable.setStyleSheet("background-color:#ffffff;");
    consumeTable.setEditTriggers(QAbstractItemView::NoEditTriggers);
    consumeTable.setSelectionBehavior(QAbstractItemView::SelectRows);
    consumeTable.horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    consumeTable.horizontalHeader()->setFont(font);
    consumeTable.hide();

    employeeTable.setParent(parent);
    employeeTable.setGeometry(20, 55, 984, 565);
    employeeTable.setStyleSheet("background-color:#ffffff;");
    employeeTable.setEditTriggers(QAbstractItemView::NoEditTriggers);
    employeeTable.setSelectionBehavior(QAbstractItemView::SelectRows);
    employeeTable.horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    employeeTable.horizontalHeader()->setFont(font);
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

QJsonArray tableList::tran_doc_array(QJsonDocument doc){
    return doc.array();
}

QJsonArray addinto_json(QJsonArray jsonarray, const Customer& customer) {
    jsonarray.append(customer.toJson());
    return jsonarray;
}
QJsonArray addinto_json(QJsonArray jsonarray,const Consume& consume){
    jsonarray.append(consume.toJson());
    return jsonarray;
}
QJsonArray addinto_json(QJsonArray jsonarray,const Employee& employee){
    jsonarray.append(employee.toJson());
    return jsonarray;
}
QJsonDocument tableList::readJsonFile(const QString& filePath) {
    QFile file(filePath);
    if(file.exists()) {
        if (!file.open(QIODevice::ReadOnly)) {
            // 文件打开失败，返回空的 QJsonDocument 对象
            return QJsonDocument();
        }

        QJsonParseError parseError;
        QJsonDocument jsonDoc = QJsonDocument::fromJson(file.readAll(), &parseError); // 解析 JSON 数据
        if (parseError.error != QJsonParseError::NoError) {
            // JSON 解析错误，返回空的 QJsonDocument 对象
            return QJsonDocument();
        }

        // 成功读取并解析 JSON 文件，返回 QJsonDocument 对象
        return jsonDoc;
    }
    else {
        // 文件不存在，创建一个空的文件
        if (!file.open(QIODevice::WriteOnly)) {
            // 创建文件失败，返回空的 QJsonDocument 对象
            return QJsonDocument();
        }

        // 写入空的 JSON 格式数据
        file.write("{}");
        file.close();

        // 返回一个空的 QJsonDocument 对象
        return QJsonDocument();
    }
}

void tableList::saveJsonArrayToFile(const QJsonArray& jsonArray, const QString& filePath) {
    // 创建一个 JSON 文档并将 JSON 数组添加到其中
    QJsonDocument doc(jsonArray);

    // 打开文件进行写入
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly)) {
        // 文件打开失败，处理错误情况
        return;
    }

    // 将 JSON 文档转换为二进制数据并写入文件
    file.write(doc.toJson());
    // 关闭文件
    file.close();
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
    // 清空表格
    customerTable.clearContents();
    customerTable.setRowCount(0);

    // 表头
    QStringList headerLabels;
    headerLabels << "会员卡号" << "姓名" << "性别"<<"手机号";
    customerTable.setColumnCount(headerLabels.size());
    customerTable.setHorizontalHeaderLabels(headerLabels);

    // 遍历
    for (int i = 0; i < jsonarray.size(); ++i) {
        QJsonObject jsonObject = jsonarray.at(i).toObject();

        // 获取每个属性
        QString property1 = jsonObject.value("cardNum").toString();
        QString property2 = jsonObject.value("fullName").toString();
        QString property3 = jsonObject.value("gender").toString();
        QString property4 = jsonObject.value("phoneNumber").toString();

        // 插入新行
        int row = customerTable.rowCount();
        customerTable.insertRow(row);

        // 添加到表格
        customerTable.setItem(row, 0, new QTableWidgetItem(property1));
        customerTable.setItem(row, 1, new QTableWidgetItem(property2));
        customerTable.setItem(row, 2, new QTableWidgetItem(property3));
        customerTable.setItem(row, 3, new QTableWidgetItem(property4));
    }
}
void tableList::consumeShow(){
    customerTable.hide();
    consumeTable.show();
    employeeTable.hide();
}
void tableList::employeeShow(){
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
