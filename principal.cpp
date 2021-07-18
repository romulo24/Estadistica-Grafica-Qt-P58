#include "principal.h"
#include "ui_principal.h"
#include <QtDebug>
#include <QFile>

Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);

    //creamos lienzo

    lienzo = QPixmap(500,500);

    //invocar al metodo dibujar

    this->dibujar();

    //Mostramos el lienzo en eel cuadro
    ui->Cuadro->setPixmap(lienzo);
}

Principal::~Principal()
{
    delete ui;
}

void Principal::dibujar()
{
  //rellenamos el lienzo de color blanco

  lienzo.fill(Qt::white);

    //creamos el pinto, este trabaja sobre el objeto lienzo

    QPainter painter(&lienzo);

    //Definimos vaariables

    int x=50;
    int y=50;
    int ancho =  100;
    int alto_1 = ui->inNota1->value();
    int alto_2 = ui->inNota2->value();
    int alto_3 = ui->inNota3->value();

    //Creamos un pincel

    QPen pincel;    //creamos pincel
    pincel.setWidth(5); //Ancho dle pincel
    pincel.setColor(Qt::blue);   //seleccionamos el color
    pincel.setJoinStyle(Qt::MiterJoin);

    //Estavlecer el pincel a pinyat

    painter.setPen(pincel);
    int num = 100;
    for(int i=y; i<450; i+=100){
        painter.drawLine(x-25,i,x+5,i);
        QString linea = QString::number(num);
        painter.drawLine(x-5, i, y+410+5, i);
        linea = QString::number(num);
        painter.drawText(x-47,i,linea);
        num-=25;
    }
    QColor nota(87, 53, 78);
    pincel.setColor(nota);
    painter.setPen(pincel);
    for (int o=x; o<450; o+=100) {
        QString nota1 = "Barra 1";
        painter.drawText(x+25, y+415, nota1);
        QString nota2 = "Barra 2";
        painter.drawText(x+180, y+415, nota2);
        QString nota3 = "Barra 3";
        painter.drawText(x+340, y+415, nota3);
    }
    //Graficar barras

    //Crear un pincel para los bordes
    QPen pincel2;

    QColor colorBorde1(78,3,48);
    QColor colorRelleno1(190,12,12);

    pincel.setColor(colorBorde1);
    painter.setPen(pincel2);
    painter.setPen(pincel);
    painter.setBrush(colorRelleno1);
    //Dibujar la primera barra

    painter.drawRect(x,y+(400-alto_1),ancho, alto_1);

    //Creamoss un nuevo colores

    QColor colorBorde2 (78,3,48);
    QColor colorRelleno2(190,120,162);

    //Establecer el color al poincel

    pincel.setColor(colorBorde2);

    //Volver a establecer al objeto painter

    painter.setPen(pincel);

    //establecer el color de la brovcha

    painter.setBrush(colorRelleno2);

    //estavblecemos el color de relleno barra 2

    painter.drawRect(x+150,y+(400-alto_2),ancho, alto_2);


    //Creanso los colores de la 3ra barra

    QColor colorRelleno3 (253,253,115);
    QColor colorBorde3(196,174,51);

    //seteamos el color del pincel

    pincel.setColor(colorBorde3);

    // setamos el pincel

    painter.setPen(pincel);

    //Hacemos el relleno del color

    painter.setBrush(colorRelleno3);
    //rellenamos con el color dado junto con las operaciones necesarias
    painter.drawRect(x+300,y+(400-alto_3), ancho, alto_3);

    ui->Cuadro->setPixmap(lienzo);
}


void Principal::on_cmdGraficar_released()
{
    dibujar();


}
//Cerramos el programa la opcion de salir

void Principal::on_actionSalir_triggered()
{
    this->close();
}

//Guardar como png
void Principal::on_actionGuardar_triggered()
{

    QString nombreArchivo = QFileDialog::getSaveFileName(
                this,"Guardar imagen",QString(),"Imagenes (*.png)");
    if (!nombreArchivo.isEmpty()){
        if (lienzo.save(nombreArchivo))
            QMessageBox::information(this,"Guardar imagen","Archivo guarado en: " + nombreArchivo);
        else
            QMessageBox::warning(this,"Guardar imagen","No se pudo guardar el archivo");
    }

}
