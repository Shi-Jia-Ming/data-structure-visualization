//
// Created by sjiam on 2024/3/21.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Drawer.h" resolved

#include <QPainter>
#include <QWheelEvent>
#include <QDebug>

#include "../headers/drawer.h"
#include "../ui/ui_drawer.h"


Drawer::Drawer(QWidget *parent) :
        QWidget(parent), ui(new Ui::Drawer) {
    ui->setupUi(this);

    // 设置鼠标跟踪
    setMouseTracking(true);
    // 初始化绘制的起始点
    this->startPos = QPoint(0, 0);
}

Drawer::~Drawer() {
    delete ui;
}


void Drawer::paintEvent(QPaintEvent *event) {
    auto *painter = new QPainter(this);
    this->nodeShape.paint(painter);
    delete painter;
}

void Drawer::wheelEvent(QWheelEvent *event) {
    if (event->angleDelta().y() > 0) {
        zoom = 1.1;      // 放大
    } else {
        zoom = 0.9;        // 缩小
    }
    this->nodeShape.handleZoom(zoom, event->position());
    qDebug() << "StartPosition: " << startPos;
    qDebug() << "Zoom: " << zoom;

    // 更新绘图
    update();
}
