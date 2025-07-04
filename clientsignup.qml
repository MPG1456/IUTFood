import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 6.5
// import clidb
Window{
    id: win
    width:400
    height:600
    minimumWidth: 400
    minimumHeight: 600
    title:"client sign up"
    visible: true
    // Clientdatbase
    // {
    //     id:db
    // }

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
                    id:username
                    placeholderText: "username"
                    width: insiderect.width-30
                    font.pixelSize: 14
                }
                TextField
                {
                    id:password
                    placeholderText: "password"
                    width: insiderect.width-30
                    font.pixelSize: 14
                    echoMode: TextInput.Password
                }
                TextField
                {
                    id:firstname
                    placeholderText: "firstname"
                    width: insiderect.width-30
                    font.pixelSize: 14
                }
                TextField
                {
                    id:lastname
                    placeholderText: "lastname"
                    width: insiderect.width-30
                    font.pixelSize: 14
                }
                TextField
                {
                    id:phonenum
                    placeholderText: "phone number"
                    width: insiderect.width-30
                    font.pixelSize: 14
                    inputMask: "09999999999;_"
                    onTextChanged: {
                        if(phonenum.text.length>11)
                        {
                            phonenum.text=phonenum.text.slice(0,11)
                        }
                    }
                }
                Column
                {
                    spacing: 7
                    Label
                    {
                    text: "enter your age"
                    }

                SpinBox
                {
                    id:age
                    width: insiderect.width-30
                    font.pixelSize: 14
                    from:5
                    to:200
                    stepSize: 1
                    value:18
                }
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
                    placeholderText: "home address"
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
                Row{
                    spacing:7
                    anchors.horizontalCenter: parent.horizontalCenter
                    width:back.width + submit.width +spacing
                    Button
                    {
                        id:back
                        text: "back"
                        width: col.width/3
                        onClicked:
                        {
                            var component =Qt.createComponent("main.qml")
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
                    Button
                    {
                    id:submit
                    text: "submit"
                    width: col.width/3
                    onClicked:                                        {
                    // if(!db.usernameexist(username.text))
                    // {
                    // db.adduser(username.text , password.text , firstname.text , lastname.text ,age.value, country.text , city.text , postalcode.text , homeadr.text ,homephone.text , phonenum.text);
                    // }
                    // else
                    // {
                    // console.log("this username already exist")
                    // }
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
