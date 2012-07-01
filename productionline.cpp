#include "productionline.h"

ProductionLine::ProductionLine()
{
}


ProductionLine::ProductionLine(int demand, int workDays, double workHours, double oeeValue) {
    demandPerYear = demand;
    workDaysPerYear = workDays;
    workHoursPerDay = workHours;
    oee = oeeValue;


    //
    // missing initialisation of remaining variables for calculation!!!
    //

}



int ProductionLine::calculateUnitsPerDay() {
    return demandPerYear/workDaysPerYear;

}

double ProductionLine::calculateTaktTime() {
    return (1.0 * workHoursPerDay*60*60 / unitsPerDay);

}

double ProductionLine::calculateCycleTime() {
    return taktTime/oee;
}
