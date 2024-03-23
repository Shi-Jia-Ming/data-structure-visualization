//
// Created by sjiam on 2024/3/21.
//

#ifndef DATA_STRUCTURE_VISUALIZATION_CHAINNODESHAPE_H
#define DATA_STRUCTURE_VISUALIZATION_CHAINNODESHAPE_H

#include <QPainter>
#include <QFont>
#include <QDebug>
#include <QFontMetrics>
#include <type_traits>
#include <string>
#include "ChainNode.h"
#include "TypeTraits.h"

template<typename T>
class ChainNode;

// 链表节点的绘图类
template<typename T>
class ChainNodeShape {
public:
    explicit ChainNodeShape(ChainNode<T> value, QPointF startPos);

    explicit ChainNodeShape(QPointF startPos);

    // 入箭头位置
    QPointF inPos;
    // 出箭头位置
    QPointF outPos;

    // 绘制函数
    void paint(QPainter *painter);

    // 计算缩放后的坐标变换
    void handleZoom(float zoom, QPointF mousePos);

    // 计算平移后的坐标变换
    void handleTranslate(double deltaX, double deltaY);

private:
    // 矩形的座上顶点坐标
    QPointF startPos;
    // 矩形的长，初始值为 100
    double length;
    // 矩形的宽，初始值为 50
    double width;

    //  字体大小
    double fontSize = 12;
    // 矩形的中心点，用来显示结点的值
    QPointF centralPos;
    // 矩形中心要显示的文字的值
    QString strValue;
    // 矩形中心要显示的文字的样式
    QFont fontStyle = QFont("Microsoft YaHei", this->fontSize);
    // 字体度量对象
    QFontMetrics fontMetrics = QFontMetrics(this->fontStyle);

    // 链表节点的值
    ChainNode<T> node;

    // 计算矩形中心点的坐标
    void calcCentralPos();
    // 设置节点的值
    void setValue(const T &nodeValue, ChainNode<T> *&next);
};

/**
 * 构造函数
 *
 * @tparam T 节点中值的类型
 * @param value 节点的对象
 * @param startPos 该节点绘制的顶点
 */
template<typename T>
ChainNodeShape<T>::ChainNodeShape(ChainNode<T> value, QPointF startPos)
        : node(value), startPos(startPos), length(100), width(50) {

    // 设置节点的值
    this->strValue = TypeTraits<T>::to_qstring(this->node.value);
    fontMetrics.boundingRect(this->strValue);

    // 计算中心点
    this->calcCentralPos();
}

/**
 * 构造函数
 *
 * @tparam T 节点中值的类型
 * @param startPos 该节点绘制的顶点
 */
template<typename T>
ChainNodeShape<T>::ChainNodeShape(QPointF startPos)
        : startPos(startPos), length(50), width(25) {
    // 计算中心点
    this->calcCentralPos();
}

/**
 * 设置节点的值
 *
 * @tparam T 节点中值的类型
 * @param nodeValue 结点的值
 * @param next 链表 NEXT 指针
 */
template<typename T>
void ChainNodeShape<T>::setValue(const T &nodeValue, ChainNode<T> *&next) {
    this->node = ChainNode<T>(nodeValue, next);

    // 设置要显示的值
    this->strValue = TypeTraits<T>::to_qstring(this->node.value);
    fontMetrics.boundingRect(this->strValue);
}

/**
 * 计算矩形的中心点
 *
 * @tparam T 节点中值的类型
 */
template<typename T>
void ChainNodeShape<T>::calcCentralPos() {
    this->centralPos = this->startPos +
                       QPointF(this->length / 2, this->width / 2) -
                       QPointF(this->fontMetrics.horizontalAdvance(this->strValue) / 2,
                               -this->fontMetrics.height() / 2);

    this->inPos = this->startPos + QPointF(0, this->width / 2);
    this->outPos = this->startPos + QPointF(this->length, this->width / 2);
}

/**
 * 处理图形的平移
 *
 * @tparam T 节点中值的类型
 * @param deltaX X 轴偏移量
 * @param deltaY Y 轴偏移量
 */
template<typename T>
void ChainNodeShape<T>::handleTranslate(double deltaX, double deltaY) {
    this->startPos.setX(this->startPos.x() + deltaX);
    this->startPos.setY(this->startPos.y() + deltaY);
    // 计算中心点
    this->calcCentralPos();
}

/**
 * 处理图形的缩放
 *
 * @tparam T 节点中值的类型
 * @param zoom 图形的缩放系数
 * @param mousePos 鼠标位置
 */
template<typename T>
void ChainNodeShape<T>::handleZoom(float zoom, QPointF mousePos) {
    // 长和宽缩放
    this->length *= zoom;
    this->width *= zoom;
    // 字体大小调整
    this->fontSize *= zoom;
    this->fontStyle.setPixelSize(this->fontSize);
    this->fontMetrics = QFontMetrics(this->fontStyle);
    // 调整矩形左上角坐标
    this->startPos.setX(this->startPos.x() * zoom + (1 - zoom) * mousePos.x());
    this->startPos.setY(this->startPos.y() * zoom + (1 - zoom) * mousePos.y());
    // 计算中心点
    this->calcCentralPos();
}


/**
 * 定义链表节点的绘图事件
 *
 * @tparam T 节点中值的类型
 * @param painter 画笔指针
 */
template<typename T>
void ChainNodeShape<T>::paint(QPainter *painter) {
    // 绘制矩形
    painter->drawRect(startPos.x(), startPos.y(), length, width);
    // 在中心点显示链表的值
    fontStyle.setPixelSize(fontSize);
    painter->setFont(this->fontStyle);
    painter->drawText(this->centralPos, this->strValue);

    // 计算中心点
    this->calcCentralPos();
}

#endif //DATA_STRUCTURE_VISUALIZATION_CHAINNODESHAPE_H
