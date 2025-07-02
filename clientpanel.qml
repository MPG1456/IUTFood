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
    title:"client panel"
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
        Drawer {
                id: drawer
                edge: Qt.RightEdge
                width: parent.width * 0.7
                modal: true

                Column {
                    anchors.fill: parent
                    spacing: 20
                    padding: 20

                    Label { text: "خانه" }
                    Label { text: "پروفایل" }
                    Label { text: "سفارش‌ها" }
                    Label { text: "خروج" }
                }
            }
        Flickable
        {
            id:insiderect
            clip:true
            anchors.fill: parent
            contentHeight: col.height
            }
            ScrollBar.vertical: ScrollBar
            {
                policy:ScrollBar.AsNeeded
            }
            }

        }

    }
