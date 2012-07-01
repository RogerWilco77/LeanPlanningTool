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


    /*!
      * This constructor sets up a new ProductionLine object
      * \param demandPerYear is demand per year as integer
      * \param workDaysPerYear is number of workdays per year as integer
      * \param workHoursPerDay is number of planned work hours per day as double
      * \param oee is estimated Overall Equipment Effectiveness as double
      */


    ProductionLine(int demand, int workDays, double workHours, double oeeValue);

    double getCycleTime();      /*! returns cycle time in seconds */
    double getTaktTime();       /*! returns takt time in seconds */
    double getUnitsPerDay();    /*! returns units per day required */


private:
    int demandPerYear;          /*! < customer demand of pieces per year */
    int workDaysPerYear;        /*! < work days per year considering bank holidays, shut downs, ... */
    double workHoursPerDay;    /*! < planned work hours. Work hours - pause - planned maintenance...*/
    double oee;                 /*! < estimated OEE (Overall Equipment Effectiveness)*/
    double cycleTime;           /*! cycle time of production line */
    double taktTime;            /*! takt time of production line */
    int unitsPerDay;            /*! units per day required */

    int calculateUnitsPerDay();     /*! > calculate the demand in units per day */
    double calculateTaktTime();     /*! > calculate the takt time to cover units per day in seconds*/
    double calculateCycleTime();    /*! > calculate the cycle time to fulfill takt considering OEE  in seconds*/




};

#endif // PRODUCTIONLINE_H
