#ifndef PROCALERTSVIEW_H
#define PROCALERTSVIEW_H

#include <QWidget>

#include "procalertmodel.h"

namespace Ui {
class ProcAlertsView;
}

using QPF::ProcAlertModel;

class ProcAlertsView : public QWidget
{
    Q_OBJECT

public:
    explicit ProcAlertsView(QWidget *parent = 0);
    ~ProcAlertsView();

private:
    Ui::ProcAlertsView * ui;
    ProcAlertModel * model;
};

#endif // PROCALERTSVIEW_H
