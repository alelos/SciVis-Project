
#include <QApplication>
#include "MainWindow.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv) ;
    MainWindow w("/Users/alelos/Desktop/brain/") ;
    w.show() ;
    return app.exec();
}
