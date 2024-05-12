#include "employee.h"
#include <QJsonObject>


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
