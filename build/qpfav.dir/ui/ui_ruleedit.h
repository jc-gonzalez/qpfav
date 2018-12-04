/********************************************************************************
** Form generated from reading UI file 'ruleedit.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RULEEDIT_H
#define UI_RULEEDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_RuleEdit
{
public:
    QVBoxLayout *verticalLayout_4;
    QGroupBox *gpboxTool;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *edName;
    QSpacerItem *horizontalSpacer_3;
    QFrame *line;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_6;
    QListWidget *lstwdgInputs;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_8;
    QListWidget *lstwdgOutputs;
    QLabel *label_7;
    QLineEdit *edCondition;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_9;
    QHBoxLayout *horizontalLayout;
    QComboBox *cboxProcessor;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *btnOK;
    QPushButton *btnCancel;

    void setupUi(QDialog *RuleEdit)
    {
        if (RuleEdit->objectName().isEmpty())
            RuleEdit->setObjectName(QStringLiteral("RuleEdit"));
        RuleEdit->resize(456, 426);
        verticalLayout_4 = new QVBoxLayout(RuleEdit);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        gpboxTool = new QGroupBox(RuleEdit);
        gpboxTool->setObjectName(QStringLiteral("gpboxTool"));
        verticalLayout_3 = new QVBoxLayout(gpboxTool);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_5 = new QLabel(gpboxTool);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(label_5);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        edName = new QLineEdit(gpboxTool);
        edName->setObjectName(QStringLiteral("edName"));

        horizontalLayout_5->addWidget(edName);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);


        horizontalLayout_4->addLayout(horizontalLayout_5);


        verticalLayout_3->addLayout(horizontalLayout_4);

        line = new QFrame(gpboxTool);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_6 = new QLabel(gpboxTool);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout->addWidget(label_6);

        lstwdgInputs = new QListWidget(gpboxTool);
        lstwdgInputs->setObjectName(QStringLiteral("lstwdgInputs"));
        lstwdgInputs->setAlternatingRowColors(true);
        lstwdgInputs->setSelectionMode(QAbstractItemView::MultiSelection);

        verticalLayout->addWidget(lstwdgInputs);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_8 = new QLabel(gpboxTool);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_2->addWidget(label_8);

        lstwdgOutputs = new QListWidget(gpboxTool);
        lstwdgOutputs->setObjectName(QStringLiteral("lstwdgOutputs"));
        lstwdgOutputs->setAlternatingRowColors(true);
        lstwdgOutputs->setSelectionMode(QAbstractItemView::MultiSelection);

        verticalLayout_2->addWidget(lstwdgOutputs);


        horizontalLayout_2->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout_2);

        label_7 = new QLabel(gpboxTool);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_3->addWidget(label_7);

        edCondition = new QLineEdit(gpboxTool);
        edCondition->setObjectName(QStringLiteral("edCondition"));

        verticalLayout_3->addWidget(edCondition);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_9 = new QLabel(gpboxTool);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_9);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        cboxProcessor = new QComboBox(gpboxTool);
        cboxProcessor->setObjectName(QStringLiteral("cboxProcessor"));

        horizontalLayout->addWidget(cboxProcessor);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        horizontalLayout->setStretch(0, 2);
        horizontalLayout->setStretch(1, 1);

        horizontalLayout_3->addLayout(horizontalLayout);


        verticalLayout_3->addLayout(horizontalLayout_3);


        verticalLayout_4->addWidget(gpboxTool);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_4);

        btnOK = new QPushButton(RuleEdit);
        btnOK->setObjectName(QStringLiteral("btnOK"));

        horizontalLayout_8->addWidget(btnOK);

        btnCancel = new QPushButton(RuleEdit);
        btnCancel->setObjectName(QStringLiteral("btnCancel"));

        horizontalLayout_8->addWidget(btnCancel);


        verticalLayout_4->addLayout(horizontalLayout_8);


        retranslateUi(RuleEdit);
        QObject::connect(btnOK, SIGNAL(clicked()), RuleEdit, SLOT(accept()));
        QObject::connect(btnCancel, SIGNAL(clicked()), RuleEdit, SLOT(reject()));

        QMetaObject::connectSlotsByName(RuleEdit);
    } // setupUi

    void retranslateUi(QDialog *RuleEdit)
    {
        RuleEdit->setWindowTitle(QApplication::translate("RuleEdit", "Orchestration Rule Editor", Q_NULLPTR));
        gpboxTool->setTitle(QApplication::translate("RuleEdit", "Orchestration Rule definition", Q_NULLPTR));
        label_5->setText(QApplication::translate("RuleEdit", "Name", Q_NULLPTR));
        label_6->setText(QApplication::translate("RuleEdit", "Inputs", Q_NULLPTR));
        label_8->setText(QApplication::translate("RuleEdit", "Outputs", Q_NULLPTR));
        label_7->setText(QApplication::translate("RuleEdit", "Condition", Q_NULLPTR));
        label_9->setText(QApplication::translate("RuleEdit", "Processor", Q_NULLPTR));
        btnOK->setText(QApplication::translate("RuleEdit", "&OK", Q_NULLPTR));
        btnCancel->setText(QApplication::translate("RuleEdit", "&Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RuleEdit: public Ui_RuleEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RULEEDIT_H
