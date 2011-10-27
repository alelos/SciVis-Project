#ifndef HISTOGRAMVIEWITEM_H
#define HISTOGRAMVIEWITEM_H

#include <QVTKGraphicsItem.h>

class vtkXYPlotActor ;

class HistogramViewItem : public QVTKGraphicsItem
{
    public 
        HistogramViewItem(QGLContext *context, QGraphicsItem *parent = 0) ;
        ~HistogramViewItem() ;
    private
        vtkSmartPointer<vtkXYPlotActor> plot ;
} ;











#endif // HISTOGRAMVIEWITEM_H
