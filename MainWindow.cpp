#include "MainWindow.h"

MainWindow::MainWindow(string dirname, string filename, QWidget *parent) : vr(dirname), h(filename) {
    center = new QWidget(this) ;       /* center widget, holds everything together */
    createSettingsBox() ;

    QGridLayout *centerLayout = new QGridLayout ;
    centerLayout->addWidget(vr.getRenderWindow(), 0, 1) ;
    centerLayout->addWidget(h.getRenderWindow(),1, 1) ;
    centerLayout->addWidget(settingsBox, 0, 2) ;

    setWindowTitle("Corals") ;
    center->setLayout(centerLayout) ;
    setCentralWidget(center) ;
}

MainWindow::~MainWindow() {
    delete settingsBox ;
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  createSettingsBox
 *  Description:  This function creates all the settings in a QGroupBox widget. It gets called from the constructor.
 * =====================================================================================
 */

void MainWindow::createSettingsBox() {
    settingsBox = new QGroupBox("Settings") ;
    settingsBox->setAlignment(Qt::AlignHCenter) ;

    QHBoxLayout *buttonLayout = new QHBoxLayout ; // Horizontal box for buttons
    QPushButton *quitButton = new QPushButton("Quit") ;
    connect(quitButton, SIGNAL(clicked()), qApp, SLOT(quit())) ; // Connection between the quit button and the global object qApp which terminates the application 

    buttonLayout->addWidget(quitButton) ;
    
    settingsBox->setLayout(buttonLayout) ;
}
