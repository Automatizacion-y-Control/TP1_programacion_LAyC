#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGlobal>  // para qint8

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_spinBox_valueChanged(int value);  // <--- conectamos esta señal

private:
    Ui::MainWindow *ui;
    qint8 contador;  // <--- Variable que guarda el valor actual
};

#endif // MAINWINDOW_H
