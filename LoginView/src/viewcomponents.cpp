#include "viewcomponents.h"

namespace LoginView {


int ViewComponentsQML::noShow() const
{
    return ViewComponents::NoShow;
}

int ViewComponentsQML::title() const
{
    return ViewComponents::Title;
}

int ViewComponentsQML::firstName() const
{
    return ViewComponents::FirstName;
}

int ViewComponentsQML::lastName() const
{
    return ViewComponents::LastName;
}

int ViewComponentsQML::eMail() const
{
    return ViewComponents::EMail;
}

int ViewComponentsQML::nickname() const
{
    return ViewComponents::Nickname;
}

int ViewComponentsQML::password() const
{
    return ViewComponents::Password;
}

int ViewComponentsQML::sigupPage() const
{
    return ViewComponents::SigupPage;
}

int ViewComponentsQML::loginPage() const
{
    return ViewComponents::LoginPage;
}

int ViewComponentsQML::termOfUse() const
{
    return ViewComponents::TermOfUse;
}
}
