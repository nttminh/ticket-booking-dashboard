/********************************************************************************
** Form generated from reading UI file 'Finish.ui'
**
** Created by: Qt User Interface Compiler version 6.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINISH_H
#define UI_FINISH_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Finish
{
public:
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLabel *label_time;
    QLabel *label_5;
    QGridLayout *gridLayout;
    QLabel *label_8;
    QLabel *label_7;
    QLabel *label_ticketCost;
    QLabel *label_foodCost;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_13;
    QLabel *label_totalCost;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_14;

    void setupUi(QDialog *Finish)
    {
        if (Finish->objectName().isEmpty())
            Finish->setObjectName(QString::fromUtf8("Finish"));
        Finish->resize(1024, 640);
        Finish->setLayoutDirection(Qt::LeftToRight);
        verticalLayout = new QVBoxLayout(Finish);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(Finish);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_2->addWidget(label, 0, Qt::AlignHCenter);

        label_2 = new QLabel(Finish);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2, 0, Qt::AlignHCenter);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_3 = new QLabel(Finish);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font;
        font.setPointSize(12);
        label_3->setFont(font);

        horizontalLayout->addWidget(label_3, 0, Qt::AlignHCenter);

        label_time = new QLabel(Finish);
        label_time->setObjectName(QString::fromUtf8("label_time"));
        label_time->setFont(font);

        horizontalLayout->addWidget(label_time, 0, Qt::AlignHCenter);


        verticalLayout_2->addLayout(horizontalLayout);


        verticalLayout->addLayout(verticalLayout_2);

        label_5 = new QLabel(Finish);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout->addWidget(label_5, 0, Qt::AlignHCenter);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_8 = new QLabel(Finish);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        QFont font1;
        font1.setPointSize(16);
        label_8->setFont(font1);
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_8, 1, 0, 1, 1, Qt::AlignHCenter);

        label_7 = new QLabel(Finish);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font1);
        label_7->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_7, 0, 0, 1, 1, Qt::AlignHCenter);

        label_ticketCost = new QLabel(Finish);
        label_ticketCost->setObjectName(QString::fromUtf8("label_ticketCost"));
        label_ticketCost->setFont(font1);

        gridLayout->addWidget(label_ticketCost, 0, 1, 1, 1, Qt::AlignHCenter);

        label_foodCost = new QLabel(Finish);
        label_foodCost->setObjectName(QString::fromUtf8("label_foodCost"));
        label_foodCost->setFont(font1);

        gridLayout->addWidget(label_foodCost, 1, 1, 1, 1, Qt::AlignHCenter);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_13 = new QLabel(Finish);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        horizontalLayout_2->addWidget(label_13, 0, Qt::AlignRight);

        label_totalCost = new QLabel(Finish);
        label_totalCost->setObjectName(QString::fromUtf8("label_totalCost"));
        label_totalCost->setFont(font1);

        horizontalLayout_2->addWidget(label_totalCost);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_14 = new QLabel(Finish);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setLayoutDirection(Qt::LeftToRight);
        label_14->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

        horizontalLayout_3->addWidget(label_14, 0, Qt::AlignHCenter);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(Finish);

        QMetaObject::connectSlotsByName(Finish);
    } // setupUi

    void retranslateUi(QDialog *Finish)
    {
        Finish->setWindowTitle(QCoreApplication::translate("Finish", "Order Summary", nullptr));
        label->setText(QCoreApplication::translate("Finish", "<html><head/><body><p><span style=\" font-size:36pt;\">BOOKING CONFIRMATION</span></p><p><br/></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("Finish", "<html><head/><body><p><span style=\" font-size:24pt;\">Payment Successful</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("Finish", "<html><head/><body><p><span style=\" font-size:12pt;\">Booking Date &amp; Time:</span></p></body></html>", nullptr));
        label_time->setText(QString());
        label_5->setText(QCoreApplication::translate("Finish", "<html><head/><body><p><span style=\" font-size:16pt;\">Order Summary</span></p></body></html>", nullptr));
        label_8->setText(QCoreApplication::translate("Finish", "Food ($)", nullptr));
        label_7->setText(QCoreApplication::translate("Finish", "Tickets ($)", nullptr));
        label_ticketCost->setText(QCoreApplication::translate("Finish", "0", nullptr));
        label_foodCost->setText(QCoreApplication::translate("Finish", "0", nullptr));
        label_13->setText(QCoreApplication::translate("Finish", "<html><head/><body><p><span style=\" font-size:16pt;\">Total ($)</span></p></body></html>", nullptr));
        label_totalCost->setText(QCoreApplication::translate("Finish", "0", nullptr));
        label_14->setText(QCoreApplication::translate("Finish", "<html><head/><body><p><span style=\" font-size:16pt;\">Payment Mode: Cash</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Finish: public Ui_Finish {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINISH_H
