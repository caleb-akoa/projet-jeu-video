#include "gestion.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Gestion w;
    w.show();
    return a.exec();
}
