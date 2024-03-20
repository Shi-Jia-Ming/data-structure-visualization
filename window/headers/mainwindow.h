//
// Created by sjiam on 2024/3/20.
//

#ifndef DATA_STRUCTURE_VISUALIZATION_MAINWINDOW_H
#define DATA_STRUCTURE_VISUALIZATION_MAINWINDOW_H

#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;

private:
    Ui::MainWindow *ui{};
};


#endif //DATA_STRUCTURE_VISUALIZATION_MAINWINDOW_H
