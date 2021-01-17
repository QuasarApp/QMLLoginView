//#
//# Copyright (C) 2018-2020 Yankovich Andrei (EndrII).
//# Distributed under the lgplv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#

#ifndef USERVIEWVALIDATIONDATA_H
#define USERVIEWVALIDATIONDATA_H
#include "loginview_global.h"
#include <QObject>

namespace LoginView {

/**
 * @brief The UserViewValidationData class contains data of the last validation.
 */
class UserViewValidationData
{
    Q_GADGET
    Q_PROPERTY(bool country READ country WRITE setCountry)              // ValidationAddersses::Country
    Q_PROPERTY(bool firstName READ firstName WRITE setFirstName)        // ValidationAddersses::FirstName
    Q_PROPERTY(bool lastName READ lastName WRITE setLastName)           // ValidationAddersses::LastName
    Q_PROPERTY(bool rawPassword READ rawPassword WRITE setRawPassword)  // ValidationAddersses::RawPassword
    Q_PROPERTY(bool email READ email WRITE setEmail)                    // ValidationAddersses::Email
    Q_PROPERTY(bool nickname READ nickname WRITE setNickname)           // ValidationAddersses::nickname
    Q_PROPERTY(bool noError READ noError)

public:
    UserViewValidationData();
    /**
     * @return true if member has error
     */
    bool country() const;
    bool firstName() const;
    bool lastName() const;
    bool rawPassword() const;
    bool email() const;

    friend bool operator !=(const UserViewValidationData &left,
                            const UserViewValidationData &right);
    friend bool operator ==(const UserViewValidationData &left,
                            const UserViewValidationData &right);

    bool noError() const;
    bool nickname() const;

public slots:
    void setCountry(bool country);
    void setFirstName(bool firstName);
    void setLastName(bool lastName);
    void setRawPassword(bool rawPassword);
    void setEmail(bool email);

    void setNickname(bool nickname);

private:
    int m_data;
};
}

#endif // USERVIEWVALIDATIONDATA_H
