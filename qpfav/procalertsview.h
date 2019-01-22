#ifndef PROCALERTSVIEW_H
#define PROCALERTSVIEW_H

#include <QWidget>

#include "procalertmodel.h"
#include "actionshandler.h"
#include "mainwindow.h"

namespace Ui {
class ProcAlertsView;
}

using QPF::ProcAlertModel;
using QPF::ActionsHandler;
using QPF::MainWindow;

class ProcAlertsView : public QWidget
{
    Q_OBJECT

public:
    explicit ProcAlertsView(QWidget *parent = 0);
    ~ProcAlertsView();

public slots:
    void setActionsHandler(ActionsHandler * a);
    void showProcAlertInfo();
    void locateAlertInProduct();

private:
    Ui::ProcAlertsView * ui;
    ProcAlertModel * model;
    ActionsHandler * aHdl;
    MainWindow * mw;
};

#endif // PROCALERTSVIEW_H
