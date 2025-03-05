#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QString>
#include <QSerialPortInfo>
#include <QMessageBox>
#include <QTimer>
#include <QPainter>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QSerialPort *serialPort;//定义串口指针


private slots:

    /*手动连接槽函数*/
    void manual_serialPortReadyRead();

    QString processTextData(const QByteArray &recBuf);

    QString processHexData(const QByteArray &recBuf);

    void updatePortStatus();

    /*以下为mainwindow.ui文件中点击“转到槽”自动生成的函数*/
    void on_Openserial_po_clicked();

    void on_Send_po_clicked();

    void on_Clear_po_clicked();

    void on_Clearsend_po_clicked();

    void on_Timesend_po_stateChanged(int arg1);

    void on_Checkseial_po_clicked();

    void updateSendRecvCount(QLabel *lbl, const QString &prefix, long num);

    void setNumOnLabel(QLabel *lbl, const QString &prefix, long num);

private:
    Ui::MainWindow *ui;

    // 发送、接收字节计数
    long sendNum, recvNum;
    QLabel *lblSendNum;
    QLabel *lblRecvNum;
    QLabel *lblPortState;


    // 定时发送-定时器
    QTimer *timSend;
    QTimer *portScanTimer;
    //QTimer *timCheckPort;
    //串口连接状态
    bool isPortConnected = false;  // 初始状态为断开连接
};
#endif // MAINWINDOW_H

