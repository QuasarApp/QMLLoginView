#include "countrysparser.h"
#include "loginviewmodel.h"
#include <QXmlStreamReader>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDebug>

LoginViewModel::LoginViewModel(const QString modelName, QObject *parent)
    : QObject(parent) {
    m_modelName = modelName;
}

LoginViewModel::~LoginViewModel() {
    if (m_countrysParser) {
        delete m_countrysParser;
    }
}

bool LoginViewModel::setCounrySource(const QString &path) {

    if (!m_countrysParser) {
        m_countrysParser = new CountrysParser();
    }

    m_countrysParser->parseXMLSource(path, m_countryList);

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

