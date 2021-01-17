//#
//# Copyright (C) 2018-2020 Yankovich Andrei (EndrII).
//# Distributed under the lgplv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#

#ifndef LV_USERDATA_H
#define LV_USERDATA_H
#include <QObject>
#include "loginview_global.h"

namespace LoginView {

/**
 * @brief The UserData class This is base class for save user data.
 */
class LOGINVIEW_EXPORT UserData
{
    Q_GADGET
    Q_PROPERTY(int country READ country WRITE setCountry)
    Q_PROPERTY(QString firstName READ firstName WRITE setFirstName)
    Q_PROPERTY(QString lastName READ lastName WRITE setLastName)
    Q_PROPERTY(QString rawPassword READ rawPassword WRITE setRawPassword)
    Q_PROPERTY(QString email READ email WRITE setEmail)
    Q_PROPERTY(QString nickname READ nickname WRITE setNickname)

public:
    UserData();

    int country() const;
    QString firstName() const;
    QString lastName() const;
    QString rawPassword() const;
    QString email() const;
    friend bool operator !=(const UserData& left, const UserData& right);
    friend bool operator ==(const UserData& left, const UserData& right);

    QString nickname() const;

public slots:
    void setCountry(int country);
    void setFirstName(const QString& firstName);
    void setLastName(const QString& lastName);
    void setRawPassword(const QString& rawPassword);
    void setEmail(const QString& email);

    void setNickname(const QString &nickname);

private:
    int m_country;
    QString m_firstName;
    QString m_lastName;
    QString m_rawPassword;
    QString m_email;

    QString m_nickname;
};

}
#endif // LV_USERDATA_H
