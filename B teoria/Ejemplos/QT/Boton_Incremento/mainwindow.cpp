#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //--Variables--
    ui->setupUi(this);

    //--Asigno Valores Iniciales
    miNumero=10;
    miCadena=" ";
    mensaje="Valor Actual:  ";

    //--Luego de Asignar los valores iniciales los muestro
    miCadena.setNum(miNumero);  // Convierto int a string
    ui->resultado->setText(mensaje+miCadena);

    //--Conexion Señal-Slot--
    connect(ui->BotonIncrementar,SIGNAL(clicked()),SLOT(miIncremento()));
    connect(ui->BotonResetear,SIGNAL(clicked()),SLOT(miReset()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*
 * Incrementa la variable "miNumero" en 1, la convierte en tipo string y pega el texto en el Qlabel "resultado" atravez del puntero *ui
*/
void MainWindow::miIncremento(){
    miNumero=miNumero+10;        // Incremento en 1 a "miNumero"
    miCadena.setNum(miNumero);  // Convierto int a string
    ui->resultado->setText(mensaje+miCadena);
}

/*
 * Resetea a cero en la variable "miNumero",la convierte en tipo string y pega el texto en el Qlabel "resultado" atravez del puntero *ui
*/
void MainWindow::miReset(){
    miNumero=0;                 // Reseto a cero
    miCadena.setNum(miNumero);  // Convierto int a string
    ui->resultado->setText(mensaje+miCadena);
}
