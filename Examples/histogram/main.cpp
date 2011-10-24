
#include <vtkSmartPointer.h>
#include <vtkImageAccumulate.h>
#include <vtkImageData.h>
#include <vtkImageExtractComponents.h>
#include <vtkDICOMImageReader.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkDataSetReader.h>
#include <vtkXYPlotActor.h>

int main(int argc, const char *argv[])
{
    vtkSmartPointer<vtkDICOMImageReader> reader = vtkSmartPointer<vtkDICOMImageReader>::New() ;
    reader->SetFileName("/Volumes/Data/Documents/DICOM/445_0000.dcm") ;
    reader->Update() ;

    int numComponents = reader->GetOutput()->GetNumberOfScalarComponents() ;
    int ignoreZero = 0 ;

    vtkSmartPointer<vtkXYPlotActor> plot = vtkSmartPointer<vtkXYPlotActor>::New() ;
    plot->ExchangeAxesOff() ;
    plot->SetXValuesToValue() ;

    double xmax = 0;
    double ymax = 0;

    double colors[3][3] = {
        {1,0,0},
        {0,1,0},
        {0,0,1}
    } ;
    std::cout << numComponents << std::endl ;

    for (int i = 0; i < numComponents; i++) {
        vtkSmartPointer<vtkImageExtractComponents> extract = vtkSmartPointer<vtkImageExtractComponents>::New() ;
        extract->SetInputConnection(reader->GetOutputPort()) ;
        extract->SetComponents(i) ;
        extract->Update() ;
        double range[2] ;
        extract->GetOutput()->GetScalarRange(range) ;

        vtkSmartPointer<vtkImageAccumulate> histogram = vtkSmartPointer<vtkImageAccumulate>::New() ;
        histogram->SetInputConnection(extract->GetOutputPort()) ;
        histogram->SetComponentExtent(0, static_cast<int>(range[1]) - static_cast<int>(range[0]) - 1, 0,0,0,0) ;
        histogram->SetComponentOrigin(range[0], 0, 0) ;
        histogram->SetComponentSpacing(1, 0, 0) ;
        histogram->SetIgnoreZero(ignoreZero) ;
        histogram->Update() ;
        
        if( range[1] > xmax ) 
        { 
            xmax = range[1];
        }
        if( histogram->GetOutput()->GetScalarRange()[1] > ymax ) 
        {
            ymax = histogram->GetOutput()->GetScalarRange()[1];
        }

        plot->AddInput( histogram->GetOutput() );

        if( numComponents > 1 )
        {
            plot->SetPlotColor(i,colors[i]);
        }
    } 
    
    plot->SetXRange(0, xmax) ;
    plot->SetYRange(0, ymax) ;
    

    vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New() ;
    renderer->AddActor(plot) ;
    vtkSmartPointer<vtkRenderWindow> renderWindow = vtkSmartPointer<vtkRenderWindow>::New() ;
    renderWindow->AddRenderer(renderer) ;
    vtkSmartPointer<vtkRenderWindowInteractor> interactor = vtkSmartPointer<vtkRenderWindowInteractor>::New() ;
    interactor->SetRenderWindow(renderWindow) ;

    interactor->Initialize() ;
    interactor->Start() ;

    return 0;
}
