/********************************************************************************
** Form generated from reading UI file 'exttooledit.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXTTOOLEDIT_H
#define UI_EXTTOOLEDIT_H

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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ExtToolEdit
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *gpboxTool;
    QFormLayout *formLayout;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *edName;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_6;
    QLineEdit *edDesc;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_7;
    QLineEdit *edExe;
    QToolButton *tbtnSelectExe;
    QLabel *label_9;
    QLineEdit *edArgs;
    QLabel *label_8;
    QHBoxLayout *horizontalLayout_6;
    QLineEdit *edProdTypes;
    QToolButton *tbtnSelectProdTypes;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *btnHelp;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *btnOK;
    QPushButton *btnCancel;

    void setupUi(QDialog *ExtToolEdit)
    {
        if (ExtToolEdit->objectName().isEmpty())
            ExtToolEdit->setObjectName(QStringLiteral("ExtToolEdit"));
        ExtToolEdit->resize(531, 236);
        verticalLayout = new QVBoxLayout(ExtToolEdit);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gpboxTool = new QGroupBox(ExtToolEdit);
        gpboxTool->setObjectName(QStringLiteral("gpboxTool"));
        formLayout = new QFormLayout(gpboxTool);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label_5 = new QLabel(gpboxTool);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_5);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        edName = new QLineEdit(gpboxTool);
        edName->setObjectName(QStringLiteral("edName"));

        horizontalLayout_5->addWidget(edName);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);


        formLayout->setLayout(0, QFormLayout::FieldRole, horizontalLayout_5);

        label_6 = new QLabel(gpboxTool);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_6);

        edDesc = new QLineEdit(gpboxTool);
        edDesc->setObjectName(QStringLiteral("edDesc"));

        formLayout->setWidget(1, QFormLayout::FieldRole, edDesc);

        label_7 = new QLabel(gpboxTool);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_7);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        edExe = new QLineEdit(gpboxTool);
        edExe->setObjectName(QStringLiteral("edExe"));

        horizontalLayout_7->addWidget(edExe);

        tbtnSelectExe = new QToolButton(gpboxTool);
        tbtnSelectExe->setObjectName(QStringLiteral("tbtnSelectExe"));

        horizontalLayout_7->addWidget(tbtnSelectExe);


        formLayout->setLayout(2, QFormLayout::FieldRole, horizontalLayout_7);

        label_9 = new QLabel(gpboxTool);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout->setWidget(3, QFormLayout::LabelRole, label_9);

        edArgs = new QLineEdit(gpboxTool);
        edArgs->setObjectName(QStringLiteral("edArgs"));

        formLayout->setWidget(3, QFormLayout::FieldRole, edArgs);

        label_8 = new QLabel(gpboxTool);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout->setWidget(4, QFormLayout::LabelRole, label_8);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        edProdTypes = new QLineEdit(gpboxTool);
        edProdTypes->setObjectName(QStringLiteral("edProdTypes"));
        edProdTypes->setReadOnly(true);

        horizontalLayout_6->addWidget(edProdTypes);

        tbtnSelectProdTypes = new QToolButton(gpboxTool);
        tbtnSelectProdTypes->setObjectName(QStringLiteral("tbtnSelectProdTypes"));

        horizontalLayout_6->addWidget(tbtnSelectProdTypes);


        formLayout->setLayout(4, QFormLayout::FieldRole, horizontalLayout_6);


        verticalLayout->addWidget(gpboxTool);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        btnHelp = new QPushButton(ExtToolEdit);
        btnHelp->setObjectName(QStringLiteral("btnHelp"));

        horizontalLayout_8->addWidget(btnHelp);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_4);

        btnOK = new QPushButton(ExtToolEdit);
        btnOK->setObjectName(QStringLiteral("btnOK"));

        horizontalLayout_8->addWidget(btnOK);

        btnCancel = new QPushButton(ExtToolEdit);
        btnCancel->setObjectName(QStringLiteral("btnCancel"));

        horizontalLayout_8->addWidget(btnCancel);


        verticalLayout->addLayout(horizontalLayout_8);


        retranslateUi(ExtToolEdit);
        QObject::connect(btnHelp, SIGNAL(clicked()), ExtToolEdit, SLOT(showHelp()));
        QObject::connect(tbtnSelectExe, SIGNAL(clicked()), ExtToolEdit, SLOT(selectApp()));
        QObject::connect(tbtnSelectProdTypes, SIGNAL(clicked()), ExtToolEdit, SLOT(selectProdTypes()));
        QObject::connect(btnOK, SIGNAL(clicked()), ExtToolEdit, SLOT(accept()));
        QObject::connect(btnCancel, SIGNAL(clicked()), ExtToolEdit, SLOT(reject()));

        QMetaObject::connectSlotsByName(ExtToolEdit);
    } // setupUi

    void retranslateUi(QDialog *ExtToolEdit)
    {
        ExtToolEdit->setWindowTitle(QApplication::translate("ExtToolEdit", "External Tool Edition", Q_NULLPTR));
        gpboxTool->setTitle(QApplication::translate("ExtToolEdit", "External Tool: ", Q_NULLPTR));
        label_5->setText(QApplication::translate("ExtToolEdit", "Name", Q_NULLPTR));
        label_6->setText(QApplication::translate("ExtToolEdit", "Description", Q_NULLPTR));
        label_7->setText(QApplication::translate("ExtToolEdit", "Executable", Q_NULLPTR));
        tbtnSelectExe->setText(QApplication::translate("ExtToolEdit", "...", Q_NULLPTR));
        label_9->setText(QApplication::translate("ExtToolEdit", "Arguments", Q_NULLPTR));
        label_8->setText(QApplication::translate("ExtToolEdit", "Product Types", Q_NULLPTR));
        tbtnSelectProdTypes->setText(QApplication::translate("ExtToolEdit", "...", Q_NULLPTR));
        btnHelp->setText(QApplication::translate("ExtToolEdit", "&Help", Q_NULLPTR));
        btnOK->setText(QApplication::translate("ExtToolEdit", "&OK", Q_NULLPTR));
        btnCancel->setText(QApplication::translate("ExtToolEdit", "&Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ExtToolEdit: public Ui_ExtToolEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXTTOOLEDIT_H
