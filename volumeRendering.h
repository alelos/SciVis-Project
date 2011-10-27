/*
 * =====================================================================================
 *
 *       Filename:  volumeRendering.h
 *
 *    Description:  Class responsible for data reading (DICOM files), and volume rendering on gpu with smart mapper.
 *
 *        Version:  1.0
 *        Created:  09/29/2011 13:28:57
 *       Revision:  none
 *       Compiler:  llvm/clang++
 *
 *         Author:  YOUR NAME (Louis Dijkstra Alex Theiakos), 
 *        Company:  
 *
 * =====================================================================================
 */

#include <vtkDICOMImageReader.h>
#include <vtkImageData.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkSmartVolumeMapper.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkSmartPointer.h>
#include <vtkAlgorithm.h>
#include <vtkVolume.h>
#include <vtkVolumeProperty.h>
#include <vtkColorTransferFunction.h>
#include <vtkPiecewiseFunction.h>
#include <QVTKWidget.h>
#include <QObject>
#include <string>
#include <iostream>

using std::string ;

/*
 * =====================================================================================
 *        Class:  VolumeRendering
 *  Description:  This class reads the DICOM file and volume renderes the data. Constructor needs a directory name.
 * =====================================================================================
 */
class VolumeRendering : public QObject {
    Q_OBJECT ;
    public:
        VolumeRendering(string dirname) ;
        ~VolumeRendering() ;
        inline QVTKWidget* getRenderWindow(){ return qvtkWidget ; }
        void setupReader() ;
        void setupDefaultTransferFunctions (int minValue, int maxValue) ; 
        void setupRenderer() ;
        void setupTransferFunctions() ;
        void setupVolume() ;
    public slots:
        //TODO functions to change color and opacity functions depending on the UI sliders.
        void startRendering() ;
        void setOpacityFunction(int startPoint, float startValue, int endPoint, float endValue) ;
        void clearAllPoints() ;
    private:
        string dirname ;
        vtkDICOMImageReader *DICOMreader ;
        vtkRenderer *renderer ;
        vtkRenderWindow *renderWindow ;
        QVTKWidget *qvtkWidget ;
        vtkSmartVolumeMapper *mapper ;
        vtkVolume *volume ;
        vtkVolumeProperty *property ;
        vtkColorTransferFunction *colorFun ;
        vtkPiecewiseFunction *opacityFun ;
        vtkAlgorithm *reader ;
        vtkImageData *input ;
};
