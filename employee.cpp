#include "employee.h"
#include <QJsonObject>


Employee::Employee(const QString& id, const QString& name, bool gender, const QString& phoneNumber, QMap<QString, double>& proj)
    : employeeId(id), employeeName(name), employeeGender(gender), employeePhoneNumber(phoneNumber), hairdressingProjects(proj)
{
    // 在这里执行其他的初始化操作
}


Employee::Employee()
    : employeeId(), employeeName(), employeeGender(), employeePhoneNumber(), hairdressingProjects()
{
    // 在这里执行其他的初始化操作
}

QJsonObject Employee::toJson() const {
    QJsonObject json;
    json["employeeId"] = employeeId;
    json["employeeName"] = employeeName;
    json["employeeGender"] = employeeGender ? "Male" : "Female";
    json["employeePhoneNumber"] = employeePhoneNumber;

    // 创建美发项目的 JSON 对象
    QJsonObject hairdressingJson;
    for (auto it = hairdressingProjects.constBegin(); it != hairdressingProjects.constEnd(); ++it) {
        hairdressingJson[it.key()] = it.value();
    }
    json["hairdressingProjects"] = hairdressingJson;

    return json;
}
