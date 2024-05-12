#include "consume.h"

Consume::Consume(const QString& cardNum, const QString& fullName, bool gender, const QString& phoneNumber, const QPair<QString, double>& proj)
    : Customer(cardNum, fullName, gender, phoneNumber), project(proj)
{
    // 在这里执行其他的初始化操
}
Consume::Consume()
    : Customer("", "", 0, ""), project()
{
    // 在这里执行其他的初始化操作
}
QJsonObject Consume::toJson() const {
    QJsonObject obj;
    obj["cardNum"] = card_num;
    obj["fullName"] = name;
    obj["gender"] = sex ? "Male" : "Female";
    obj["phoneNumber"] = phone_num;
    obj["projectName"] = project.first;
    obj["projectPrice"] = project.second;
    return obj;
}
