#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "ui_login.h"
#include <QPushButton>
class Login : public QDialog
{
    Q_OBJECT

public:
    Login(QWidget *parent = 0);
    ~Login();

private slots:
    void ExecCancel();

private:
    Ui::LoginClass ui;
    QPushButton *pLogin;
    QPushButton *pCancel;
};

#endif // LOGIN_H
