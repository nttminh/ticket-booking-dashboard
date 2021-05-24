/********************************************************************************
** Form generated from reading UI file 'ShowtimeAdmin.ui'
**
** Created by: Qt User Interface Compiler version 6.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWTIMEADMIN_H
#define UI_SHOWTIMEADMIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ShowtimeAdmin
{
public:
    QHBoxLayout *horizontalLayout_3;
    QTableView *tableView_movieList;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_moviePhoto;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout_10;
    QHBoxLayout *horizontalLayout_5;
    QLabel *lbl_movieName;
    QLineEdit *lineEdit_movieName;
    QHBoxLayout *horizontalLayout_6;
    QLabel *lbl_movieLength;
    QLineEdit *lineEdit_movieLength;
    QHBoxLayout *horizontalLayout_7;
    QLabel *lbl_timeSlot;
    QComboBox *comboBox_timeSlot;
    QHBoxLayout *horizontalLayout_10;
    QLabel *lbl_Poster;
    QPushButton *btn_choosePhoto;
    QPushButton *btn_addMovie;
    QFrame *line;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label_movieId;
    QLineEdit *lineEdit_movieIdWillBeRemoved;
    QPushButton *btn_removeMovie;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_export;

    void setupUi(QDialog *ShowtimeAdmin)
    {
        if (ShowtimeAdmin->objectName().isEmpty())
            ShowtimeAdmin->setObjectName(QString::fromUtf8("ShowtimeAdmin"));
        ShowtimeAdmin->resize(1024, 640);
        horizontalLayout_3 = new QHBoxLayout(ShowtimeAdmin);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        tableView_movieList = new QTableView(ShowtimeAdmin);
        tableView_movieList->setObjectName(QString::fromUtf8("tableView_movieList"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableView_movieList->sizePolicy().hasHeightForWidth());
        tableView_movieList->setSizePolicy(sizePolicy);
        tableView_movieList->setMinimumSize(QSize(650, 0));
        tableView_movieList->setStyleSheet(QString::fromUtf8("QHeaderView::section { background-color:black }"));
        tableView_movieList->setShowGrid(true);

        horizontalLayout_3->addWidget(tableView_movieList);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_moviePhoto = new QLabel(ShowtimeAdmin);
        label_moviePhoto->setObjectName(QString::fromUtf8("label_moviePhoto"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_moviePhoto->sizePolicy().hasHeightForWidth());
        label_moviePhoto->setSizePolicy(sizePolicy1);
        label_moviePhoto->setMinimumSize(QSize(348, 242));
        label_moviePhoto->setScaledContents(true);
        label_moviePhoto->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_moviePhoto);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);

        groupBox_2 = new QGroupBox(ShowtimeAdmin);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        lbl_movieName = new QLabel(groupBox_2);
        lbl_movieName->setObjectName(QString::fromUtf8("lbl_movieName"));

        horizontalLayout_5->addWidget(lbl_movieName);

        lineEdit_movieName = new QLineEdit(groupBox_2);
        lineEdit_movieName->setObjectName(QString::fromUtf8("lineEdit_movieName"));

        horizontalLayout_5->addWidget(lineEdit_movieName);


        verticalLayout_10->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        lbl_movieLength = new QLabel(groupBox_2);
        lbl_movieLength->setObjectName(QString::fromUtf8("lbl_movieLength"));

        horizontalLayout_6->addWidget(lbl_movieLength);

        lineEdit_movieLength = new QLineEdit(groupBox_2);
        lineEdit_movieLength->setObjectName(QString::fromUtf8("lineEdit_movieLength"));

        horizontalLayout_6->addWidget(lineEdit_movieLength);


        verticalLayout_10->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        lbl_timeSlot = new QLabel(groupBox_2);
        lbl_timeSlot->setObjectName(QString::fromUtf8("lbl_timeSlot"));

        horizontalLayout_7->addWidget(lbl_timeSlot);

        comboBox_timeSlot = new QComboBox(groupBox_2);
        comboBox_timeSlot->addItem(QString());
        comboBox_timeSlot->addItem(QString());
        comboBox_timeSlot->addItem(QString());
        comboBox_timeSlot->addItem(QString());
        comboBox_timeSlot->addItem(QString());
        comboBox_timeSlot->setObjectName(QString::fromUtf8("comboBox_timeSlot"));

        horizontalLayout_7->addWidget(comboBox_timeSlot);


        verticalLayout_10->addLayout(horizontalLayout_7);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        lbl_Poster = new QLabel(groupBox_2);
        lbl_Poster->setObjectName(QString::fromUtf8("lbl_Poster"));

        horizontalLayout_10->addWidget(lbl_Poster);

        btn_choosePhoto = new QPushButton(groupBox_2);
        btn_choosePhoto->setObjectName(QString::fromUtf8("btn_choosePhoto"));

        horizontalLayout_10->addWidget(btn_choosePhoto);


        verticalLayout_10->addLayout(horizontalLayout_10);

        btn_addMovie = new QPushButton(groupBox_2);
        btn_addMovie->setObjectName(QString::fromUtf8("btn_addMovie"));

        verticalLayout_10->addWidget(btn_addMovie);


        verticalLayout_2->addLayout(verticalLayout_10);


        verticalLayout_4->addWidget(groupBox_2);

        line = new QFrame(ShowtimeAdmin);
        line->setObjectName(QString::fromUtf8("line"));
        line->setLineWidth(1);
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line);

        groupBox = new QGroupBox(ShowtimeAdmin);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy2);
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_movieId = new QLabel(groupBox);
        label_movieId->setObjectName(QString::fromUtf8("label_movieId"));

        horizontalLayout->addWidget(label_movieId);

        lineEdit_movieIdWillBeRemoved = new QLineEdit(groupBox);
        lineEdit_movieIdWillBeRemoved->setObjectName(QString::fromUtf8("lineEdit_movieIdWillBeRemoved"));
        lineEdit_movieIdWillBeRemoved->setInputMethodHints(Qt::ImhPreferNumbers);

        horizontalLayout->addWidget(lineEdit_movieIdWillBeRemoved);

        btn_removeMovie = new QPushButton(groupBox);
        btn_removeMovie->setObjectName(QString::fromUtf8("btn_removeMovie"));

        horizontalLayout->addWidget(btn_removeMovie);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_4->addWidget(groupBox);

        groupBox_3 = new QGroupBox(ShowtimeAdmin);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        horizontalLayout_2 = new QHBoxLayout(groupBox_3);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton_export = new QPushButton(groupBox_3);
        pushButton_export->setObjectName(QString::fromUtf8("pushButton_export"));

        horizontalLayout_2->addWidget(pushButton_export);


        verticalLayout_4->addWidget(groupBox_3);


        horizontalLayout_3->addLayout(verticalLayout_4);


        retranslateUi(ShowtimeAdmin);

        QMetaObject::connectSlotsByName(ShowtimeAdmin);
    } // setupUi

    void retranslateUi(QDialog *ShowtimeAdmin)
    {
        ShowtimeAdmin->setWindowTitle(QCoreApplication::translate("ShowtimeAdmin", "Dialog", nullptr));
        label_moviePhoto->setText(QCoreApplication::translate("ShowtimeAdmin", "Image goes in here", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("ShowtimeAdmin", "Add Movie", nullptr));
        lbl_movieName->setText(QCoreApplication::translate("ShowtimeAdmin", "Name", nullptr));
        lbl_movieLength->setText(QCoreApplication::translate("ShowtimeAdmin", "Length", nullptr));
        lbl_timeSlot->setText(QCoreApplication::translate("ShowtimeAdmin", "Time slot", nullptr));
        comboBox_timeSlot->setItemText(0, QCoreApplication::translate("ShowtimeAdmin", "1", nullptr));
        comboBox_timeSlot->setItemText(1, QCoreApplication::translate("ShowtimeAdmin", "2", nullptr));
        comboBox_timeSlot->setItemText(2, QCoreApplication::translate("ShowtimeAdmin", "3", nullptr));
        comboBox_timeSlot->setItemText(3, QCoreApplication::translate("ShowtimeAdmin", "4", nullptr));
        comboBox_timeSlot->setItemText(4, QCoreApplication::translate("ShowtimeAdmin", "5", nullptr));

        lbl_Poster->setText(QCoreApplication::translate("ShowtimeAdmin", "Poster", nullptr));
        btn_choosePhoto->setText(QCoreApplication::translate("ShowtimeAdmin", "Choose Photo", nullptr));
        btn_addMovie->setText(QCoreApplication::translate("ShowtimeAdmin", "Add Movie", nullptr));
        groupBox->setTitle(QCoreApplication::translate("ShowtimeAdmin", "Remove Movie", nullptr));
        label_movieId->setText(QCoreApplication::translate("ShowtimeAdmin", "Movie ID", nullptr));
        btn_removeMovie->setText(QCoreApplication::translate("ShowtimeAdmin", "Remove Movie", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("ShowtimeAdmin", "Export data to file", nullptr));
        pushButton_export->setText(QCoreApplication::translate("ShowtimeAdmin", "Export", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ShowtimeAdmin: public Ui_ShowtimeAdmin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWTIMEADMIN_H
