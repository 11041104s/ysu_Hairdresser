#ifndef CONSUME_H
#define CONSUME_H

#include "customer.h"
#include <QJsonArray>

//消费的基本信息，如卡号、姓名、性别、电话号码，消费项目及其金额
class Consume : public Customer
{
public:
    Consume();
    Consume(const QString& cardNum, const QString& fullName, bool gender, const QString& phoneNumber, const QPair<QString, double>& proj);
    QJsonObject toJson() const ;
private:
    QPair<QString, double> project;
};

#endif
