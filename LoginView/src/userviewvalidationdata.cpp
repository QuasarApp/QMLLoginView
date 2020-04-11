#include "userviewvalidationdata.h"

namespace LoginView {

enum class ValidationAddersses {
    Country                 = 0x01,
    FirstName               = 0x02,
    LastName                = 0x04,
    RawPassword             = 0x08,
    Email                   = 0x10
};

UserViewValidationData::UserViewValidationData() {
}

bool UserViewValidationData::country() const {
    return m_data & static_cast<int>(ValidationAddersses::Country);
}

bool UserViewValidationData::firstName() const {
    return m_data & static_cast<int>(ValidationAddersses::FirstName);
}

bool UserViewValidationData::lastName() const {
    return m_data & static_cast<int>(ValidationAddersses::LastName);
}

bool UserViewValidationData::rawPassword() const {
    return m_data & static_cast<int>(ValidationAddersses::RawPassword);
}

bool UserViewValidationData::email() const {
    return m_data & static_cast<int>(ValidationAddersses::Email);
}

void UserViewValidationData::setCountry(bool country) {
    m_data = static_cast<int>(ValidationAddersses::Country) & country;
}

void UserViewValidationData::setFirstName(bool firstName) {
    m_data = firstName;
}

void UserViewValidationData::setLastName(bool lastName) {
    m_data = lastName;
}

void UserViewValidationData::setRawPassword(bool rawPassword) {
    m_data = rawPassword;
}

void UserViewValidationData::setEmail(bool email) {
    m_data = email;
}

}
