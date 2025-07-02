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
    title:"client panel"
    visible: true
    StackView
    {
        id:stackv
        anchors.fill: parent
        initialItem: ""
    }
    Drawer {
        id: menu
        edge: Qt.RightEdge
        width: 280
        height: parent.height
        modal: true

        Rectangle {
            anchors.fill: parent
            color: "#2E2E2E"
            radius: 10
            border.color: "#444"
            border.width: 1
            // padding: 10

            Flickable {
                anchors.fill: parent
                contentHeight: col.height

                Column {
                    id: col
                    width: parent.width
                    spacing: 20

                    // بخش اول
                    Rectangle {
                        width: parent.width
                        color: "#3A3A3A"
                        radius: 8
                        // padding: 10

                        Column {
                            spacing: 8
                            anchors.fill: parent

                            Text {
                                text: "حساب کاربری"
                                font.pixelSize: 16
                                color: "white"
                                font.bold: true
                            }

                            // آیتم های بخش حساب کاربری
                            Repeater {
                                model: ["پروفایل", "رمز عبور", "تغییر ایمیل"]
                                delegate: Button {
                                    text: modelData
                                    background: Rectangle {
                                        color: "#555"
                                        radius: 5
                                    }
                                    font.pixelSize: 14
                                    onClicked: {
                                        console.log(text + " کلیک شد")
                                        menu.close()
                                    }
                                }
                            }
                        }
                    }

                    // بخش دوم
                    Rectangle {
                        width: parent.width
                        color: "#3A3A3A"
                        radius: 8
                        // padding: 10

                        Column {
                            spacing: 8
                            anchors.fill: parent

                            Text {
                                text: "تنظیمات"
                                font.pixelSize: 16
                                color: "white"
                                font.bold: true
                            }

                            Repeater {
                                model: ["اعلان‌ها", "حریم خصوصی", "درباره ما"]
                                delegate: Button {
                                    text: modelData
                                    background: Rectangle {
                                        color: "#555"
                                        radius: 5
                                    }
                                    font.pixelSize: 14
                                    onClicked: {
                                        console.log(text + " کلیک شد")
                                        menu.close()
                                    }
                                }
                            }
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
        }
        Button{
        id:hamburger
        anchors.top: parent.top
        anchors.right: parent.right
        icon.source: "qrc:/projimages/hamburger.png"
        width:parent.width/5
        height:parent.height/7.5
        background: null
        anchors.rightMargin: 10
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

