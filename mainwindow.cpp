#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    numberInput = ui->lineEdit_number;
    calculateButton = ui->pushButton_enter;
    resultLabel = ui->label_3;
    connect(calculateButton, &QPushButton::clicked, this, &MainWindow::calculatePower);
    connect(numberInput, &QLineEdit::textChanged, this, &MainWindow::clearResult);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::calculatePower()
{
    bool ok;
    int number = numberInput->text().toInt(&ok);
    if (!ok)
    {
        resultLabel->setText("Ошибка: введенное значение не является числом");
        return;
    }
    int a = 0, b = 0, c;
    while (pow(2, b) < number)
    {
        c = pow(2, b);
        a = b;
        b++;
    }
    int firstPow = a;
    int secondPow = b;
    if (number == pow(2, b))
    {

        resultLabel->setText(QString("Число %1 является 2 в степени %2 ").arg(number).arg(secondPow));
    }
    else
    {
        resultLabel->setText(QString("Число %1 находится между степенями %2 и %3").arg(number).arg(firstPow).arg(secondPow));
    }
}



void MainWindow::clearResult()
{
    resultLabel->clear();
}

