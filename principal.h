#ifndef PRINCIPAL_H
#define PRINCIPAL_H
#include <QMainWindow>
#include <QPainter>
#include <QFileDialog>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class Principal; }
QT_END_NAMESPACE

class Principal : public QMainWindow
{
    Q_OBJECT

public:
    Principal(QWidget *parent = nullptr);
    ~Principal();

private slots:
    void on_cmdGraficar_released();
    void on_actionSalir_triggered();
    void on_actionGuardar_triggered();

private:
    Ui::Principal *ui;

    //objeto nuevo
    QPixmap lienzo;
    void dibujar();
};
#endif // PRINCIPAL_H
