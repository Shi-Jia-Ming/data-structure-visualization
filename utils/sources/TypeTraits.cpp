//
// Created by sjiam on 2024/3/22.
//

#include <QString>
#include "../headers/TypeTraits.h"


QString TypeTraits<int>::to_qstring(int val) {
    return QString::number(val);
}


QString TypeTraits<QString>::to_qstring(QString val) {
    return val;
}

QString TypeTraits<double>::to_qstring(double val) {
    return QString::number(val);
}