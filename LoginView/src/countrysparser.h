#ifndef COUNTRYSPARSER_H
#define COUNTRYSPARSER_H

#include <QHash>

class QXmlStreamReader;

namespace LoginView {

class CountrysParser
{
public:
    CountrysParser();
    bool parseXMLSource(const QString &xmlFile, QHash<int, QString>& result);

private:
    bool isEndOf(QXmlStreamReader &xml, const QString& tag);
    bool isStartOf(QXmlStreamReader &xml, const QString& tag);
    int getCode(QXmlStreamReader &xml);
    QString getName(QXmlStreamReader &xml);
    bool parseCountry(QXmlStreamReader &xml, QHash<int, QString>& result);
    bool parseCountries(QXmlStreamReader &xml, QHash<int, QString>& result);
    bool isValidItem(QXmlStreamReader &xml);
};

}

#endif // COUNTRYSPARSER_H
