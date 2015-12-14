#include "XMLDataParse.h"

XMLDataParse::XMLDataParse()
{

}

QString XMLDataParse::getValue(QString rawData, QString param)
{
    int startIndex = -1, endIndex = -1;
    QString result = "";
    QString startTag ("<%1>"), endTag ("<%1/>");
    startTag = startTag.arg(param);
    endTag = endTag.arg(param);

    startIndex = rawData.indexOf(startTag, Qt::CaseInsensitive);
    endIndex = rawData.indexOf(endTag, Qt::CaseInsensitive);

    if (-1 == startIndex || -1 == endIndex)
        result = "";
    else
    {
        startIndex += startTag.length();
        result = rawData.mid(startIndex, endIndex - startIndex);
    }

    return result;

}
