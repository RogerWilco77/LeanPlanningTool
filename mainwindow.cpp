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


    double demand = 1000.0*ui->spbxDemandPerYear->value();
    double workdays = 1.0*ui->spbxWorkDaysPerYear->value();
    double workhours = ui->spbxWorkHoursPerDay->value();
    double oee = ui->spbxOee->value();


    ProductionLine *production;

    production = new ProductionLine(demand, workdays, workhours, oee);

    ui->lcdNumber->display(production->getUnitsPerDay());
    ui->lcdTaktTime->display(production->getTaktTime());
    ui->lcdCycleTime->display(production->getCycleTime());

}
