#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <QJsonArray>

//雇员基本信息，包括id，名字，性别，电话号，负责项目和价格

class Employee
{
public:
    Employee();
    Employee(const QString& id, const QString& name, bool gender, const QString& phoneNumber,QMap<QString, double>& proj);
    QJsonObject toJson() const ;
private:
    QString employeeId;
    QString employeeName;
    bool employeeGender;
    QString employeePhoneNumber;
    QMap<QString, double> hairdressingProjects; // 美发项目及对应价格
};

#endif // EMPLOYEE_H
