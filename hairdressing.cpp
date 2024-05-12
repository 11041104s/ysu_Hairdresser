#include "hairdressing.h"


QPair<QString, double> Hairdressing::getPair(const QString& projectName){
    return qMakePair(projectName, priceList[projectName]);
}
