/********************************************************************************
** Form generated from reading UI file 'verbleveldlg.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VERBLEVELDLG_H
#define UI_VERBLEVELDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_VerbLevelDlg
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QListWidget *listWidget;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *VerbLevelDlg)
    {
        if (VerbLevelDlg->objectName().isEmpty())
            VerbLevelDlg->setObjectName(QStringLiteral("VerbLevelDlg"));
        VerbLevelDlg->resize(184, 270);
        verticalLayout = new QVBoxLayout(VerbLevelDlg);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(VerbLevelDlg);
        label->setObjectName(QStringLiteral("label"));
        label->setWordWrap(true);

        verticalLayout->addWidget(label);

        listWidget = new QListWidget(VerbLevelDlg);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        verticalLayout->addWidget(listWidget);

        buttonBox = new QDialogButtonBox(VerbLevelDlg);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(VerbLevelDlg);
        QObject::connect(buttonBox, SIGNAL(accepted()), VerbLevelDlg, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), VerbLevelDlg, SLOT(reject()));

        QMetaObject::connectSlotsByName(VerbLevelDlg);
    } // setupUi

    void retranslateUi(QDialog *VerbLevelDlg)
    {
        VerbLevelDlg->setWindowTitle(QApplication::translate("VerbLevelDlg", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("VerbLevelDlg", "Select log files minimun verbosity level:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class VerbLevelDlg: public Ui_VerbLevelDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VERBLEVELDLG_H
