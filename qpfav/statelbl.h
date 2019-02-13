#ifndef STATELBL_H
#define STATELBL_H

#include <QWidget>
namespace Ui {
class StateLabel;
}

class StateLabel : public QWidget
{
    Q_OBJECT

public:
    explicit StateLabel(QWidget *parent = 0);
    ~StateLabel();

public slots:
    void setState(QString s);

private slots:
    void run();

private:
    Ui::StateLabel * ui;
};

#endif // STATELBL_H
