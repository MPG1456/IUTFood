import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 6.5
import "."
import QtQuick.Window
import DataStore 1.0
import Network 1.0
Window{
    id: win
    width:400
    height:600
    minimumWidth: 400
    minimumHeight: 600
    title:"sign in"
    visible: true
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
                    id:usernamefield
                    placeholderText: "username"
                    width: insiderect.width-30
                    font.pixelSize: 14
                }
                TextField
                {
                    id:passwordfield
                    placeholderText: "password"
                    width: insiderect.width-30
                    font.pixelSize: 14
                    echoMode: TextInput.Password
                }
                Dialog
                {
                    id:message
                    title: "incorrect  user or pass ✕"
                    standardButtons: Dialog.Ok
                    // background:Rectangle
                    // {
                    //     color:"#c5e1a5"
                    //     anchors.fill:message
                    //     radius:10
                    // }
                    height: mainrect.height/4
                    width:mainrect.width/4
                    anchors.centerIn: parent
                    visible: false
                    contentItem: Label
                    {
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }
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
                        if(usernamefield.text==="Admin")
                        {
                            if(passwordfield.text==="12345")
                            {
                                var component =Qt.createComponent("adminpanel.qml")
                                if(component.status===Component.Ready)
                                {
                                    var newWin = component.createObject(null ,{
                                    width =win.width,
                                    height =win.height,
                                    x:win.x,
                                    y:win.y,
                                    visibility:win.visibility
                                                                        })
                                    newWin.show();
                                    win.close();
                                }
                            }
                        }
                        else
                        {
                        if(DataStore.checkClientUserPass(usernamefield.text , passwordfield.text))
                        {
                        var component =Qt.createComponent("clientpanel.qml")
                        if(component.status===Component.Ready)
                        {
                            var newWin = component.createObject(null ,{
                            width =win.width,
                            height =win.height,
                            x:win.x,
                            y:win.y,
                            visibility:win.visibility
                                                                })
                            newWin.show();
                            win.close();
                        }
                        console.log("111111!");
                        }
                        else
                        {
                            console.log("2222222");
                            message.open()
                        }
                        }
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
                                var component =Qt.createComponent("clientsignup.qml")
                                if(component.status===Component.Ready)
                                {
                                var newWin = component.createObject(null ,{
                                width =win.width,
                                height =win.height,
                                x:win.x,
                                y:win.y,
                                visibility:win.visibility
                                })
                                newWin.show();
                                win.close();
                            }
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
                                var component =Qt.createComponent("restaurantsignin.qml")
                                                        if(component.status===Component.Ready)
                                                        {
                                                            var newWin = component.createObject(null ,{
                                                            width =win.width,
                                                            height =win.height,
                                                            x:win.x,
                                                            y:win.y,
                                                            visibility:win.visibility
                                                                                                })
                                                            newWin.show();
                                                            win.close();
                                                        }
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
                                var component =Qt.createComponent("deliverysignin.qml")
                                                        if(component.status===Component.Ready)
                                                        {
                                                            var newWin = component.createObject(null ,{
                                                            width =win.width,
                                                            height =win.height,
                                                            x:win.x,
                                                            y:win.y,
                                                            visibility:win.visibility
                                                                                                })
                                                            newWin.show();
                                                        win.close();
                                                    }
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
