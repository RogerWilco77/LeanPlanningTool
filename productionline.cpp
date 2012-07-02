#include "productionline.h"

ProductionLine::ProductionLine()
{
}


ProductionLine::ProductionLine(double demand, double workDays, double workHours, double oeeValue) {
    demandPerYear = demand;
    workDaysPerYear = workDays;
    workHoursPerDay = workHours;
    oee = oeeValue;



    unitsPerDay = calculateUnitsPerDay(); //weakness: the order is mandatory because unitsPerDay is required for TaktTime
    taktTime = calculateTaktTime();
    cycleTime = calculateCycleTime();

}



double ProductionLine::calculateUnitsPerDay() {
    return demandPerYear/workDaysPerYear;

}

double ProductionLine::calculateTaktTime() {
    return (1.0 * workHoursPerDay*60*60 / unitsPerDay);

}

double ProductionLine::calculateCycleTime() {
    return taktTime*oee;
}


double ProductionLine::getUnitsPerDay() {
    return unitsPerDay;
}

double ProductionLine::getTaktTime() {
    return taktTime;
}

double ProductionLine::getCycleTime() {
    return cycleTime;
}
