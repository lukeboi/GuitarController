import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.15
import Qt.labs.platform 1.0
import QtQuick.Dialogs 1.3
import midiHandler 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    property var currentFile: "Select A MIDI File";

    TextField {
        id: textField
        x: 8
        y: 7
        text: currentFile
        placeholderText: qsTr("Text Field")
    }

    Button {
        id: button
        x: 214
        y: 7
        width: 40
        text: qsTr("...")
        onClicked: fileDialog.open()
    }


    FileDialog {
        id: fileDialog
        onAccepted: {
            console.log("You chose: " + fileDialog.fileUrls)
            currentFile = fileUrl

        }
        folder: StandardPaths.writableLocation(StandardPaths.DocumentsLocation)
    }
}
