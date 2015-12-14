#ifndef XMLDATAPARSE_H
#define XMLDATAPARSE_H

#include <QObject>

class XMLDataParse
{
public:
    XMLDataParse();

    static QString getValue(QString rawData, QString param);
};

#endif // XMLDATAPARSE_H
