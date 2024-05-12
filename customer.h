#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <QString>
#include <QJsonObject>

class Customer
{
public:
    Customer(const QString& cardNum, const QString& fullName, bool gender, const QString& phoneNumber)
        : card_num(cardNum), name(fullName), sex(gender), phone_num(phoneNumber){};
    Customer(): card_num(""), name(""), sex(false), phone_num(""){};
    ~Customer();
    QJsonObject toJson() const ;

protected:
    QString card_num;
    QString name;
    bool sex;
    QString phone_num;

};
#endif // CUSTOMER_H
