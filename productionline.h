#ifndef PRODUCTIONLINE_H
#define PRODUCTIONLINE_H


/*!
  * This class represents all kinds of production lines. In most cases probably an assembly line.
  * Smaller units, maybe even machines or single production operations,
  * can inherit basic peoperties such as OEE from this class
  */



class ProductionLine
{
public:
    ProductionLine();
    ProductionLine(int demandPerYear, int workDaysPerYear, int workHoursPerDay, double OEE);

    double getCycleTime();
    double getTaktTime();
    double getUnitsPerDay();


private:
    int demandPerYear;      /*! < customer demand of pieces per year */
    int workDaysPerYear;    /*! < work days per year considering bank holidays, shut downs, ... */
    int workHoursPerDay;    /*! < planned work hours. Work hours - pause - planned maintenance...*/
    double oee;             /*! < estimated OEE (Overall Equipment Effectiveness)*/
    double cycleTime;
    double taktTime;
    int unitsPerDay;





};

#endif // PRODUCTIONLINE_H
