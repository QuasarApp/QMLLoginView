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

TextField {

    property string tooltip: "";
    property bool hasError: false;
    property bool hasEdited: false;

    function changeBorderColor() {
        if (!hasEdited)
            return;

        if (hasError) {
            background.color = "#ff2802"

        } else {
            background.color = "#5bd469"
        }
    }

    onHasErrorChanged: {
        changeBorderColor();
    }

    onHasEditedChanged: {
        changeBorderColor();
    }

    hoverEnabled: true

    ToolTip.delay: 250
    ToolTip.timeout: 5000
    ToolTip.visible: hovered && tooltip.length
    ToolTip.text: tooltip


}
