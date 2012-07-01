#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->btnCalculate, SIGNAL(clicked()), this, SLOT(calculateMetrics()));   /*! connects the pushbotton btnCalculate with the function calculateMetrics() */




}

MainWindow::~MainWindow()
{
    delete ui;
}



/*! calculates the Metrics based on basic entries */
void MainWindow::calculateMetrics() {


    int demand = ui->spbxDemandPerYear->value();
    int workdays = ui->spbxWorkDaysPerYear->value();
    double workhours = ui->spbxWorkHoursPerDay->value();
    double oee = ui->spbxOee->value();


    ProductionLine *production;

    production = new ProductionLine(demand, workdays, workhours, oee);

}
