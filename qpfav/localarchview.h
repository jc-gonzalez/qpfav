#ifndef LOCALARCHVIEW_H
#define LOCALARCHVIEW_H

#include <QWidget>
#include <QComboBox>

#include "productsmodel.h"

namespace Ui {
class LocalArchiveView;
}

using QPF::ProductsModel;

class LocalArchiveView : public QWidget
{
    Q_OBJECT

public:
    explicit LocalArchiveView(QWidget *parent = 0);
    ~LocalArchiveView();
    void setAutoButtons(QComboBox * cboxAuto);

public slots:
    void autoBtnsChanged(const QModelIndex& topLeft, 
                         const QModelIndex& bottomRight);

    void run();
    void arefresh();
    void aexpand();
    void acollapse();
    void aresize();

private:
    enum AutoBehavior { AUTO_UPDATE, 
                        AUTO_EXPAND, 
                        AUTO_RESIZE, 
                        MULTI_SELECT };

    Ui::LocalArchiveView * ui;
    ProductsModel * model;

    QStandardItemModel * autoBtnsModel;
    std::vector<QStandardItem*> autoBtns;

    bool autoUpdate, autoExpand, autoResize;
};

#endif // LOCALARCHVIEW_H
