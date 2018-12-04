/********************************************************************************
** Form generated from reading UI file 'swarmedit.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SWARMEDIT_H
#define UI_SWARMEDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SwarmEdit
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *gpboxTool;
    QGridLayout *gridLayout;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *edSwarmId;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *edManagerIP;
    QLabel *label_10;
    QLabel *label_6;
    QLabel *label_9;
    QLabel *label_8;
    QLabel *label_11;
    QHBoxLayout *horizontalLayout_9;
    QSpinBox *spbxScale;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_10;
    QLineEdit *edImage;
    QSpacerItem *horizontalSpacer_6;
    QLineEdit *edWorkerIPs;
    QLineEdit *edArgs;
    QLineEdit *edExe;
    QHBoxLayout *horizontalLayout_6;
    QLineEdit *edSrvName;
    QSpacerItem *horizontalSpacer_7;
    QLabel *label_12;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *btnOK;
    QPushButton *btnCancel;

    void setupUi(QDialog *SwarmEdit)
    {
        if (SwarmEdit->objectName().isEmpty())
            SwarmEdit->setObjectName(QStringLiteral("SwarmEdit"));
        SwarmEdit->resize(493, 316);
        verticalLayout = new QVBoxLayout(SwarmEdit);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gpboxTool = new QGroupBox(SwarmEdit);
        gpboxTool->setObjectName(QStringLiteral("gpboxTool"));
        gridLayout = new QGridLayout(gpboxTool);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_5 = new QLabel(gpboxTool);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_5, 0, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        edSwarmId = new QLineEdit(gpboxTool);
        edSwarmId->setObjectName(QStringLiteral("edSwarmId"));

        horizontalLayout_5->addWidget(edSwarmId);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);


        gridLayout->addLayout(horizontalLayout_5, 0, 1, 1, 1);

        edManagerIP = new QLineEdit(gpboxTool);
        edManagerIP->setObjectName(QStringLiteral("edManagerIP"));

        gridLayout->addWidget(edManagerIP, 2, 1, 1, 1);

        label_10 = new QLabel(gpboxTool);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_10, 6, 0, 1, 1);

        label_6 = new QLabel(gpboxTool);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_6, 2, 0, 1, 1);

        label_9 = new QLabel(gpboxTool);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_9, 4, 0, 1, 1);

        label_8 = new QLabel(gpboxTool);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_8, 5, 0, 1, 1);

        label_11 = new QLabel(gpboxTool);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_11, 7, 0, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        spbxScale = new QSpinBox(gpboxTool);
        spbxScale->setObjectName(QStringLiteral("spbxScale"));

        horizontalLayout_9->addWidget(spbxScale);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_5);

        horizontalLayout_9->setStretch(1, 2);

        gridLayout->addLayout(horizontalLayout_9, 4, 1, 1, 1);

        label_7 = new QLabel(gpboxTool);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_7, 3, 0, 1, 1);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        edImage = new QLineEdit(gpboxTool);
        edImage->setObjectName(QStringLiteral("edImage"));

        horizontalLayout_10->addWidget(edImage);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_6);


        gridLayout->addLayout(horizontalLayout_10, 5, 1, 1, 1);

        edWorkerIPs = new QLineEdit(gpboxTool);
        edWorkerIPs->setObjectName(QStringLiteral("edWorkerIPs"));

        gridLayout->addWidget(edWorkerIPs, 3, 1, 1, 1);

        edArgs = new QLineEdit(gpboxTool);
        edArgs->setObjectName(QStringLiteral("edArgs"));
        edArgs->setReadOnly(true);

        gridLayout->addWidget(edArgs, 7, 1, 1, 1);

        edExe = new QLineEdit(gpboxTool);
        edExe->setObjectName(QStringLiteral("edExe"));
        edExe->setReadOnly(true);

        gridLayout->addWidget(edExe, 6, 1, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        edSrvName = new QLineEdit(gpboxTool);
        edSrvName->setObjectName(QStringLiteral("edSrvName"));

        horizontalLayout_6->addWidget(edSrvName);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_7);


        gridLayout->addLayout(horizontalLayout_6, 1, 1, 1, 1);

        label_12 = new QLabel(gpboxTool);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_12, 1, 0, 1, 1);


        verticalLayout->addWidget(gpboxTool);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_4);

        btnOK = new QPushButton(SwarmEdit);
        btnOK->setObjectName(QStringLiteral("btnOK"));

        horizontalLayout_8->addWidget(btnOK);

        btnCancel = new QPushButton(SwarmEdit);
        btnCancel->setObjectName(QStringLiteral("btnCancel"));

        horizontalLayout_8->addWidget(btnCancel);


        verticalLayout->addLayout(horizontalLayout_8);


        retranslateUi(SwarmEdit);
        QObject::connect(btnOK, SIGNAL(clicked()), SwarmEdit, SLOT(accept()));
        QObject::connect(btnCancel, SIGNAL(clicked()), SwarmEdit, SLOT(reject()));

        QMetaObject::connectSlotsByName(SwarmEdit);
    } // setupUi

    void retranslateUi(QDialog *SwarmEdit)
    {
        SwarmEdit->setWindowTitle(QApplication::translate("SwarmEdit", "Swarm Definition Editor", Q_NULLPTR));
        gpboxTool->setTitle(QApplication::translate("SwarmEdit", "Swarm definition", Q_NULLPTR));
        label_5->setText(QApplication::translate("SwarmEdit", "Swarm ID", Q_NULLPTR));
        label_10->setText(QApplication::translate("SwarmEdit", "Executable", Q_NULLPTR));
        label_6->setText(QApplication::translate("SwarmEdit", "Manager IP", Q_NULLPTR));
        label_9->setText(QApplication::translate("SwarmEdit", "Scale", Q_NULLPTR));
        label_8->setText(QApplication::translate("SwarmEdit", "Image", Q_NULLPTR));
        label_11->setText(QApplication::translate("SwarmEdit", "Arguments", Q_NULLPTR));
        label_7->setText(QApplication::translate("SwarmEdit", "Worker IPs", Q_NULLPTR));
        label_12->setText(QApplication::translate("SwarmEdit", "Service Name", Q_NULLPTR));
        btnOK->setText(QApplication::translate("SwarmEdit", "&OK", Q_NULLPTR));
        btnCancel->setText(QApplication::translate("SwarmEdit", "&Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SwarmEdit: public Ui_SwarmEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SWARMEDIT_H
