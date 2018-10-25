#include "darkpalette.h"

#include <QApplication>
#include <QStyleFactory>

DarkPalette::DarkPalette(QMainWindow * parent) : mw(parent)
{
}

void DarkPalette::apply(QString palName)
{
    qApp->setStyle(QStyleFactory::create("Fusion"));

    QPalette darkPalette;
    darkPalette.setColor(QPalette::Window, QColor(53,53,53));
    darkPalette.setColor(QPalette::WindowText, Qt::white);
    darkPalette.setColor(QPalette::Base, QColor(25,25,25));
    darkPalette.setColor(QPalette::AlternateBase, QColor(53,53,53));
    darkPalette.setColor(QPalette::ToolTipBase, Qt::white);
    darkPalette.setColor(QPalette::ToolTipText, Qt::white);
    darkPalette.setColor(QPalette::Text, Qt::white);
    darkPalette.setColor(QPalette::Button, QColor(53,53,53));
    darkPalette.setColor(QPalette::ButtonText, Qt::white);
    darkPalette.setColor(QPalette::BrightText, Qt::red);
    darkPalette.setColor(QPalette::Link, QColor(42, 130, 218));
    darkPalette.setColor(QPalette::Highlight, QColor(42, 130, 218));
    darkPalette.setColor(QPalette::HighlightedText, Qt::black);
    qApp->setPalette(darkPalette);

    mw->setStyleSheet(buildQss(palName));
}

