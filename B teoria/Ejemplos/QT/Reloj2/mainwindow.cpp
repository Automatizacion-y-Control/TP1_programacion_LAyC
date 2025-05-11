#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Reloj Analógico");
    resize(300, 300);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, QOverload<>::of(&MainWindow::update));
    timer->start(1000); // actualizar cada segundo
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *) {
    static const QPoint hourHand[3] = { QPoint(7,8), QPoint(-7,8), QPoint(0,-40) };
    static const QPoint minuteHand[3] = { QPoint(7,8), QPoint(-7,8), QPoint(0,-70) };
    static const QPoint secondHand[3] = { QPoint(2,8), QPoint(-2,8), QPoint(0,-90) };

    QTime time = QTime::currentTime();
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.translate(width() / 2, height() / 2);
    painter.scale(width() / 200.0, height() / 200.0);

    // Aguja de la hora
    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::black);
    painter.save();
    painter.rotate(30.0 * ((time.hour() + time.minute() / 60.0)));
    painter.drawConvexPolygon(hourHand, 3);
    painter.restore();

    // Aguja del minuto
    painter.setBrush(Qt::darkGray);
    painter.save();
    painter.rotate(6.0 * time.minute());
    painter.drawConvexPolygon(minuteHand, 3);
    painter.restore();

    // Aguja del segundo
    painter.setBrush(Qt::red);
    painter.save();
    painter.rotate(6.0 * time.second());
    painter.drawConvexPolygon(secondHand, 3);
    painter.restore();

    // Marcas del reloj
    painter.setPen(Qt::black);
    for (int i = 0; i < 12; ++i) {
        painter.drawLine(88, 0, 96, 0);
        painter.rotate(30.0);
    }
}
