#include "domparser.h"

DomParser::DomParser(QTreeWidget *tree)
{
    treeWidget= tree;
}

bool DomParser::readFile(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        std::cerr << "Error: Cannot read file " << qPrintable(fileName)
         << ": " << qPrintable(file.errorString()) << std::endl;
        return false;
    }

    QString errorStr;
    int errorLine;
    int errorColumn;

    QDomDocument doc;

    if (!doc.setContent(&file, false, &errorStr, &errorLine, &errorColumn)) {
        std::cerr << "Error: Parse Error at line " << errorLine << ", column " << errorColumn << ": " << qPrintable(errorStr) << std::endl;
        return false;
    }

    QDomElement root = doc.documentElement();
    if (root.tagName() != "linedefinition") {
        std::cerr << "Error: not a line definiton file" << std::endl;
        return false;
    }
    parseLineDefinitionElement(root);
    return true;
}


void DomParser::parseLineDefinitionElement(const QDomElement &element)
{
    QDomNode child = element.firstChild();
    while (!child.isNull())
    {
        if (child.toElement().tagName() == "demand_per_year")
            parseDemandPerYearElement(child.toElement(), treeWidget->invisibleRootItem());
        child = child.nextSibling();

    }
}

void DomParser::parseDemandPerYearElement(const QDomElement &element, QTreeWidgetItem *parent)
{
    QTreeWidgetItem *item = new QTreeWidgetItem(parent);
    item->setText(0, element.attribute("term"));

    QDomNode child = element.firstChild();
    while (!child.isNull())
    {
        if (child.toElement().tagName() == "demand_per_year")
        {
            parseDemandPerYearElement(child.toElement(), item);
        }
        else if (child.toElement().tagName() == "work_days_per_year")
        {

        }
    }
}

