#include "domparser.h"

DomParser::DomParser(QTreeWidget *tree)
{
    treeWidget= tree;
}

bool DomParser::readFile(const QString &fileName)
{
    QFile file(FileName);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
std:cerr << "Error: Cannot read file " << qPrintable(fileNAme)
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
