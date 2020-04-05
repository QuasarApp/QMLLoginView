#include "loginviewmodel.h"
#include <QFile>
#include <QXmlStreamReader>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDebug>

LoginViewModel::LoginViewModel(const QString modelName, QObject *parent)
    : QObject(parent) {
    m_modelName = modelName;
}

int LoginViewModel::getCode(QXmlStreamReader &xml) {
    if (xml.tokenType() != QXmlStreamReader::StartElement)
        return -1;

    while (xml.readNext() != QXmlStreamReader::Characters && !xml.hasError());

    bool ok;
    int res = xml.text().toInt(&ok);

    if (ok)
        return res;

    return -1;
}

QString LoginViewModel::getName(QXmlStreamReader &xml) {
    if (xml.tokenType() != QXmlStreamReader::StartElement)
        return "";

    while (xml.readNext() != QXmlStreamReader::Characters && !xml.hasError());

    return xml.text().toString();
}

bool LoginViewModel::parseCountry(QXmlStreamReader& xml) {
    if (xml.tokenType() != QXmlStreamReader::StartElement)
        return "";

    int code = 0;
    QString name;
    while (!(xml.readNext() == QXmlStreamReader::EndElement && xml.name() == "country")) {
        if (xml.tokenType() == QXmlStreamReader::StartElement && xml.name() == "code") {
            code = getCode(xml);
            if (code < 0) {
                qDebug() << "error parse, code of country is invalid: line " << xml.lineNumber();
                return false;
            }
        } else if (xml.tokenType() == QXmlStreamReader::StartElement && xml.name() == "name") {
            name = getName(xml);
            if (name.isEmpty()) {
                qDebug() << "error parse, name of country is empty: line " << xml.lineNumber();
                return false;
            }
        }
    }

    m_countryList[code] = name;
    return true;
}

bool LoginViewModel::setCounrySource(const QString &path) {
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return false;
    }

    QXmlStreamReader xml(&file);

    m_countryList.clear();

    while (!xml.atEnd()) {

        if (xml.hasError()){
            qDebug() << "error parse file: line " << xml.lineNumber();
            file.close();
            return false;
        }

        QXmlStreamReader::TokenType token = xml.readNext();
        if (xml.name() == "countriyes" && token == QXmlStreamReader::EndElement) {
            break;
        }

        if (token == QXmlStreamReader::StartElement) {
            if (xml.name() == "country" && !parseCountry(xml)) {
                file.close();
                return false;
            }
        }
    }

    file.close();

    emit countryListChanged();
    return true;
}

bool LoginViewModel::init( QQmlApplicationEngine *engine) {
    if (!engine)
        return false;

    auto root = engine->rootContext();
    if (!root)
        return false;

    if (!root->contextProperty(m_modelName).isNull()) {
        qDebug() << m_modelName << " already used!";
        return false;
    }

    engine->addImportPath(":/");
    root->setContextProperty(m_modelName, this);
    return true;
}

int LoginViewModel::country() const {
    return m_country;
}

QStringList LoginViewModel::countryList() const {
    return m_countryList.values();
}

void LoginViewModel::setCountry(int country) {
    if (m_country == country)
        return;

    m_country = country;
    emit countryListChanged();
}

