#ifndef CONSUME_H
#define CONSUME_H

#include "customer.h"
#include <QJsonArray>

class Consume : public Customer
{
public:
    Consume();
    Consume(const QString& cardNum, const QString& fullName, bool gender, const QString& phoneNumber, const QPair<QString, double>& proj);
    QJsonObject toJson() const ;
private:
    QPair<QString, double> project;
};

#endif // CONSUME_H