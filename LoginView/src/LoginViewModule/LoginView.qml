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
    }

    property bool lightMode: header.lightMode
    property var lognViewModel: null

    Material.theme: (lightMode)? Material.Light: Material.Dark
    Material.accent: (lightMode)? Material.LightBlue: Material.Orange
    Universal.theme: (lightMode)? Material.Light: Material.Dark
    Universal.accent: (lightMode)? Material.LightBlue: Material.Orange

    contentItem:
        Item {
        GridLayout {

            rows: 6
            columns: 2
            rowSpacing: 15
            columnSpacing: 15

            id: content

            LVMTextInput {
                placeholderText: qsTr("First Name")
                Layout.columnSpan: (content.width > 350)? 1 : 2;
                Layout.fillWidth: true
            }

            LVMTextInput {
                placeholderText: qsTr("Last Name")
                Layout.columnSpan: (content.width > 350)? 1 : 2;
                Layout.fillWidth: true
            }

            LVMComboBox {
                placeholderText: qsTr("Select you country")
                Layout.columnSpan: 2
                Layout.fillWidth: true
            }

            LVMTextInput {
                placeholderText: qsTr("EMail")
                Layout.columnSpan: 2
                Layout.fillWidth: true
            }

            LVMTextInput {
                placeholderText: qsTr("Pasword")
                Layout.columnSpan: 2
                Layout.fillWidth: true
            }

            LVMCheckBox {
                text: qsTr("I accept the Terms of use")
                Layout.columnSpan: 2
                Layout.fillWidth: true

            }

            LVMButton {
                text: qsTr("Sign Up")
            }
            anchors.bottomMargin: 40
            anchors.leftMargin: 20
            anchors.rightMargin: 20
            anchors.fill: parent
        }

    }
}
