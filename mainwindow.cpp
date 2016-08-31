/****************************************************************************
**
**
****************************************************************************/

//! [0]
#include <QtGui>
#include "mainwindow.h"
#include "myhelper.h"
//! [0]
QRegExp regExp("\\b(?:(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.){3}(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\b");
//! [1]
MainWindow::MainWindow()
{
    //textEdit = new QTextEdit;
    //setCentralWidget(textEdit);
    //setParent(this);
    myHelper::SetSystemCode();
    iniCentralWidget();

    setCentralWidget(pSplitter);
    createActions();
    createMenus();
    createToolBars();
    createStatusBar();
    createDockWindows();

    setWindowTitle(tr("Dock Widgets"));


}
//! [1]
void MainWindow::iniCentralWidget()
{
    //垂直分割
    pSplitter=new QSplitter(Qt::Vertical,0);
    //tablewidget
    pTableView = new QTableWidget(0,4);
    pTableView->setWindowTitle("VIP List");
    pTableView->resize(800, 400);
    pTableView->setHorizontalHeaderItem(0, new QTableWidgetItem(tr("数据集DataSetID")));
    pTableView->setHorizontalHeaderItem(1, new QTableWidgetItem(QObject::tr("数据名称dataName")));
    pTableView->setHorizontalHeaderItem(2, new QTableWidgetItem(QObject::tr("数据标识indexno")));
    pTableView->setHorizontalHeaderItem(3, new QTableWidgetItem(QObject::tr("数据值value")));
    pTableView->setColumnWidth(0, 100);
    pTableView->setColumnWidth(1, 150);
    pTableView->setColumnWidth(2, 150);
    pTableView->setColumnWidth(3, 150);
    pTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    pTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    pTableView->showGrid();
    //recvLabel
    recvLabel=new QLabel;
    recvLabel->setText(tr("报文:"));
    //pRecvTextEdit
    pRecvTextEdit=new QTextEdit;
    pRecvTextEdit->setReadOnly(true);

    //pSplitter添加各个控件
    pSplitter->addWidget(pTableView);
    pSplitter->addWidget(pRecvTextEdit);
}

//! [3]
void MainWindow::print()
{
#ifndef QT_NO_PRINTER
    QTextDocument *document = textEdit->document();
    QPrinter printer;

    QPrintDialog *dlg = new QPrintDialog(&printer, this);
    if (dlg->exec() != QDialog::Accepted)
        return;

    document->print(&printer);

    statusBar()->showMessage(tr("Ready"), 2000);
#endif
}
//! [3]

void MainWindow::login()
{   
    plogin=new Login(this);
    plogin->setAttribute(Qt::WA_ShowModal, false);
    plogin->setWindowModality(Qt::WindowModal);
    plogin->show();

}


//! [4]
void MainWindow::save()
{
    QString fileName = QFileDialog::getSaveFileName(this,
                        tr("Choose a file name"), ".",
                        tr("HTML (*.html *.htm)"));
    if (fileName.isEmpty())
        return;
    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("Dock Widgets"),
                             tr("Cannot write file %1:\n%2.")
                             .arg(fileName)
                             .arg(file.errorString()));
        return;
    }

    QTextStream out(&file);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    out << textEdit->toHtml();
    QApplication::restoreOverrideCursor();

    statusBar()->showMessage(tr("Saved '%1'").arg(fileName), 2000);
}
//! [4]

//! [5]
void MainWindow::undo()
{
    QTextDocument *document = textEdit->document();
    document->undo();
}
//! [5]

//! [6]
void MainWindow::insertCustomer(const QString &customer)
{
    if (customer.isEmpty())
        return;
    QStringList customerList = customer.split(", ");
    QTextDocument *document = textEdit->document();
    QTextCursor cursor = document->find("NAME");
    if (!cursor.isNull()) {
        cursor.beginEditBlock();
        cursor.insertText(customerList.at(0));
        QTextCursor oldcursor = cursor;
        cursor = document->find("ADDRESS");
        if (!cursor.isNull()) {
            for (int i = 1; i < customerList.size(); ++i) {
                cursor.insertBlock();
                cursor.insertText(customerList.at(i));
            }
            cursor.endEditBlock();
        }
        else
            oldcursor.endEditBlock();
    }
}
//! [6]

//! [7]
void MainWindow::addParagraph(const QString &paragraph)
{
    if (paragraph.isEmpty())
        return;
    QTextDocument *document = textEdit->document();
    QTextCursor cursor = document->find(tr("Yours sincerely,"));
    if (cursor.isNull())
        return;
    cursor.beginEditBlock();
    cursor.movePosition(QTextCursor::PreviousBlock, QTextCursor::MoveAnchor, 2);
    cursor.insertBlock();
    cursor.insertText(paragraph);
    cursor.insertBlock();
    cursor.endEditBlock();

}
//! [7]

void MainWindow::about()
{

}

