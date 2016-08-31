#include "login.h"
#include "myhelper.h"
Login::Login(QWidget *parent)
    : QDialog(parent)
{
    ui.setupUi(this);
    //setWindowFlags(/*Qt::CustomizeWindowHint|*/Qt::FramelessWindowHint);
    //hide();
    pLogin=new QPushButton;
    pCancel=new QPushButton;

    connect(pCancel,SIGNAL(clicked()),this,SLOT(close()));
}

Login::~Login()
{
    delete pLogin;
    delete pCancel;
}
void Login::ExecCancel()
{
    //close();
}
