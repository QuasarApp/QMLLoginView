//#
//# Copyright (C) 2020-2021 Yankovich Andrei (EndrII).
//# Distributed under the lgplv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#

#ifndef VIEWCOMPONENTS_H
#define VIEWCOMPONENTS_H
#include <QObject>

namespace LoginView {

/**
 * @brief The ViewComponents enum used for control of the components view.
 * default is All
 */
enum ViewComponents {
    /// No show any componets.
    NoShow          = 0x0000,
    /// Show Title of the qml page.
    Title           = 0x0001,
    /// Show first name input widget.
    FirstName       = 0x0002,
    /// Show last name input widget.
    LastName        = 0x0004,
    /// Show email name input widget.
    EMail           = 0x0008,
    /// Show nickname input widget.
    Nickname        = 0x0010,
    /// Show password input widget.
    Password        = 0x0020,
    /// Show register page.
    SigupPage    = 0x0040,
    /// Show login page.
    LoginPage       = 0x0080,
    /// Show term of use button and accept term of use checkbox.
    TermOfUse       = 0x0100,
    /// Show only one input widget with name.
    RegNameOnly     = Title | Nickname | SigupPage,

    /// Show all widgets and pages.
    All             = EMail | Title | FirstName | LastName | Nickname | Password | SigupPage | LoginPage | TermOfUse
};

/**
 * @brief The ViewComponentsQML class This is qml implementation of the ViewComponents enum.
 */
class ViewComponentsQML
{
    Q_GADGET
    Q_PROPERTY(int noShow READ noShow)
    Q_PROPERTY(int title READ title)
    Q_PROPERTY(int firstName READ firstName)
    Q_PROPERTY(int lastName READ lastName)
    Q_PROPERTY(int eMail READ eMail)
    Q_PROPERTY(int nickname READ nickname)
    Q_PROPERTY(int password READ password)
    Q_PROPERTY(int sigupPage READ sigupPage)
    Q_PROPERTY(int loginPage READ loginPage)
    Q_PROPERTY(int termOfUse READ termOfUse)

public:
    ViewComponentsQML() = default;

    int noShow() const;
    int title() const;
    int firstName() const;
    int lastName() const;
    int eMail() const;
    int nickname() const;
    int password() const;
    int sigupPage() const;
    int loginPage() const;
    int termOfUse() const;
};

}

Q_DECLARE_METATYPE(LoginView::ViewComponentsQML)
#endif // VIEWCOMPONENTS_H
