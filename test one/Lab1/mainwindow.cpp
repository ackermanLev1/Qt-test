#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <math.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    digitBTNs = {{Qt::Key_0,ui->btnNum0},
                {Qt::Key_1,ui->btnNum1},
                {Qt::Key_2,ui->btnNum2},
                {Qt::Key_3,ui->btnNum3},
                {Qt::Key_4,ui->btnNum4},
                {Qt::Key_5,ui->btnNum5},
                {Qt::Key_6,ui->btnNum6},
                {Qt::Key_7,ui->btnNum7},
                {Qt::Key_8,ui->btnNum8},
                {Qt::Key_9,ui->btnNum9},
               };

    foreach(auto btn,digitBTNs)
        connect(btn,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
//    connect(ui->btnNum1,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
//    connect(ui->btnNum2,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
//    connect(ui->btnNum3,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
//    connect(ui->btnNum4,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
//    connect(ui->btnNum5,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
//    connect(ui->btnNum6,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
//    connect(ui->btnNum7,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
//    connect(ui->btnNum8,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
//    connect(ui->btnNum9,SIGNAL(clicked()),this,SLOT(btnNumClicked()));

    connect(ui->btnAdd,SIGNAL(clicked()),this,SLOT(btnBinaryOperatorClicked()));
    connect(ui->btnMinus,SIGNAL(clicked()),this,SLOT(btnBinaryOperatorClicked()));
    connect(ui->btnMultiply,SIGNAL(clicked()),this,SLOT(btnBinaryOperatorClicked()));
    connect(ui->btnDivide,SIGNAL(clicked()),this,SLOT(btnBinaryOperatorClicked()));

    connect(ui->btnPercent,SIGNAL(clicked()),this,SLOT(btnUnaryOperatorClicked()));
    connect(ui->btnInverse,SIGNAL(clicked()),this,SLOT(btnUnaryOperatorClicked()));
    connect(ui->btnSquare,SIGNAL(clicked()),this,SLOT(btnUnaryOperatorClicked()));
    connect(ui->btnSquareRoot,SIGNAL(clicked()),this,SLOT(btnUnaryOperatorClicked()));
    connect(ui->btnSign,SIGNAL(clicked()),this,SLOT(btnUnaryOperatorClicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::calculation(bool *ok)
{
    double result=0;
    if(operands.size()==2 && opcodes.size()>0)
    {
        //取操作数
        double operand1 = operands.front().toDouble();
        operands.pop_front();
        double operand2 = operands.front().toDouble();
        operands.pop_front();

        //取操作符
        QString op = opcodes.front();
        opcodes.pop_front();

        if(op == "+"){
            result = operand1 + operand2;
        }else if(op == "-"){
            result = operand1 - operand2;
        }else if(op == "×"){
            result = operand1 * operand2;
        }else if(op == "/"){
            result = operand1 / operand2;
        }

        operands.push_back(QString::number(result));

        ui->statusbar->showMessage(QString("calcuation is in progress: operands is %1,opcode is %2").arg(
                                       operands.size()).arg(
                                       opcodes.size()));
    }else
        ui->statusbar->showMessage(QString("operands is %1,opcode is %2").arg(
                                       operands.size()).arg(opcodes.size()));

    return QString::number(result);
}

void MainWindow::btnNumClicked()
{
    QString digit = qobject_cast<QPushButton*>(sender())->text();

    if(digit == "0" && operand == "0")
        digit = "";
    if(operand == "0" && digit != "0")
        operand = "";

    operand += digit;

    ui->display->setText(operand);

}

void MainWindow::on_btnPeriod_clicked()
{
    if(operand.isEmpty()){
        operand = "0.";
    } else if(!operand.contains(".")){
        operand += qobject_cast<QPushButton*>(sender())->text();
    }

    ui->display->setText(operand);
}


void MainWindow::on_btnDelete_clicked()
{

    operand = operand.left(operand.length() - 1);
    ui->display->setText(operand);
}


void MainWindow::on_btnClear_clicked()
{
    operand.clear();
    ui->display->setText(operand);
}

void MainWindow::btnBinaryOperatorClicked()
{
    QString opcode = qobject_cast<QPushButton*>(sender())->text();
    qDebug() << opcode;

    if(operand != "")
    {
        operands.push_back(operand);
        operand = "";

        opcodes.push_back(opcode);

        QString result = calculation();

        ui->display->setText(result);
    }
}

void MainWindow::btnUnaryOperatorClicked()
{
    if(operand != ""){
        double result = operand.toDouble();
        operand = "";

        QString op =qobject_cast<QPushButton*>(sender())->text();

        if(op == "%")
            result /=100.0;
        else if(op == "1/x")
            result = 1/result;
        else if(op == "x^2")
            result *=result;
        else if(op == "√x")
             result =sqrt(result);
        else if(op == "±")
            result =-result;

        ui->display->setText(QString::number(result));
    }
}


void MainWindow::on_btnEqual_clicked()
{
    if(operand != "")
    {
        operands.push_back(operand);
        operand = "";
    }

    QString result = calculation();
    ui->display->setText(result);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    foreach(auto btnKey, digitBTNs.keys()){
        if(event->key() == btnKey)
            digitBTNs[btnKey]->animateClick(100);
    }

    switch(event->key())
    {
        case Qt::Key_Plus:      // 加号
            ui->btnAdd->animateClick(100);
            break;
        case Qt::Key_Minus:     // 减号
            ui->btnMinus->animateClick(100);
            break;
        case Qt::Key_Asterisk:  // 乘号(*)
            ui->btnMultiply->animateClick(100);
            break;
        case Qt::Key_Slash:     // 除号(/)
            ui->btnDivide->animateClick(100);
            break;
        case Qt::Key_Percent:   // 百分号(%)
            ui->btnPercent->animateClick(100);
            break;
        case Qt::Key_Escape:    // 清除(C)
            ui->btnClear->animateClick(100);
            break;
        case Qt::Key_Backspace: // 退格键(⌫)
            ui->btnDelete->animateClick(100);
            break;
        case Qt::Key_Equal:     // 等号(=)
        case Qt::Key_Enter:     // 回车键(对应=)
        case Qt::Key_Return:    // 小键盘回车键(对应=)
            ui->btnEqual->animateClick(100);
            break;
        case Qt::Key_Period:    // 小数点(.)
            ui->btnPeriod->animateClick(100);
            break;
        default:
            // 其他键不处理，交给父类
            QMainWindow::keyPressEvent(event);
    }

}
