//#
//# Copyright (C) 2018-2021 Yankovich Andrei (EndrII).
//# Distributed under the lgplv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#

#include "countrysparser.h"
#include "QDebug"
#include <QFile>
#include <QXmlStreamReader>
namespace LoginView {

CountrysParser::CountrysParser() {

}

bool CountrysParser::isValidItem(QXmlStreamReader &xml) {
    if (xml.error() != QXmlStreamReader::NoError) {
        qDebug() << xml.errorString() << " in line: " << xml.lineNumber();
        return false;
    }

    return true;
}

bool CountrysParser::parseXMLSource(const QString &xmlFile, QHash<int, QString> &result) {
    QFile file(xmlFile);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return false;
    }

    QXmlStreamReader xml(&file);

    result.clear();
    bool success = false;
    while (!xml.atEnd()) {
        auto token = xml.readNext();

        if (!isValidItem(xml)) {
            break;
        }

        if (token == QXmlStreamReader::StartElement && xml.name() == QString("countries")) {
            success = parseCountries(xml, result);
            break;
        }
    }

    file.close();
    return success;
}

int CountrysParser::getCode(QXmlStreamReader &xml) {
    if (xml.tokenType() != QXmlStreamReader::StartElement)
        return -1;

    while (xml.readNext() != QXmlStreamReader::Characters && !xml.hasError());

    bool ok;
    int res = xml.text().toInt(&ok);

    if (ok)
        return res;

    return -1;
}

QString CountrysParser::getName(QXmlStreamReader &xml) {
    if (xml.tokenType() != QXmlStreamReader::StartElement)
        return "";

    while (xml.readNext() != QXmlStreamReader::Characters && !xml.hasError());

    return xml.text().toString();
}

bool CountrysParser::parseCountry(QXmlStreamReader& xml, QHash<int, QString>& result) {
    if (xml.tokenType() != QXmlStreamReader::StartElement)
        return false;

    int code = 0;
    QString name;
    while (!(xml.readNext() == QXmlStreamReader::EndElement && xml.name() == QString("country"))) {

        if (!isValidItem(xml)) {
            return false;
        }

        if (xml.tokenType() == QXmlStreamReader::StartElement && xml.name() == QString("code")) {
            code = getCode(xml);
            if (code < 0) {
                qDebug() << "error parse, code of country is invalid: line "
                         << xml.lineNumber();
                return false;
            }
        } else if (xml.tokenType() == QXmlStreamReader::StartElement && xml.name() == QString("name")) {
            name = getName(xml);
            if (name.isEmpty()) {
                qDebug() << "error parse, name of country is empty: line "
                         << xml.lineNumber();
                return false;
            }
        }
    }

    result[code] = name;
    return true;
}

bool CountrysParser::parseCountries(QXmlStreamReader &xml, QHash<int, QString>& result) {

    if (xml.tokenType() != QXmlStreamReader::StartElement)
        return false;

    while (!(xml.readNext() == QXmlStreamReader::EndElement && xml.name() == QString("countries"))) {

        if (!isValidItem(xml)) {
            return false;
        }

        if (xml.tokenType() == QXmlStreamReader::StartElement && xml.name() == QString("country") && !parseCountry(xml, result)) {
            return false;
        }
    }

    return true;
}

}
