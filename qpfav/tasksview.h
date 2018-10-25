#ifndef TASKSVIEW_H
#define TASKSVIEW_H

#include <QWidget>
#include "tasksmodel.h"

namespace Ui {
class TasksView;
}

using QPF::TasksModel;

class TasksView : public QWidget
{
    Q_OBJECT

public:
    explicit TasksView(QWidget *parent = 0);
    ~TasksView();

private:
    Ui::TasksView * ui;

    TasksModel * model;
};

#endif // TASKSVIEW_H
