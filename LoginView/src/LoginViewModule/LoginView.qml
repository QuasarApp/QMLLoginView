//#
//# Copyright (C) 2018-2021 Yankovich Andrei (EndrII).
//# Distributed under the lgplv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#

import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls.Material 2.15
import QtQuick.Controls.Universal 2.15

Page {

    id: root;

    header: LVMHeader{
        id: header
        withTitle: privateRoot.withTitle
        title: (privateRoot.isRegisterNewUser)? qsTr("Create a new account"): qsTr("LogIn")
        help: (privateRoot.isRegisterNewUser)? qsTr('Please fill this form to create an account'):
                                             qsTr('Please fill this form to login in your account')
    }

    property var lognViewModel: null

    signal loginClicked(var isregister);

    function clear() {

        countryInput.currentIndex = -1
        pass1.text = ""
        pass2.text = ""
        termOfUse.checked = false
    }

    Connections {
        target: lognViewModel
        function clearView () {
            clear();
        }
    }

    leftPadding: 0
    rightPadding: 0

    Flickable {
        contentWidth: content.width
        contentHeight: content.height
        clip: true
        ScrollBar.vertical: ScrollBar { policy: ScrollBar.AsNeeded }
        ScrollBar.horizontal: ScrollBar { policy: ScrollBar.AsNeeded }
        GridLayout {
            id: content

            columns: Math.floor(root.width / childWidth)
            width: root.width
            columnSpacing: 15
            rowSpacing: 0
            property int childWidth: firstNameInput.height * 4

            LVMTextInput {
                id: firstNameInput
                placeholderText: qsTr("First Name")
                Layout.fillWidth: true
                visible: privateRoot.isRegisterNewUser && privateRoot.firstName
                tooltip: (hasError)? qsTr("Empy or incorrect name. Please enter your name."):  ""
                hasError: (privateRoot.errors && privateRoot.errors.firstName);
                onTextChanged: {
                    if (lognViewModel) {
                        lognViewModel.data.firstName = text;
                    }
                    hasEdited = true
                }
                text: (lognViewModel)? lognViewModel.data.firstName: "";

            }

            LVMTextInput {
                id: lastNameInput

                placeholderText: qsTr("Last Name")
                Layout.fillWidth: true
                visible: privateRoot.isRegisterNewUser && privateRoot.lastName
                hasError: (privateRoot.errors && privateRoot.errors.lastName);

                onTextChanged: {
                    if (lognViewModel) {
                        lognViewModel.data.lastName = text;
                    }
                    hasEdited = true

                }
                text: (lognViewModel)? lognViewModel.data.lastName: "";


            }

            Item {
                // separator
                Layout.preferredHeight: 0
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                Layout.columnSpan: Math.max(content.columns, 1)
            }

            LVMComboBox {
                id: countryInput

                placeholderText: qsTr("Select you country")
                Layout.fillWidth: true
                visible: privateRoot.isRegisterNewUser && model.length
                onCurrentIndexChanged: {
                    if (lognViewModel) {
                        lognViewModel.data.country = lognViewModel.countryCodeList[currentIndex];
                    }
                }

            }

            Item {
                // separator
                Layout.preferredHeight: 0
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                Layout.columnSpan: Math.max(content.columns, 1)
            }


            LVMTextInput {
                id: emailInput

                placeholderText: qsTr("EMail")
                Layout.fillWidth: true
                visible: privateRoot.email
                hasError: (privateRoot.errors && privateRoot.errors.email);
                tooltip: (hasError)? qsTr("Empty or incorrect email address. Please enter your name.") : ""
                onTextChanged: {
                    if (lognViewModel) {
                        lognViewModel.data.email = text;
                    }
                    hasEdited = true

                }
                text: (lognViewModel)?lognViewModel.data.email: "";

            }

            LVMTextInput {
                id: nicknameInput

                placeholderText: qsTr("Nickname")
                Layout.fillWidth: true
                visible:  privateRoot.nickName
                hasError: (privateRoot.errors && privateRoot.errors.nickname);
                tooltip: (hasError)? qsTr("Empty or incorrect Nickname. Please enter your name.") : ""
                onTextChanged: {
                    if (lognViewModel) {
                        lognViewModel.data.nickname = text;
                    }
                    hasEdited = true

                }

                text: (lognViewModel)? lognViewModel.data.nickname: "";

            }

            Item {
                // separator
                Layout.preferredHeight: 0
                Layout.fillWidth: true
                Layout.columnSpan: Math.max(content.columns, 1)
            }

            LVMTextInput {
                id: pass1
                placeholderText: qsTr("password")
                Layout.fillWidth: true
                hasError: (privateRoot.errors && privateRoot.errors.rawPassword);
                tooltip: (hasError)? lognViewModel.passwordError : ""
                onTextChanged: {
                    privateRoot.paswordValidation()
                }
                visible: privateRoot.password

                echoMode: TextInput.Password
            }

            LVMTextInput {
                id: pass2
                placeholderText: qsTr("Confirm password")
                Layout.fillWidth: true
                visible: privateRoot.isRegisterNewUser && privateRoot.password

                onTextChanged: {
                    privateRoot.paswordValidation()
                }
                echoMode: TextInput.Password

            }

            LVMButton {
                text: qsTr("Forgot password")
                visible: !privateRoot.isRegisterNewUser
                enabled: !(privateRoot.errors && privateRoot.errors.email)

                onClicked: {
                    if (lognViewModel) {
                        lognViewModel.rememberPasswordRequest();
                    }
                }
            }

            Item {
                // separator
                Layout.preferredHeight: 0
                Layout.fillWidth: true

                Layout.columnSpan: Math.max(content.columns, 1)
            }

            LVMCheckBox {
                id: termOfUse
                text: qsTr("I accept the Terms of use")
                Layout.fillWidth: true
                visible:privateRoot.isRegisterNewUser && privateRoot.termOfuse

            }

            LVMButton {
                text: qsTr("Show terms of use")
                visible: privateRoot.isRegisterNewUser && privateRoot.termOfuse
                onClicked: {
                    if (lognViewModel) {
                        lognViewModel.showTermOfUseRequest();
                    }
                }
            }

            Item {
                // separator
                Layout.preferredHeight: 0
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.columnSpan: Math.max(content.columns, 1)
            }

        }

        anchors.fill: parent
    }


    footer: ColumnLayout {
        LVMButton {
            text: privateRoot.acceptButtonText.length?
                      privateRoot.acceptButtonText:
                      (privateRoot.isRegisterNewUser)?
                          qsTr("SignUp"):
                          qsTr("LogIn")

            visible: true
            enabled: privateRoot.enableAccept(privateRoot.errors, privateRoot.isRegisterNewUser,
                                              privateRoot.password, pass2.hasError, termOfUse.checked,
                                              privateRoot.termOfuse)
            onClicked: {
                if (lognViewModel) {
                    if (privateRoot.isRegisterNewUser) {
                        lognViewModel.registerRequest();
                    } else {
                        lognViewModel.loginRequest();
                    }
                }
                loginClicked(privateRoot.isRegisterNewUser);
            }
        }

        TabBar {
                id: tabBar

                visible: privateRoot.loginPage && privateRoot.registerPage
                Layout.fillWidth: true
                currentIndex: privateRoot.pageToIndex(privateRoot.currentPage)
                TabButton {
                    text: qsTr("Login In")
                }
                TabButton {
                    text: qsTr("Sign Up")
                }

                onCurrentIndexChanged: {
                    if (lognViewModel) {
                        if (currentIndex)
                            lognViewModel.setCurrentPage(ViewComponents.sigupPage)
                        else
                            lognViewModel.setCurrentPage(ViewComponents.loginPage)

                    }
                }
            }
    }


    Item {
        id: privateRoot;

        // Private propertyes
        property bool isRegisterNewUser: pageSelector(tabBar.currentIndex, registerPage, loginPage)
        property var errors: (lognViewModel)? lognViewModel.validationData : null
        property bool withTitle: (lognViewModel)? lognViewModel.fTitle: false
        property bool lastName: (lognViewModel)? lognViewModel.fLastName: false
        property bool firstName: (lognViewModel)? lognViewModel.fFirstName: false
        property bool nickName: (lognViewModel)? lognViewModel.fNickname: false
        property bool email: (lognViewModel)? lognViewModel.fEMail: false
        property bool password: (lognViewModel)? lognViewModel.fPassword: false
        property bool loginPage: (lognViewModel)? lognViewModel.fLogin: false
        property bool registerPage: (lognViewModel)? lognViewModel.fRegister: false
        property bool termOfuse: (lognViewModel)? lognViewModel.fTermOfUse: false
        property int currentPage: (lognViewModel)? lognViewModel.currentPage: 0

        property string acceptButtonText: (lognViewModel)? lognViewModel.acceptButtonText: false

        property int widgetsCount: lastName + firstName + nickName + email + password + withTitle

        function pageSelector(toolBarIndex, registerPage, loginPage) {
            if (registerPage && loginPage)
                return toolBarIndex;

            return registerPage;
        }

        function pageToIndex(currentPage) {
            return currentPage === ViewComponents.sigupPage
        }

        function paswordValidation() {
            if (lognViewModel) {
                lognViewModel.data.rawPassword = pass1.text;
            }
            pass1.hasEdited = true

            if (!privateRoot.isRegisterNewUser) {
                return;
            }

            pass2.hasError = false;
            pass2.tooltip = "";

            if (pass1.text != pass2.text || pass1.length <= 0) {
                pass2.hasError = true;
                pass2.hasEdited = true;
                pass2.tooltip = qsTr("Password must match the 1st field and the password cannot be empty");
            }
        }

        function enableAccept(errors, isRegisterNewUser, fShowPassword,
                              passHasError, termOfUse, fShowTermOfUse) {

            if (!(errors && errors.noError)) {
                return false;
            }

            if (isRegisterNewUser && fShowPassword) {
                return !passHasError && (termOfUse || !fShowTermOfUse)
            }

            return true;
        }
    }
}
