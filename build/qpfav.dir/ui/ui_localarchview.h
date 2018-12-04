/********************************************************************************
** Form generated from reading UI file 'localarchview.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOCALARCHVIEW_H
#define UI_LOCALARCHVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LocalArchiveView
{
public:
    QVBoxLayout *verticalLayout;
    QTreeView *vw;

    void setupUi(QWidget *LocalArchiveView)
    {
        if (LocalArchiveView->objectName().isEmpty())
            LocalArchiveView->setObjectName(QStringLiteral("LocalArchiveView"));
        LocalArchiveView->resize(400, 300);
        verticalLayout = new QVBoxLayout(LocalArchiveView);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        vw = new QTreeView(LocalArchiveView);
        vw->setObjectName(QStringLiteral("vw"));

        verticalLayout->addWidget(vw);


        retranslateUi(LocalArchiveView);

        QMetaObject::connectSlotsByName(LocalArchiveView);
    } // setupUi

    void retranslateUi(QWidget *LocalArchiveView)
    {
        LocalArchiveView->setWindowTitle(QApplication::translate("LocalArchiveView", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LocalArchiveView: public Ui_LocalArchiveView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOCALARCHVIEW_H
