/********************************************************************************
** Form generated from reading UI file 'sysalertsview.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYSALERTSVIEW_H
#define UI_SYSALERTSVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SysAlertsView
{
public:
    QVBoxLayout *verticalLayout;
    QTableView *vw;

    void setupUi(QWidget *SysAlertsView)
    {
        if (SysAlertsView->objectName().isEmpty())
            SysAlertsView->setObjectName(QStringLiteral("SysAlertsView"));
        SysAlertsView->resize(400, 300);
        verticalLayout = new QVBoxLayout(SysAlertsView);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        vw = new QTableView(SysAlertsView);
        vw->setObjectName(QStringLiteral("vw"));

        verticalLayout->addWidget(vw);


        retranslateUi(SysAlertsView);

        QMetaObject::connectSlotsByName(SysAlertsView);
    } // setupUi

    void retranslateUi(QWidget *SysAlertsView)
    {
        SysAlertsView->setWindowTitle(QApplication::translate("SysAlertsView", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SysAlertsView: public Ui_SysAlertsView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSALERTSVIEW_H
