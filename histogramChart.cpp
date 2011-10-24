/*
 * =====================================================================================
 *
 *       Filename:  histogramChart.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/15/2011 16:33:56
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */


#include "histogramChart.h"

Histogram::Histogram(string fl) : filename(fl), ignoreZero(0), numComponents(0), xmax(0), ymax(0) {
    
    reader = vtkSmartPointer<vtkDICOMImageReader>::New() ;
    reader->SetFileName(filename.c_str()) ;
    plot = vtkSmartPointer<vtkXYPlotActor>::New() ;
    numComponents = reader->GetOutput()->GetNumberOfScalarComponents() ;

    drawPlot() ;

    renderer = vtkSmartPointer<vtkRenderer>::New() ;
    renderer->AddActor(plot) ;
    renderWindow = vtkSmartPointer<vtkRenderWindow>::New() ;
    renderWindow->AddRenderer(renderer) ;
    iren = new QVTKWidget ;
    iren->SetRenderWindow(renderWindow) ;

    //iren->Initialize() ;
    //interactor->Start() ;
}

Histogram::~Histogram() {}
    
void Histogram::drawPlot() {
    for(std::size_t i = 0; i < numComponents; i++ ) {
        vtkSmartPointer<vtkImageExtractComponents> extract = vtkSmartPointer<vtkImageExtractComponents>::New() ;
        extract->SetInputConnection(reader->GetOutputPort()) ;
        extract->SetComponents(i) ;
        extract->Update() ;
        double range[2] ;
        extract->GetOutput()->GetScalarRange(range) ;

        histo = vtkSmartPointer<vtkImageAccumulate>::New() ;
        histo->SetInputConnection(extract->GetOutputPort()) ;
        histo->SetComponentExtent(0, static_cast<int>(range[1]) - static_cast<int>(range[0]) - 1, 0,0,0,0) ;
        histo->SetComponentOrigin(range[0], 0, 0) ;
        histo->SetComponentSpacing(1, 0, 0) ;
        histo->SetIgnoreZero(ignoreZero) ;
        histo->Update() ;
        
        if( range[1] > xmax ) 
        { 
            xmax = range[1];
        }
        if( histo->GetOutput()->GetScalarRange()[1] > ymax ) 
        {
            ymax = histo->GetOutput()->GetScalarRange()[1];
        }

        plot->AddInput( histo->GetOutput() );

        /*  
        if( numComponents > 1 )
        {
            plot->SetPlotColor(i,colors[i]);
        }*/
    }

    plot->SetXRange(0, xmax) ;
    plot->SetYRange(0, ymax) ;

}
