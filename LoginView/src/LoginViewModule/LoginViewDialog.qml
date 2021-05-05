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

    width: 4 * metrix.pt
    height: 6 * metrix.pt

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
