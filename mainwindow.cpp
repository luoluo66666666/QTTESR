#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QSerialPortInfo"
#include <QSerialPort>
#include <QMessageBox>
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 创建串口对象
    serialPort = new QSerialPort(this);

    // 连接串口的读取信号到手动读取槽函数
    connect(serialPort, &QSerialPort::readyRead, this, &MainWindow::manual_serialPortReadyRead);

    // 初始化串口选择框，清空已有内容
    ui->Serial_po->clear();

    // 查找并显示可用串口到下拉框中
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        ui->Serial_po->addItem(info.portName());  // 添加串口名称到下拉框
    }

    // 初始化发送和接收计数
    sendNum = 0;
    recvNum = 0;

    // 创建并设置状态栏
    QStatusBar *sBar = statusBar();

    // 创建显示发送和接收计数的标签
    lblSendNum = new QLabel(this);
    lblRecvNum = new QLabel(this);
    lblPortState = new QLabel(this);

    // 设置串口连接状态标签
    lblPortState->setText("Disconnected");
    lblPortState->setStyleSheet("color:red"); // 设置串口状态标签为红色，表示未连接

    // 设置标签最小大小
    lblSendNum->setMinimumSize(100, 20);
    lblRecvNum->setMinimumSize(100, 20);
    lblPortState->setMinimumSize(550, 20);

    // 设置标签显示的发送和接收计数
    setNumOnLabel(lblSendNum, "S: ", sendNum);
    setNumOnLabel(lblRecvNum, "R: ", recvNum);

    // 将标签从右到左依次添加到状态栏
    sBar->addPermanentWidget(lblPortState);
    sBar->addPermanentWidget(lblSendNum);
    sBar->addPermanentWidget(lblRecvNum);

    // 创建并设置定时器，用于定时发送数据
    timSend = new QTimer(this);
    timSend->setInterval(1000);  // 设置定时时长为 1000 毫秒
    connect(timSend, &QTimer::timeout, this, [=](){
        on_Send_po_clicked();  // 定时发送数据的操作
    });

    // 创建定时器，用于定时扫描串口状态
    portScanTimer = new QTimer(this);
    portScanTimer->setInterval(5000);  // 每 5 秒扫描一次串口状态
    connect(portScanTimer, &QTimer::timeout, this, &MainWindow::updatePortStatus);
    portScanTimer->start();  // 启动定时器
}



/*析构函数*/
MainWindow::~MainWindow()
{
    delete ui; // 删除ui对象
}



/*更新串口状态*/
void MainWindow::updatePortStatus()
{
    // 获取当前选择的串口名称
    QString selectedPort = ui->Serial_po->currentText();

    if (selectedPort.isEmpty()) {
        return;  // 如果没有选择串口，则不做任何操作
    }

    // 获取串口信息
    QSerialPortInfo selectedPortInfo;
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        if (info.portName() == selectedPort) {
            selectedPortInfo = info;
            break;
        }
    }

    // 检查串口是否在使用
    QSerialPort testPort;
    testPort.setPort(selectedPortInfo);
    bool isUsed = testPort.open(QIODevice::ReadWrite);  // 尝试打开串口进行读写操作

    // 检查串口是否被占用
    if (isUsed) {
        // 串口被占用
        if (!isPortConnected) {
            lblPortState->setText("Connected");
            lblPortState->setStyleSheet("color:green");  // 设置串口状态标签为绿色，表示已连接
            isPortConnected = true;  // 保存串口连接状态
        }
        testPort.close();  // 使用完毕后关闭串口
    } else {
        // 串口未被占用
        if (isPortConnected) {
            lblPortState->setText("Disconnected");
            lblPortState->setStyleSheet("color:red");  // 设置串口状态标签为红色，表示未连接
            isPortConnected = false;  // 更新连接状态
        }
    }
}


/*检测通讯端口槽函数*/
void MainWindow::on_Checkseial_po_clicked()
{
    ui->Serial_po->clear(); // 清空串口选择框

    // 通过QSerialPortInfo查找并添加可用串口
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        ui->Serial_po->addItem(info.portName()); // 添加串口名称到下拉框
    }
}


