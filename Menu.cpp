
#include "Menu.h"
#include <iostream>

using namespace std ;

Menu::Menu(QWidget *parent):QWidget(parent)
{

        juego = NULL;   //  INICIALIZO PUNTERO A LA VENTANA DEL JUEGO

        QFont fuentePlayer("MS Serif", 10, QFont::Bold);

        //  SETEO VENTANA DEL MENU
        setGeometry(50,50,330,165);
        setFixedSize(330,165);
        setWindowTitle("Pow Pow Project");


        //  AGREGO TITULO
        lbltitulo = new QLabel("POW POW PROJECT", this);
        QFont fuenteTitulo("MS Serif", 15, QFont::Bold);
        lbltitulo->setFont(fuenteTitulo);
        lbltitulo->setGeometry(60,10,210,30);


        //  AGREGO ETIQUETAS JUGADORES
        lblplayer1 = new QLabel("PLAYER 1",this);
        lblplayer1->setFont(fuentePlayer);
        lblplayer1->setGeometry(10,55,100,25);

        lblplayer2 = new QLabel("PLAYER 2",this);
        lblplayer2->setFont(fuentePlayer);
        lblplayer2->setGeometry(10,85,100,25);


        //  ESPACIOS PARA AGREGAR NOMBRES
        nombre1 = new QLineEdit(this);
        nombre1->setGeometry(100,55,200,25);

        nombre2 = new QLineEdit(this);
        nombre2->setGeometry(100,85,200,25);


        //  BOTONES
        btnplay = new QPushButton("Play",this);
        btnplay->setAutoDefault(true);
        btnplay->setGeometry(200,125,80,20);
        connect(btnplay, SIGNAL(clicked()), this, SLOT(Jugar()));

        btnexit = new QPushButton("Exit",this);
        btnexit->setGeometry(50,125,80,20);
        connect(btnexit, SIGNAL(clicked()), this, SLOT(Salir()));


}

Menu::~Menu()
{
    //dtor
}




void Menu::Jugar()
{
    QMessageBox Alert;
    Alert.setGeometry(300,300,0,0);
    Alert.setWindowTitle("Pow Pow Project");
    Alert.setIcon(QMessageBox::Information);
    QFont fuenteAlert("Arial", 10, QFont::Bold);
    Alert.setFont(fuenteAlert);
    Alert.setText("   Debe ingresar ambos jugadores.     ");

    // VERIFICO SI FUERON INGRESADOS AMBOS NOMBRES
    if((nombre1->text()==NULL) | (nombre2->text()==NULL))
    {
        Alert.exec();
        return;
    }

    //  ARRANCO CON EL JUEGO (paso un puntero al objeto menu y a los jugadores)
    if(!juego)
    {
        juego = new Juego(nombre1->text(),nombre2->text());
        juego->SetJuego(this);
    }

    juego->show();
    hide();

}

void Menu::Salir()
{
    //  MENSAJE DE ALERTA POR SALIR DEL JUEGO
    QMessageBox Alert;

    Alert.setWindowTitle("Pow Pow Project");
    QFont fuenteAlert("Arial", 9, QFont::Bold);
    Alert.setFont(fuenteAlert);
    Alert.setText("  ¿Seguro que quiere salir del juego?");
    Alert.setIcon(QMessageBox::Warning);
    Alert.setStandardButtons(QMessageBox::Cancel|QMessageBox::Ok);
    Alert.setDefaultButton(QMessageBox::Cancel);

    int rtn = Alert.exec(); // tomo el valor retornado por el messagebox

    if(rtn == QMessageBox::Ok) qApp->quit();

}
