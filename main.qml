import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.15
import Qt.labs.platform 1.0
import QtQuick.Dialogs 1.3

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Guitar Controller")

    Button {
        id: button
        x: 13
        y: 12
        width: 40
        text: qsTr("...")
        onClicked: fileDialog.open()
    }


    FileDialog {
        id: fileDialog
        selectMultiple: false
        onAccepted: {
            midiHandler.filePath = fileUrl
        }
        folder: StandardPaths.writableLocation(StandardPaths.DocumentsLocation)
    }

    Text {
        id: element
        x: 59
        y: 25
        text: midiHandler.filePath
        font.pixelSize: 12
    }
}