void MainWindow::createActions()
{
    newLoginAct = new QAction(QIcon(":/images/new.png"), tr("&登录"),
                               this);
    newLoginAct->setShortcut(tr("Ctrl+N"));
    newLoginAct->setStatusTip(tr("Create a new form letter"));
    connect(newLoginAct, SIGNAL(triggered()), this, SLOT(login()));


    saveAct = new QAction(QIcon(":/images/save.png"), tr("&Save..."), this);
    saveAct->setShortcut(tr("Ctrl+S"));
    saveAct->setStatusTip(tr("Save the current form letter"));
    connect(saveAct, SIGNAL(triggered()), this, SLOT(save()));

    printAct = new QAction(QIcon(":/images/print.png"), tr("&Print..."), this);
    printAct->setShortcut(tr("Ctrl+P"));
    printAct->setStatusTip(tr("Print the current form letter"));
    connect(printAct, SIGNAL(triggered()), this, SLOT(print()));

    undoAct = new QAction(QIcon(":/images/undo.png"), tr("&Undo"), this);
    undoAct->setShortcut(tr("Ctrl+Z"));
    undoAct->setStatusTip(tr("Undo the last editing action"));
    connect(undoAct, SIGNAL(triggered()), this, SLOT(undo()));

    quitAct = new QAction(tr("&Quit"), this);
    quitAct->setShortcut(tr("Ctrl+Q"));
    quitAct->setStatusTip(tr("Quit the application"));
    connect(quitAct, SIGNAL(triggered()), this, SLOT(close()));

    aboutAct = new QAction(tr("&About"), this);
    aboutAct->setStatusTip(tr("Show the application's About box"));
    connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));

    aboutQtAct = new QAction(tr("About &Qt"), this);
    aboutQtAct->setStatusTip(tr("Show the Qt library's About box"));
    connect(aboutQtAct, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newLoginAct);
    fileMenu->addAction(saveAct);
    fileMenu->addAction(printAct);
    fileMenu->addSeparator();
    fileMenu->addAction(quitAct);

    editMenu = menuBar()->addMenu(tr("&Edit"));
    editMenu->addAction(undoAct);

    viewMenu = menuBar()->addMenu(tr("&View"));

    menuBar()->addSeparator();

    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(aboutAct);
    helpMenu->addAction(aboutQtAct);
}

void MainWindow::createToolBars()
{
    fileToolBar = addToolBar(tr("File"));
    fileToolBar->addAction(newLoginAct);
    fileToolBar->addAction(saveAct);
    fileToolBar->addAction(printAct);

    editToolBar = addToolBar(tr("Edit"));
    editToolBar->addAction(undoAct);
}

//! [8]
void MainWindow::createStatusBar()
{
    statusBar()->showMessage(tr("Ready"));
}
//! [8]

//! [9]
void MainWindow::createDockWindows()
{
    QDockWidget *dock = new QDockWidget(tr("网络设置"), this);
    dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    dock->setMinimumWidth(200); 
    dock->showMinimized();
    pGrpboxLocal = new QGroupBox(dock);
    pGrpboxLocal->setMaximumSize(200,250);
    localhostLabel=new QLabel(pGrpboxLocal);
    localhostLabel->setText(tr("&IP地址:"));
    localportLabel=new QLabel(pGrpboxLocal);
    localportLabel->setText(tr("&端口:"));

    localhostLineEdit = new QLineEdit(pGrpboxLocal);
    localhostLineEdit->setValidator(new QRegExpValidator(regExp, this));
    localportLineEdit=new QLineEdit(pGrpboxLocal);
    localportLineEdit->setValidator(new QIntValidator(1, 65535, this));
    localhostLabel->setBuddy(localhostLineEdit);
    localportLabel->setBuddy(localportLineEdit);
    pConn=new QPushButton(tr("连接"));
    pConn->setDefault(true);
    pConn->setEnabled(false);
    pStop = new QPushButton(tr("停止"));
    pStop->setDefault(true);
    pStop->setEnabled(false);
    quitButton = new QPushButton(tr("Quit"));

    QVBoxLayout *pVlocalnetcfg=new QVBoxLayout;
    pVlocalnetcfg->addWidget(localhostLabel);
    pVlocalnetcfg->addWidget(localhostLineEdit);
    pVlocalnetcfg->addWidget(localportLabel);
    pVlocalnetcfg->addWidget(localportLineEdit);

    QHBoxLayout *pHlayout = new QHBoxLayout;
    pHlayout->addWidget(pConn);
    pHlayout->addWidget(pStop);
    pHlayout->addWidget(quitButton);

    QVBoxLayout *pVlayout = new QVBoxLayout;
    pVlayout->addLayout(pVlocalnetcfg);
    pVlayout->addLayout(pHlayout);
    pGrpboxLocal->setLayout(pVlayout);

    dock->setWidget(pGrpboxLocal);
    addDockWidget(Qt::RightDockWidgetArea, dock,Qt::Vertical);
    viewMenu->addAction(dock->toggleViewAction());

    dock = new QDockWidget(tr("Paragraphs"), this);
    paragraphsList = new QListWidget(dock);
    dock->setWidget(paragraphsList);
    addDockWidget(Qt::RightDockWidgetArea, dock);
    viewMenu->addAction(dock->toggleViewAction());
}
//! [9]
