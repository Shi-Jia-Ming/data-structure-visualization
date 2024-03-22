//
// Created by sjiam on 2024/3/21.
//

#ifndef DATA_STRUCTURE_VISUALIZATION_CHAINNODESHAPE_H
#define DATA_STRUCTURE_VISUALIZATION_CHAINNODESHAPE_H

#include <QPainter>
#include "ChainNode.h"

template <typename T>
class ChainNode;

// 链表节点的绘图类
template <typename T>
class ChainNodeShape {
public:
    explicit ChainNodeShape(ChainNode<T> value, QPoint startPos, double length, double width)
            :value(value), startPos(startPos), length(length), width(width) {}

    explicit ChainNodeShape( QPoint startPos, double length, double width)
            :startPos(startPos), length(length), width(width) {}

    // 绘制函数
    void paint(QPainter *painter);
    // 设置节点的值
    void setValue(T value, ChainNode<T> *next);
    // 计算缩放后的坐标变换
    void handleZoom(float zoom, QPointF mousePos);
    // 计算平移后的坐标变换
    void handleTranslate(double deltaX, double deltaY);

private:
    // 矩形的座上顶点坐标
    QPointF startPos;
    // 矩形的长
    double length;
    // 矩形的宽
    double width;

    // 链表节点的值
    ChainNode<T> value;
};

template<typename T>
void ChainNodeShape<T>::handleTranslate(double deltaX, double deltaY) {
    this->startPos.setX(this->startPos.x() + deltaX);
    this->startPos.setY(this->startPos.y() + deltaY);
}

template<typename T>
void ChainNodeShape<T>::handleZoom(float zoom, QPointF mousePos) {
    // 长和宽缩放
    this->length *= zoom;
    this->width *= zoom;
    // 调整矩形左上角坐标
    this->startPos.setX(this->startPos.x() * zoom + (1 - zoom) * mousePos.x());
    this->startPos.setY(this->startPos.y() * zoom + (1 - zoom) * mousePos.y());
}

template<typename T>
void ChainNodeShape<T>::setValue(T nodeValue, ChainNode<T> *next) {
    this->value = ChainNode<T>(nodeValue, next);
}

template<typename T>
void ChainNodeShape<T>::paint(QPainter *painter) {
    painter->drawRect(startPos.x(), startPos.y(), length, width);
}

#endif //DATA_STRUCTURE_VISUALIZATION_CHAINNODESHAPE_H
