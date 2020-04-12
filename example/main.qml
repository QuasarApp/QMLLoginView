import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Controls 2.12 as Controls
import QtQuick.Layouts 1.12
import LoginViewModule 1.0
import QtQuick.Dialogs 1.3

Window {

    height: 600
    width: 400

    minimumHeight: 400
    minimumWidth: 200

    visible: true
    LoginView {
        lognViewModel: exampleLogin
        anchors.fill: parent
    }

    title: qsTr("Example of LoginView")
}
