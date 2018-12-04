/********************************************************************************
** Form generated from reading UI file 'tasksview.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASKSVIEW_H
#define UI_TASKSVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TasksView
{
public:
    QVBoxLayout *verticalLayout;
    QTableView *vw;

    void setupUi(QWidget *TasksView)
    {
        if (TasksView->objectName().isEmpty())
            TasksView->setObjectName(QStringLiteral("TasksView"));
        TasksView->resize(400, 300);
        verticalLayout = new QVBoxLayout(TasksView);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        vw = new QTableView(TasksView);
        vw->setObjectName(QStringLiteral("vw"));

        verticalLayout->addWidget(vw);


        retranslateUi(TasksView);

        QMetaObject::connectSlotsByName(TasksView);
    } // setupUi

    void retranslateUi(QWidget *TasksView)
    {
        TasksView->setWindowTitle(QApplication::translate("TasksView", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TasksView: public Ui_TasksView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASKSVIEW_H
