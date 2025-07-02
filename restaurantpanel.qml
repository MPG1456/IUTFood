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
    title:"restaurant panel"
    visible: true
    StackView
    {
        id:stackv
        anchors.fill: parent
        initialItem: ""
    }
    Drawer
    {
        id:menu
        edge:Qt.RightEdge
        width:Math.min(win.width/2 ,500)
        height: parent.height
        // Rectangle
        // {
        //     height: menu.height
        //     width: menu.width
        //     color:"#2E2E2E"
        //     radius: 20
        // }
        ListModel
        {
            id:menuelement
            ListElement{name:"Home";pageaddress:"restaurantpanel.qml"}
            ListElement{name:"change menu";pageaddress:"changemenu.qml"}
            ListElement{name:"change order status";pageaddress:"Orderstatus.qml"}
            ListElement{name:"preview";pageaddress:"Preview.qml"}

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
                        stackv.push(model.pageaddress)
                        win.close()
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
                    ListElement{name:"Saleh";order:"kentaki"}
                    ListElement{name:"Parsa";order:"salad"}
                    ListElement{name:"Ali";order:"chicken"}
                    ListElement{name:"Reza";order:"water"}

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
                                spacing: 20
                                Text {
                                    text:name
                                    font.pixelSize: 13
                                    font.bold: true
                                }
                                Text {
                                    text: "order: " + order
                                    font.pixelSize: 11
                                    color: "red"
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
        Button{
        id:cart
        anchors.top: parent.top
        anchors.left: parent.left
        icon.source: "qrc:/projimages/cart.png"
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
