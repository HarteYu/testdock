/********************************************************************************
** Form generated from reading ui file 'login.ui'
**
** Created: Tue Jul 14 11:35:11 2015
**      by: Qt User Interface Compiler version 4.4.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LoginClass
{
public:
    QGroupBox *groupBox;
    QLabel *userlabel;
    QLineEdit *lineEdit;
    QLabel *passwdlabel;
    QLineEdit *lineEdit_2;
    QPushButton *loginBtn;
    QPushButton *cancelBtn;

    void setupUi(QDialog *LoginClass)
    {
    if (LoginClass->objectName().isEmpty())
        LoginClass->setObjectName(QString::fromUtf8("LoginClass"));
    LoginClass->resize(305, 157);
    groupBox = new QGroupBox(LoginClass);
    groupBox->setObjectName(QString::fromUtf8("groupBox"));
    groupBox->setGeometry(QRect(0, 0, 301, 151));
    userlabel = new QLabel(groupBox);
    userlabel->setObjectName(QString::fromUtf8("userlabel"));
    userlabel->setGeometry(QRect(40, 30, 71, 21));
    QFont font;
    font.setFamily(QString::fromUtf8("SimSun"));
    font.setPointSize(12);
    font.setBold(false);
    font.setItalic(false);
    font.setUnderline(false);
    font.setWeight(50);
    font.setStrikeOut(false);
    userlabel->setFont(font);
    lineEdit = new QLineEdit(groupBox);
    lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
    lineEdit->setGeometry(QRect(120, 30, 141, 20));
    passwdlabel = new QLabel(groupBox);
    passwdlabel->setObjectName(QString::fromUtf8("passwdlabel"));
    passwdlabel->setGeometry(QRect(40, 70, 81, 21));
    passwdlabel->setFont(font);
    lineEdit_2 = new QLineEdit(groupBox);
    lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
    lineEdit_2->setGeometry(QRect(120, 70, 141, 20));
    loginBtn = new QPushButton(groupBox);
    loginBtn->setObjectName(QString::fromUtf8("loginBtn"));
    loginBtn->setGeometry(QRect(50, 120, 75, 23));
    cancelBtn = new QPushButton(groupBox);
    cancelBtn->setObjectName(QString::fromUtf8("cancelBtn"));
    cancelBtn->setGeometry(QRect(160, 120, 75, 23));

    retranslateUi(LoginClass);

    QMetaObject::connectSlotsByName(LoginClass);
    } // setupUi

    void retranslateUi(QDialog *LoginClass)
    {
    LoginClass->setWindowTitle(QApplication::translate("LoginClass", "Login", 0, QApplication::UnicodeUTF8));
    groupBox->setTitle(QApplication::translate("LoginClass", "GroupBox", 0, QApplication::UnicodeUTF8));
    userlabel->setText(QApplication::translate("LoginClass", "User:", 0, QApplication::UnicodeUTF8));
    passwdlabel->setText(QApplication::translate("LoginClass", "PassWord:", 0, QApplication::UnicodeUTF8));
    loginBtn->setText(QApplication::translate("LoginClass", "Login", 0, QApplication::UnicodeUTF8));
    cancelBtn->setText(QApplication::translate("LoginClass", "Cancel", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(LoginClass);
    } // retranslateUi

};

namespace Ui {
    class LoginClass: public Ui_LoginClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H