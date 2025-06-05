import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Window 2.15


Window {
    id: mainWindow
    objectName: "mainWindow"
    visible: true
    width: 640
    height: 480
    title: "CloudSealQt"
    flags: Qt.FramelessWindowHint | Qt.Window
    color: "transparent"

    Pane {
        id: root
        objectName: "root"
        anchors.fill: parent
        background: Rectangle {
            radius: 10
            color: "white"
            border.width: 1
            border.color: "#dcdcdc"
        }
    }

    function createDynamicComponentFromString(componentString) {
        return Qt.createQmlObject(componentString, root);
    }

}


