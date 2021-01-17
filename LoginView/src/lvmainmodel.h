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

    /// Skip all validation of password
    NoValidation    = 0x00,
    /// Check size. Size must be large than 8 chars.
    Size8andMore    = 0x01,
    /// Check chars. Password must be contains a numbers.
    NumberChars     = 0x02,
    /// Check chars. Password must be contains small chars.
    LitinSmallChars = 0x04,
    /// Check chars. Password must be contains large chars.
    LatinLargeChars = 0x08,
    /// Check chars. Password must be contains extra chars. Example: (%.~*^#).
    ExtraChars      = 0x10
};

/**
 * @brief The ShowExtraComponent enum used for control of the components view.
 * default is All
 */
enum ShowExtraComponent {
    /// No show any componets.
    NoShow          = 0x00,
    /// Show Title of the qml page.
    Title           = 0x01,
    /// Show first name input widget.
    FirstName       = 0x02,
    /// Show last name input widget.
    LastName        = 0x04,
    /// Show email name input widget.
    EMail           = 0x08,
    /// Show nickname input widget.
    Nickname        = 0x10,
    /// Show password input widget.
    Password        = 0x20,
    /// Show register page.
    RegisterPage    = 0x40,
    /// Show login page.
    LoginPage       = 0x80,
    /// Show all widgets and pages.
    All             = EMail | Title | FirstName | LastName | Nickname | Password | RegisterPage | LoginPage
};

/**
 * @brief The LVMainModel class is main model of the qml login view.
 */
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
    Q_PROPERTY(QString acceptButtonText READ acceptButtonText WRITE setAcceptButtonText NOTIFY acceptButtonTextChanged)

public:
    explicit LVMainModel(const QString modelName,
                            QObject *parent = nullptr);
    ~LVMainModel();
    /**
     * @brief setCountriesSource This method sets path to xml source file and extract list of countrys
     * @param path This is path to xml sources of countries
     * @return true if the function finished successful
     */
    Q_INVOKABLE bool setCountriesSource(const QString &path);

    /**
     * @brief init - prepare all items for use on qml.
     * @param engine - current qml engine of application
     * @return true if the function finished successful
     */
    bool init(QQmlApplicationEngine *engine);

    /**
     * @brief country This method return current country id.
     * @return current country id.
     */
    int country() const;

    /**
     * @brief countryList This method retun list of availabel countries.
     * @return string list of available countries.
     */
    QStringList countryList() const;

    /**
     * @brief data This method return information of created or lofined user.
     * @return return information of created or lofined user.
     */
    UserData data() const;

    /**
     * @brief validData This method return structure that display valid data.
     * @return information about last validation.
     */
    UserViewValidationData validData() const;

    /**
     * @brief passwordError This method return text message about last password error.
     *  For get more information about password errors see the PasswordValidationLvl enum.
     * @return Error message.
     */
    QString passwordError() const;

    /**
     * @brief countryCodeList This method return the list of ids of the countries.
     * @return countries ids.
     */
    QList<int> countryCodeList() const;

    /**
     * @brief loginRequest This method invoked wjet user click the login button.
     */
    Q_INVOKABLE void loginRequest();

    /**
     * @brief rememberPasswordRequest This method invoked when user click the forgetpassword button.
     */
    Q_INVOKABLE void rememberPasswordRequest();

    /**
     * @brief registerRequest This method invoked when user click the signUp button.
     */
    Q_INVOKABLE void registerRequest();

    /**
     * @brief showTermOfUseRequest This method invoked when user click the "show temr of use" button.
     */
    Q_INVOKABLE void showTermOfUseRequest();

    /**
     * @brief components This method return visible comonents of this model.
     * @return return information about visible companents of Qml View. for more information see the ShowExtraComponent enum.
     */
    ShowExtraComponent components() const;

    /**
     * @brief setComponents This method sets visibel companents of the qml view.
     * @param components This is enum with visible companents. For get more information see Thee ShowExtraComponent enum class.
     */
    void setComponents(const ShowExtraComponent &components);

    /**
     * @brief fTitle This method return Title visible state.
     * @return Title visible state.
     */
    bool fTitle() const;

    /**
     * @brief fFirstName This method return first name visible state.
     * @return first name visible state.
     */
    bool fFirstName() const;

    /**
     * @brief fLastName This method return last name visible state.
     * @return last name visible state.
     */
    bool fLastName() const;

    /**
     * @brief fNickname This method return nickname visible state.
     * @return nickname visible state.
     */
    bool fNickname() const;

    /**
     * @brief fPassword This method return password visible state.
     * @return password visible state.
     */
    bool fPassword() const;

    /**
     * @brief fEMail This method return email visible state.
     * @return email visible state.
     */
    bool fEMail() const;

    /**
     * @brief fRegister This method return register page visible state.
     * @return register page visible state.
     */
    bool fRegister() const;

    /**
     * @brief fLogin This method return login page visible state.
     * @return login page visible state.
     */
    bool fLogin() const;
    /**
     * @brief clear - clear all data from view
     */
    void clear();

    /**
     * @brief acceptButtonText This method return alternative text of the accept button.
     * @return  alternative text of the accept button
     */
    QString acceptButtonText() const;

