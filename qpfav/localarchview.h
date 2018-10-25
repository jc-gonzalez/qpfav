#ifndef LOCALARCHVIEW_H
#define LOCALARCHVIEW_H

#include <QWidget>

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

private:
    Ui::LocalArchiveView * ui;
    ProductsModel * model;
};

#endif // LOCALARCHVIEW_H
