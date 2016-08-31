/*************************************************************************
**
****************************************************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "login.h"
QT_BEGIN_NAMESPACE
class QAction;
class QListWidget;
class QMenu;
class QTextEdit;
class QSplitter;
class QTableWidget;
class QLabel;
class QTextEdit;
class QLineEdit;
class QGroupBox;
class QPushButton;
QT_END_NAMESPACE

//! [0]
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

private slots:
    void save();
    void login();
    void print();
    void undo();
    void about();
    void insertCustomer(const QString &customer);
    void addParagraph(const QString &paragraph);

private:
    void iniCentralWidget();
    void createActions();
    void createMenus();
    void createToolBars();
    void createStatusBar();
    void createDockWindows();

    QTextEdit *textEdit;
    QListWidget *customerList;
    QListWidget *paragraphsList;

    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *viewMenu;
    QMenu *helpMenu;
    QToolBar *fileToolBar;
    QToolBar *editToolBar;
    QAction *newLoginAct;
    QAction *saveAct;
    QAction *printAct;
    QAction *undoAct;
    QAction *aboutAct;
    QAction *aboutQtAct;
    QAction *quitAct;


    QSplitter *pSplitter;
    QTableWidget *pTableView;
    QLabel *recvLabel;
    QTextEdit *pRecvTextEdit;
    QLabel *localhostLabel;
    QLabel *localportLabel;
    QLineEdit *localhostLineEdit;
    QLineEdit *localportLineEdit;
    QGroupBox *pGrpboxLocal;

    QPushButton *pConn;
    QPushButton *pStop;
    QPushButton *quitButton;
    Login *plogin;
};
//! [0]

#endif
