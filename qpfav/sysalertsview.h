#ifndef SYSALERTSVIEW_H
#define SYSALERTSVIEW_H

#include <QWidget>

#include "sysalertmodel.h"

namespace Ui {
class SysAlertsView;
}

using QPF::SysAlertModel;

class SysAlertsView : public QWidget
{
    Q_OBJECT

public:
    explicit SysAlertsView(QWidget *parent = 0);
    ~SysAlertsView();

private:
    Ui::SysAlertsView * ui;
    SysAlertModel * model;
};

#endif // SYSALERTSVIEW_H
