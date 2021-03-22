//#
//# Copyright (C) 2018-2021 Yankovich Andrei (EndrII).
//# Distributed under the lgplv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#

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
