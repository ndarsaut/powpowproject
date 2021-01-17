#include "Jugador.h"


Jugador::Jugador(QString name)
{
    nombre = name;
    puntos = 0;
}

Jugador::~Jugador()
{
    //dtor
}


void Jugador::Sumapunto()
{
    puntos++;       // sumo punto al jugador indicado
}

int Jugador::GetPuntos()
{
    return puntos;
}

QString Jugador::GetNombre()
{
    return nombre;
}

QString Jugador::GetNombre_Puntos()
{
    QString N = nombre;
    N = N.toUpper();
    N.append(" ");
    N.append(QString::number(puntos));

    return N;
}


