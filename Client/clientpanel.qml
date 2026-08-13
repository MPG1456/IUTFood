    import QtQuick 2.15
    import QtQuick.Controls 2.15
    import QtQuick.Layouts 6.5
    import "."

    ApplicationWindow {
        id: win
        width: 400
        height: 600
        minimumWidth: 400
        minimumHeight: 600
        title: "client panel"
        visible: true

        Drawer {
            id: menu
            edge: Qt.RightEdge
            width: Math.min(win.width / 2, 500)
            height: parent.height
            // background: Rectangle { color: "#2E2E2E" }

            ListModel {
                id: menuelement
                ListElement { name: "Home"; pageaddress: "clientpanel.qml" }
                ListElement { name: "Filter page"; pageaddress: "filterpage.qml" }
                ListElement { name: "Order tracking"; pageaddress: "Ordertracking.qml" }
                ListElement { name: "Order history"; pageaddress: "orderhistory.qml" }
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

                        Column {
                            spacing: 20
                            Text {
                                text: name
                                font.pixelSize: 13
                                font.bold: true
                            }
                        }
                    }

                    MouseArea {
                        anchors.fill: parent
                        hoverEnabled: true
                        onEntered: hovered = true
                        onExited: hovered = false
                        onClicked: {
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
                            } else {
                                console.log("Component load error:", component.errorString())
                            }
                        }
                    }
                }
            }
        }

        Rectangle {
            id: mainrect
            anchors.fill: parent
            color: "#333"

            Image {
                id: mainimage
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
                        anchors.topMargin: win.height / 10
                        anchors.left: parent.left
                        anchors.leftMargin: 14

                        TextField {
                            id: searchbar
                            placeholderText: "search..."
                            width: insiderect.width - 30
                            font.pixelSize: 14
                        }

                        ListModel {
                            id: element
                            ListElement { name: "Tarkhoon"; location: "isfahan soroosh";pageaddress: "menu.qml"}
                            ListElement { name: "Kentakihouse"; location: "isfahan Ahmadabad";pageaddress: "menu.qml"}
                            ListElement { name: "Safa"; location: "isfahan noorbaran";pageaddress: "menu.qml" }
                            ListElement { name: "golchin"; location: "Tehran saadat abad";pageaddress: "menu.qml" }
                        }

                        ListView {
                            width: searchbar.width
                            height: win.height * 5 / 6
                            model: element
                            spacing: 8
                            clip: true
                            delegate: Rectangle {
                            width: ListView.view.width
                            property bool hovered: false
                            border.color: hovered ? "#888" : "#ccc"
                            height: 80
                            radius: 10
                            color: hovered ? "#d0eaff" : "#f5f5f5"

                                Row {
                                    anchors.fill: parent
                                    anchors.margins: 10
                                    spacing: 8

                                    Column {
                                        spacing: 20
                                        Text {
                                            text: "restaurant name: " + name
                                            font.pixelSize: 13
                                            font.bold: true
                                        }
                                        Text {
                                            text: "location: " + location
                                            font.pixelSize: 11
                                            color: "red"
                                        }
                                    }
                                }
                                MouseArea {
                                    anchors.fill: parent
                                    hoverEnabled: true
                                    onEntered: hovered = true
                                    onExited: hovered = false
                                    onClicked: {
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
                                        } else {
                                            console.log("Component load error:", component.errorString())
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


            Button {
                id: hamburger
                z: 100
                anchors.top: parent.top
                anchors.right: parent.right
                icon.source: "qrc:/projimages/hamburger.png"
                width: parent.width / 5
                height: parent.height / 7.5
                background: null
                anchors.rightMargin: 2

                onClicked: menu.open()
            }

            Button {
                id: cart
                z: 100
                anchors.top: parent.top
                anchors.left: parent.left
                icon.source: "qrc:/projimages/cart.png"
                width: parent.width / 5
                height: parent.height / 7.5
                background: null
                anchors.leftMargin: 2

                onClicked: {
                    console.log("clickeddd")
                    var component = Qt.createComponent("shoppingcart.qml")
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
                    } else {
                        console.log("Component error:", component.errorString())
                    }
                }
            }
            }
        }
    }
