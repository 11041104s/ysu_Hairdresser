#ifndef HAIRDRESSING_H
#define HAIRDRESSING_H
#include <QString>
#include <QMap>
#include <QPair>

class Hairdressing {
public:
    Hairdressing() {
        priceList.insert("洗剪吹", 50.0);
        priceList.insert("染发", 80.0);
        priceList.insert("剪发", 30.0);
        priceList.insert("烫发", 100.0);
        priceList.insert("护发", 60.0);
    }

    Hairdressing(const QString& name, double price) {
        // 添加指定的美发项目及对应价格
        priceList.insert(name, price);
    }
    // 获取收费
    double getPrice(const QString& projectName) const;

    QPair<QString, double> getPair(const QString& projectName);
    // 更新收费
    void updatePrice(const QString& projectName, double newPrice);


private:
    // 名称和收费
    QMap<QString, double> priceList;
};
#endif // EMPLOYEE_H
