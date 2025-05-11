# 🧪 C_solucion – Proyecto final del Trabajo Práctico #1

Esta carpeta contiene la **solución completa y funcional** del Trabajo Práctico #1 – *Calculadora con Qt*, desarrollada durante el cursado de la materia **Programación** de la Licenciatura en Automatización y Control.

---

## 📄 Contenidos de la carpeta

### 📘 `Trabajo Practico #1 - Calculadora en Qt.pdf`
Versión final entregada del trabajo práctico. Contiene:
- Índice completo del informe.
- Explicación del contexto y la consigna.
- Desarrollo paso a paso del diseño e implementación.
- Fundamentos teóricos de Qt utilizados.
- Estructura del repositorio y conclusiones.

Es el documento principal para comprender el enfoque metodológico y técnico aplicado a la resolución del TP.

### 📁 `CalculadoraQt/`
Carpeta raíz del proyecto implementado en **Qt Creator**, desarrollada en C++ con GUI basada en widgets.

Contiene:
- `mainwindow.ui`: Diseño visual de la calculadora (botones, display, layout).
- `mainwindow.h / .cpp`: Lógica completa del funcionamiento, estado y control de eventos.
- `main.cpp`: Punto de entrada del programa.
- `CMakeLists.txt`: Archivo de configuración del proyecto para compilación con CMake.

---

## ⚙️ Cómo compilar y ejecutar

1. **Abrir Qt Creator.**
2. Seleccionar `Archivo > Abrir archivo o proyecto...`.
3. Cargar `CalculadoraQt/CMakeLists.txt`.
4. Verificar que el entorno de compilación esté correctamente configurado.
5. Compilar el proyecto (`Ctrl+B`) y ejecutarlo (`Ctrl+R`).

---

## 📎 Observaciones

- La calculadora implementa operaciones básicas: suma, resta, multiplicación y división.
- El diseño visual es completamente responsive gracias al uso de `QGridLayout`.
- La lógica está centralizada en un único slot: `manejarEntrada()`.
- Se implementó control de errores, como división por cero y entradas inválidas.
- El resultado se muestra en formato decimal o notación compacta según el caso.
- El código está documentado con comentarios educativos y organización clara.

---

> 💡 Esta carpeta representa el núcleo del proyecto práctico. El código puede ser reutilizado para otros fines educativos o como base para futuras aplicaciones con interfaces gráficas.
