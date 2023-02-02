/********************************************************************************
** Form generated from reading UI file 'flyingbox.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FLYINGBOX_H
#define UI_FLYINGBOX_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FlyingBoxClass
{
public:
    QWidget *centralWidget;
    QTextEdit *textEdit;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_setup;
    QPushButton *pushButton_fly;
    QPushButton *pushButton_shake;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *FlyingBoxClass)
    {
        if (FlyingBoxClass->objectName().isEmpty())
            FlyingBoxClass->setObjectName(QString::fromUtf8("FlyingBoxClass"));
        FlyingBoxClass->resize(608, 502);
        centralWidget = new QWidget(FlyingBoxClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(10, 10, 571, 331));
        QFont font;
        font.setPointSize(20);
        textEdit->setFont(font);
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(20, 350, 561, 80));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_setup = new QPushButton(horizontalLayoutWidget);
        pushButton_setup->setObjectName(QString::fromUtf8("pushButton_setup"));

        horizontalLayout->addWidget(pushButton_setup);

        pushButton_fly = new QPushButton(horizontalLayoutWidget);
        pushButton_fly->setObjectName(QString::fromUtf8("pushButton_fly"));

        horizontalLayout->addWidget(pushButton_fly);

        pushButton_shake = new QPushButton(horizontalLayoutWidget);
        pushButton_shake->setObjectName(QString::fromUtf8("pushButton_shake"));

        horizontalLayout->addWidget(pushButton_shake);

        FlyingBoxClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(FlyingBoxClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 608, 26));
        FlyingBoxClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(FlyingBoxClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        FlyingBoxClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(FlyingBoxClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        FlyingBoxClass->setStatusBar(statusBar);

        retranslateUi(FlyingBoxClass);

        QMetaObject::connectSlotsByName(FlyingBoxClass);
    } // setupUi

    void retranslateUi(QMainWindow *FlyingBoxClass)
    {
        FlyingBoxClass->setWindowTitle(QApplication::translate("FlyingBoxClass", "FlyingBox", 0, QApplication::UnicodeUTF8));
        pushButton_setup->setText(QApplication::translate("FlyingBoxClass", "\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        pushButton_fly->setText(QApplication::translate("FlyingBoxClass", "\351\243\236\350\241\214", 0, QApplication::UnicodeUTF8));
        pushButton_shake->setText(QApplication::translate("FlyingBoxClass", "\346\212\226\345\212\250", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FlyingBoxClass: public Ui_FlyingBoxClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FLYINGBOX_H
