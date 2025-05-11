#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , contador(0)
{
    ui->setupUi(this);

    // Limites para simular un qint8
    ui->spinBox->setMinimum(-128);
    ui->spinBox->setMaximum(200);
    ui->spinBox->setValue(contador);

    ui->label->setText("Valor: " + QString::number(contador));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_spinBox_valueChanged(int value)
{
    contador = static_cast<qint8>(value);
    ui->label->setText("Valor: " + QString::number(contador));
}
