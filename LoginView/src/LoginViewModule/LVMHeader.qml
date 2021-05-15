//#
//# Copyright (C) 2018-2021 Yankovich Andrei (EndrII).
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

    height: layout.height + 15

    property string help: ""
    property string title: ""
    property bool withTitle: false

    clip: true

    Metrix{
        id: metrix
    }

    ColumnLayout {
        id: layout
        Label {
            id: title_txt
            text: title;
            wrapMode: Text.WordWrap
            Layout.fillWidth: true

            font.capitalization: Font.AllUppercase
            font.bold: true
            Layout.alignment: Qt.AlignLeft
            visible: withTitle
        }

        Label {
            id: help_txt
            wrapMode: Text.WordWrap
            text: help;
            Layout.alignment: Qt.AlignLeft
            Layout.fillWidth: true
        }

        anchors.left: parent.left
        anchors.right: parent.right

        spacing: 15

    }

    Rectangle {
        height: 1
        color: "#bdb9bb"

        anchors.bottom: parent.bottom

        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.right: parent.right
        anchors.rightMargin: 0
        visible: withTitle
        anchors.topMargin: 15

    }
    anchors.bottomMargin: 15

}
