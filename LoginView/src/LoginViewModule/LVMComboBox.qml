//#
//# Copyright (C) 2018-2020 Yankovich Andrei (EndrII).
//# Distributed under the lgplv3 software license, see the accompanying
//# Everyone is permitted to copy and distribute verbatim copies
//# of this license document, but changing it is not allowed.
//#

import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Controls.Material 2.12
import QtQuick.Controls.Universal 2.12

ComboBox {

    property string placeholderText: ""
    property string tooltip: "";

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

    hoverEnabled: true

    ToolTip.delay: 250
    ToolTip.timeout: 5000
    ToolTip.visible: hovered && tooltip.length
    ToolTip.text: tooltip
}
