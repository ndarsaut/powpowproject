#include "Escenario.h"
#include <iostream>

using namespace std;

Escenario::Escenario(QWidget * juego, Tanque * tanque1, Tanque * tanque2)
{

        if(fondo.load("Background","PNG")) cout << "\ncargo todo joya";     //  Leo el archivo del fondo de pantalla
        fondo = fondo.scaledToWidth(778);
        fondo = fondo.copy(0,70,fondo.width(),318);

        pantalla = new QGraphicsScene(juego);                       //  Creo la escena dentro del widget juego

        pantalla->addPixmap(fondo);                                 //  Agrego el fondo de pantalla a la escena

        tq1 = pantalla->addPixmap(tanque1->Get_tanque());           //  Agrego los tanques a la escena
        tq1->setOffset(tanque1->Get_coordenada_x(),263);


        tq2 = pantalla->addPixmap(tanque2->Get_tanque());
        tq2->setOffset(tanque2->Get_coordenada_x(),263);


        verPantalla = new QGraphicsView(pantalla,juego);            //  Hago visible la escena creada
        verPantalla->setGeometry(60,37,780,320);
        verPantalla->show();

}

Escenario::~Escenario()
{
    //dtor
}

void Escenario::Set_x_tq1(Tanque * t)
{
        tq1->setOffset(t->Get_coordenada_x(),263);   /** AGREGAR EVENTO DE ACTUALIZAR PANTALLA   */
}

void Escenario::Set_x_tq2(Tanque * t)
{
        tq2->setOffset(t->Get_coordenada_x(),263);
}
