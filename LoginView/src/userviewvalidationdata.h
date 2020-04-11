#ifndef USERVIEWVALIDATIONDATA_H
#define USERVIEWVALIDATIONDATA_H
#include "loginview_global.h"
#include <QObject>

namespace LoginView {

class UserViewValidationData
{
    Q_GADGET
    Q_PROPERTY(bool country READ country WRITE setCountry)              // ValidationAddersses::Country
    Q_PROPERTY(bool firstName READ firstName WRITE setFirstName)        // ValidationAddersses::FirstName
    Q_PROPERTY(bool lastName READ lastName WRITE setLastName)           // ValidationAddersses::LastName
    Q_PROPERTY(bool rawPassword READ rawPassword WRITE setRawPassword)  // ValidationAddersses::RawPassword
    Q_PROPERTY(bool email READ email WRITE setEmail)                    // ValidationAddersses::Email

public:
    UserViewValidationData();
    bool country() const;
    bool firstName() const;
    bool lastName() const;
    bool rawPassword() const;
    bool email() const;

public slots:
    void setCountry(bool country);

    void setFirstName(bool firstName);

    void setLastName(bool lastName);

    void setRawPassword(bool rawPassword);

    void setEmail(bool email);

private:
    int m_data;
};
}
#endif // USERVIEWVALIDATIONDATA_H
