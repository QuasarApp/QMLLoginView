//#
//# Copyright (C) 2018-2021 Yankovich Andrei (EndrII).
//# Distributed under the lgplv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#

#include "userviewvalidationdata.h"

namespace LoginView {

enum class ValidationAddersses {
    Country                 = 0x01,
    FirstName               = 0x02,
    LastName                = 0x04,
    RawPassword             = 0x08,
    Email                   = 0x10,
    Nickname                = 0x20

};

UserViewValidationData::UserViewValidationData() {
    m_data = static_cast<int>(ValidationAddersses::FirstName) |
            static_cast<int>(ValidationAddersses::Country) |
            static_cast<int>(ValidationAddersses::LastName) |
            static_cast<int>(ValidationAddersses::RawPassword) |
            static_cast<int>(ValidationAddersses::Nickname) |
            static_cast<int>(ValidationAddersses::Email);
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

bool UserViewValidationData::noError() const {
    return !m_data;
}

bool UserViewValidationData::nickname() const {
    return m_data & static_cast<int>(ValidationAddersses::Nickname);
}

bool operator !=(const UserViewValidationData &left,
                 const UserViewValidationData &right) {
    return left.m_data != right.m_data;
}

bool operator ==(const UserViewValidationData &left,
                 const UserViewValidationData &right) {
    return !(left != right);
}

void UserViewValidationData::setCountry(bool country) {
    m_data &= ~static_cast<int>(ValidationAddersses::Country);
    m_data |= (static_cast<int>(ValidationAddersses::Country) * (country & 0x01));
}

void UserViewValidationData::setFirstName(bool firstName) {
    m_data &= ~static_cast<int>(ValidationAddersses::FirstName);
    m_data |= (static_cast<int>(ValidationAddersses::FirstName) * (firstName & 0x01));
}

void UserViewValidationData::setLastName(bool lastName) {
    m_data &= ~static_cast<int>(ValidationAddersses::LastName);
    m_data |= (static_cast<int>(ValidationAddersses::LastName) * (lastName & 0x01));
}

void UserViewValidationData::setRawPassword(bool rawPassword) {
    m_data &= ~static_cast<int>(ValidationAddersses::RawPassword);
    m_data |= (static_cast<int>(ValidationAddersses::RawPassword) * (rawPassword & 0x01));
}

void UserViewValidationData::setEmail(bool email) {
    m_data &= ~static_cast<int>(ValidationAddersses::Email);
    m_data |= (static_cast<int>(ValidationAddersses::Email) * (email & 0x01));
}

void UserViewValidationData::setNickname(bool nickname) {
    m_data &= ~static_cast<int>(ValidationAddersses::Nickname);
    m_data |= (static_cast<int>(ValidationAddersses::Nickname) * (nickname & 0x01));
}

}
