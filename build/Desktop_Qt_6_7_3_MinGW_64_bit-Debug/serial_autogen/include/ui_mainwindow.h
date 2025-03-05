/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label_7;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_2;
    QCheckBox *Line_po;
    QCheckBox *Hex_po;
    QPushButton *Clear_po;
    QLabel *label_4;
    QCheckBox *Time_po;
    QTextEdit *Sendedit_po;
    QPlainTextEdit *Recvedit_po;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout;
    QComboBox *Databit_po;
    QLabel *label;
    QComboBox *Serial_po;
    QLabel *label_6;
    QLabel *label_3;
    QPushButton *Checkseial_po;
    QPushButton *Openserial_po;
    QComboBox *Baudrate_po;
    QComboBox *Checkbit_po;
    QLabel *label_2;
    QComboBox *Stopbit_po;
    QLabel *label_5;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout;
    QPushButton *Send_po;
    QPushButton *Clearsend_po;
    QWidget *widget;
    QGridLayout *gridLayout_3;
    QLabel *label_8;
    QCheckBox *Sendhex_po;
    QCheckBox *Senewline_po;
    QCheckBox *Timesend_po;
    QSpinBox *Sendms_po;
    QLabel *label_9;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(897, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(20, 30, 54, 16));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(20, 280, 191, 74));
        gridLayout_2 = new QGridLayout(layoutWidget);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        Line_po = new QCheckBox(layoutWidget);
        Line_po->setObjectName("Line_po");

        gridLayout_2->addWidget(Line_po, 2, 1, 1, 1);

        Hex_po = new QCheckBox(layoutWidget);
        Hex_po->setObjectName("Hex_po");

        gridLayout_2->addWidget(Hex_po, 1, 1, 1, 1);

        Clear_po = new QPushButton(layoutWidget);
        Clear_po->setObjectName("Clear_po");

        gridLayout_2->addWidget(Clear_po, 1, 0, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName("label_4");

        gridLayout_2->addWidget(label_4, 0, 0, 1, 1);

        Time_po = new QCheckBox(layoutWidget);
        Time_po->setObjectName("Time_po");

        gridLayout_2->addWidget(Time_po, 2, 0, 1, 1);

        Sendedit_po = new QTextEdit(centralwidget);
        Sendedit_po->setObjectName("Sendedit_po");
        Sendedit_po->setGeometry(QRect(240, 440, 391, 91));
        Recvedit_po = new QPlainTextEdit(centralwidget);
        Recvedit_po->setObjectName("Recvedit_po");
        Recvedit_po->setGeometry(QRect(240, 50, 471, 381));
        Recvedit_po->setReadOnly(true);
        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(20, 50, 191, 213));
        gridLayout = new QGridLayout(layoutWidget1);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        Databit_po = new QComboBox(layoutWidget1);
        Databit_po->addItem(QString());
        Databit_po->addItem(QString());
        Databit_po->addItem(QString());
        Databit_po->addItem(QString());
        Databit_po->setObjectName("Databit_po");

        gridLayout->addWidget(Databit_po, 3, 1, 1, 1);

        label = new QLabel(layoutWidget1);
        label->setObjectName("label");

        gridLayout->addWidget(label, 4, 0, 1, 1);

        Serial_po = new QComboBox(layoutWidget1);
        Serial_po->setObjectName("Serial_po");

        gridLayout->addWidget(Serial_po, 0, 1, 1, 1);

        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName("label_6");

        gridLayout->addWidget(label_6, 0, 0, 1, 1);

        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 5, 0, 1, 1);

        Checkseial_po = new QPushButton(layoutWidget1);
        Checkseial_po->setObjectName("Checkseial_po");

        gridLayout->addWidget(Checkseial_po, 6, 0, 1, 2);

        Openserial_po = new QPushButton(layoutWidget1);
        Openserial_po->setObjectName("Openserial_po");

        gridLayout->addWidget(Openserial_po, 7, 0, 1, 2);

        Baudrate_po = new QComboBox(layoutWidget1);
        Baudrate_po->addItem(QString());
        Baudrate_po->addItem(QString());
        Baudrate_po->addItem(QString());
        Baudrate_po->addItem(QString());
        Baudrate_po->addItem(QString());
        Baudrate_po->addItem(QString());
        Baudrate_po->addItem(QString());
        Baudrate_po->addItem(QString());
        Baudrate_po->setObjectName("Baudrate_po");

        gridLayout->addWidget(Baudrate_po, 1, 1, 1, 1);

        Checkbit_po = new QComboBox(layoutWidget1);
        Checkbit_po->addItem(QString());
        Checkbit_po->addItem(QString());
        Checkbit_po->addItem(QString());
        Checkbit_po->setObjectName("Checkbit_po");

        gridLayout->addWidget(Checkbit_po, 5, 1, 1, 1);

        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        Stopbit_po = new QComboBox(layoutWidget1);
        Stopbit_po->addItem(QString());
        Stopbit_po->addItem(QString());
        Stopbit_po->addItem(QString());
        Stopbit_po->setObjectName("Stopbit_po");

        gridLayout->addWidget(Stopbit_po, 4, 1, 1, 1);

        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName("label_5");

        gridLayout->addWidget(label_5, 3, 0, 1, 1);

        layoutWidget2 = new QWidget(centralwidget);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(640, 470, 77, 56));
        verticalLayout = new QVBoxLayout(layoutWidget2);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        Send_po = new QPushButton(layoutWidget2);
        Send_po->setObjectName("Send_po");

        verticalLayout->addWidget(Send_po);

        Clearsend_po = new QPushButton(layoutWidget2);
        Clearsend_po->setObjectName("Clearsend_po");

        verticalLayout->addWidget(Clearsend_po);

        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(20, 373, 150, 70));
        gridLayout_3 = new QGridLayout(widget);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(widget);
        label_8->setObjectName("label_8");

        gridLayout_3->addWidget(label_8, 0, 0, 1, 1);

        Sendhex_po = new QCheckBox(widget);
        Sendhex_po->setObjectName("Sendhex_po");

        gridLayout_3->addWidget(Sendhex_po, 1, 0, 1, 1);

        Senewline_po = new QCheckBox(widget);
        Senewline_po->setObjectName("Senewline_po");

        gridLayout_3->addWidget(Senewline_po, 1, 1, 1, 2);

        Timesend_po = new QCheckBox(widget);
        Timesend_po->setObjectName("Timesend_po");

        gridLayout_3->addWidget(Timesend_po, 2, 0, 1, 1);

        Sendms_po = new QSpinBox(widget);
        Sendms_po->setObjectName("Sendms_po");

        gridLayout_3->addWidget(Sendms_po, 2, 1, 1, 1);

        label_9 = new QLabel(widget);
        label_9->setObjectName("label_9");

        gridLayout_3->addWidget(label_9, 2, 2, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 897, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        Databit_po->setCurrentIndex(3);
        Baudrate_po->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\344\270\262\345\217\243\350\256\276\347\275\256", nullptr));
        Line_po->setText(QCoreApplication::translate("MainWindow", "\350\207\252\345\212\250\346\215\242\350\241\214", nullptr));
        Hex_po->setText(QCoreApplication::translate("MainWindow", "Hex\346\216\245\346\224\266", nullptr));
        Clear_po->setText(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272\346\216\245\346\224\266", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\346\216\245\346\224\266\350\256\276\347\275\256", nullptr));
        Time_po->setText(QCoreApplication::translate("MainWindow", "\346\227\266\351\227\264\346\210\263", nullptr));
        Databit_po->setItemText(0, QCoreApplication::translate("MainWindow", "5", nullptr));
        Databit_po->setItemText(1, QCoreApplication::translate("MainWindow", "6", nullptr));
        Databit_po->setItemText(2, QCoreApplication::translate("MainWindow", "7", nullptr));
        Databit_po->setItemText(3, QCoreApplication::translate("MainWindow", "8", nullptr));

        label->setText(QCoreApplication::translate("MainWindow", "\345\201\234\346\255\242\344\275\215", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\347\253\257\345\217\243", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\346\240\241\351\252\214\344\275\215", nullptr));
        Checkseial_po->setText(QCoreApplication::translate("MainWindow", "\346\243\200\346\265\213\344\270\262\345\217\243", nullptr));
        Openserial_po->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
        Baudrate_po->setItemText(0, QCoreApplication::translate("MainWindow", "1200", nullptr));
        Baudrate_po->setItemText(1, QCoreApplication::translate("MainWindow", "2400", nullptr));
        Baudrate_po->setItemText(2, QCoreApplication::translate("MainWindow", "4800", nullptr));
        Baudrate_po->setItemText(3, QCoreApplication::translate("MainWindow", "9600", nullptr));
        Baudrate_po->setItemText(4, QCoreApplication::translate("MainWindow", "19200", nullptr));
        Baudrate_po->setItemText(5, QCoreApplication::translate("MainWindow", "38400", nullptr));
        Baudrate_po->setItemText(6, QCoreApplication::translate("MainWindow", "57600", nullptr));
        Baudrate_po->setItemText(7, QCoreApplication::translate("MainWindow", "115200", nullptr));

        Baudrate_po->setCurrentText(QCoreApplication::translate("MainWindow", "9600", nullptr));
        Checkbit_po->setItemText(0, QCoreApplication::translate("MainWindow", "none", nullptr));
        Checkbit_po->setItemText(1, QCoreApplication::translate("MainWindow", "\345\245\207\346\240\241\351\252\214", nullptr));
        Checkbit_po->setItemText(2, QCoreApplication::translate("MainWindow", "\345\201\266\346\240\241\351\252\214", nullptr));

        label_2->setText(QCoreApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207", nullptr));
        Stopbit_po->setItemText(0, QCoreApplication::translate("MainWindow", "1", nullptr));
        Stopbit_po->setItemText(1, QCoreApplication::translate("MainWindow", "1.5", nullptr));
        Stopbit_po->setItemText(2, QCoreApplication::translate("MainWindow", "2", nullptr));

        label_5->setText(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\344\275\215", nullptr));
        Send_po->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201", nullptr));
        Clearsend_po->setText(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272\345\217\221\351\200\201", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201\350\256\276\347\275\256", nullptr));
        Sendhex_po->setText(QCoreApplication::translate("MainWindow", "Hex\345\217\221\351\200\201", nullptr));
        Senewline_po->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201\346\226\260\350\241\214", nullptr));
        Timesend_po->setText(QCoreApplication::translate("MainWindow", "\350\207\252\345\212\250\345\217\221\351\200\201", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "ms", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
