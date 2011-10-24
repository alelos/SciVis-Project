/*
 * =====================================================================================
 *
 *       Filename:  histogramChart.h
 *
 *    Description:  class to provide a histogram of the dcm file
 *
 *        Version:  1.0
 *        Created:  10/15/2011 16:05:01
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */


#include <vtkXYPlotActor.h>
#include <vtkImageAccumulate.h>
#include <QVTKWidget.h>
#include <vtkSmartPointer.h>
#include <vtkImageData.h>
#include <vtkImageExtractComponents.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkDICOMImageReader.h>
#include <QObject.h>
#include <string>

using std::string ;

class Histogram : public QObject 
{
    Q_OBJECT ;
    public:
    Histogram(string fl) ;
    ~Histogram() ;
    inline QVTKWidget* getRenderWindow() {return iren ;}
    void drawPlot() ;
    private:
    QVTKWidget *iren ;
    vtkSmartPointer<vtkRenderer> renderer ;
    vtkSmartPointer<vtkRenderWindow> renderWindow ;
    vtkSmartPointer<vtkRenderWindowInteractor> renWin ;
    vtkSmartPointer<vtkXYPlotActor> plot ;
    vtkSmartPointer<vtkDICOMImageReader> reader ;    
    vtkSmartPointer<vtkImageAccumulate> histo ;
    string filename ;
    int ignoreZero, numComponents  ;
    double xmax, ymax ;
};


