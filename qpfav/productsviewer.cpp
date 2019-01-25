#include "productsviewer.h"
#include "ui_productsviewer.h"

#include <QFileInfo>
#include <QDesktopServices>
#include <QMessageBox>
#include <QUrl>
#include <QTextEdit>

#include "util.h"
#include "xmlsyntaxhighlight.h"
#include "qjsonviewer.h"

#include "config.h"
using Configuration::cfg;

#include <iostream>

#define TRC(s) std::cerr << s << std::endl;

#define TASK_NAME_COLUMN    3
#define TASK_STATUS_COLUMN  6
#define TASK_DATA_COLUMN    9

ProductsViewer::ProductsViewer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProductsViewer)
{
    ui->setupUi(this);
}

ProductsViewer::~ProductsViewer()
{
    delete ui;
}

void ProductsViewer::createNewViewer(QString fullPath)
{
    QFileInfo fs(fullPath);
    QString tabName = fs.fileName();

    // Find in existing ui->tabs
    if (selectProductViewer(tabName)) { return; }

    // If not existing, check first taht the file can be open
    TRC((fs.absoluteFilePath() + fs.suffix()).toStdString());
    QFile file(fs.absoluteFilePath());
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        TRC("Cannot open file");
        return;
    }

    // Then, create new viewer with file content
    QString iconRscName;
    QWidget * editor = 0;
    if (fs.suffix() == "xml") {
        QString content = getFileContent(&file);
        QTextEdit * ed = new QTextEdit;
        XMLBasicSyntaxHighlighter * highlighter = new XMLBasicSyntaxHighlighter(ed);
        Q_UNUSED(highlighter);
        ed->setPlainText(content);
        ed->setReadOnly(true);
        editor = ed;
        iconRscName = ":/img/xml.png";
    } else if (fs.suffix() == "json") {
        QJSONViewer * ed = new QJSONViewer;
        QString content = getFileContent(&file);
        QByteArray data = content.toLocal8Bit();
        ed->init(tabName, data);
        editor = ed;
        iconRscName = ":/img/json.png";
    } else if (fs.suffix() == "fits") {
        QString header;
        binaryGetFITSHeader(fs.absoluteFilePath(), header);
        QJSONViewer * ed = new QJSONViewer;
        QByteArray data = header.toLocal8Bit();
        ed->init(tabName, data);
        editor = ed;
        iconRscName = ":/img/brick.png";
    } else if (fs.suffix() == "log") {
        QString content = getFileContent(&file);
        QTextEdit * ed = new QTextEdit;
        ed->setPlainText(content);
        ed->setReadOnly(true);
        editor = ed;
        iconRscName = ":/img/txt.png";
    } else {
        QString content = getFileContent(&file);
        QTextEdit * ed = new QTextEdit;
        ed->setPlainText(content);
        ed->setReadOnly(true);
        editor = ed;
        iconRscName = ":/img/bullet_blue.png";
    }

    // Ensure these ui->tabs are closable (and only these)
    editor->setObjectName(tabName);
    int tabIdx = ui->tabs->addTab(editor, tabName);
    ui->tabs->setTabIcon(tabIdx, QIcon(iconRscName));
    ui->tabs->setTabsClosable(true);

    emit newProductViewerAvailable(tabName);
}

bool ProductsViewer::selectProductViewer(QString name)
{
    QWidget * existingWdg = ui->tabs->findChild<QWidget*>(name);
    if (existingWdg != 0) {
        ui->tabs->setCurrentIndex(ui->tabs->indexOf(existingWdg));
        return true;
    }
    return false;
}
