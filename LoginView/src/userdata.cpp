//#
//# Copyright (C) 2018-2020 Yankovich Andrei (EndrII).
//# Distributed under the lgplv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#

#include "userdata.h"
namespace LoginView {

UserData::UserData() {}

int UserData::country() const {
    return m_country;
}

QString UserData::firstName() const {
    return m_firstName;
}

QString UserData::lastName() const {
    return m_lastName;
}

QString UserData::rawPassword() const{
    return m_rawPassword;
}

QString UserData::email() const {
    return m_email;
}

void UserData::setCountry(int country) {
    m_country = country;
}

void UserData::setFirstName(const QString &firstName) {
    m_firstName = firstName;
}

void UserData::setLastName(const QString& lastName) {
    m_lastName = lastName;
}

void UserData::setRawPassword(const QString& rawPassword) {
    m_rawPassword = rawPassword;
}

void UserData::setEmail(const QString &email) {
    m_email = email;
}

bool operator !=(const UserData &left, const UserData &right) {
    return left.m_email != right.m_email ||
           left.m_country != right.m_country ||
           left.m_rawPassword != right.m_rawPassword ||
           left.m_firstName != right.m_firstName ||
           left.m_lastName != right.m_lastName;
}

bool operator ==(const UserData &left, const UserData &right) {
    return !(left != right);
}
}
