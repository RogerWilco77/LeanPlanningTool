#ifndef DOMPARSER_H
#define DOMPARSER_H

#include <QtXml>


class DomParser
{
public:
    DomParser(QTreeWidget *tree);

    bool readFile(const QString &fileName);

private:
    void parseLineDefinitionElement(const QDomElement &element);
    void parseDemandPerYearElement(const QDomElement &element, QTreeWidgetItem *parent);
    void parseWorkdaysPerYearElement (const QDomElement &element, QTreeWidgetItem *parent);


};

#endif // DOMPARSER_H
