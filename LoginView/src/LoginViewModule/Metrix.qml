/*
 * Copyright (C) 2021-2021 QuasarApp.
 * Distributed under the lgplv3 software license, see the accompanying
 * Everyone is permitted to copy and distribute verbatim copies
 * of this license document, but changing it is not allowed.
*/

import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls.Material 2.15
import QtQuick.Controls 2.15

Item {
    readonly property int pointCount: 100;
    readonly property real mm: Screen.pixelDensity
    readonly property real sm: 10 * mm
    readonly property real dsm: Math.sqrt(Math.pow(Screen.desktopAvailableWidth, 2) + Math.pow(Screen.desktopAvailableHeight, 2)) / sm
    readonly property real pt: getfactor(dsm) * sm
    readonly property real controlPtMaterial: Material.buttonHeight
    readonly property real gamePt: (width < height) ? width / pointCount : height / pointCount;
    readonly property real fontPoints: textMetrics.averageCharacterWidth;

    function getfactor(dsm) {
        if ( dsm < 70) {
            return 1
        } else if (dsm < 140) {
            return 2;
        } else
            return 4;
    }

    FontMetrics {
        id: textMetrics
        font.bold: true
        font.capitalization: Font.AllUppercase

    }

    anchors.fill: parent;
}
