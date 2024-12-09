import QtQuick 2.15

Item {
    width: 200
    height: 25

    id: _item
    property string placeHolderText: "Введите данные..."
    property int fontSizePt: 16


    Rectangle {
        id: rectangle
        color: "#00ffffff"
        anchors.fill: parent

        TextInput {
            id: textInput
            anchors.fill: parent
            font.pointSize: _item.fontSizePt
            color: "#000000"

            Text {
                text: _item.placeHolderText
                font.pointSize: _item.fontSizePt
                color: "#aaa"
                anchors.fill: parent
                visible: textInput.text.length === 0
            }
        }
    }

    Rectangle {
        id: rectangle1
        color: "#433d3d"
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: rectangle.bottom
        anchors.bottom: parent.bottom
        anchors.leftMargin: 0
        anchors.rightMargin: 0
        anchors.topMargin: 0
        anchors.bottomMargin: -1
    }

}
