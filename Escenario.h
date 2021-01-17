
#include "Tanque.h"

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>

class QPixmap;
class Tanque;

class Escenario
{

    private:

        QPixmap fondo;

        QGraphicsScene * pantalla;
        QGraphicsView * verPantalla;

        QGraphicsPixmapItem * tq1;      //  PUNTEROS A LOS TANQUES DENTRO DE LA ESCENA
        QGraphicsPixmapItem * tq2;

    public:
        Escenario(QWidget *, Tanque *, Tanque *);
        ~Escenario();
        void Set_x_tq1(Tanque *);
        void Set_x_tq2(Tanque *);
};