public slots:
    /**
     * @brief setCountry This slot sets current contry. This method work with qml View and invoked when user change own country.
     * @param country This is new country id.
     */
    void setCountry(int country);

    /**
     * @brief setData sets new data for view on qml page.
     * @param data new user data.
     */
    void setData(const UserData &data);

    /**
     * @brief setAcceptButtonText This method sets new test of the accept button. Use this method if you wnat change test on main button.
     * @param acceptButtonText new text of the accept button.
     */
    void setAcceptButtonText(const QString& acceptButtonText);

signals:
    /**
     * @brief countryChanged This signal emited when country on page is  will be changed.
     * @param country new country id.
     */
    void countryChanged(int country);

    /**
     * @brief countryListChanged This method emited when available country list will be changed.
     */
    void countryListChanged();

    /**
     * @brief countryCodeListChanged This method emited when available country list will be changed.
     */
    void countryCodeListChanged();

    /**
     * @brief sigLoginRequest
     * emited when user try login.
     */
    void sigLoginRequest(const UserData&);

    /**
     * @brief sigRegisterRequest
     * emited when user try create new accaunt.
     */
    void sigRegisterRequest(const UserData&);

    /**
     * @brief sigForgotPasswordRequest
     * emited when user forgot own password.
     */
    void sigForgotPasswordRequest(const UserData&);

    /**
     * @brief sigShowTermOfUseRequest
     * emited when user click on "Show term of use" button.
     */
    void sigShowTermOfUseRequest();

    /**
     * @brief dataChanged emited when data of qml form will be changed.
     * @param data new data of qml form.
     */
    void dataChanged(UserData data);

    /**
     * @brief validDataChanged This method emited when model is finished validation of the accepted user data.
     * @param validationData this is validation results.
     */
    void validDataChanged(UserViewValidationData validationData);

    /**
     * @brief passwordErrorChanged This method will be emoted when user password have a any error.
     * @param passwordError This is new erro message of user password.
     */
    void passwordErrorChanged(QString passwordError);

    /**
     * @brief showChanged This signal emited when rules of shows components will be changed
     */
    void showChanged();

    /**
     * @brief clearView This signal emited when need to clear a view. for more ifnformation see The clear method.
     */
    void clearView();

    /**
     * @brief acceptButtonTextChanged This signal emited when text of the accept button will be changed.
     * @param acceptButtonText Tihs is new test of the accept button.
     */
    void acceptButtonTextChanged(QString acceptButtonText);

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
    QString m_acceptButtonText;
};

}
#endif // LOGINVIEWMODEL_H
