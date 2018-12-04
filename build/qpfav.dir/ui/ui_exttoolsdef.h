/********************************************************************************
** Form generated from reading UI file 'exttoolsdef.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXTTOOLSDEF_H
#define UI_EXTTOOLSDEF_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ExtToolsDef
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QTableWidget *tblwdgUserDefTools;
    QVBoxLayout *verticalLayout;
    QPushButton *btnAddNew;
    QPushButton *btnEdit;
    QPushButton *btnRemove;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnOK;
    QPushButton *btnCancel;

    void setupUi(QDialog *ExtToolsDef)
    {
        if (ExtToolsDef->objectName().isEmpty())
            ExtToolsDef->setObjectName(QStringLiteral("ExtToolsDef"));
        ExtToolsDef->resize(832, 241);
        ExtToolsDef->setSizeGripEnabled(true);
        verticalLayout_2 = new QVBoxLayout(ExtToolsDef);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        tblwdgUserDefTools = new QTableWidget(ExtToolsDef);
        if (tblwdgUserDefTools->columnCount() < 5)
            tblwdgUserDefTools->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tblwdgUserDefTools->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tblwdgUserDefTools->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tblwdgUserDefTools->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tblwdgUserDefTools->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tblwdgUserDefTools->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tblwdgUserDefTools->setObjectName(QStringLiteral("tblwdgUserDefTools"));
        tblwdgUserDefTools->horizontalHeader()->setStretchLastSection(true);
        tblwdgUserDefTools->verticalHeader()->setVisible(false);
        tblwdgUserDefTools->verticalHeader()->setStretchLastSection(false);

        horizontalLayout->addWidget(tblwdgUserDefTools);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        btnAddNew = new QPushButton(ExtToolsDef);
        btnAddNew->setObjectName(QStringLiteral("btnAddNew"));

        verticalLayout->addWidget(btnAddNew);

        btnEdit = new QPushButton(ExtToolsDef);
        btnEdit->setObjectName(QStringLiteral("btnEdit"));

        verticalLayout->addWidget(btnEdit);

        btnRemove = new QPushButton(ExtToolsDef);
        btnRemove->setObjectName(QStringLiteral("btnRemove"));

        verticalLayout->addWidget(btnRemove);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        btnOK = new QPushButton(ExtToolsDef);
        btnOK->setObjectName(QStringLiteral("btnOK"));

        horizontalLayout_2->addWidget(btnOK);

        btnCancel = new QPushButton(ExtToolsDef);
        btnCancel->setObjectName(QStringLiteral("btnCancel"));

        horizontalLayout_2->addWidget(btnCancel);


        verticalLayout_2->addLayout(horizontalLayout_2);


        retranslateUi(ExtToolsDef);
        QObject::connect(btnAddNew, SIGNAL(clicked()), ExtToolsDef, SLOT(addNewTool()));
        QObject::connect(btnEdit, SIGNAL(clicked()), ExtToolsDef, SLOT(editTool()));
        QObject::connect(btnRemove, SIGNAL(clicked()), ExtToolsDef, SLOT(removeTool()));
        QObject::connect(btnOK, SIGNAL(clicked()), ExtToolsDef, SLOT(accept()));
        QObject::connect(btnCancel, SIGNAL(clicked()), ExtToolsDef, SLOT(cancelDlg()));
        QObject::connect(tblwdgUserDefTools, SIGNAL(doubleClicked(QModelIndex)), ExtToolsDef, SLOT(editTool(QModelIndex)));
        QObject::connect(btnCancel, SIGNAL(clicked()), ExtToolsDef, SLOT(reject()));

        QMetaObject::connectSlotsByName(ExtToolsDef);
    } // setupUi

    void retranslateUi(QDialog *ExtToolsDef)
    {
        ExtToolsDef->setWindowTitle(QApplication::translate("ExtToolsDef", "External Tools Definition", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tblwdgUserDefTools->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ExtToolsDef", "Tool Name", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tblwdgUserDefTools->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("ExtToolsDef", "Description", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tblwdgUserDefTools->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("ExtToolsDef", "Executable", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tblwdgUserDefTools->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("ExtToolsDef", "Arguments", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = tblwdgUserDefTools->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("ExtToolsDef", "Prod.Types", Q_NULLPTR));
        btnAddNew->setText(QApplication::translate("ExtToolsDef", "&Add new", Q_NULLPTR));
        btnEdit->setText(QApplication::translate("ExtToolsDef", "&Edit", Q_NULLPTR));
        btnRemove->setText(QApplication::translate("ExtToolsDef", "&Remove", Q_NULLPTR));
        btnOK->setText(QApplication::translate("ExtToolsDef", "&OK", Q_NULLPTR));
        btnCancel->setText(QApplication::translate("ExtToolsDef", "&Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ExtToolsDef: public Ui_ExtToolsDef {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXTTOOLSDEF_H