/*发送数据*/
void MainWindow::on_Send_po_clicked()
{
    if (!serialPort->isOpen()) {
        QMessageBox::warning(this, "串口未打开", "请先打开串口！");
        lblPortState->setStyleSheet("color:red");
        return;
    }

    QByteArray array;
    QString str_send;

    // Hex复选框
    if (ui->Sendhex_po->checkState() == Qt::Checked) {
        array = QByteArray::fromHex(ui->Sendedit_po->toPlainText().toUtf8());
    } else {
        array = ui->Sendedit_po->toPlainText().toLocal8Bit();
    }

    // 如果选择了换行，追加换行符
    if (ui->Senewline_po->checkState() == Qt::Checked) {
        array.append("\r\n");
    }

    // 添加 "send" 标识
    str_send = "[send:] " + QString::fromUtf8(array);  // 加上 "[send]" 标识

    // 发送数据并检查发送字节数
    int bytesWritten = serialPort->write(array);

    // 发送字节计数并显示
    if (bytesWritten > 0) {
        sendNum += bytesWritten;
        updateSendRecvCount(lblSendNum, "S: ", sendNum);
        // 显示带标识的发送数据
        // 将发送的数据插入到接收框 (ReadEdit) 中，并换行
        ui->Recvedit_po->insertPlainText(str_send);  // 将发送的数据带 "[send:]" 标识插入到接收框
        ui->Recvedit_po->insertPlainText("\r\n");     // 插入换行符，确保每次发送数据后换行
        ui->Recvedit_po->moveCursor(QTextCursor::End);  // 保持光标在文本框末尾
    } else {
        // 发送失败的处理
        QMessageBox::warning(this, "发送失败", QString("数据发送失败: %1").arg(serialPort->errorString()));
    }
}



/*读取数据*/
void MainWindow::manual_serialPortReadyRead()
{
    QByteArray recBuf = serialPort->readAll();  // 读取串口数据
    QString str_rev;

    // 更新接收字节计数
    recvNum += recBuf.size();
    setNumOnLabel(lblRecvNum, "R: ", recvNum);  // 更新状态栏接收计数

    // 判断是否需要以文本方式处理接收到的数据
    if (!ui->Hex_po->isChecked()) {
        // 文本显示模式
        str_rev = processTextData(recBuf);
    } else {
        // 16进制显示模式
        str_rev = processHexData(recBuf);
    }

    // 在接收到的数据前加上 [recv] 标识
    QString str_with_recv = "[recv:] " + str_rev;

    // 将接收到的数据插入到接收文本框，并确保每次接收到的数据后换行
    ui->Recvedit_po->insertPlainText(str_with_recv);
    ui->Recvedit_po->insertPlainText("\r\n");  // 插入换行符，确保每次接收的数据都在新的一行
    ui->Recvedit_po->moveCursor(QTextCursor::End);  // 保持光标在文本末尾
}



/*处理文本数据*/
QString MainWindow::processTextData(const QByteArray &recBuf)
{
    QString str_rev;
    if (ui->Time_po->isChecked()) {
        // 如果需要时间戳
        QDateTime nowtime = QDateTime::currentDateTime();
        str_rev = "[" + nowtime.toString("yyyy-MM-dd hh:mm:ss") + "] ";
    }

    // 根据换行选项处理数据
    if (ui->Line_po->isChecked()) {
        str_rev += QString(recBuf).append("\r\n");
    } else {
        str_rev += QString(recBuf);
    }

    return str_rev;
}



/*处理16进制数据*/
QString MainWindow::processHexData(const QByteArray &recBuf)
{
    QString strHex = recBuf.toHex().toUpper();  // 转换为大写16进制字符串
    QString formattedHex;

    // 添加空格以便格式化
    for (int i = 0; i < strHex.length(); i += 2) {
        formattedHex += strHex.mid(i, 2) + " ";
    }

    QString str_rev;
    if (ui->Time_po->isChecked()) {
        // 如果需要时间戳
        QDateTime nowtime = QDateTime::currentDateTime();
        str_rev = "[" + nowtime.toString("yyyy-MM-dd hh:mm:ss") + "] ";
    }

    // 根据换行选项处理数据
    if (ui->Line_po->isChecked()) {
        str_rev += formattedHex.append("\r\n");
    } else {
        str_rev = formattedHex;
    }

    return str_rev;
}

