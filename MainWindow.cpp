#include "MainWindow.h"
#include <QLabel>
#include <QLineEdit>
#include <QHeaderView>
#include <QPushButton>

MainWindow::MainWindow(string dirname, string filename, QWidget *parent) : vr(dirname), h(dirname), m_rowToRemove(0) {
    center = new QWidget(this) ;       /* center widget, holds everything together */
    //center->setMinimumSize(600,480) ;
    createSettingsBox() ;
    createOpacityBox() ;

    QGridLayout *centerLayout = new QGridLayout ;
    centerLayout->setColumnMinimumWidth(0,400);
    centerLayout->setColumnMinimumWidth(1,300);
    centerLayout->setRowMinimumHeight(0, 350);
    centerLayout->setRowMinimumHeight(1, 150);
    //centerLayout->setRowMinimumHeight(2, 150);
    centerLayout->addWidget(vr.getRenderWindow(),0, 0) ;
    centerLayout->addWidget(h.getRenderWindow(),1, 0) ;
    centerLayout->addWidget(opacityBox,0, 1) ;
    centerLayout->addWidget(settingsBox, 1, 1) ;

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

    //QHBoxLayout *buttonLayout = new QHBoxLayout ; // Horizontal box for buttons
    QGridLayout *mainLayout = new QGridLayout ;

    QPushButton *quitButton = new QPushButton("Quit") ;
    QPushButton *renderButton = new QPushButton("Render") ;
    connect(quitButton, SIGNAL(clicked()), qApp, SLOT(quit())) ; // Connection between the quit button and the global object qApp which terminates the application 
    connect(renderButton, SIGNAL(clicked()), &vr, SLOT(startRendering())) ;
    mainLayout->addWidget(renderButton, 0, 0) ;
    mainLayout->addWidget(quitButton, 0, 1) ;
    settingsBox->setLayout(mainLayout) ;
}

void MainWindow::createOpacityBox() {

    opacityBox = new QGroupBox("Opacity Transfer Function") ;
    opacityBox->setAlignment(Qt::AlignHCenter) ;
    QGridLayout *mainLayout = new QGridLayout ;

    QPushButton *addPointsToOpacity = new QPushButton("Add points") ;
    QPushButton *addNewSegment = new QPushButton("Add new segment") ;
    QPushButton *removeSegment = new QPushButton("Remove segment") ;
    opacityTable = new QTableWidget(1,4) ;
    QLineEdit *insertRowToRemove = new QLineEdit ;
    QLabel *labelRowToRemove = new QLabel("Insert the number of\nrow to remove") ;
    labelRowToRemove->setWordWrap(true) ;
    /* 
    for (int i = 0; i < opacityTable->columnCount(); i++) {
        opacityTable->setColumnWidth(i, 100) ;
    }
    */
    QStringList horizontalLabels ;
    horizontalLabels << "Start Point" << "Start Value" << "End Point" << "End Value" ;
    opacityTable->setHorizontalHeaderLabels(horizontalLabels) ;

    connect(addPointsToOpacity, SIGNAL(clicked()), this, SLOT(addOpacityPoints()) ) ;
    connect(addNewSegment, SIGNAL(clicked()), this, SLOT(addOpacityRow())) ;
    connect(insertRowToRemove, SIGNAL(textChanged(QString)), this, SLOT(rowToRemove(QString))) ;
    connect(removeSegment, SIGNAL(clicked()), this, SLOT(removeOpacityPoints())) ;


    mainLayout->addWidget(opacityTable, 0, 0, 1, 3) ;
    mainLayout->addWidget(addNewSegment, 1, 0) ;
    mainLayout->addWidget(addPointsToOpacity, 1, 1) ;
    mainLayout->addWidget(labelRowToRemove, 2, 0) ;
    mainLayout->addWidget(insertRowToRemove, 2, 1) ;
    mainLayout->addWidget(removeSegment, 1, 2) ;
    opacityBox->setLayout(mainLayout) ;
}

void MainWindow::addOpacityPoints() {
    for (int i = 0; i < opacityTable->rowCount(); i++) {
        QTableWidgetItem *startPoint = opacityTable->item(i, 0) ;
        QTableWidgetItem *startValue = opacityTable->item(i, 1) ;
        QTableWidgetItem *endPoint = opacityTable->item(i, 2) ;
        QTableWidgetItem *endValue = opacityTable->item(i, 3) ;

        vr.setOpacityFunction(startPoint->text().toInt(), startValue->text().toFloat(), endPoint->text().toInt(), endValue->text().toFloat()) ;
    }
}

void MainWindow::addOpacityRow() {
    int row = opacityTable->rowCount() ;
    opacityTable->insertRow(row) ;
}

void MainWindow::rowToRemove(QString r) {
    m_rowToRemove = r.toInt() ;
}

void MainWindow::removeOpacityPoints() {
    QTableWidgetItem *startPoint = opacityTable->item(m_rowToRemove, 0) ;
    QTableWidgetItem *endPoint = opacityTable->item(m_rowToRemove, 2) ;

    if (m_rowToRemove != 0) {
        opacityTable->removeRow(m_rowToRemove - 1) ;
    }
}
