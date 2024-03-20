//
// Created by sjiam on 2024/3/20.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "../headers/mainwindow.h"
#include "../ui/ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // 设置主窗口中dock栏为底栏
    this->addDockWidget(Qt::BottomDockWidgetArea, ui->dockWidget);
    // 设置dock栏不可关闭或移动
    ui->dockWidget->setFeatures(QDockWidget::NoDockWidgetFeatures);
    // 设置dock栏初始高度
    ui->dockWidget->setMinimumHeight(200);
    ui->dockWidget->setMaximumHeight(500);
}

MainWindow::~MainWindow() {
    delete ui;
}