/*打开串口函数*/
void MainWindow::on_Openserial_po_clicked()
{
    // 串口初始化
    QSerialPort::BaudRate baudRate;
    QSerialPort::DataBits dataBits;
    QSerialPort::StopBits stopBits;
    QSerialPort::Parity checkBits;

    // 获取串口波特率
    QMap<QString, QSerialPort::BaudRate> baudRateMap = {
        {"1200", QSerialPort::Baud1200},
        {"2400", QSerialPort::Baud2400},
        {"4800", QSerialPort::Baud4800},
        {"9600", QSerialPort::Baud9600},
        {"19200", QSerialPort::Baud19200},
        {"38400", QSerialPort::Baud38400},
        {"57600", QSerialPort::Baud57600},
        {"115200", QSerialPort::Baud115200}
    };
    baudRate = baudRateMap.value(ui->Baudrate_po->currentText(), QSerialPort::Baud9600); // 默认9600

    // 获取串口数据位
    QMap<QString, QSerialPort::DataBits> dataBitsMap = {
        {"5", QSerialPort::Data5},
        {"6", QSerialPort::Data6},
        {"7", QSerialPort::Data7},
        {"8", QSerialPort::Data8}
    };
    dataBits = dataBitsMap.value(ui->Databit_po->currentText(), QSerialPort::Data8); // 默认8位

    // 获取串口停止位
    QMap<QString, QSerialPort::StopBits> stopBitsMap = {
        {"1", QSerialPort::OneStop},
        {"1.5", QSerialPort::OneAndHalfStop},
        {"2", QSerialPort::TwoStop}
    };
    stopBits = stopBitsMap.value(ui->Stopbit_po->currentText(), QSerialPort::OneStop); // 默认1位停止位

    // 获取串口奇偶校验位
    QMap<QString, QSerialPort::Parity> checkBitsMap = {
        {"none", QSerialPort::NoParity},
        {"奇校验", QSerialPort::OddParity},
        {"偶校验", QSerialPort::EvenParity}
    };
    checkBits = checkBitsMap.value(ui->Checkbit_po->currentText(), QSerialPort::NoParity); // 默认无校验

    // 初始化串口属性，设置端口号、波特率、数据位、停止位、奇偶校验位数
    serialPort->setPortName(ui->Serial_po->currentText());
    serialPort->setBaudRate(baudRate);
    serialPort->setDataBits(dataBits);
    serialPort->setStopBits(stopBits);
    serialPort->setParity(checkBits);

    // 根据初始化好的串口属性，打开串口
    if(ui->Openserial_po->text() == "打开串口") {
        if(serialPort->open(QIODevice::ReadWrite)) {
            // 打开成功
            ui->Openserial_po->setText("关闭串口");
            ui->Serial_po->setEnabled(false); // 禁止选择串口

            // 状态栏显示端口信息
            QString sm = "%1 OPENED, %2, %3, %4, %5";
            QString status = sm.arg(serialPort->portName())
                                 .arg(serialPort->baudRate())
                                 .arg(serialPort->dataBits())
                                 .arg(serialPort->stopBits())
                                 .arg(serialPort->parity());
            lblPortState->setText(status);
            lblPortState->setStyleSheet("color:green");
        } else {
            // 打开失败
            QMessageBox::critical(this, "错误提示", "串口打开失败！\r\n该串口可能被占用或无法访问\r\n请选择正确的串口");
        }
    } else {
        // 关闭串口
        serialPort->close();
        ui->Openserial_po->setText("打开串口");
        ui->Serial_po->setEnabled(true); // 恢复串口选择

        // 状态栏显示端口状态
        QString sm = "%1 CLOSED";
        QString status = sm.arg(serialPort->portName());
        lblPortState->setText(status);
        lblPortState->setStyleSheet("color:red");
    }
}



/*更新发送/接收字节数*/
void MainWindow::updateSendRecvCount(QLabel *lbl, const QString &prefix, long num)
{
    lbl->setText(prefix + QString::number(num));
}



/*清空*/
void MainWindow::on_Clear_po_clicked()
{
    ui->Recvedit_po->clear(); // 清空接收编辑框
    ui->Sendedit_po->clear(); // 清空发送编辑框

    // 重置发送和接收字节计数
    sendNum = 0;
    recvNum = 0;

    // 更新状态栏显示
    updateSendRecvCount(lblSendNum, "S: ", sendNum);
    updateSendRecvCount(lblRecvNum, "R: ", recvNum);

}



/* 更新状态栏的发送或接收计数 */
void MainWindow::setNumOnLabel(QLabel *lbl, const QString &prefix, long num)
{
    lbl->setText(prefix + QString::number(num));  // 更新状态栏显示
}




/* 清空发送框及计数 */
void MainWindow::on_Clearsend_po_clicked()
{
    ui->Sendedit_po->clear();  // 清空发送编辑框
    sendNum = 0;  // 重置发送字节计数

    // 更新状态栏显示发送计数
    setNumOnLabel(lblSendNum, "S: ", sendNum);
}




/* 定时发送开关，选择复选框 */
void MainWindow::on_Timesend_po_stateChanged(int arg1)
{
    // 复选框状态为未选中时停止定时发送
    if (arg1 == Qt::Unchecked) {
        timSend->stop();  // 停止定时发送
        ui->Sendms_po->setEnabled(true);  // 恢复时间输入框可用
    } else {  // 复选框选中时，启动定时发送
        bool ok;
        int interval = ui->Sendms_po->text().toInt(&ok);  // 获取输入框中的时间值

        if (ok && interval >= 10) {  // 如果输入的是合法值并且 >= 10ms
            timSend->start(interval);  // 启动定时器并设置间隔时间
            ui->Sendms_po->setEnabled(false);  // 禁用输入框，避免误操作
        } else {
            QMessageBox::critical(this, "错误提示", "定时发送的最小间隔为 10ms\n请确保输入的值 >= 10ms");
        }
    }
}



