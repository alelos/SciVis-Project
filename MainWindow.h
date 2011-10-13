/*
 * =====================================================================================
 *
 *       Filename:  MainWindow.h
 *
 *    Description:  Main GUI of the SciVis project, implemented in Qt
 *
 *        Version:  1.0
 *        Created:  09/29/2011 10:56:29
 *       Revision:  none
 *       Compiler:  llvm/clang++
 *
 *         Author:  YOUR NAME (Louis Dijkstra, Alex Theiakos) 
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef  MAINWINDOW_H_INC
#define  MAINWINDOW_H_INC

#include <QtGui/QMainWindow>
#include <QWidget>
#include <QVTKWidget.h>
#include <QCoreApplication>
#include <QGridLayout>
#include <QGroupBox>
#include <QHBoxLayout>
#include <string>
#include <QPushButton>
#include "volumeRendering.h"


/*
 * =====================================================================================
 *        Class:  MainWindow
 *  Description:  Creating the main GUI for the program
 * =====================================================================================
 */

using std::string ;
using std::cout ;
using std::cout ;

class MainWindow : public QMainWindow {
    Q_OBJECT ;
    public:
        MainWindow(string dirname, QWidget *parent = 0) ;       // Constructor 
        ~MainWindow() ;                         // Destructor 
        void createSettingsBox() ;                   // Function to set up the settings part of the gui
    private:
        QGroupBox *settingsBox ;                // Widget for the settings
        QWidget *center ;
        VolumeRendering vr ;
} ;
#endif   // ----- #ifndef MAINWINDOW_H_INC  ----- 
