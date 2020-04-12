import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Controls.Material 2.12
import QtQuick.Controls.Universal 2.12

Button {
    property string tooltip: "";
    hoverEnabled: true

    ToolTip.delay: 250
    ToolTip.timeout: 5000
    ToolTip.visible: hovered && tooltip.length
    ToolTip.text: tooltip
}
