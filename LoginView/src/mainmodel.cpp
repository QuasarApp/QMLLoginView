#include "countrysparser.h"
#include "mainmodel.h"
#include <QXmlStreamReader>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDebug>

namespace LoginView {


MainModel::MainModel(const QString modelName, QObject *parent)
    : QObject(parent) {
    m_modelName = modelName;
}

MainModel::~MainModel() {
    if (m_countrysParser) {
        delete m_countrysParser;
    }
}

bool MainModel::setCounrySource(const QString &path) {

    if (!m_countrysParser) {
        m_countrysParser = new CountrysParser();
    }

    m_countrysParser->parseXMLSource(path, m_countryList);

    emit countryListChanged();
    return true;
}

bool MainModel::init( QQmlApplicationEngine *engine) {
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

int MainModel::country() const {
    return m_country;
}

QStringList MainModel::countryList() const {
    return m_countryList.values();
}

UserData MainModel::data() const {
    return m_data;
}

void MainModel::setCountry(int country) {
    if (m_country == country)
        return;

    m_country = country;
    emit countryListChanged();
}

void MainModel::setData(UserData data) {
    if (m_data == data)
        return;

    m_data = data;
    emit dataChanged(m_data);
}

bool MainModel::isValidData(const UserData& data) {


    return true;
}

}
