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

/**
 * @brief The ShowExtraComponent enum
 * default Title | FirstName | LastName
 */
enum ShowExtraComponent {
    NoShow          = 0x00,
    Title           = 0x01,
    FirstName       = 0x02,
    LastName        = 0x04,
    EMail           = 0x08,
    Nickname        = 0x10,

    All             = EMail | Title | FirstName | LastName | Nickname
};

class LOGINVIEW_EXPORT LVMainModel: public QObject
{
    Q_OBJECT

    Q_PROPERTY(QStringList countryList READ countryList NOTIFY countryListChanged)
    Q_PROPERTY(QList<int> countryCodeList READ countryCodeList NOTIFY countryCodeListChanged)

    Q_PROPERTY(bool fTitle READ fTitle NOTIFY showChanged)
    Q_PROPERTY(bool fLastName READ fLastName NOTIFY showChanged)
    Q_PROPERTY(bool fFirstName READ fFirstName NOTIFY showChanged)
    Q_PROPERTY(bool fNickname READ fNickname NOTIFY showChanged)
    Q_PROPERTY(bool fEMail READ fEMail NOTIFY showChanged)

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


    ShowExtraComponent components() const;
    void setComponents(const ShowExtraComponent &components);

    bool fTitle() const;
    bool fFirstName() const;
    bool fLastName() const;
    bool fNickname() const;

    bool fEMail() const;

    /**
     * @brief clear - clear all data from view
     */
    void clear();

public slots:
    void setCountry(int country);

    /**
     * @brief setData set new data for view
     * @param data
     */
    void setData(const UserData &data);

signals:
    void countryChanged(int country);
    void countryListChanged();
    void countryCodeListChanged();

    /**
     * @brief sigLoginRequest
     * emited when user try login
     */
    void sigLoginRequest(const UserData&);

    /**
     * @brief sigRegisterRequest
     * emited when user try create new accaunt
     */
    void sigRegisterRequest(const UserData&);

    /**
     * @brief sigForgotPasswordRequest
     * emited when user forgot own password
     */
    void sigForgotPasswordRequest(const UserData&);

    /**
     * @brief sigShowTermOfUseRequest
     * emited when user click on "Show term of use" button
     */
    void sigShowTermOfUseRequest();


    void dataChanged(UserData data);
    void validDataChanged(UserViewValidationData validationData);
    void passwordErrorChanged(QString passwordError);

    /**
     * @brief showChanged - emited when show components changed
     * @param ftitle
     */
    void showChanged();
    void clearView();

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
    ShowExtraComponent _components = ShowExtraComponent::All;
};

}
#endif // LOGINVIEWMODEL_H
