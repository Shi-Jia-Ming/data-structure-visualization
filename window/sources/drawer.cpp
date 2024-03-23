//
// Created by sjiam on 2024/3/21.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Drawer.h" resolved

#include <QPainter>
#include <QWheelEvent>
#include <QDebug>
#include "ChainShape.h"
#include "../headers/drawer.h"
#include "../ui/ui_drawer.h"


Drawer::Drawer(QWidget *parent) :
        QWidget(parent), ui(new Ui::Drawer) {
    Ui::Drawer::setupUi(this);

    // 设置鼠标跟踪
    setMouseTracking(true);
    // 初始化绘制的起始点
    this->startPos = QPoint(0, 0);
    // 初始化拖拽事件的起点坐标
    this->dragStartPos = QPointF(-1, -1);

    // 初始化链表数据
    auto *a = new ChainNode<int>(1, nullptr);
    auto *b = new ChainNode<int>(2, a);
    auto *c = new ChainNode<int>(3, b);
    this->chainShape = ChainShape<int>(c, QPointF(100, 100));


}

Drawer::~Drawer() {
    delete ui;
}


void Drawer::paintEvent(QPaintEvent *event) {
    auto *painter = new QPainter(this);
    this->chainShape.paint(painter);
    delete painter;
}

void Drawer::wheelEvent(QWheelEvent *event) {
    if (event->angleDelta().y() > 0) {
        zoom = 1.1;      // 放大
    } else {
        zoom = 0.9;      // 缩小
    }
    this->chainShape.handleZoom(zoom, event->position());
    // 更新绘图
    update();
}

void Drawer::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        this->isDragging = true;
        this->dragStartPos = event->position();
    }
}

void Drawer::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        this->isDragging = false;
    }
}

void Drawer::mouseMoveEvent(QMouseEvent *event) {
    if (this->isDragging && this->dragStartPos.x() != -1 && this->dragStartPos.y() != -1) {
        double deltaX = event->position().x() - this->dragStartPos.x();
        double deltaY = event->position().y() - this->dragStartPos.y();
        this->chainShape.handleTranslate(deltaX, deltaY);
        update();
    }
    this->dragStartPos = event->position();
}
