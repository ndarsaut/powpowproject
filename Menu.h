#pragma once

#include "Juego.h"

#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QSlider>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>


class Juego;
class Jugador;
class QString;

//  MENU DE INICIO

class Menu : public QWidget
{
    Q_OBJECT

    private:

        //  PUNTERO A LA PROXIMA VENTANA
        Juego * juego;

        //  TITULO
        QLabel * lbltitulo;

        //  INGRESO DE JUGADORES Y NOMBRES
        QLabel * lblplayer1;
        QLabel * lblplayer2;

        QLineEdit * nombre1;
        QLineEdit * nombre2;

        //  BOTONES
        QPushButton * btnexit;
        QPushButton * btnplay;

        QMessageBox * Alert;

    public:
        Menu(QWidget * parent = 0);
        ~Menu();

    public slots:
        void Jugar();
        void Salir();

};


