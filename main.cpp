
#include <QApplication>
#include "MainWindow.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv) ;
    MainWindow w("/Users/alelos/Desktop/brain/", "/Volumes/Data/Documents/DICOM/445_0000.dcm") ;
    w.show() ;
    return app.exec();
}
