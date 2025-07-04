import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 6.5
import "."
ApplicationWindow{
    id: win
    width:400
    height:600
    minimumWidth: 400
    minimumHeight: 600
    title:"delivery panel"
    visible: true
    Drawer
    {
        id:menu
        edge:Qt.RightEdge
        width:Math.min(win.width/2 ,500)
        height: parent.height
        // Rectangle
        // {
        //     anchors.fill: parent
        //     color:"#2E2E2E"
        //     radius: 20
        //     z:-1
        // }
        ListModel
        {
            id:menuelement
            ListElement{name:"Home";pageaddress:"deliverypanel.qml"}
            ListElement{name:"order status";pageaddress:"orderstatus.qml"}
        }
        ListView
        {
            width: parent.width
            height: win.height*5/6
            model: menuelement
            // spacing: 8
            clip: true
            delegate: Rectangle
            {
                id:rectfield
                width:parent.width
                height: 55
                border.color:"#ccc"
                color:"#f5f5f5"
                Row
                {
                    anchors.fill: parent
                    anchors.margins: 10
                    spacing: 8
                    Column
                    {
                        spacing: 20
                        Text {
                            text: name
                            font.pixelSize: 13
                            font.bold: true
                        }
                    }
                }
                MouseArea
                {
                    anchors.fill: parent
                    onClicked:
                    {
                        menu.close()
                        var component =Qt.createComponent(model.pageaddress)
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
                anchors.topMargin: win.height/10
                anchors.left: parent.left
                anchors.leftMargin: 14
                TextField
                {
                    id:searchbar
                    placeholderText: "search..."
                    width: insiderect.width-30
                    font.pixelSize: 14
                }
                ListModel
                {
                    id:element
                    ListElement{name:"Saleh";order:"kentaki";restaurant:"kentakihouse";address:"soroosh"}
                    ListElement{name:"Parsa";order:"salad";restaurant:"Tarkhoon";address:"ahmadabad"}
                    ListElement{name:"Ali";order:"chicken";restaurant:"jan";address:"toghchi"}
                    ListElement{name:"Reza";order:"water";restaurant:"alibaba";address:"soroosh"}

                }
                ListView
                {
                    width: searchbar.width
                    height: win.height*5/6
                    model: element
                    spacing: 8
                    clip: true
                    delegate: Rectangle
                    {
                        width:parent.width
                        height: 80
                        radius:10
                        border.color:"#ccc"
                        color:"#f5f5f5"
                        Row
                        {
                            anchors.fill: parent
                            anchors.margins: 10
                            spacing: 8
                            Column
                            {
                                spacing:20
                                Text {
                                    text:name
                                    font.pixelSize: 13
                                    font.bold: true
                                }
                                Row
                                {
                                    anchors.margins: 10
                                    spacing: 9
                                Text {
                                    text: "order: " + order
                                    font.pixelSize: 11
                                    color: "red"
                                }
                                Text {
                                    text: "restaurant: " + restaurant
                                    font.pixelSize: 11
                                    color: "green"
                                }
                                }
                            }
                        }
                    }
                }

            }

        Button{
        id:hamburger
        anchors.top: parent.top
        anchors.right: parent.right
        icon.source: "qrc:/projimages/hamburger.png"
        width:parent.width/5
        height:parent.height/7.5
        background: null
        anchors.rightMargin: 2
        onClicked:
        {
            console.log("clickeddd")
            menu.open();
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
