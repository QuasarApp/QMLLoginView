//#
//# Copyright (C) 2018-2020 Yankovich Andrei (EndrII).
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
    height: 500
    width: 400

    header: LVMHeader{
        id: header
        withTitle: root.withTitle
        title: (conntent.isRegisterNewUser)? qsTr("SignUp"): qsTr("LogIn")
        help: (conntent.isRegisterNewUser)? qsTr('Please fill this form to create an account'):
                                             qsTr('Please fill this form to login in your account')
    }
    property bool withTitle: (lognViewModel)? lognViewModel.fTitle: false
    property bool lastName: (lognViewModel)? lognViewModel.fLastName: false
    property bool firstName: (lognViewModel)? lognViewModel.fFirstName: false
    property bool nickName: (lognViewModel)? lognViewModel.fNickname: false
    property bool email: (lognViewModel)? lognViewModel.fEMail: false

    property var lognViewModel: null
    property bool registerNewUser: true
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

    contentItem:
        Item {
        id: conntent
        property bool isRegisterNewUser: tabBar.currentIndex
        property var errors: (lognViewModel)? lognViewModel.validationData : null

        GridLayout {

            rows: 8
            columns: 2
            rowSpacing: 15
            columnSpacing: 15

            id: content

            function paswordValidation() {
                if (lognViewModel) {
                    lognViewModel.data.rawPassword = pass1.text;
                }
                pass1.hasEdited = true

                if (!conntent.isRegisterNewUser) {
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

            LVMTextInput {
                id: firstNameInput
                placeholderText: qsTr("First Name")
                Layout.columnSpan: (content.width > 350)? 1 : 2;
                Layout.fillWidth: true
                visible: conntent.isRegisterNewUser && root.firstName
                tooltip: (hasError)? qsTr("Empy or incorrect name. Please enter yuor name."):  ""
                hasError: (conntent.errors && conntent.errors.firstName);
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
                Layout.columnSpan: (content.width > 350)? 1 : 2;
                Layout.fillWidth: true
                visible: conntent.isRegisterNewUser && root.lastName
                hasError: (conntent.errors && conntent.errors.lastName);

                onTextChanged: {
                    if (lognViewModel) {
                        lognViewModel.data.lastName = text;
                    }
                    hasEdited = true

                }
                text: (lognViewModel)? lognViewModel.data.lastName: "";


            }

            LVMComboBox {
                id: countryInput

                placeholderText: qsTr("Select you country")
                Layout.columnSpan: 2
                Layout.fillWidth: true
                visible: conntent.isRegisterNewUser && model.length
                onCurrentIndexChanged: {
                    if (lognViewModel) {
                        lognViewModel.data.country = lognViewModel.countryCodeList[currentIndex];
                    }
                }

            }

            LVMTextInput {
                id: emailInput

                placeholderText: qsTr("EMail")
                Layout.columnSpan: (root.email && root.nickName)? (content.width > 350)? 1 : 2 : 2;
                Layout.fillWidth: true
                visible: root.email
                hasError: (conntent.errors && conntent.errors.email);
                tooltip: (hasError)? qsTr("Empty or incorrect email address. Please enter yuor name.") : ""
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
                Layout.columnSpan: (root.email && root.nickName)? (content.width > 350)? 1 : 2 : 2;
                Layout.fillWidth: true
                visible:  root.nickName
                hasError: (conntent.errors && conntent.errors.nickname);
                tooltip: (hasError)? qsTr("Empty or incorrect Nickname. Please enter yuor name.") : ""
                onTextChanged: {
                    if (lognViewModel) {
                        lognViewModel.data.nickname = text;
                    }
                    hasEdited = true

                }

                text: (lognViewModel)? lognViewModel.data.nickname: "";

            }

            LVMTextInput {
                id: pass1
                placeholderText: qsTr("Pasword")
                Layout.columnSpan: (conntent.isRegisterNewUser)? ((content.width > 350)? 1 : 2): 2;
                Layout.fillWidth: true
                hasError: (conntent.errors && conntent.errors.rawPassword);
                tooltip: (hasError)? lognViewModel.passwordError : ""
                onTextChanged: {
                    content.paswordValidation()
                }

                echoMode: TextInput.Password
            }

            LVMTextInput {
                id: pass2
                placeholderText: qsTr("Confirm pasword")
                Layout.columnSpan: (content.width > 350)? 1 : 2;
                Layout.fillWidth: true
                visible: conntent.isRegisterNewUser

                onTextChanged: {
                    content.paswordValidation()
                }
                echoMode: TextInput.Password

            }

            LVMCheckBox {
                id: termOfUse
                text: qsTr("I accept the Terms of use")
                Layout.columnSpan: (content.width > 350)? 1 : 2;
                Layout.fillWidth: true
                visible:conntent.isRegisterNewUser

            }

            LVMButton {
                text: qsTr("Show terms of use")
                visible: conntent.isRegisterNewUser
                onClicked: {
                    if (lognViewModel) {
                        lognViewModel.showTermOfUseRequest();
                    }
                }
            }

            LVMButton {
                text: (conntent.isRegisterNewUser)? qsTr("SignUp") : qsTr("LogIn")
                visible: true
                enabled: (conntent.errors && conntent.errors.noError) &&
                         ((conntent.isRegisterNewUser)? !pass2.hasError && termOfUse.checked: true)

                onClicked: {
                    if (lognViewModel) {
                        if (conntent.isRegisterNewUser) {
                            lognViewModel.registerRequest();
                        } else {
                            lognViewModel.loginRequest();
                        }
                    }
                    loginClicked(conntent.isRegisterNewUser);
                }
            }

            LVMButton {
                text: qsTr("Forgot password")
                visible: !conntent.isRegisterNewUser
                enabled: !(conntent.errors && conntent.errors.email)

                onClicked: {
                    if (lognViewModel) {
                        lognViewModel.rememberPasswordRequest();
                    }
                }
            }
            anchors.bottomMargin: 40
            anchors.leftMargin: 20
            anchors.rightMargin: 20
            anchors.fill: parent
        }

    }

    footer: TabBar {
        id: tabBar

        currentIndex: registerNewUser
        TabButton {
            text: qsTr("Login In")
        }
        TabButton {
            text: qsTr("Sign Up")
        }

    }
}
