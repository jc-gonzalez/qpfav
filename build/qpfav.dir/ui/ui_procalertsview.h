/********************************************************************************
** Form generated from reading UI file 'procalertsview.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROCALERTSVIEW_H
#define UI_PROCALERTSVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProcAlertsView
{
public:
    QVBoxLayout *verticalLayout;
    QTableView *vw;

    void setupUi(QWidget *ProcAlertsView)
    {
        if (ProcAlertsView->objectName().isEmpty())
            ProcAlertsView->setObjectName(QStringLiteral("ProcAlertsView"));
        ProcAlertsView->resize(400, 300);
        verticalLayout = new QVBoxLayout(ProcAlertsView);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        vw = new QTableView(ProcAlertsView);
        vw->setObjectName(QStringLiteral("vw"));

        verticalLayout->addWidget(vw);


        retranslateUi(ProcAlertsView);

        QMetaObject::connectSlotsByName(ProcAlertsView);
    } // setupUi

    void retranslateUi(QWidget *ProcAlertsView)
    {
        ProcAlertsView->setWindowTitle(QApplication::translate("ProcAlertsView", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ProcAlertsView: public Ui_ProcAlertsView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROCALERTSVIEW_H
