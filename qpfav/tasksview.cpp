#include "tasksview.h"
#include "ui_tasksview.h"

#include "tasksmodel.h"

TasksView::TasksView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TasksView)
{
    ui->setupUi(this);
    ui->vw->setSelectionBehavior(QAbstractItemView::SelectRows);

    model = new TasksModel;
    ui->vw->setModel(model);
}

TasksView::~TasksView()
{
    delete ui;
}
