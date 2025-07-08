import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 6.5

ApplicationWindow {
    id: win
    width: 400
    height: 600
    minimumWidth: 400
    minimumHeight: 600
    visible: true
    title: "admin croud"

    Rectangle {
        id: mainrect
        anchors.fill: parent
        color: "#333"

        Image {
            source: "qrc:/projimages/pexels-pixabay-260922.jpg"
            fillMode: Image.PreserveAspectCrop
            opacity: 0.5
            anchors.fill: parent
        }

        Rectangle {
            radius: 15
            color: "#FFFAF7"
            anchors.centerIn: parent
            width: Math.min(win.width - 90, 500)
            height: Math.min(win.height - 130, 750)

            Flickable {
                id: insiderect
                clip: true
                anchors.fill: parent
                contentHeight: col.height
                Column {
                    id: col
                    width: parent.width * 0.9
                    spacing: 12
                    anchors.top: parent.top
                    anchors.topMargin: 20
                    anchors.horizontalCenter: parent.horizontalCenter
                    ListModel {
                        id: element
                        ListElement { username: "Saleh"; phonenumber: "09133325279"; city: "Isfahan" }
                        ListElement { username: "Parsa"; phonenumber: "09133325279"; city: "Tehran" }
                        ListElement { username: "Ali"; phonenumber: "09133325279"; city: "Shiraz" }
                        ListElement { username: "Reza"; phonenumber: "09133325279"; city: "Tabriz" }
                    }

                    ListView {
                        width: parent.width
                        height: 400
                        model: element
                        spacing: 8
                        clip: true

                        delegate: Rectangle {
                            id: littlerect
                            width: parent.width
                            height: 100
                            radius: 10
                            border.color: "#ccc"
                            color: "#f5f5f5"
                            Row {
                                spacing: 6
                                anchors.top: parent.top
                                anchors.right: parent.right
                                anchors.topMargin: 6
                                anchors.rightMargin: 6

                                Button {
                                    icon.source: "qrc:/projimages/bin.png"
                                    width: 30
                                    height: 30
                                    background: null
                                    onClicked: {
                                        console.log("Delete:", username)
                                    }
                                }

                                Button {
                                    icon.source: "qrc:/projimages/block.png"
                                    width: 30
                                    height: 30
                                    background: null
                                    onClicked: {
                                        console.log("Block:", username)
                                    }
                                }
                            }

                            Column {
                                anchors.fill: parent
                                anchors.margins: 10
                                spacing: 6

                                Text {
                                    text: username
                                    font.pixelSize: 14
                                    font.bold: true
                                }

                                Row {
                                    spacing: 10
                                    Text {
                                        text: "Phone: " + phonenumber
                                        font.pixelSize: 12
                                        color: "red"
                                    }
                                    Text {
                                        text: "City: " + city
                                        font.pixelSize: 12
                                        color: "green"
                                    }
                                }
                            }
                        }
                    }
                }

                ScrollBar.vertical: ScrollBar {
                    policy: ScrollBar.AsNeeded
                }
            }


        // دکمه اضافه کردن کاربر
        Button {
            id: adduser
            anchors.top: parent.top
            anchors.left: parent.left
            icon.source: "qrc:/projimages/plus.png"
            width: parent.width / 5
            height: parent.height / 7.5
            background: null
            anchors.leftMargin: 2
            onClicked: {
                console.log("clickeddd")
                var component = Qt.createComponent("clientsignup.qml")
                if (component.status === Component.Ready) {
                    var newWin = component.createObject(null, {
                        width: win.width,
                        height: win.height,
                        x: win.x,
                        y: win.y,
                        visibility: win.visibility
                    })
                    newWin.show()
                    win.close()
                }
            }
        }
        Button {
            id: hamburger
            anchors.top: parent.top
            anchors.right: parent.right
            icon.source: "qrc:/projimages/hamburger.png"
            width: parent.width / 5
            height: parent.height / 7.5
            background: null
            anchors.rightMargin: 2
            onClicked: {
                console.log("clickeddd")
                menu.open()
            }
        }
        }
    }
    Drawer {
        id: menu
        edge: Qt.RightEdge
        width: Math.min(win.width / 2, 500)
        height: parent.height

        ListModel {
            id: menuelement
            ListElement { name: "Home"; pageaddress: "adminpanel.qml" }
            ListElement { name: "change or add user"; pageaddress: "admincroud.qml" }
            ListElement { name: "accept restaurant request"; pageaddress: "acceptrequest.qml" }
        }

        ListView {
            width: parent.width
            height: win.height * 5 / 6
            model: menuelement
            clip: true

            delegate: Rectangle {
                width: ListView.view.width
                property bool hovered: false
                border.color: hovered ? "#888" : "#ccc"
                height: 55
                color: hovered ? "#d0eaff" : "#f5f5f5"
                Row {
                    anchors.fill: parent
                    anchors.margins: 10
                    spacing: 8

                    Text {
                        text: name
                        font.pixelSize: 13
                        font.bold: true
                    }
                }

                MouseArea {
                    anchors.fill : parent
                                            hoverEnabled: true
                                            onEntered: hovered = true
                                            onExited: hovered = false                    onClicked: {
                        menu.close()
                        var component = Qt.createComponent(pageaddress)
                        if (component.status === Component.Ready) {
                            var newWin = component.createObject(null, {
                                width: win.width,
                                height: win.height,
                                x: win.x,
                                y: win.y,
                                visibility: win.visibility
                            })
                            newWin.show()
                            win.close()
                        }
                    }
                }
            }
        }
    }
}
