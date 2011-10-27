#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), connector()
{
    center = new QWidget(this) ;
    QGridLayout *centerLayout = new QGridLayout ;
    
    setupLoginBox();

    centerLayout->addWidget(loginBox,0,0);
    centerLayout->addWidget(connector.getOutput(),1,0) ;
    setWindowTitle("Connector");
    center->setLayout(centerLayout);
    setCentralWidget(center);
}

MainWindow::~MainWindow()
{

}

void MainWindow::setupLoginBox(){
    // Setting the member variables for the login box
    loginBox = new QGroupBox("Login Details") ;
    loginBox->setAlignment(Qt::AlignLeft);

    loginButton = new QPushButton("Login") ;
    loginButton->setDisabled(true);
    l_username = new QLineEdit ;
    l_passSara = new QLineEdit ;
    l_passVNC = new QLineEdit ;
    QGridLayout *mainLayout = new QGridLayout ;

    QPushButton *uploadButton = new QPushButton("Upload") ;
    QPushButton *quitButton = new QPushButton("Quit") ;
    QPushButton *moreSettingsTime = new QPushButton("Set time") ;
    moreSettingsTime->setCheckable(true) ;

    QLabel *labelUserName = new QLabel("Username:") ;
    labelUserName->setBuddy(l_username);

    QLabel *labelPassSara = new QLabel("RVS &Password:") ;
    l_passSara->setEchoMode(QLineEdit::Password);
    labelPassSara->setBuddy(l_passSara);

    QLabel *labelPassVNC = new QLabel("VNC &Password:") ;
    l_passVNC->setEchoMode(QLineEdit::Password);
    labelPassVNC->setBuddy(l_passVNC);

    // Set the fields to fill in the time you need for the vnc session
    QWidget *extension = new QWidget ;
    QGridLayout *extensionLayout = new QGridLayout ;
    QLabel *labelHours = new QLabel("Hours") ;
    QLineEdit *hours = new QLineEdit ;
    QLabel *labelMinutes = new QLabel("Minutes") ;
    QLineEdit *minutes = new QLineEdit ;
    QLabel *labelSeconds = new QLabel("Seconds") ;
    QLineEdit *seconds = new QLineEdit ;
    extensionLayout->addWidget(labelHours, 0,0) ;
    extensionLayout->addWidget(hours,0,1) ;
    extensionLayout->addWidget(labelMinutes,0,2) ;
    extensionLayout->addWidget(minutes,0,3) ;
    extensionLayout->addWidget(labelSeconds,0,4) ;
    extensionLayout->addWidget(seconds,0,5) ;
    extension->setLayout(extensionLayout) ;
    connect(moreSettingsTime, SIGNAL(toggled(bool)), extension, SLOT(setVisible(bool))) ;

    // Connecting the string fields with the connector variables of username and the 2 passwords
    // Also connection the string fields with the button to disable it if all 3 of them are not full

    connect(l_username, SIGNAL(textChanged(QString)), &connector, SLOT(setUsername(QString))) ;
    connect(l_passSara, SIGNAL(textChanged(QString)), &connector, SLOT(setPassword(QString))) ;
    connect(l_passVNC, SIGNAL(textChanged(QString)), &connector, SLOT(setVNCPassword(QString))) ;
    connect(l_username, SIGNAL(textChanged(QString)), this, SLOT(enableLoginButton())) ;
    connect(l_passSara, SIGNAL(textChanged(QString)), this, SLOT(enableLoginButton())) ;
    connect(l_passVNC, SIGNAL(textChanged(QString)), this, SLOT(enableLoginButton())) ;
    connect(hours, SIGNAL(textChanged(QString)), &connector, SLOT(setTimeHours(QString))) ;
    connect(minutes, SIGNAL(textChanged(QString)), &connector, SLOT(setTImeMinutes(QString))) ;
    connect(seconds, SIGNAL(textChanged()), &connector, SLOT(setTimeSeconds(QString))) ;
    connect(loginButton, SIGNAL(clicked()), this, SLOT(execute())) ;
    connect(quitButton, SIGNAL(clicked()), this, SLOT(logoutAndQuit())) ;

    // Attach the widgets to the main grid layout
    mainLayout->addWidget(labelUserName, 0, 0);
    mainLayout->addWidget(l_username, 0, 1);
    mainLayout->addWidget(labelPassSara, 1, 0);
    mainLayout->addWidget(l_passSara, 1, 1);
    mainLayout->addWidget(labelPassVNC, 2, 0);
    mainLayout->addWidget(l_passVNC, 2, 1);
    mainLayout->addWidget(uploadButton, 0, 2);
    mainLayout->addWidget(loginButton, 1, 2);
    mainLayout->addWidget(moreSettingsTime, 2, 2) ;
    mainLayout->addWidget(extension,3,0,1,3) ;
    /*  
    mainLayout->addWidget(labelHours, 3, 0) ;
    mainLayout->addWidget(hours, 3, 1) ;
    mainLayout->addWidget(labelMinutes, 3, 2) ;
    mainLayout->addWidget(minutes, 3, 3) ;
    mainLayout->addWidget(labelSeconds,3, 4) ;
    mainLayout->addWidget(seconds, 3, 5) ;
    */
    loginBox->setLayout(mainLayout);
    extension->hide() ;
}


// Disable the login button if all the fields are not completed
void MainWindow::enableLoginButton() {
    if (l_username->text().isEmpty() || l_passSara->text().isEmpty() || l_passVNC->text().isEmpty()) {
        loginButton->setDisabled(true);
    }
    else {
        loginButton->setEnabled(true);
    }
}

void MainWindow::execute() {
    connector.libsshLogin() ;
    int node = connector.startVNCSession() ;
    sleep(5) ;
    connector.connectToVNCServer(node) ;
}

void MainWindow::logoutAndQuit() {
    if (connector.sshSession == NULL ) {
        qApp->quit() ;
    }
    else {
        connector.logout() ;
        qApp->quit() ;
    }
}
