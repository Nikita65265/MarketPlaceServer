import QtQuick
import "TextInput_normal"
import "../Widgets"
import QtQuick.Controls 2.15

Window {
    id: window
    width: 640
    height: 360
    visible: true
    color: "#252428"
    flags: Qt.Window | Qt.WindowTitleHint | Qt.WindowCloseButtonHint
    title: qsTr("Диспетчер управления базой данных")

    Rectangle {
        id: main_rectangle
        anchors.fill: parent
        gradient: Gradient {
            GradientStop {
                position: 0
                color: "#61122e"
            }

            GradientStop {
                position: 0.41228
                color: "#3e0b23"
            }

            GradientStop {
                position: 0.22807
                color: "#3e0b23"
            }

            GradientStop {
                position: 0.60965
                color: "#390c22"
            }

            GradientStop {
                position: 0.90351
                color: "#050c11"
            }



            orientation: Gradient.Horizontal
        }
        z: 0

        CurButton {
            id: button_input
            x: 235
            y: 257
            width: 171
            height: 25
            anchors.verticalCenter: parent.verticalCenter
            z: 1
            anchors.horizontalCenterOffset: 0
            anchors.verticalCenterOffset: 123
            anchors.horizontalCenter: parent.horizontalCenter

            onClickedButton: {
                console.log("Кнопка нажата")
            }
        }

        SwipeView {
            id: swipeView
            y: 8
            width: 307
            height: 177
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenterOffset: -29
            anchors.horizontalCenterOffset: 0
            currentIndex: 0

            // contentItem: ListView {
            //     model: swipeView.contentModel
            //     interactive: swipeView.interactive
            //     currentIndex: swipeView.currentIndex

            //     spacing: swipeView.spacing
            //     orientation: swipeView.orientation
            //     snapMode: ListView.SnapOneItem
            //     boundsBehavior: Flickable.StopAtBounds

            //     highlightRangeMode: ListView.StrictlyEnforceRange
            //     preferredHighlightBegin: 0
            //     preferredHighlightEnd: 0
            //     highlightMoveDuration: 2000
            //     //                    min:10
            // }

            Item {
                id: item_registration
                Column {
                    id: column_registartion
                    anchors.fill: parent
                    anchors.leftMargin: 0
                    anchors.rightMargin: 0
                    anchors.topMargin: 0
                    anchors.bottomMargin: 0
                    z: 1
                    spacing: 10

                    TextInput_normal  {
                        id: text_first_name
                        width: 300
                        height: 25
                        placeHolderText: "Имя"
                    }

                    TextInput_normal {
                        id: text_last_name
                        width: 300
                        height: 25
                        placeHolderText: "Фамилия"
                    }

                    TextInput_normal {
                        id: text_mail
                        width: 300
                        height: 25
                        placeHolderText: "Электронная почта"
                    }

                    TextInput_normal {
                        id: text_password
                        width: 300
                        height: 25
                        placeHolderText: "Пароль"
                    }

                    TextInput_normal {
                        id: text_repeat_password
                        width: 300
                        height: 25
                        placeHolderText: "Повторите пароль"
                    }
                }

                Behavior on opacity {
                    NumberAnimation {
                        duration: 1000
                        easing.type: Easing.InOutQuad
                    }
                }
            }

            Item {
                id: item_login
                visible: false

                Column {
                    id: column_login
                    anchors.fill: parent
                    z: 1
                    spacing: 10

                    TextInput_normal {
                        id: text_login_email
                        width: 300
                        height: 25
                        placeHolderText: "Электронная почта"
                    }
                    TextInput_normal {
                        id: text_login_password
                        width: 300
                        height: 25
                        placeHolderText: "Пароль"
                    }

                }

                Behavior on opacity {
                    NumberAnimation {
                        duration: 1000
                        easing.type: Easing.InOutQuad
                    }
                }
            }
        }

        Rectangle {
            id: rectangle_switch_registration_login
            width: 152
            height: 30
            color: "#00ffffff"
            anchors.verticalCenter: parent.verticalCenter
            anchors.verticalCenterOffset: 80
            anchors.horizontalCenterOffset: 0
            anchors.horizontalCenter: parent.horizontalCenter

            Switch {
                id: switch_registration_login
                x: 150
                y: -35
                text: qsTr("Регистрация")
                anchors.fill: parent
                anchors.leftMargin: 0
                anchors.rightMargin: 0
                anchors.topMargin: -8
                anchors.bottomMargin: 8

                onCheckedChanged: {
                    if (checked) {
                        item_registration.opacity = 0
                        item_login.opacity = 1

                        item_registration.visible = false
                        item_login.visible = true

                        switch_registration_login.text = "Войти"

                        swipeView.currentIndex = 1
                    }
                    else {
                        item_registration.opacity = 1
                        item_login.opacity = 0

                        item_registration.visible = true
                        item_login.visible = false

                        switch_registration_login.text = "Регистрация"

                        swipeView.currentIndex = 0
                    }

                }
            }
        }
    }

}


