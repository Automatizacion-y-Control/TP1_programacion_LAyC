#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRegularExpression>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Ajusta el tamaño de la ventana ppal.
    this->setFixedSize(260, 420);         // Tamaño fijo
    this->setWindowTitle("Calculadora");  // Título de la ventana

    // Estado inicial del display
    ui->display->setText("0");

    // Reinicio completo de variables
    numeroActual = "";
    operadorActual = "";
    operando1 = 0;
    esperandoSegundoOperando = false;
    resultadoMostrado = false;
    mensajeError = "";
    errorDetectado = false;

    // Conectamos todos los botones de la calculadora al slot manejarEntrada()
    // Esto nos permite procesar todos los clics desde un solo método central

    connect(ui->btn0,      &QPushButton::clicked, this, &MainWindow::manejarEntrada);
    connect(ui->btn1,      &QPushButton::clicked, this, &MainWindow::manejarEntrada);
    connect(ui->btn2,      &QPushButton::clicked, this, &MainWindow::manejarEntrada);
    connect(ui->btn3,      &QPushButton::clicked, this, &MainWindow::manejarEntrada);
    connect(ui->btn4,      &QPushButton::clicked, this, &MainWindow::manejarEntrada);
    connect(ui->btn5,      &QPushButton::clicked, this, &MainWindow::manejarEntrada);
    connect(ui->btn6,      &QPushButton::clicked, this, &MainWindow::manejarEntrada);
    connect(ui->btn7,      &QPushButton::clicked, this, &MainWindow::manejarEntrada);
    connect(ui->btn8,      &QPushButton::clicked, this, &MainWindow::manejarEntrada);
    connect(ui->btn9,      &QPushButton::clicked, this, &MainWindow::manejarEntrada);
    connect(ui->btn00,     &QPushButton::clicked, this, &MainWindow::manejarEntrada);

    connect(ui->btnPunto,  &QPushButton::clicked, this, &MainWindow::manejarEntrada);
    connect(ui->btnSuma,   &QPushButton::clicked, this, &MainWindow::manejarEntrada);
    connect(ui->btnResta,  &QPushButton::clicked, this, &MainWindow::manejarEntrada);
    connect(ui->btnMult,   &QPushButton::clicked, this, &MainWindow::manejarEntrada);
    connect(ui->btnDiv,    &QPushButton::clicked, this, &MainWindow::manejarEntrada);

    connect(ui->btnIgual,  &QPushButton::clicked, this, &MainWindow::manejarEntrada);
    connect(ui->btnDel,    &QPushButton::clicked, this, &MainWindow::manejarEntrada);
    connect(ui->btnSup,    &QPushButton::clicked, this, &MainWindow::manejarEntrada);
    // o si el botón se llama SUP
    // connect(ui->btnSUP, &QPushButton::clicked, this, &MainWindow::manejarEntrada);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// SLOT PUBLICO
