#ifndef DARKPALETTE_H
#define DARKPALETTE_H

#include <QMainWindow>

class DarkPalette
{
public:
    DarkPalette(QMainWindow * parent);

    void apply(QString styleName, QString palName);

private:
    QString buildQss(QString &palName);

    QMainWindow * mw;
};

#endif // DARKPALETTE_H
