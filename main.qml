import QtQuick 2.12
import QtQuick.Window 2.12
import Qt.labs.platform 1.0
import QtQuick.Dialogs 1.3
import QtQuick.Controls 2.12
import com.internal.MidiHandler 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Guitar Controller")

    MidiHandler {
        id: midiHandler
    }

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
        text: "foo"
        font.pixelSize: 12
    }

    ListView {
        required model
        id: listView
        x: 13
        y: 58
        width: 110
        height: 160
        delegate: Item {
            id: element1
            x: 5
            width: 80
            height: 40
            Row {
                id: row1
                spacing: 10

                Text {
                    text: name
                    font.bold: true
                    anchors.verticalCenter: parent.verticalCenter
                }

                Text {
                    text: note
                    font.weight: note.none
                    anchors.verticalCenter: parent.verticalCenter
                    font.bold: true
                }
            }
        }
    }
}