// función que maneja todos los botones presionados.
// interpreta el texto del botón y actúa según su tipo.
void MainWindow::manejarEntrada() {
    // Obtenemos el botón que envió la señal
    QPushButton *boton = qobject_cast<QPushButton *>(sender());
    QString texto = boton->text();

    // Normalizamos operadores visibles a los usados internamente
    if (texto == "x") texto = "×";
    if (texto == "/") texto = "÷";

    // Si hubo un error previo, sólo permitimos reiniciar con AC o SUP
    if (errorDetectado) {
        if (texto == "AC" || texto == "SUP") {
            limpiarTodo();
        }
        return;
    }

    // Si es el botón AC (reiniciar)
    if (texto == "AC" || texto == "SUP") {
        limpiarTodo();
        return;
    }

    // Si es el botón DEL (borrar último)
    if (texto == "DEL") {
        borrarUltimoCaracter();
        return;
    }

    // Si es el botón "=" (evaluar)
    if (texto == "=") {
        if (!numeroActual.isEmpty() && !operadorActual.isEmpty()) {
            calcularResultado();
        } else {
            mostrarError("Operación incompleta");
        }
        return;
    }

    // Si es un operador (+, -, ×, ÷)
    if (esOperador(texto)) {
        if (!numeroActual.isEmpty()) {
            operando1 = numeroActual.toDouble();
            operadorActual = texto;
            esperandoSegundoOperando = true;
            resultadoMostrado = false;
            numeroActual.clear();  // nos preparamos para el segundo número
        } else if (texto == "-" && operadorActual.isEmpty()) {
            // Permitimos comenzar con número negativo
            numeroActual = "-";
            ui->display->setText(numeroActual);
        }
        return;
    }

    // Si se presiona un punto decimal
    if (texto == ".") {
        if (!numeroActual.contains(".")) {
            numeroActual += ".";
        }
        ui->display->setText(numeroActual);
        return;
    }

    // Si se presiona un número (0-9 o 00)
    if (QRegularExpression("^[0-9]+$").match(texto).hasMatch()) {
        if (resultadoMostrado) {
            limpiarTodo();
        }

        if (esperandoSegundoOperando) {
            numeroActual.clear();
            esperandoSegundoOperando = false;
        }

        numeroActual += texto;
        ui->display->setText(numeroActual);
        return;
    }

    // Si llega acá, es una entrada no reconocida
    mostrarError("Entrada inválida");
}


// FUNCIONES AUXILIARES
// función que reinicia todos los estados internos de la calculadora.
// no recibe parámetros. Borra display, operandos, operador y errores previos.
void MainWindow::limpiarTodo() {
    numeroActual.clear();
    operadorActual.clear();
    operando1 = 0;
    esperandoSegundoOperando = false;
    resultadoMostrado = false;
    mensajeError.clear();
    errorDetectado = false;
    ui->display->setText("0");
}

// función que elimina el último carácter del número en curso.
// si queda vacío, se muestra "0" en el display.
void MainWindow::borrarUltimoCaracter() {
    if (!numeroActual.isEmpty()) {
        numeroActual.chop(1);
        ui->display->setText(numeroActual.isEmpty() ? "0" : numeroActual);
    }
}

// función que muestra un mensaje de error en el display.
// activa el estado de error interno. recibe el mensaje como parámetro.
void MainWindow::mostrarError(const QString &mensaje) {
    errorDetectado = true;
    mensajeError = mensaje;
    ui->display->setText("⚠️ " + mensaje);
}

// función que verifica si un texto representa un operador válido.
// recibe una cadena. devuelve true si es +, -, × o ÷.
bool MainWindow::esOperador(const QString &texto) {
    return texto == "+" || texto == "-" || texto == "×" || texto == "÷";
}

// función que evalúa la operación actual: operando1 operador numeroActual.
// no recibe parámetros. muestra el resultado o un error si la operación es inválida.
void MainWindow::calcularResultado() {
    double operando2 = numeroActual.toDouble();
    double resultado = 0;

    // validación de división por cero
    if (operadorActual == "÷" && operando2 == 0) {
        mostrarError("No se puede dividir por cero");
        return;
    }

    // evaluación de la operación según el operador almacenado
    if (operadorActual == "+")       resultado = operando1 + operando2;
    else if (operadorActual == "-")  resultado = operando1 - operando2;
    else if (operadorActual == "×")  resultado = operando1 * operando2;
    else if (operadorActual == "÷")  resultado = operando1 / operando2;
    else {
        mostrarError("Operador inválido");
        return;
    }

    // se genera la cadena con el resultado (en notación compacta si es necesario)
    QString textoResultado = QString::number(resultado, 'g', 12);
    ui->display->setText(textoResultado);

    // se guarda el resultado como nuevo número activo
    numeroActual = textoResultado;
    operadorActual.clear();
    esperandoSegundoOperando = false;
    resultadoMostrado = true;
}
