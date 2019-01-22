#ifndef SYSALERTSVIEW_H
#define SYSALERTSVIEW_H

#include <QWidget>

#include "sysalertmodel.h"
#include "actionshandler.h"
#include "mainwindow.h"

namespace Ui {
class SysAlertsView;
}

using QPF::SysAlertModel;
using QPF::ActionsHandler;
using QPF::MainWindow;

class SysAlertsView : public QWidget
{
    Q_OBJECT

public:
    explicit SysAlertsView(QWidget *parent = 0);
    ~SysAlertsView();

public slots:
    void setActionsHandler(ActionsHandler * a);
    void showSysAlertInfo();

private:
    Ui::SysAlertsView * ui;
    SysAlertModel * model;
    ActionsHandler * aHdl;
    MainWindow * mw;
};

#endif // SYSALERTSVIEW_H
