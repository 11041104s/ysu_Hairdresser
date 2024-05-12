#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <QJsonArray>

class Employee
{
public:
    Employee();
    Employee(const QString& id, const QString& name, bool gender, const QString& phoneNumber);
    QJsonObject toJson() const ;
private:
    QString employeeId;
    QString employeeName;
    bool employeeGender;
    QString employeePhoneNumber;
    QMap<QString, double> hairdressingProjects; // 美发项目及对应价格
};

#endif // EMPLOYEE_H
