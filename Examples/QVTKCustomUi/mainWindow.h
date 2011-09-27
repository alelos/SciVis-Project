#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QCoreApplication>
#include <QWidget>
#include <QGroupBox>
#include <QGridLayout>
#include <vtkConeSource.h>
#include <vtkPolyData.h>
#include <vtkSmartPointer.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>
#include <QVTKWidget.h>
#include <QHBoxLayout>
#include <QPushButton>


class MainWindow : public QMainWindow
{
    Q_OBJECT ;
public:
    MainWindow(QWidget *parent = 0) ;
    ~MainWindow() ;
    void setupCone() ;
    void createSettingsBox() ;
private:
    //QGraphicsView *view ;
    QVTKWidget *center ;
    QGroupBox *settingsBox ;
    vtkRenderWindow *renderWindow ;
};

#endif // MAINWINDOW_H
