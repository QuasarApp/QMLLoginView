import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls.Material 2.12
import QtQuick.Controls.Universal 2.12

Control {

    height: 110

    property string help: qsTr('please fill this form to create an account')
    property bool lightMode: themeSwitch.lightMode

    ColumnLayout {
        LVMSwitch {
            id: themeSwitch
            Layout.alignment: Qt.AlignRight
            Layout.preferredHeight: 30
        }

        Label {
            text: qsTr("Sign Up");
            font.pixelSize: 24
            font.bold: true
            Layout.alignment: Qt.AlignLeft

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
        anchors.leftMargin: 15
        anchors.right: parent.right
        anchors.rightMargin: 15

    }

}
