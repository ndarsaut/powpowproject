#pragma once

#include <QLabel>


class Jugador
{
    private:
        QString nombre;
        int puntos;

    public:
        Jugador(QString);
        ~Jugador();
        void Sumapunto();
        int GetPuntos();
        QString GetNombre();
        QString GetNombre_Puntos();

};
