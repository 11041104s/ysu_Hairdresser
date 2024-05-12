#include "customer.h"

// Customer::Customer()
// {

// }
QJsonObject Customer::toJson() const {
    QJsonObject obj;
    obj["cardNum"] = card_num;
    obj["fullName"] = name;
    obj["gender"] = sex ? "Male" : "Female";
    obj["phoneNumber"] = phone_num;
    return obj;
}
