//
// Created by sjiam on 2024/3/21.
//

#ifndef DATA_STRUCTURE_VISUALIZATION_DRAWER_H
#define DATA_STRUCTURE_VISUALIZATION_DRAWER_H

#include <QWidget>
#include <string>
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

    // 鼠标左键点击事件
    void mousePressEvent(QMouseEvent *event) override;

    // 鼠标左键释放事件
    void mouseReleaseEvent(QMouseEvent *event) override;

    // 鼠标移动事件
    void mouseMoveEvent(QMouseEvent *event) override;

private:
    Ui::Drawer *ui;

    // 画板的缩放系数
    float zoom = 1;

    // 画板是否被拖拽
    bool isDragging = false;
    // 拖拽鼠标起始点
    QPointF dragStartPos;

    // 绘制起始点
    QPoint startPos;

    // 定义链表节点
//    ChainNode<QString> node = ChainNode<QString>("1", nullptr);
    // 定义链表视图
//    ChainNodeShape<QString> nodeShape = ChainNodeShape<QString>(node, startPos + QPoint(100, 100));
    ChainNode<int> nodeInt = ChainNode<int>(1, nullptr);
    ChainNodeShape<int> nodeShapeInt = ChainNodeShape<int>(nodeInt, startPos + QPoint(300, 300));
};

#endif //DATA_STRUCTURE_VISUALIZATION_DRAWER_H
