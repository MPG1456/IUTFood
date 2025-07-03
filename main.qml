import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 6.5
import "."
Window{
    id: win
    width:400
    height:600
    minimumWidth: 400
    minimumHeight: 600
    title:"sign in"
    visible: true
    StackView
    {
        id:stackv
        anchors.fill: parent
        initialItem: ""
    }

    Rectangle
    {
        id:mainrect

        anchors.fill: parent
        color:"#333"
        Image {
            id: mainimage
            source: "qrc:/projimages/pexels-pixabay-260922.jpg"
            fillMode: Image.PreserveAspectCrop
            opacity: 0.5
            anchors.fill: parent
        }
        Rectangle
        {
        radius:15
        color:"#FFFAF7"
        anchors.centerIn: parent
        width:Math.min(win.width-90 , 500)
        height:Math.min(win.height-130 , 750)
        Flickable
        {
            id:insiderect
            clip:true
            anchors.fill: parent
            contentHeight: col.height
            Column
            {
                id:col
                width: parent.width*0.9
                spacing: 12
                anchors.top:parent.top
                anchors.topMargin: 15
                anchors.left: parent.left
                anchors.leftMargin: 14

                Label
                {
                    width:parent.width
                    id:label1
                    text: "sign in"
                    font.pixelSize: 26
                    font.bold: true
                    horizontalAlignment: Text.AlignHCenter
                    color:"#468898"
                }
                TextField
                {
                    placeholderText: "username"
                    width: insiderect.width-30
                    font.pixelSize: 14
                }
                TextField
                {
                    placeholderText: "password"
                    width: insiderect.width-30
                    font.pixelSize: 14
                    echoMode: TextInput.Password
                }
                // adress{}
                Row{
                    spacing:7
                    anchors.horizontalCenter: parent.horizontalCenter
                    width:submit.width +spacing
                    Button
                    {
                        id:submit
                        text: "submit"
                        width: col.width/2
                        onClicked:
                        {
                        stackv.push("adminpanel.qml")
                        win.close()
                        }
                    }

                }


            Row
                {
                    spacing: 5
                    anchors.horizontalCenter: parent.horizontalCenter
                    Text {

                        text: "don't you have an account?"

                    }
                    Text {
                        text: "sign up"
                        color: "red"
                        font.bold: true
                        MouseArea
                        {
                            anchors.fill: parent
                            hoverEnabled: true
                            onEntered:
                            {
                                cursorShape:Qt.PointingHandCursor
                            }
                            onClicked:
                            {
                                stackv.push("clientsignup.qml")
                                win.close()

                            }
                        }
                    }


            }
            Row
                {
                    spacing: 5
                    anchors.horizontalCenter: parent.horizontalCenter
                    Text {

                        text: "do you have restaurant?"

                    }
                    Text {
                        text: "restaurant sign in"
                        color: "red"
                        font.bold: true
                        MouseArea
                        {
                            anchors.fill: parent
                            onEntered:
                            {
                                cursorShape:Qt.PointingHandCursor
                            }

                            onClicked:
                            {
                                stackv.push("restaurantsignin.qml")
                                win.close()
                            }
                        }
                    }

                }
            Row
                {
                    spacing: 5
                    anchors.horizontalCenter: parent.horizontalCenter
                    Text {
                        text: "Delivery sign in"
                        color: "red"
                        font.bold: true
                        MouseArea
                        {
                            anchors.fill: parent
                            onEntered:
                            {
                                cursorShape:Qt.PointingHandCursor
                            }

                            onClicked:
                            {
                                stackv.push("deliverysignin.qml")
                                win.close()
                            }
                        }
                    }

                }
            }
            ScrollBar.vertical: ScrollBar
            {
                policy:ScrollBar.AsNeeded
            }
            }

        }

    }


}
