import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 6.5
import restdb

Window{
    id: win
    width:400
    height:600
    minimumWidth: 400
    minimumHeight: 600
    title:"restaurant sign up"
    visible: true
    Restaurantbatabse {
        id: db
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
                    text: "sign up"
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
                    id:pass
                    placeholderText: "password"
                    width: insiderect.width-30
                    font.pixelSize: 14
                    echoMode: TextInput.Password
                }
                TextField
                {
                    id:namefield
                    placeholderText: "name"
                    width: insiderect.width-30
                    font.pixelSize: 14
                }
                TextField
                {
                    id:resta
                    placeholderText: "restaurant name"
                    width: insiderect.width-30
                    font.pixelSize: 14
                }
                TextField
                {
                    id: country
                    placeholderText: "country"
                    width: insiderect.width-30
                    font.pixelSize: 14
                }
                TextField
                {
                    id: city
                    placeholderText: "city"
                    width: insiderect.width-30
                    font.pixelSize: 14
                }
                TextField
                {
                    id:postalcode
                    placeholderText: "postal code"
                    width: insiderect.width-30
                    font.pixelSize: 14
                }
                TextField
                {
                    id:homeadr
                    placeholderText: "home adress"
                    width: insiderect.width-30
                    font.pixelSize: 14
                }
                TextField
                {
                    id:homephone
                    placeholderText: "home phone"
                    width: insiderect.width-30
                    font.pixelSize: 14
                }
                TextArea
                {
                    id:bio
                    placeholderText: "bio"
                    width: insiderect.width-30
                    font.pixelSize: 14
                }

                Button
                {
                    text: "sumbit"
                    width: parent.width+10
                    onClicked:
                    {
                        if(!db.usernameexist(usernamefield.text))
                        {
                            db.adduser(usernamefield.text , pass.text , namefield.text , resta.text , country.text , city.text , postalcode.text , homeadr.text ,homephone.text , bio.taxt);
                        }
                        else
                        {
                            // db.printAllUsers();
                        console.log("this username already exist")
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
