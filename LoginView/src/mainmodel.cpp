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
    m_validLvl = static_cast<PasswordValidationLvl>(
                PasswordValidationLvl::Size8andMore |
                PasswordValidationLvl::LitinSmallChars |
                PasswordValidationLvl::LatinLargeChars);
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
    emit countryCodeListChanged();
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

    qRegisterMetaType<LoginView::UserData>("UserData");
    qRegisterMetaType<LoginView::UserViewValidationData>("UserViewValidationData");

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

UserViewValidationData MainModel::validData() const {
    return m_validationData;
}

QString MainModel::passwordError() const {
    return m_passwordError;
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
    checkValid(data);
    emit dataChanged(m_data);
}

void MainModel::setPasswordError(QString passwordError) {
    if (m_passwordError == passwordError)
        return;

    m_passwordError = passwordError;
    emit passwordErrorChanged(m_passwordError);
}

void MainModel::setValidData(UserViewValidationData validationData) {
    if (m_validationData == validationData)
        return;

    m_validationData = validationData;

    QString temp;
    if (m_validLvl & PasswordValidationLvl::Size8andMore) {
        temp += tr("must be longer than 8 characters");
    }

    if (m_validLvl & PasswordValidationLvl::NumberChars) {
        temp += ((!temp.isEmpty())? ", ": "") + tr("must contain numbers");
    }

    if (m_validLvl & PasswordValidationLvl::LitinSmallChars) {
        temp += ((!temp.isEmpty())? ", ": "") + tr("must contain small chars");
    }

    if (m_validLvl & PasswordValidationLvl::LatinLargeChars) {
        temp += ((!temp.isEmpty())? ", ": "") + tr("must contain large chars");
    }

    if (m_validLvl & PasswordValidationLvl::ExtraChars) {
        temp += ((!temp.isEmpty())? ", ": "") + tr("must contain extra chars (!@#$%^&*)");
    }

    setPasswordError((temp.isEmpty())? "": tr("Password requirements: ") + temp);

    emit validDataChanged(m_validationData);
}

void MainModel::checkValid(const UserData& data) {

    UserViewValidationData result;

    result.setEmail(!data.email().contains(QRegExp("^([a-zA-Z0-9_\-\.]+)@([a-zA-Z0-9_\-\.]+)\.([a-zA-Z]{2,5})$")));
    result.setCountry(!m_countryList.contains(data.country()));
    result.setLastName(false);
    result.setFirstName(data.firstName().contains(" ") || data.firstName().isEmpty());

    bool passwordValidation = true;

    if (m_validLvl & PasswordValidationLvl::Size8andMore) {
        passwordValidation = passwordValidation &&
                data.rawPassword().length() >= 8;
    }

    if (m_validLvl & PasswordValidationLvl::NumberChars) {
        passwordValidation = passwordValidation &&
                data.rawPassword().contains(QRegExp("[0-9]"));
    }

    if (m_validLvl & PasswordValidationLvl::LitinSmallChars) {
        passwordValidation = passwordValidation &&
                data.rawPassword().contains(QRegExp("[a-z]"));
    }

    if (m_validLvl & PasswordValidationLvl::LatinLargeChars) {
        passwordValidation = passwordValidation &&
                data.rawPassword().contains(QRegExp("[A-Z]"));
    }

    if (m_validLvl & PasswordValidationLvl::ExtraChars) {
        passwordValidation = passwordValidation &&
                data.rawPassword().contains(QRegExp("[!@#$%^&*]"));
    }

    result.setRawPassword(!passwordValidation);

    setValidData(result);
}

QList<int> LoginView::MainModel::countryCodeList() const {
    return m_countryList.keys();
}

void MainModel::loginRequest() {
    if (!m_validationData.email()) {
        emit sigLoginRequest(m_data);
    }
}

void MainModel::rememberPasswordRequest() {
    if (!m_validationData.email()) {
        emit sigForgotPasswordRequest(m_data);
    }
}

void MainModel::registerRequest() {
    if (m_validationData.noError()) {
        emit sigRegisterRequest(m_data);
    }
}

void MainModel::showTermOfUseRequest() {
    emit sigShowTermOfUseRequest();
}

}
