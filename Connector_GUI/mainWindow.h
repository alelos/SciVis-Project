#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QLineEdit>
#include <QFuture>
#include <QtCore>
#include <QWidget>
#include <QGridLayout>
#include <QColor>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QString>
#include <QPushButton>
#include <QPalette>
#include <QFont>
#include <QTextEdit>
#include "Connector.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void enableLoginButton() ;
    void writeToSlots() ;
    void execute() ;
    void logoutAndQuit() ;
private:
    void setupLoginBox() ;
    QString m_username ;
    QString m_password ;
    QLineEdit *l_username ;
    QLineEdit *l_passSara ;
    QLineEdit *l_passVNC ;
    QPushButton *loginButton ;
    QWidget *center ;
    QGroupBox *settingsBox ;
    QGroupBox *loginBox ;
    Connector connector ;
};

#endif // MAINWINDOW_H
