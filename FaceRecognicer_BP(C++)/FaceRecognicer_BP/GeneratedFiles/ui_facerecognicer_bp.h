/********************************************************************************
** Form generated from reading UI file 'facerecognicer_bp.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FACERECOGNICER_BP_H
#define UI_FACERECOGNICER_BP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FaceRecognicer_BPClass
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton;
    QLabel *label_4;
    QLabel *label_5;
    QTextEdit *textEdit;
    QPushButton *pushButton_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *FaceRecognicer_BPClass)
    {
        if (FaceRecognicer_BPClass->objectName().isEmpty())
            FaceRecognicer_BPClass->setObjectName(QStringLiteral("FaceRecognicer_BPClass"));
        FaceRecognicer_BPClass->resize(489, 461);
        centralWidget = new QWidget(FaceRecognicer_BPClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(120, 50, 64, 60));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(260, 60, 41, 20));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(220, 100, 81, 21));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(270, 140, 81, 28));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(330, 60, 72, 15));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(330, 100, 72, 15));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(50, 180, 381, 191));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(110, 140, 93, 28));
        FaceRecognicer_BPClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(FaceRecognicer_BPClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 489, 26));
        FaceRecognicer_BPClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(FaceRecognicer_BPClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        FaceRecognicer_BPClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(FaceRecognicer_BPClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        FaceRecognicer_BPClass->setStatusBar(statusBar);

        retranslateUi(FaceRecognicer_BPClass);

        QMetaObject::connectSlotsByName(FaceRecognicer_BPClass);
    } // setupUi

    void retranslateUi(QMainWindow *FaceRecognicer_BPClass)
    {
        FaceRecognicer_BPClass->setWindowTitle(QApplication::translate("FaceRecognicer_BPClass", "FaceRecognicer_BP", 0));
        label->setText(QApplication::translate("FaceRecognicer_BPClass", "face", 0));
        label_2->setText(QApplication::translate("FaceRecognicer_BPClass", "\346\234\235\345\220\221\357\274\232", 0));
        label_3->setText(QApplication::translate("FaceRecognicer_BPClass", "\346\230\257\345\220\246\346\210\264\345\242\250\351\225\234\357\274\232", 0));
        pushButton->setText(QApplication::translate("FaceRecognicer_BPClass", "\350\275\275\345\205\245\345\233\276\347\211\207", 0));
        label_4->setText(QApplication::translate("FaceRecognicer_BPClass", "xxxx", 0));
        label_5->setText(QApplication::translate("FaceRecognicer_BPClass", "xxxx", 0));
        pushButton_2->setText(QApplication::translate("FaceRecognicer_BPClass", "\345\274\200\345\247\213\350\256\255\347\273\203", 0));
    } // retranslateUi

};

namespace Ui {
    class FaceRecognicer_BPClass: public Ui_FaceRecognicer_BPClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FACERECOGNICER_BP_H
