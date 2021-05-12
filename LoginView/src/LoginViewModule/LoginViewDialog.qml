import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls.Material 2.12
import QtQuick.Controls.Universal 2.12
import QtQuick.Window 2.12

Popup {
    id: root
    property var lognViewModel: null
    property real point: metrix.pt
    property real controlPtMaterial: metrix.controlPtMaterial

    width: Math.max(6 * metrix.controlPtMaterial, parent.width * 0.5)
    height: Math.max(6 * metrix.controlPtMaterial, parent.height * 0.5)

    x: parent.width / 2 - width / 2
    y: parent.height / 2 - height / 2

    Metrix {
        id: metrix
    }

    contentItem: LoginView {
        id: source
        lognViewModel: root.lognViewModel

        onLoginClicked: {
            root.close();
        }
    }

    onClosed: {
        source.clear();
    }

}
