#ifndef USERDATA_H
#define USERDATA_H
#include <QObject>
#include "loginview_global.h"

namespace LoginView {

class LOGINVIEW_EXPORT UserData
{
    Q_GADGET
    Q_PROPERTY(int country READ country WRITE setCountry)
    Q_PROPERTY(QString firstName READ firstName WRITE setFirstName)
    Q_PROPERTY(QString lastName READ lastName WRITE setLastName)
    Q_PROPERTY(QString rawPassword READ rawPassword WRITE setRawPassword)
    Q_PROPERTY(QString email READ email WRITE setEmail)

public:
    UserData();

    int country() const;
    QString firstName() const;
    QString lastName() const;
    QString rawPassword() const;
    QString email() const;
    friend bool operator !=(const UserData& left, const UserData& right);
    friend bool operator ==(const UserData& left, const UserData& right);


public slots:
    void setCountry(int country);
    void setFirstName(const QString& firstName);
    void setLastName(const QString& lastName);
    void setRawPassword(const QString& rawPassword);
    void setEmail(const QString& email);

private:
    int m_country;
    QString m_firstName;
    QString m_lastName;
    QString m_rawPassword;
    QString m_email;
};

}
#endif // USERDATA_H
