#ifndef CONNECTOR_H
#define CONNECTOR_H


#include <QObject>
#include <QString>
#include <QCoreApplication>
#include <QProcess>
#include <QStringList>
#include <QTextEdit>
#include <QPalette>
#include <QFont>
#include <QMessageBox>
#include <QFileDialog>
#include <string>
#include <libssh/libssh.h>

using std::string ;

class Connector : public QObject
{
    Q_OBJECT;
public:
    Connector() ;
    ~Connector() ;
    ssh_session sshSession ;
signals:
public slots:
    //void login() ;
    void setUsername(QString username) ;
    void libsshLogin() ;
    int startVNCSession(string hours="1", string minutes="00", string seconds="00") ;
    void setPassword(QString passSara) ;
    void setVNCPassword(QString passvnc) ;
    void setTimeHours(QString hours) ;
    void setTimeMinutes(QString minutes) ;
    void setTimeSeconds(QString seconds) ;
    QTextEdit *getOutput() ;
    void writeToOutput() ;
    void connectToVNCServer(int node) ;
    void logout() ;
private:
    void setupOutputBox() ;
    ssh_channel channel ;
    string m_username, m_passSara, m_passvnc ;
    QString q_username, q_passSara, q_passvnc ;
    string m_hours, m_minutes, m_seconds ;
    QTextEdit *output ;
    QProcess *process ;
} ;

#endif // CONNECTOR_H
