//
// Created by sjiam on 2024/3/23.
//

#ifndef DATA_STRUCTURE_VISUALIZATION_CHAINSHAPE_H
#define DATA_STRUCTURE_VISUALIZATION_CHAINSHAPE_H

#include <vector>
#include "ChainNodeShape.h"

template<typename T>
class ChainShape {
public:
    explicit ChainShape(std::vector<ChainNodeShape<T>> chainNodeShape);

    explicit ChainShape(ChainNode<T> *head, QPointF startPos);

    explicit ChainShape();

    void paint(QPainter *painter);

    // 计算缩放后的坐标变换
    void handleZoom(float zoom, QPointF mousePos);

    // 计算平移后的坐标变换
    void handleTranslate(double deltaX, double deltaY);

private:
    // 链表视图节点列表
    std::vector<ChainNodeShape<T>> chainNodeShape;
};


/**
 * 默认空构造函数
 * @tparam T 链表节点中值的类型
 */
template<typename T>
ChainShape<T>::ChainShape() = default;

/**
 *  构造函数
 * @tparam T 链表节点中值的类型
 * @param chainNodeShape 链表视图节点列表
 */
template<typename T>
ChainShape<T>::ChainShape(std::vector<ChainNodeShape<T>> chainNodeShape)
        :chainNodeShape(chainNodeShape) {}


/**
 * 构造函数
 * @tparam T 链表中值的类型
 * @param head 链表头节点
 * @param startPos 链表视图开始的坐标
 */
template<typename T>
ChainShape<T>::ChainShape(ChainNode<T> *head, QPointF startPos) {
    for (ChainNode<T> *move = head; move != nullptr; move = move->next) {
        this->chainNodeShape.push_back(ChainNodeShape<T>(*move, startPos));
        startPos.setX(startPos.x() + 200);
    }
}

template<typename T>
void ChainShape<T>::paint(QPainter *painter) {
    // 箭头的起始坐标
    QPointF startPos, endPos;

    // 绘制第一个节点
    auto it = this->chainNodeShape.begin();
    it->paint(painter);
    startPos = it->outPos;
    for (it = this->chainNodeShape.begin() + 1; it != chainNodeShape.end(); ++it) {
        endPos = it->inPos;
        // 绘制箭头
        painter->drawLine(startPos, endPos);
        // 绘制节点
        it->paint(painter);
        startPos = it->outPos;
    }
}


template<typename T>
void ChainShape<T>::handleZoom(float zoom, QPointF mousePos) {
    for (auto it = this->chainNodeShape.begin(); it != this->chainNodeShape.end(); ++it) {
        it->handleZoom(zoom, mousePos);
    }
}


template<typename T>
void ChainShape<T>::handleTranslate(double deltaX, double deltaY) {
    for (auto it = this->chainNodeShape.begin(); it != this->chainNodeShape.end(); ++it) {
        it->handleTranslate(deltaX, deltaY);
    }
}


#endif //DATA_STRUCTURE_VISUALIZATION_CHAINSHAPE_H
