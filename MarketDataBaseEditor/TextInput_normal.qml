import QtQuick 2.15

Item {
    id: _item
    width: 200
    height: 45

    property string placeHolderText: "Введите данные..."
    property int fontPointSize: 16
    property string underLineColor: "#aaa";

    Rectangle {
        id: rectangle
        color: "#00000000"
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.bottom: underLine.top
        anchors.bottomMargin: 0

        TextInput {
            id: textInput
            color: "#ffffff"
            anchors.fill: parent
            anchors.leftMargin: 5
            anchors.rightMargin: 5
            anchors.topMargin: 2
            anchors.bottomMargin: 2
            font.pixelSize: _item.fontPointSize
            verticalAlignment: Text.AlignVCenter

            Text {
                text: _item.placeHolderText
                anchors.fill: parent
                verticalAlignment: Text.AlignVCenter
                font.pointSize: _item.fontPointSize
                color: "#aaa"
                visible: !textInput.text.length
            }
        }
    }

    Rectangle {
        id: underLine
        y: 44
        height: 1
        color: _item.underLineColor
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.leftMargin: 0
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
    }

}
