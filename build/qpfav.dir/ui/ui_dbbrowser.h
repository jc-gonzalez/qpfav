/********************************************************************************
** Form generated from reading UI file 'dbbrowser.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DBBROWSER_H
#define UI_DBBROWSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QVBoxLayout>
#include "browser.h"

QT_BEGIN_NAMESPACE

class Ui_DBBrowser
{
public:
    QVBoxLayout *verticalLayout_3;
    Browser *browser;

    void setupUi(QDialog *DBBrowser)
    {
        if (DBBrowser->objectName().isEmpty())
            DBBrowser->setObjectName(QStringLiteral("DBBrowser"));
        DBBrowser->resize(841, 484);
        DBBrowser->setSizeGripEnabled(true);
        verticalLayout_3 = new QVBoxLayout(DBBrowser);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(2, 2, 2, 2);
        browser = new Browser(DBBrowser);
        browser->setObjectName(QStringLiteral("browser"));

        verticalLayout_3->addWidget(browser);


        retranslateUi(DBBrowser);

        QMetaObject::connectSlotsByName(DBBrowser);
    } // setupUi

    void retranslateUi(QDialog *DBBrowser)
    {
        DBBrowser->setWindowTitle(QApplication::translate("DBBrowser", "Internal Database Browser", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DBBrowser: public Ui_DBBrowser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DBBROWSER_H