QString DarkPalette::buildQss(QString & palName)
{
    static const QString darkQss(
    "QToolTip{border:1px solid #000;background-color:%1;padding:1px;border-radius:3px;opacity:100}"
    "QWidget{color:#b1b1b1;background-color:#323232}"
    "QWidget:item:hover{background-color:QLinearGradient(x1: 0,y1: 0,x2: 0,y2: 1,stop: 0 %1,stop: 1 %2);color:#000}"
    "QWidget:item:selected{background-color:QLinearGradient(x1: 0,y1: 0,x2: 0,y2: 1,stop: 0 %1,stop: 1 %3)}"
    "QMenuBar::item{background:transparent}QMenuBar::item:selected{background:transparent;border:1px solid %4}QMenuBar::item:pressed{background:#444;border:1px solid #000;background-color:QLinearGradient(x1:0,y1:0,x2:0,y2:1,stop:1 #212121,stop:0.4 #343434);margin-bottom:-1px;padding-bottom:1px}"
    "QMenu{border:1px solid #000}QMenu::item{padding:2px 20px}QMenu::item:selected{color:#000}"
    "QWidget:disabled{color:#404040;background-color:#323232}"
    "QAbstractItemView{background-color:QLinearGradient(x1: 0,y1: 0,x2: 0,y2: 1,stop: 0 #4d4d4d,stop: 0.1 #646464,stop: 1 #5d5d5d)}"
    "QLineEdit{background-color:QLinearGradient(x1: 0,y1: 0,x2: 0,y2: 1,stop: 0 #4d4d4d,stop: 0 #646464,stop: 1 #5d5d5d);padding:1px;border-style:solid;border:1px solid #1e1e1e;border-radius:5}"
    "QPushButton{color:#b1b1b1;background-color:QLinearGradient(x1: 0,y1: 0,x2: 0,y2: 1,stop: 0 #565656,stop: 0.1 #525252,stop: 0.5 #4e4e4e,stop: 0.9 #4a4a4a,stop: 1 #464646);border-width:1px;border-color:#1e1e1e;border-style:solid;border-radius:3;padding:3px;font-size:12px;padding-left:5px;padding-right:5px}"
    "QPushButton:pressed{background-color:QLinearGradient(x1: 0,y1: 0,x2: 0,y2: 1,stop: 0 #2d2d2d,stop: 0.1 #2b2b2b,stop: 0.5 #292929,stop: 0.9 #282828,stop: 1 #252525)}"
    "QComboBox{selection-background-color:%4;background-color:QLinearGradient(x1: 0,y1: 0,x2: 0,y2: 1,stop: 0 #565656,stop: 0.1 #525252,stop: 0.5 #4e4e4e,stop: 0.9 #4a4a4a,stop: 1 #464646);border-style:solid;border:1px solid #1e1e1e;border-radius:5}QComboBox:hover,QPushButton:hover{border:2px solid QLinearGradient(x1: 0,y1: 0,x2: 0,y2: 1,stop: 0 %1,stop: 1 %3)}"
    "QComboBox:on{padding-top:3px;padding-left:4px;background-color:QLinearGradient(x1: 0,y1: 0,x2: 0,y2: 1,stop: 0 #2d2d2d,stop: 0.1 #2b2b2b,stop: 0.5 #292929,stop: 0.9 #282828,stop: 1 #252525);selection-background-color:%4}QComboBox QAbstractItemView{border:2px solid #a9a9a9;selection-background-color:QLinearGradient(x1: 0,y1: 0,x2: 0,y2: 1,stop: 0 %1,stop: 1 %3)}"
    "QComboBox::drop-down{subcontrol-origin:padding;subcontrol-position:top right;width:15px;border-left-width:0;border-left-color:#a9a9a9;border-left-style:solid;border-top-right-radius:3px;border-bottom-right-radius:3px}"
    "QComboBox::down-arrow{image:url(:/img/down_arrow.png)}QGroupBox:focus{border:2px solid QLinearGradient(x1: 0,y1: 0,x2: 0,y2: 1,stop: 0 %1,stop: 1 %3)}"
    "QTextEdit:focus{border:2px solid QLinearGradient(x1: 0,y1: 0,x2: 0,y2: 1,stop: 0 %1,stop: 1 %3)}"
    "QScrollBar:horizontal{border:1px solid #222;background:QLinearGradient(x1: 0,y1: 0,x2: 0,y2: 1,stop: 0.0 #121212,stop: 0.2 #282828,stop: 1 #484848);height:7px;margin:0 16px}"
    "QScrollBar::handle:horizontal{background:QLinearGradient(x1: 0,y1: 0,x2: 1,y2: 0,stop: 0 %1,stop: 0.5 %3,stop: 1 %1);min-height:20px;border-radius:2px}"
    "QScrollBar::add-line:horizontal{border:1px solid #1b1b19;border-radius:2px;background:QLinearGradient(x1: 0,y1: 0,x2: 1,y2: 0,stop: 0 %1,stop: 1 %3);width:14px;subcontrol-position:right;subcontrol-origin:margin}"
    "QScrollBar::sub-line:horizontal{border:1px solid #1b1b19;border-radius:2px;background:QLinearGradient(x1: 0,y1: 0,x2: 1,y2: 0,stop: 0 %1,stop: 1 %3);width:14px;subcontrol-position:left;subcontrol-origin:margin}"
    "QScrollBar::right-arrow:horizontal,QScrollBar::left-arrow:horizontal{border:1px solid #000;width:1px;height:1px;background:#fff}QScrollBar::add-page:horizontal,QScrollBar::sub-page:horizontal{background:none}"
    "QScrollBar:vertical{background:QLinearGradient(x1: 0,y1: 0,x2: 1,y2: 0,stop: 0.0 #121212,stop: 0.2 #282828,stop: 1 #484848);width:7px;margin:16px 0;border:1px solid #222}"
    "QScrollBar::handle:vertical{background:QLinearGradient(x1: 0,y1: 0,x2: 0,y2: 1,stop: 0 %1,stop: 0.5 %3,stop: 1 %1);min-height:20px;border-radius:2px}"
    "QScrollBar::add-line:vertical{border:1px solid #1b1b19;border-radius:2px;background:QLinearGradient(x1: 0,y1: 0,x2: 0,y2: 1,stop: 0 %1,stop: 1 %3);height:14px;subcontrol-position:bottom;subcontrol-origin:margin}"
    "QScrollBar::sub-line:vertical{border:1px solid #1b1b19;border-radius:2px;background:QLinearGradient(x1: 0,y1: 0,x2: 0,y2: 1,stop: 0 %3,stop: 1 %1);height:14px;subcontrol-position:top;subcontrol-origin:margin}"
    "QScrollBar::up-arrow:vertical,QScrollBar::down-arrow:vertical{border:1px solid #000;width:1px;height:1px;background:#fff}QScrollBar::add-page:vertical,QScrollBar::sub-page:vertical{background:none}"
    "QTextEdit{background-color:#242424}QPlainTextEdit{background-color:#242424}"
    "QHeaderView::section{background-color:QLinearGradient(x1:0,y1:0,x2:0,y2:1,stop:0 #616161,stop: 0.5 #505050,stop: 0.6 #434343,stop:1 #656565);color:#fff;padding-left:4px;border:1px solid #6c6c6c}"
    "QCheckBox:disabled{color:#414141}"
    "QDockWidget::title{text-align:center;spacing:3px;background-color:QLinearGradient(x1:0,y1:0,x2:0,y2:1,stop:0 #323232,stop: 0.5 #242424,stop:1 #323232)}"
    "QDockWidget::close-button,QDockWidget::float-button{text-align:center;spacing:1px;background-color:QLinearGradient(x1:0,y1:0,x2:0,y2:1,stop:0 #323232,stop: 0.5 #242424,stop:1 #323232)}"
    "QDockWidget::close-button:hover,QDockWidget::float-button:hover{background:#242424}QDockWidget::close-button:pressed,QDockWidget::float-button:pressed{padding:1px -1px -1px 1px}"
    "QMainWindow::separator{background-color:QLinearGradient(x1:0,y1:0,x2:0,y2:1,stop:0 #161616,stop: 0.5 #151515,stop: 0.6 #212121,stop:1 #343434);color:#fff;padding-left:4px;border:1px solid #4c4c4c;spacing:3px}"
    "QMainWindow::separator:hover{background-color:QLinearGradient(x1:0,y1:0,x2:0,y2:1,stop:0 %3,stop:0.5 %5 stop:1 %1);color:#fff;padding-left:4px;border:1px solid #6c6c6c;spacing:3px}"
    "QToolBar::handle{spacing:3px;background:url(:/img/handle.png)}"
    "QMenu::separator{height:2px;background-color:QLinearGradient(x1:0,y1:0,x2:0,y2:1,stop:0 #161616,stop: 0.5 #151515,stop: 0.6 #212121,stop:1 #343434);color:#fff;padding-left:4px;margin-left:10px;margin-right:5px}"
    "QProgressBar{border:2px solid grey;border-radius:5px;text-align:center}"
    "QProgressBar::chunk{background-color:%3;width:2.15px;margin:.5px}"
    "QTabBar::tab{color:#b1b1b1;border:1px solid #444;border-bottom-style:none;background-color:#323232;margin-right:-1px;padding:3px 10px 2px}"
    "QTabWidget::pane{border:1px solid #444;top:1px}QTabBar::tab:last{margin-right:0;border-top-right-radius:3px}QTabBar::tab:first:!selected{margin-left:0;border-top-left-radius:3px}"
    "QTabBar::tab:!selected{color:#b1b1b1;border-bottom-style:solid;margin-top:3px;background-color:QLinearGradient(x1:0,y1:0,x2:0,y2:1,stop:1 #212121,stop:.4 #343434)}"
    "QTabBar::tab:selected{border-top-left-radius:3px;border-top-right-radius:3px;margin-bottom:0}"
    "QTabBar::tab:!selected:hover{border-top-left-radius:3px;border-top-right-radius:3px;background-color:QLinearGradient(x1:0,y1:0,x2:0,y2:1,stop:1 #212121,stop:0.4 #343434,stop:0.2 #343434,stop:0.1 %4)}"
    "QRadioButton::indicator:checked,QRadioButton::indicator:unchecked{color:#b1b1b1;background-color:#323232;border:1px solid #b1b1b1;border-radius:6px}"
    "QRadioButton::indicator:checked{background-color:qradialgradient(cx: 0.5,cy: 0.5,fx: 0.5,fy: 0.5,radius: 1.0,stop: 0.25 %4,stop: 0.3 #323232)}"
    "QCheckBox::indicator{color:#b1b1b1;background-color:#323232;border:1px solid #b1b1b1;width:9px;height:9px}QRadioButton::indicator{border-radius:6px}"
    "QRadioButton::indicator:hover,QCheckBox::indicator:hover{border:1px solid %4}QCheckBox::indicator:checked{image:url(:/img/checkbox.png)}"
    "QCheckBox::indicator:disabled,QRadioButton::indicator:disabled{border:1px solid #444}"
    /*"QDial{background-color:QLinearGradient(x1: 0.177, y1: 0.004, x2: 0.831, y2: 0.911, "
    "stop: 0 white,stop: 0.061 white,stop: 0.066 lightgray,stop: 0.5 #242424,stop: 0.505 #000000,"
    "stop: 0.827 #040404,stop: 0.966 #292929,stop: 0.983 #2e2e2e);}"*/
    "QLCDNumber{color:#b1b1b1;background-color:QLinearGradient(x1: 0,y1: 0,x2: 0,y2: 1,stop: 0 #565656,stop: 0.1 #525252,stop: 0.5 #4e4e4e,stop: 0.9 #4a4a4a,stop: 1 #464646);border-width:1px;border-color:#1e1e1e;border-style:solid;border-radius:6;padding:3px;font-size:12px;padding-left:5px;padding-right:5px}");

    typedef QVector<QColor>        Palette;
    typedef QMap<QString, Palette> CatalogueOfPalettes;

    static CatalogueOfPalettes palettes
    {
        {"DarkOrange", {QColor("#ffa02f"), QColor("#ca0619"), QColor("#d7801a"), QColor("#ffaa00"), QColor("#b56c17")}},
        {"DarkGreen",  {QColor("#4fa02f"), QColor("#1ac619"), QColor("#27d01a"), QColor("#3faa00"), QColor("#056c17")}},
        {"DarkBlue",   {QColor("#2fa0ff"), QColor("#0a16ca"), QColor("#1780da"), QColor("#00aaff"), QColor("#156cb7")}}
    };

    Palette pal(palettes[palName]);

    int i = 1;
    QString finalQss(darkQss);
    foreach (const QColor c, pal) {
        finalQss.replace(QString("%%1").arg(i), c.name());
        ++i;
    }

    return finalQss;
}
