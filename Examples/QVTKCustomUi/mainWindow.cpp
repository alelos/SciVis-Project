#include "mainWindow.h"

MainWindow::MainWindow(QWidget *parent) {
    //center = new QWidget(this) ;
    QWidget *centerTrue = new QWidget(this) ;
    center = new QVTKWidget ;
    setupCone() ;
    createSettingsBox() ;

    QGridLayout *centerLayout = new QGridLayout ;
    centerLayout->addWidget(settingsBox, 0, 2) ;
    centerLayout->addWidget(center, 0, 1) ;

    setWindowTitle("Testing") ;
    center->SetRenderWindow(renderWindow) ; 
    centerTrue->setLayout(centerLayout) ;
    setCentralWidget(centerTrue) ;
}

MainWindow::~MainWindow() {

}

void MainWindow::setupCone() {
    
    //the cone
    vtkConeSource* cone = vtkConeSource::New() ;
    cone->Update() ;

    vtkPolyDataMapper* mapper = vtkPolyDataMapper::New() ;
    mapper->SetInputConnection(cone->GetOutputPort()) ;

    vtkActor* actor = vtkActor::New() ;
    actor->SetMapper(mapper) ;

    vtkRenderer* renderer = vtkRenderer::New() ;
    renderWindow = vtkRenderWindow::New() ;

    renderWindow->AddRenderer(renderer) ;

    //interactor
    vtkRenderWindowInteractor* windowInteractor = vtkRenderWindowInteractor::New() ;
    windowInteractor->SetRenderWindow(renderWindow) ;
    renderer->AddActor(actor) ;
    renderer->SetBackground(0, 0, 0) ;
    
    renderWindow->Render() ;
}

void MainWindow::createSettingsBox() {
    settingsBox = new QGroupBox("Settings") ;
    settingsBox->setAlignment(Qt::AlignHCenter) ;

    QHBoxLayout *buttonLayout = new QHBoxLayout ;

    QPushButton *quitButton = new QPushButton("Quit") ;
    connect(quitButton, SIGNAL(clicked()), qApp, SLOT(quit())) ;
    buttonLayout->addWidget(quitButton) ;
    settingsBox->setLayout(buttonLayout) ;
}
