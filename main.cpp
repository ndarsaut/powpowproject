#include <QApplication>
#include "Menu.h"


int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    Menu * m1 = new Menu();

    m1->show();

    return app.exec();
}
