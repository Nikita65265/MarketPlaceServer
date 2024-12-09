import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    id: _item
    property string textButton: "Войти"
    property string textButtonColor: "#ffffff"
    property int textButtonFontPointSize: 16
    width: 200
    height: 30

    Button {
        id: button
        visible: true
        anchors.fill: parent
        highlighted: false
        flat: false
        display: AbstractButton.TextOnly

        background: Rectangle {
            id: rectangle
            color: "#ffffff"
            border.color: "black"
            radius: 5;

            gradient: Gradient {
                id: buttonGradient
                GradientStop {
                    position: 0.00;
                    color: "#3a0833";
                }
                GradientStop {
                    position: 1.00;
                    color: "#110707";
                }
            }
            anchors.fill: parent

            Text {
                color: _item.textButtonColor
                text: _item.textButton
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pointSize: _item.textButtonFontPointSize
                anchors.fill: parent
            }
        }

        MouseArea {
            anchors.fill: parent
            hoverEnabled: true

            onPressed: {
                // Изменение цвета градиента при нажатии
                buttonGradient.stops[0].color = "#5a0833"; // Новый цвет для первого градиента
                buttonGradient.stops[1].color = "#310707"; // Новый цвет для второго градиента
            }

            onReleased: {
                // Возврат к исходному градиенту при отпускании
                buttonGradient.stops[0].color = "#3a2833"; // Исходный цвет для первого градиента
                buttonGradient.stops[1].color = "#112707"; // Исходный цвет для второго градиента
            }

            onEntered: {
                // Изменение цвета градиента при наведении
                buttonGradient.stops[0].color = "#3a2833"; // Новый цвет для первого градиента при наведении
                buttonGradient.stops[1].color = "#112707"; // Новый цвет для второго градиента при наведении
            }

            onExited: {
                // Возврат к исходному градиенту при выходе курсора
                buttonGradient.stops[0].color = "#3a0833"; // Исходный цвет для первого градиента
                buttonGradient.stops[1].color = "#110707"; // Исходный цвет для второго градиента
            }
        }

    }

}
