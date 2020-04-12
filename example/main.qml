//#
//# Copyright (C) 2018-2020 Yankovich Andrei (EndrII).
//# Distributed under the lgplv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#
import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Controls 2.12 as Controls
import QtQuick.Layouts 1.12
import LoginViewModule 1.0
import QtQuick.Dialogs 1.3

Window {

    height: 600
    width: 400

    minimumHeight: 400
    minimumWidth: 200

    visible: true
    LoginView {
        lognViewModel: exampleLogin
        anchors.fill: parent
    }

    title: qsTr("Example of LoginView")
}
