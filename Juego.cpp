#pragma once
#include "Juego.h"

#include <conio.h>

using namespace std ;


Juego::Juego(QString name1, QString name2, QWidget *parent):QWidget(parent)
{

        setGeometry(50,50,900,400);
        setFixedSize(900,400);
        setWindowTitle("Pow Pow Project");

        jugador1 = new Jugador(name1);
        jugador2 = new Jugador(name2);

        QFont fuentelbl("MS Serif", 10, QFont::Bold);
        QFont jug("MS Serif", 12, QFont::Bold);

        srand(time(NULL));



        //  Datos para el jugador 1
        lblPower1 = new QLabel("POW", this);
        lblPower1->setFont(fuentelbl);
        lblPower1->setGeometry(15,375,60,15);

        lblAngle1 = new QLabel("ANGLE", this);
        lblAngle1->setFont(fuentelbl);
        lblAngle1->setGeometry(80,375,60,15);

        angle1 = new QLineEdit(this);
        angle1->setGeometry(140, 372, 40, 20);

        lbljugador1 = new QLabel(jugador1->GetNombre_Puntos(), this);
        lbljugador1->setFont(jug);
        lbljugador1->setGeometry(10,8,400,17);

        power1 = new QSlider(Qt::Vertical, this);
        power1->setGeometry(20, 50, 20, 300);
        power1->setMinimum(0);
        power1->setMaximum(99);



        //  Datos para el jugador 2
        lblPower2 = new QLabel("POW", this);
        lblPower2->setFont(fuentelbl);
        lblPower2->setGeometry(850,375,60,15);

        lblAngle2 = new QLabel("ANGLE", this);
        lblAngle2->setFont(fuentelbl);
        lblAngle2->setGeometry(720,375,60,15);

        angle2 = new QLineEdit(this);
        angle2->setGeometry(780,372,40,20);

        lbljugador2 = new QLabel(jugador2->GetNombre_Puntos(), this);
        lbljugador2->setAlignment(Qt::AlignRight);
        lbljugador2->setFont(jug);
        lbljugador2->setGeometry(490,8,400,17);

        power2 = new QSlider(Qt::Vertical, this);
        power2->setGeometry(860, 50, 20, 300);
        power2->setMinimum(0);
        power2->setMaximum(99);



        //  Boton de disparo
        fire = new QPushButton("FIRE", this);
        fire->setGeometry(400,372,80,20);
        fire->setFont(fuentelbl);


        //  Creo los tanques
        tanque1 = new Tanque("Tanque11",10+rand()%(201 - 10));          //  Envio un valor aleatorio para la coordenada x
        tanque2 = new Tanque("Tanque22",530+rand()%(720 - 530));


        //  Creo el escenario
        escenario = new Escenario(this,tanque1,tanque2);


}

Juego::~Juego()
{
    //dtor
}

void Juego::SetJuego(Menu * M)
{
        menu = M;
}

void Juego::Impacto(Tanque * T)  //  T es el tanque destruido
{
        if(T == tanque1)
        {
             T->Set_coordenada_x(10+rand()%(201 - 10));
             escenario->Set_x_tq1(tanque1);
             jugador2->Sumapunto();
        }
        else if(T == tanque2)
        {
             T->Set_coordenada_x(530+rand()%(720 - 530));
             escenario->Set_x_tq2(tanque2);
             jugador1->Sumapunto();
        }

}


