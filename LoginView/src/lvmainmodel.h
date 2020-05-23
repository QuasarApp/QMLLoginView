//#
//# Copyright (C) 2018-2020 Yankovich Andrei (EndrII).
//# Distributed under the lgplv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#


#ifndef LOGINVIEWMODEL_H
#define LOGINVIEWMODEL_H

#include <QHash>
#include <QObject>
#include "loginview_global.h"

#include "userdata.h"
#include "userviewvalidationdata.h"

class QXmlStreamReader;
class QQmlApplicationEngine;
class CountrysParser;

namespace LoginView {

/**
 * @brief The PasswordValidationLvl enum
 * This is lvl of validation password
 * by default: Size8andMore | LitinSmallChars | LatinLargeChars
 */
enum PasswordValidationLvl {
    NoValidation    = 0x00,
    Size8andMore    = 0x01,
    NumberChars     = 0x02,
    LitinSmallChars = 0x04,
    LatinLargeChars = 0x08,
    ExtraChars      = 0x10
};

class LOGINVIEW_EXPORT LVMainModel: public QObject
{
    Q_OBJECT

    Q_PROPERTY(QStringList countryList READ countryList NOTIFY countryListChanged)
    Q_PROPERTY(QList<int> countryCodeList READ countryCodeList NOTIFY countryCodeListChanged)

    Q_PROPERTY(int country READ country WRITE setCountry NOTIFY countryChanged)
    Q_PROPERTY(UserData data READ data WRITE setData NOTIFY dataChanged)
    Q_PROPERTY(UserViewValidationData validationData READ validData WRITE setValidData NOTIFY validDataChanged)
    Q_PROPERTY(QString passwordError READ passwordError WRITE setPasswordError NOTIFY passwordErrorChanged)

public:
    explicit LVMainModel(const QString modelName,
                            QObject *parent = nullptr);
    ~LVMainModel();
    /**
     * @brief setCounrySource - sets path to xml source file and extract list of countrys
     * @param path
     * @return true if the function finished successful
     */
    Q_INVOKABLE bool setCounrySource(const QString &path);

    /**
     * @brief init - prepare all items for use on qml.
     * @param engine - current qml engine of application
     * @return true if the function finished successful
     */
    bool init(QQmlApplicationEngine *engine);
    int country() const;
    QStringList countryList() const;
    UserData data() const;
    UserViewValidationData validData() const;
    QString passwordError() const;
    QList<int> countryCodeList() const;

    Q_INVOKABLE void loginRequest();
    Q_INVOKABLE void rememberPasswordRequest();
    Q_INVOKABLE void registerRequest();
    Q_INVOKABLE void showTermOfUseRequest();


public slots:
    void setCountry(int country);
    void setData(UserData data);

signals:
    void countryChanged(int country);
    void countryListChanged();
    void countryCodeListChanged();

    /**
     * @brief sigLoginRequest
     * emited when user try login
     */
    void sigLoginRequest(UserData);

    /**
     * @brief sigRegisterRequest
     * emited when user try create new accaunt
     */
    void sigRegisterRequest(UserData);

    /**
     * @brief sigForgotPasswordRequest
     * emited when user forgot own password
     */
    void sigForgotPasswordRequest(UserData);

    /**
     * @brief sigShowTermOfUseRequest
     * emited when user click on "Show term of use" button
     */
    void sigShowTermOfUseRequest();


    void dataChanged(UserData data);
    void validDataChanged(UserViewValidationData validationData);
    void passwordErrorChanged(QString passwordError);

private:
    void checkValid(const UserData &data);
    void setValidData(UserViewValidationData validationData);
    void setPasswordError(QString passwordError);

    CountrysParser *m_countrysParser = nullptr;
    QString m_modelName;
    int m_country;
    QHash<int, QString> m_countryList;
    UserData m_data;
    PasswordValidationLvl m_validLvl;

    UserViewValidationData m_validationData;
    QString m_passwordError;
};

}
#endif // LOGINVIEWMODEL_H
