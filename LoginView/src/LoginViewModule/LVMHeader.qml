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
import QtQuick.Window 2.12

Control {

    height: (withTitle)? 35 * Screen.pixelDensity: 15 * Screen.pixelDensity

    property string help: ""
    property string title: ""
    property bool withTitle: true

    ColumnLayout {
        Label {
            text: title;
            font.pixelSize: 24
            font.bold: true
            Layout.alignment: Qt.AlignLeft
            visible: withTitle
        }

        Label {
            text: help;
            Layout.alignment: Qt.AlignLeft
        }

        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.bottom: parent.bottom

        anchors.leftMargin: 15
        anchors.bottomMargin: 30

    }

    Rectangle {
        height: 1
        color: "#bdb9bb"

        anchors.bottom: parent.bottom
        anchors.bottomMargin: 15

        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.right: parent.right
        anchors.rightMargin: 0

    }

}
