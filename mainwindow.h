#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QtCore>
#include <QString>
#include <QDebug>

#include "dialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void closeEvent(QCloseEvent *event); // Overloaded function

    LoginDialog * login_dialog;

public slots:
    /******************************************
    ** Auto-connections (connectSlotsByName())
    *******************************************/
    void on_actionExit_triggered();
    void on_actionConfig_triggered();

    bool slotAcceptUserLogin(QString &, QString &);

private:
    Ui::MainWindow *ui;
protected:

};

#endif // MAINWINDOW_H
