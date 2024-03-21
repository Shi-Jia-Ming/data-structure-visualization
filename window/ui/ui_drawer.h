/********************************************************************************
** Form generated from reading UI file 'drawer.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRAWER_H
#define UI_DRAWER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Drawer
{
public:

    void setupUi(QWidget *Drawer)
    {
        if (Drawer->objectName().isEmpty())
            Drawer->setObjectName("Drawer");
        Drawer->resize(400, 300);
        Drawer->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        retranslateUi(Drawer);

        QMetaObject::connectSlotsByName(Drawer);
    } // setupUi

    void retranslateUi(QWidget *Drawer)
    {
        Drawer->setWindowTitle(QCoreApplication::translate("Drawer", "Drawer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Drawer: public Ui_Drawer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRAWER_H
