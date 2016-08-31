#ifndef MYHELPER_H
#define MYHELPER_H

#endif // MYHELPER_H

#include <QObject>
#include <QListWidget>
#include <QSettings>
#include <QWidget>
#include <QDesktopWidget>
#include <QFile>
#include <QFileIconProvider>
#include <QTextCodec>
#include <QMessageBox>
#include <QAbstractButton>
#include <QPushButton>
#include <QTime>
#include <QDateTime>
#include <QDate>
#include <QCoreApplication>
#include <QFileDialog>
#include <QProcess>
#include <QDesktopServices>
#include <QUrl>
#include <QDir>
#include <QCursor>
#include <QTimer>
#include <QSound>
#include <QApplication>
#include <QStyleFactory>
#include <QTextStream>
#include <QDebug>

class myHelper: public QObject
{
public:
    myHelper();
    ~myHelper();
    //设置全局为plastique样式
    static void SetPlastiqueStyle();

    //设置编码为GB2312
    static void SetGB2312Code();

    //设置编码为系统字体编码
    static void SetSystemCode();

    //设置编码为UTF8
    static void SetUTF8Code();

    //显示信息框，仅确定按钮
    void ShowMessageBoxInfo(QString info);

    //显示错误框，仅确定按钮
    void ShowMessageBoxError(QString info);

    //显示询问框，确定和取消按钮
    int ShowMessageBoxQuesion(QString info);

    //16进制字符串转字节数组
    QByteArray HexStrToByteArray(QString str);

    char ConvertHexChar(char ch);

    //字节数组转16进制字符串
    QString ByteArrayToHexStr(QByteArray data);

    //16进制字符串转10进制
    uchar StrHexToDecimal(QString strHex);

    //10进制字符串转10进制
    uchar StrDecimalToDecimal(QString strDecimal);

    //16进制字符串转2进制字符串
    QString StrHexToStrBin(QString strHex);

    //计算校验码
    uchar GetCheckCode(uchar data[], uchar len);

    //延时
    void Sleep(int sec);

    //获取当前路径
    QString GetCurrentPath();

    //播放声音
    void PlaySound(QString soundName);

    //获取当前日期时间星期
    QString GetLongDateTime();

    //打开网址
    void OpenUrlOrExe(QString url);

    //判断是否闰年
    bool IsLeapYear(QString strDate);

};

class FormHelper: public QObject
{
public:
    FormHelper();
    ~FormHelper();
    //窗体居中显示
    void FormInCenter(QWidget *frm);

    //窗体没有最大化按钮
    void FormNoMaxButton(QWidget *frm);

    //窗体没有最大化和最小化按钮
    void FormOnlyCloseButton(QWidget *frm);

    //设置窗体透明度
    void FormOpacity(QWidget *frm, double value);

    //窗体不能改变大小
    void FormNotResize(QWidget *frm);

    //窗体前端显示
    void FormOnTop(QWidget *frm);

    //窗体后端显示
    void FormOnBottom(QWidget *frm);

    //获取桌面大小
    QSize GetDesktopSize();

    //设置指定窗体为plastique样式
    void SetPlastiqueStyle(QWidget *frm);

    void SetCustomStyle(QWidget *frm);

    //改变样式
    bool InstallStyle(QWidget* window, QString styleFile);
};


class FileHelper : public QObject
{
public:
    FileHelper();
    ~FileHelper();
    //获取选择文件
    QString GetFileName(QString filter);

    //获取选择文件集合
    QStringList GetFileNames(QString filter);

    //获取选择文件夹中的文件
    QStringList GetFolderFileNames(QStringList filter);

    //文件是否存在
    bool FileExists(QString strFile);

    //文件夹是否存在
    bool FolderExists(QString strFolder);

    //移除文件
    bool RemoveFile(QString strFile);

    //重命名文件
    bool RenameFile(QString oldName, QString newName);

    //获取文件目录
    QString GetBasePath(QString strFullPath);

    //获取拓展名
    QString GetExtension(QString strFile);

    //获取文件夹名称
    QString GetFolderName(QString strFullPath);

    //复制文件
    bool CopyFile(QString sourceFile, QString targetFile);

    //判断是否是文件
    bool IsFile(QString strFile);

    //判断是否是文件夹
    bool IsFolder(QString strFolder);

    //追加文本
    bool AppendText(QString strFile, QString strContent );

    //创建文件夹
    bool CreateFolder(QString strFolder);

    //创建文件
    bool CreateFile(QString strFile);

    //读取文件内容
    QString GetFileContent(QString strFile);

};
