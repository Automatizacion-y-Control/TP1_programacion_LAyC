#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    /**
     * @brief Slot principal que maneja todos los botones de la interfaz.
     *
     * Interpreta el texto del botón presionado, actualiza estados,
     * y ejecuta acciones como ingresar dígitos, operadores, evaluar
     * la operación, borrar, o reiniciar la calculadora.
     */
    void manejarEntrada();

private:
    Ui::MainWindow *ui;

    /* Variables auxiliares para nuestra calculadora*/
    /**
     * @brief número que el usuario está escribiendo actualmente.
     * Se forma a medida que se presionan los botones numéricos y el punto.
     * Puede representar tanto el primer como el segundo operando.
     */
    QString numeroActual;

    /**
     * @brief operador aritmético seleccionado por el usuario.
     * Se establece al presionar +, -, × o ÷.
     */
    QString operadorActual;

    /**
     * @brief primer operando ingresado antes del operador.
     * Se guarda como double una vez que se presiona un operador.
     */
    double operando1 = 0;

    /**
     * @brief indica si se está esperando el ingreso del segundo operando.
     * Se activa después de que se presiona un operador.
     */
    bool esperandoSegundoOperando = false;

    /**
     * @brief indica si ya se mostró un resultado con el botón '='.
     * Sirve para decidir si reiniciar o continuar la operación.
     */
    bool resultadoMostrado = false;

    /**
     * @brief mensaje de error opcional que se puede mostrar en el display.
     * Se utiliza para manejar casos como división por cero o entradas inválidas.
     */
    QString mensajeError;

    /**
     * @brief indica si se ha detectado un error lógico en la operación.
     * Sirve para evitar que la operación continúe en un estado inválido.
     */
    bool errorDetectado = false;


    // Prototipos de funciones
    /**
     * @brief Reinicia completamente el estado de la calculadora.
     *
     * Borra los operandos, el operador, el display y las banderas de control.
     * Se utiliza al presionar el botón AC o SUP.
     */
    void limpiarTodo();

    /**
     * @brief Elimina el último carácter ingresado.
     *
     * Actúa sobre la variable numeroActual y actualiza el display.
     * Se utiliza al presionar el botón DEL.
     */
    void borrarUltimoCaracter();

    /**
     * @brief Evalúa la operación actual entre dos operandos.
     *
     * Convierte numeroActual en operando2, evalúa la expresión,
     * muestra el resultado o informa errores como división por cero.
     * Se invoca al presionar el botón "=".
     */
    void calcularResultado();

    /**
     * @brief Muestra un mensaje de error en el display.
     *
     * También activa la bandera errorDetectado para evitar
     * el procesamiento de entradas inválidas posteriores.
     *
     * @param mensaje El mensaje de advertencia a mostrar.
     */
    void mostrarError(const QString &mensaje);

    /**
     * @brief Determina si un texto representa un operador válido.
     *
     * @param texto Texto a verificar.
     * @return true si es +, -, × o ÷. False en caso contrario.
     */
    bool esOperador(const QString &texto);
};
#endif // MAINWINDOW_H
