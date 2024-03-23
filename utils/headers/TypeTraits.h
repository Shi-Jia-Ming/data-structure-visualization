//
// Created by sjiam on 2024/3/22.
//

#ifndef DATA_STRUCTURE_VISUALIZATION_TYPETRAITS_H
#define DATA_STRUCTURE_VISUALIZATION_TYPETRAITS_H

#include <QString>

// 类型萃取工具
template<typename T>
class TypeTraits {};

template<>
class TypeTraits<int> {
public:
    static QString to_qstring(int val);
};

template<>
class TypeTraits<QString> {
public:
    static QString to_qstring(QString val);
};

template<>
class TypeTraits<double> {
public:
    static QString to_qstring(double val);
};

// 定义类型枚举
enum Type {
    INT,
    QSTRING,
    DOUBLE
};

#endif //DATA_STRUCTURE_VISUALIZATION_TYPETRAITS_H
