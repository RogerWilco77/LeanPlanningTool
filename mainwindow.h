#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <productionline.h>


// just a comment for test

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


public slots:
    void calculateMetrics();


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H


