/********************************************************************************
** Form generated from reading UI file 'browserwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BROWSERWIDGET_H
#define UI_BROWSERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "connectionwidget.h"

QT_BEGIN_NAMESPACE

class Ui_Browser
{
public:
    QAction *insertRowAction;
    QAction *deleteRowAction;
    QAction *fieldStrategyAction;
    QAction *rowStrategyAction;
    QAction *manualStrategyAction;
    QAction *submitAction;
    QAction *revertAction;
    QAction *selectAction;
    QVBoxLayout *verticalLayout_3;
    QSplitter *splitter;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QSplitter *splitter_2;
    ConnectionWidget *connectionWidget;
    QTableView *table;
    QGroupBox *gboxSQL;
    QVBoxLayout *verticalLayout;
    QTextEdit *sqlEdit;
    QHBoxLayout *hboxLayout;
    QSpacerItem *spacerItem;
    QPushButton *clearButton;
    QPushButton *submitButton;

    void setupUi(QWidget *Browser)
    {
        if (Browser->objectName().isEmpty())
            Browser->setObjectName(QStringLiteral("Browser"));
        Browser->resize(724, 360);
        insertRowAction = new QAction(Browser);
        insertRowAction->setObjectName(QStringLiteral("insertRowAction"));
        insertRowAction->setEnabled(false);
        deleteRowAction = new QAction(Browser);
        deleteRowAction->setObjectName(QStringLiteral("deleteRowAction"));
        deleteRowAction->setEnabled(false);
        fieldStrategyAction = new QAction(Browser);
        fieldStrategyAction->setObjectName(QStringLiteral("fieldStrategyAction"));
        fieldStrategyAction->setCheckable(true);
        rowStrategyAction = new QAction(Browser);
        rowStrategyAction->setObjectName(QStringLiteral("rowStrategyAction"));
        rowStrategyAction->setCheckable(true);
        manualStrategyAction = new QAction(Browser);
        manualStrategyAction->setObjectName(QStringLiteral("manualStrategyAction"));
        manualStrategyAction->setCheckable(true);
        submitAction = new QAction(Browser);
        submitAction->setObjectName(QStringLiteral("submitAction"));
        revertAction = new QAction(Browser);
        revertAction->setObjectName(QStringLiteral("revertAction"));
        selectAction = new QAction(Browser);
        selectAction->setObjectName(QStringLiteral("selectAction"));
        verticalLayout_3 = new QVBoxLayout(Browser);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        splitter = new QSplitter(Browser);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setFrameShape(QFrame::NoFrame);
        splitter->setFrameShadow(QFrame::Plain);
        splitter->setLineWidth(1);
        splitter->setOrientation(Qt::Vertical);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        splitter_2 = new QSplitter(layoutWidget);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(splitter_2->sizePolicy().hasHeightForWidth());
        splitter_2->setSizePolicy(sizePolicy);
        splitter_2->setOrientation(Qt::Horizontal);
        connectionWidget = new ConnectionWidget(splitter_2);
        connectionWidget->setObjectName(QStringLiteral("connectionWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Ignored, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(connectionWidget->sizePolicy().hasHeightForWidth());
        connectionWidget->setSizePolicy(sizePolicy1);
        splitter_2->addWidget(connectionWidget);
        table = new QTableView(splitter_2);
        table->setObjectName(QStringLiteral("table"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(2);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(table->sizePolicy().hasHeightForWidth());
        table->setSizePolicy(sizePolicy2);
        table->setContextMenuPolicy(Qt::ActionsContextMenu);
        table->setSelectionBehavior(QAbstractItemView::SelectRows);
        table->setSortingEnabled(true);
        splitter_2->addWidget(table);

        verticalLayout_2->addWidget(splitter_2);

        splitter->addWidget(layoutWidget);
        gboxSQL = new QGroupBox(splitter);
        gboxSQL->setObjectName(QStringLiteral("gboxSQL"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(gboxSQL->sizePolicy().hasHeightForWidth());
        gboxSQL->setSizePolicy(sizePolicy3);
        gboxSQL->setMaximumSize(QSize(16777215, 160));
        verticalLayout = new QVBoxLayout(gboxSQL);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(4, 4, 4, 4);
        sqlEdit = new QTextEdit(gboxSQL);
        sqlEdit->setObjectName(QStringLiteral("sqlEdit"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(sqlEdit->sizePolicy().hasHeightForWidth());
        sqlEdit->setSizePolicy(sizePolicy4);
        sqlEdit->setMinimumSize(QSize(0, 18));
        sqlEdit->setBaseSize(QSize(0, 100));

        verticalLayout->addWidget(sqlEdit);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setObjectName(QStringLiteral("hboxLayout"));
        hboxLayout->setContentsMargins(1, 1, 1, 1);
        spacerItem = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem);

        clearButton = new QPushButton(gboxSQL);
        clearButton->setObjectName(QStringLiteral("clearButton"));

        hboxLayout->addWidget(clearButton);

        submitButton = new QPushButton(gboxSQL);
        submitButton->setObjectName(QStringLiteral("submitButton"));

        hboxLayout->addWidget(submitButton);


        verticalLayout->addLayout(hboxLayout);

        splitter->addWidget(gboxSQL);

        verticalLayout_3->addWidget(splitter);

        QWidget::setTabOrder(sqlEdit, clearButton);
        QWidget::setTabOrder(clearButton, submitButton);
        QWidget::setTabOrder(submitButton, connectionWidget);
        QWidget::setTabOrder(connectionWidget, table);

        retranslateUi(Browser);

        QMetaObject::connectSlotsByName(Browser);
    } // setupUi

    void retranslateUi(QWidget *Browser)
    {
        Browser->setWindowTitle(QApplication::translate("Browser", "Qt SQL Browser", Q_NULLPTR));
        insertRowAction->setText(QApplication::translate("Browser", "&Insert Row", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        insertRowAction->setStatusTip(QApplication::translate("Browser", "Inserts a new Row", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        deleteRowAction->setText(QApplication::translate("Browser", "&Delete Row", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        deleteRowAction->setStatusTip(QApplication::translate("Browser", "Deletes the current Row", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        fieldStrategyAction->setText(QApplication::translate("Browser", "Submit on &Field Change", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        fieldStrategyAction->setToolTip(QApplication::translate("Browser", "Commit on Field Change", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        rowStrategyAction->setText(QApplication::translate("Browser", "Submit on &Row Change", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        rowStrategyAction->setToolTip(QApplication::translate("Browser", "Commit on Row Change", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        manualStrategyAction->setText(QApplication::translate("Browser", "Submit &Manually", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        manualStrategyAction->setToolTip(QApplication::translate("Browser", "Commit Manually", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        submitAction->setText(QApplication::translate("Browser", "&Submit All", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        submitAction->setToolTip(QApplication::translate("Browser", "Submit Changes", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        revertAction->setText(QApplication::translate("Browser", "&Revert All", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        revertAction->setToolTip(QApplication::translate("Browser", "Revert", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        selectAction->setText(QApplication::translate("Browser", "S&elect", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        selectAction->setToolTip(QApplication::translate("Browser", "Refresh Data from Database", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        gboxSQL->setTitle(QApplication::translate("Browser", "SQL Query", Q_NULLPTR));
        clearButton->setText(QApplication::translate("Browser", "&Clear", Q_NULLPTR));
        submitButton->setText(QApplication::translate("Browser", "&Submit", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Browser: public Ui_Browser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BROWSERWIDGET_H
