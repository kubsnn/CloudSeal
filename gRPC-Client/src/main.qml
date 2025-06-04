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
   

    function createDynamicComponentFromString(componentString) {
        return Qt.createQmlObject(componentString, mainWindow);
    }

}


