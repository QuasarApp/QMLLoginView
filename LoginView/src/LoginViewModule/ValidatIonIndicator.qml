import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Controls.Material 2.12
import QtQuick.Controls.Universal 2.12
import QtQuick.Extras 1.4

StatusIndicator {

    id: indicator
    state: "notChanged"

    anchors.bottomMargin: 10;
    anchors.rightMargin: -5;
    anchors.topMargin: 15;

    states: [
        State {
            name: "good"
            PropertyChanges {
                target: indicator;
                color: "green"
                active: true
            }
        },
        State {
            name: "error"
            PropertyChanges {
                target: indicator;
                color: "red"

                active: true

            }
        },
        State {
            name: "notChanged"
            PropertyChanges {
                target: indicator;
                color: "red"
                active: false

            }
        }
    ]
}
