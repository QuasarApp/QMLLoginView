//#
//# Copyright (C) 2018-2020 Yankovich Andrei (EndrII).
//# Distributed under the lgplv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#

import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls.Material 2.12
import QtQuick.Controls.Universal 2.12

Page {

    height: 500
    width: 400

    header: LVMHeader{
        id: header
        title: (conntent.isRegisterNewUser)? qsTr("Sign Up"): qsTr("Login In")
        help: (conntent.isRegisterNewUser)? qsTr('please fill this form to create an account'):
                                             qsTr('please fill this form to login in your account')
    }

    property bool lightMode: header.lightMode
    property var lognViewModel: null
    property bool registerNewUser: true

    Material.theme: (lightMode)? Material.Light: Material.Dark
    Material.accent: (lightMode)? Material.LightBlue: Material.Orange
    Universal.theme: (lightMode)? Material.Light: Material.Dark
    Universal.accent: (lightMode)? Material.LightBlue: Material.Orange

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
                placeholderText: qsTr("First Name")
                Layout.columnSpan: (content.width > 350)? 1 : 2;
                Layout.fillWidth: true
                visible: conntent.isRegisterNewUser
                tooltip: (hasError)? qsTr("Empy or incorrect name. Please enter yuor name."):  ""
                hasError: (conntent.errors && conntent.errors.firstName);
                onTextChanged: {
                    if (lognViewModel) {
                        lognViewModel.data.firstName = text;
                    }
                    hasEdited = true
                }
            }

            LVMTextInput {
                placeholderText: qsTr("Last Name")
                Layout.columnSpan: (content.width > 350)? 1 : 2;
                Layout.fillWidth: true
                visible: conntent.isRegisterNewUser
                hasError: (conntent.errors && conntent.errors.lastName);

                onTextChanged: {
                    if (lognViewModel) {
                        lognViewModel.data.lastName = text;
                    }
                    hasEdited = true

                }

            }

            LVMComboBox {
                placeholderText: qsTr("Select you country")
                Layout.columnSpan: 2
                Layout.fillWidth: true
                visible: conntent.isRegisterNewUser
                onCurrentIndexChanged: {
                    if (lognViewModel) {
                        lognViewModel.data.country = lognViewModel.countryCodeList[currentIndex];
                    }
                }
            }

            LVMTextInput {
                placeholderText: qsTr("EMail")
                Layout.columnSpan: 2
                Layout.fillWidth: true
                hasError: (conntent.errors && conntent.errors.email);
                tooltip: (hasError)? qsTr("Empy or incorrect email address. Please enter yuor name.") : ""
                onTextChanged: {
                    if (lognViewModel) {
                        lognViewModel.data.email = text;
                    }
                    hasEdited = true

                }
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
                text: (conntent.isRegisterNewUser)? qsTr("Sign Up") : qsTr("Login In")
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
        width: parent.width

        currentIndex: registerNewUser
        TabButton {
            text: qsTr("Login In")
        }
        TabButton {
            text: qsTr("Sign Up")
        }

    }
}
