import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Controls.Material 2.12
import QtQuick.Controls.Universal 2.12

ComboBox {

    property string placeholderText: ""

    model : (lognViewModel)? lognViewModel.countryList: []

    Label {
        visible: placeholderText.length && !count
        text: placeholderText
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
        elide: Text.ElideRight
        anchors.fill: parent
        anchors.rightMargin: 20
        color: "#bdb9bb"
    }

}
