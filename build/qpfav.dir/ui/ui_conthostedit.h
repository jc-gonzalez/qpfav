/********************************************************************************
** Form generated from reading UI file 'conthostedit.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTHOSTEDIT_H
#define UI_CONTHOSTEDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ContHostEdit
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *gpboxTool;
    QFormLayout *formLayout;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *edHostIP;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout_9;
    QRadioButton *rbtnMaster;
    QRadioButton *rbtnProcessing;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_10;
    QSpinBox *spbxNumAgents;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *btnOK;
    QPushButton *btnCancel;
    QButtonGroup *buttonGroup;

    void setupUi(QDialog *ContHostEdit)
    {
        if (ContHostEdit->objectName().isEmpty())
            ContHostEdit->setObjectName(QStringLiteral("ContHostEdit"));
        ContHostEdit->resize(475, 172);
        verticalLayout = new QVBoxLayout(ContHostEdit);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gpboxTool = new QGroupBox(ContHostEdit);
        gpboxTool->setObjectName(QStringLiteral("gpboxTool"));
        formLayout = new QFormLayout(gpboxTool);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label_5 = new QLabel(gpboxTool);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_5);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        edHostIP = new QLineEdit(gpboxTool);
        edHostIP->setObjectName(QStringLiteral("edHostIP"));

        horizontalLayout_5->addWidget(edHostIP);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);


        formLayout->setLayout(0, QFormLayout::FieldRole, horizontalLayout_5);

        label_6 = new QLabel(gpboxTool);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_6);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        rbtnMaster = new QRadioButton(gpboxTool);
        buttonGroup = new QButtonGroup(ContHostEdit);
        buttonGroup->setObjectName(QStringLiteral("buttonGroup"));
        buttonGroup->addButton(rbtnMaster);
        rbtnMaster->setObjectName(QStringLiteral("rbtnMaster"));

        horizontalLayout_9->addWidget(rbtnMaster);

        rbtnProcessing = new QRadioButton(gpboxTool);
        buttonGroup->addButton(rbtnProcessing);
        rbtnProcessing->setObjectName(QStringLiteral("rbtnProcessing"));

        horizontalLayout_9->addWidget(rbtnProcessing);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_5);


        formLayout->setLayout(1, QFormLayout::FieldRole, horizontalLayout_9);

        label_7 = new QLabel(gpboxTool);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_7);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        spbxNumAgents = new QSpinBox(gpboxTool);
        spbxNumAgents->setObjectName(QStringLiteral("spbxNumAgents"));

        horizontalLayout_10->addWidget(spbxNumAgents);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_6);


        formLayout->setLayout(2, QFormLayout::FieldRole, horizontalLayout_10);


        verticalLayout->addWidget(gpboxTool);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_4);

        btnOK = new QPushButton(ContHostEdit);
        btnOK->setObjectName(QStringLiteral("btnOK"));

        horizontalLayout_8->addWidget(btnOK);

        btnCancel = new QPushButton(ContHostEdit);
        btnCancel->setObjectName(QStringLiteral("btnCancel"));

        horizontalLayout_8->addWidget(btnCancel);


        verticalLayout->addLayout(horizontalLayout_8);


        retranslateUi(ContHostEdit);
        QObject::connect(btnOK, SIGNAL(clicked()), ContHostEdit, SLOT(accept()));
        QObject::connect(btnCancel, SIGNAL(clicked()), ContHostEdit, SLOT(reject()));

        QMetaObject::connectSlotsByName(ContHostEdit);
    } // setupUi

    void retranslateUi(QDialog *ContHostEdit)
    {
        ContHostEdit->setWindowTitle(QApplication::translate("ContHostEdit", "Host Definition", Q_NULLPTR));
        gpboxTool->setTitle(QApplication::translate("ContHostEdit", "Host definition", Q_NULLPTR));
        label_5->setText(QApplication::translate("ContHostEdit", "Host IP", Q_NULLPTR));
        label_6->setText(QApplication::translate("ContHostEdit", "Role", Q_NULLPTR));
        rbtnMaster->setText(QApplication::translate("ContHostEdit", "Master host", Q_NULLPTR));
        rbtnProcessing->setText(QApplication::translate("ContHostEdit", "Processing host", Q_NULLPTR));
        label_7->setText(QApplication::translate("ContHostEdit", "Num. Agents", Q_NULLPTR));
        btnOK->setText(QApplication::translate("ContHostEdit", "&OK", Q_NULLPTR));
        btnCancel->setText(QApplication::translate("ContHostEdit", "&Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ContHostEdit: public Ui_ContHostEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTHOSTEDIT_H
