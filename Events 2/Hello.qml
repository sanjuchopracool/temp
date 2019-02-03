import QtQuick 2.0

Rectangle {
    anchors.fill: parent

    Text {
        id: textWidget
        text: qsTr("text")

        anchors.centerIn: parent

        MouseArea {
            anchors.fill: parent
            property int count: 1

            onClicked: {
                textWidget.text = "clicked: " + count
                count++;
            }
        }
    }
}
