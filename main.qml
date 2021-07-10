import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.15
import Qt.labs.qmlmodels 1

import TableModel 0.1
Window{
    id: root
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    TableView {
        anchors.fill: parent
        columnSpacing: 0
        rowSpacing: 0
        clip: true

        model: TableModel {}

        delegate: Rectangle {
            implicitWidth: root.width / 5
            implicitHeight: 50
            border.width: 1
            color: (heading)? "lightgray":"white"
            Text {
                text: tabledata
                anchors.centerIn: parent
            }
        }
    }
}
