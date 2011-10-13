#include "volumeRendering.h"

VolumeRendering::VolumeRendering(string dirname) : 
    dirname(dirname),
    reader(0),
    input(0)    
{
    setupReader() ;
    setupRenderer() ;

    // Check if the volume is right
    int dim[3] ;
    input->GetDimensions(dim) ;
    if (dim[0] < 2 || dim[1] < 2 || dim[2] < 2) {
        std::cout << "Error, wrong dimensions in data file" << std::endl ;
        exit(EXIT_FAILURE) ;
    } 

    setupTransferFunctions() ; 
    setupVolume() ;

    renderWindow->SetSize(600, 600) ;

    renderer->AddVolume(volume) ;
    renderer->ResetCamera() ;
    startRendering() ;
}

VolumeRendering::~VolumeRendering() {
}

void VolumeRendering::setupReader() {
    DICOMreader = vtkDICOMImageReader::New() ;
    DICOMreader->SetDirectoryName(dirname.c_str()) ;
    DICOMreader->Update() ;
    input = DICOMreader->GetOutput() ;
    reader = DICOMreader ;
}

void VolumeRendering::setupRenderer() {
    renderer = vtkRenderer::New() ; 
    renderWindow = vtkRenderWindow::New() ;
    renderWindow->AddRenderer(renderer) ;
    iren = new QVTKWidget ;

    iren->SetRenderWindow(renderWindow) ;
}

void VolumeRendering::setupVolume() {
    volume = vtkVolume::New() ;
    mapper = vtkSmartVolumeMapper::New() ;
    property = vtkVolumeProperty::New() ;

    mapper->SetInputConnection(reader->GetOutputPort()) ;
    mapper->SetBlendModeToComposite() ;
    double spacing[3] ;
    input->GetSpacing(spacing) ;

    property->SetIndependentComponents(true) ;
    property->SetColor(colorFun) ;
    property->SetScalarOpacity(opacityFun) ;
    property->SetInterpolationTypeToLinear() ;
    /*  
    property->ShadeOn() ;
    property->SetAmbient(0.1) ;                 // Look it up 
    property->SetDiffuse(0.9) ;                 // Look it up 
    property->SetSpecular(0.2) ;                // Look it up 
    property->SetSpecularPower(10.0) ;
    property->SetScalarOpacityUnitDistance(0.8918) ;
    */

    volume->SetProperty(property) ;
    volume->SetMapper(mapper) ;
}

void VolumeRendering::setupTransferFunctions() {
    colorFun = vtkColorTransferFunction::New() ;
    opacityFun = vtkPiecewiseFunction::New() ;
    opacityFun->AddPoint(0.0, 0.0) ;
    opacityFun->AddPoint(255, 0.2) ;

    colorFun->AddRGBPoint(64, 1.0, 0.0, 0.0) ;
    colorFun->AddRGBPoint(128, 0.0, 0.0, 1.0) ;
    colorFun->AddRGBPoint(196, 0.0, 1.0, 0.0) ;
        
    /*
    colorFun->AddRGBPoint(-3024, 0, 0, 0, 0.5, 0.0) ;
    colorFun->AddRGBPoint(-16, 0.73, 0.25, 0.30, 0.49, 0.61) ;
    colorFun->AddRGBPoint(641, 0.90, 0.82, 0.56, 0.5, 0.0) ;
    colorFun->AddRGBPoint(3071, 1, 1, 1, 0.5, 0.0) ;

    opacityFun->AddPoint(-3024, 0, 0.5, 0.0) ;
    opacityFun->AddPoint(-155, 0, 0.5, 0.92) ;
    opacityFun->AddPoint(217, 0.68, 0.33, 0.45) ;
    opacityFun->AddPoint(420, 0.83, 0.5, 0.0) ;
    opacityFun->AddPoint(3071, 0.80, 0.5, 0.0) ;
    */

}

void VolumeRendering::startRendering() {
    renderWindow->Render() ;
}
