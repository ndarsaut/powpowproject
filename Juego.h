#pragma once

#include "Menu.h"
#include "Jugador.h"
#include "Escenario.h"
#include "Tanque.h"

#include <iostream>
#include <time.h>
#include <stdlib.h>

#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QSlider>
#include <QLineEdit>
#include <QPushButton>
#include <QPixmap>




class Jugador;
class Menu;
class Escenario;
class QPixmap;
class QFile;

//  VENTANA DEL JUEGO

class Juego : public QWidget
{
    Q_OBJECT

    private:
        Menu * menu;  //  Puntero al menu

        //  Punteros a los jugadores
        Jugador * jugador1;
        Jugador * jugador2;

        //  Puntero al escenario
        Escenario * escenario;

        //  Puntero a los tanques
        Tanque * tanque1;
        Tanque * tanque2;

        //  Datos para el jugador 1
        QLabel * lblPower1;
        QLabel * lblAngle1;
        QLabel * lbljugador1;
        QSlider * power1;
        QLineEdit * angle1;

        //  Datos para el jugador 2
        QLabel * lblPower2;
        QLabel * lblAngle2;
        QLabel * lbljugador2;
        QSlider * power2;
        QLineEdit * angle2;

        QPushButton * fire;


    public:
        Juego(QString, QString, QWidget * parent = 0);
        ~Juego();
        void SetJuego(Menu *);     // Seteo los valores de los punteros al menu


    public slots:
        void Impacto(Tanque *);

};
