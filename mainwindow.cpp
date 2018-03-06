#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    login_dialog = new LoginDialog(parent);

    QObject::connect(login_dialog,
                     SIGNAL(acceptLogin(QString&,QString&,int&)), this,
                     SLOT( slotAcceptUserLogin(QString&,QString&)  )  );

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionExit_triggered()
{
    qDebug() << "exit call...";
    close();
}

void MainWindow::on_actionConfig_triggered()
{
    qDebug() << "config call...";

    QString user = QString("John");
    login_dialog->setUsername( user ); // optional

    //QString pass = QString("123");
    //login_dialog->setPassword( pass ); // optional
    int res = login_dialog->exec();

    qDebug() << "result: " << res;


}

bool MainWindow::slotAcceptUserLogin(QString & user, QString & pass) {
    qDebug() << "received user pass";
    qDebug() << user << pass;
    if (pass == "123") {
        login_dialog->accept();
    }
    return true;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    QMainWindow::closeEvent(event);
}
