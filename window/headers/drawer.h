//
// Created by sjiam on 2024/3/21.
//

#ifndef DATA_STRUCTURE_VISUALIZATION_DRAWER_H
#define DATA_STRUCTURE_VISUALIZATION_DRAWER_H

#include <QWidget>
#include "ChainNodeShape.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Drawer; }
QT_END_NAMESPACE

class Drawer : public QWidget {
Q_OBJECT

public:
    explicit Drawer(QWidget *parent = nullptr);

    ~Drawer() override;

public:
    // 绘制事件
    void paintEvent(QPaintEvent *event) override;
    // 鼠标滚轮事件
    void wheelEvent(QWheelEvent *event) override;

private:
    Ui::Drawer *ui;

    // 画板的缩放系数
    float zoom = 1;

    // 绘制起始点
    QPoint startPos;

    // 定义链表节点
    ChainNode<int> node = ChainNode<int>(1, nullptr);
    // 定义链表视图
    ChainNodeShape<int> nodeShape = ChainNodeShape<int>(node, startPos + QPoint(100, 100), 100, 100);
};

#endif //DATA_STRUCTURE_VISUALIZATION_DRAWER_H
