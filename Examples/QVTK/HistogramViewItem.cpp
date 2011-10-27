#include "HistogramViewItem.h"
#include <vtkGenericOpenGLReaderWindow.h>
#include <vtkgl.h>
#include <QVTKInteractor.h>
#include <vtkImageData.h>
#include <vtkImageExtractComponents.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkDICOMImageReader.h>

HistogramViewItem::HistogramViewItem(QGLContext* context, QGraphicsItem *parent) : QVTKGraphicsItem(context, parent) 
{
    plot.TakeReference(vtkXYPlotActor::New()) ;
    plot->SetInteractor(this->GetInteractor()) ;
}

HistogramViewItem::~HistogramViewItem()
{
}
