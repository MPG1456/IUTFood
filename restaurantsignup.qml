import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 6.5
// import restdb
import Network 1.0
Window{
    id: win
    width:400
    height:600
    minimumWidth: 400
    minimumHeight: 600
    title:"restaurant sign up"
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
                    property int validusername: 0
                    onTextChanged:
                    {
                        if(usernamefield.length<3)
                        {
                            errorText.visible = true
                            errorText.text = "at least 3 character"
                            usernamefield.validusername = 0
                        }
                        else
                        {
                            errorText.visible = false
                            usernamefield.validusername = 1
                        }
                    }
                }
                Text
                {
                id: errorText
                color:"red"
                visible: false
                font.pixelSize: 12
                anchors.margins: 2
                }
                TextField
                {
                    id:pass
                    placeholderText: "password"
                    width: insiderect.width-30
                    font.pixelSize: 14
                    echoMode: TextInput.Password
                    property int validpassword: 0
                    onTextChanged:
                    {
                        if(pass.length<6)
                        {
                            passErr.visible = true
                            passErr.text = "at least 6 character"
                            pass.validpassword = 0
                        }
                        else
                        {
                            passErr.visible = false
                            pass.validpassword = 1
                        }
                    }
                }
                Text
                {
                id: passErr
                color:"red"
                visible: false
                font.pixelSize: 12
                anchors.margins: 2
                }
                // TextField
                // {
                //     id:namefield
                //     placeholderText: "name"
                //     width: insiderect.width-30
                //     font.pixelSize: 14
                //     property int validname: 0
                //     onTextChanged:
                //     {
                //         if(namefield.length<3)
                //         {
                //             nameErr.visible = true
                //             nameErr.text = "at least 3 character"
                //             namefield.validname = 0
                //         }
                //         else
                //         {
                //             nameErr.visible = false
                //             namefield.validname = 1
                //         }
                //     }
                // }
                // Text
                // {
                // id: nameErr
                // color:"red"
                // visible: false
                // font.pixelSize: 12
                // anchors.margins: 2
                // }
                TextField
                {
                    id:resta
                    placeholderText: "restaurant name"
                    width: insiderect.width-30
                    font.pixelSize: 14
                    property int validrestname: 0
                    onTextChanged:
                    {
                        if(resta.length<3)
                        {
                            resNameErr.visible = true
                            resNameErr.text = "at least 3 character"
                            resta.validrestname = 0
                        }
                        else
                        {
                            resNameErr.visible = false
                            resta.validrestname = 1
                        }
                    }
                }
                Text
                {
                id: resNameErr
                color:"red"
                visible: false
                font.pixelSize: 12
                anchors.margins: 2
                }
                TextField
                {
                    id: country
                    placeholderText: "country"
                    width: insiderect.width-30
                    font.pixelSize: 14
                    property int validcountry: 0
                    onTextChanged:
                    {
                        if(country.length<3)
                        {
                            countryErr.visible = true
                            countryErr.text = "at least 3 character"
                            country.validcountry = 0
                        }
                        else
                        {
                            countryErr.visible = false
                            country.validcountry = 1
                        }
                    }
                }
                Text
                {
                id: countryErr
                color:"red"
                visible: false
                font.pixelSize: 12
                anchors.margins: 2
                }
                TextField
                {
                    id: city
                    placeholderText: "city"
                    width: insiderect.width-30
                    font.pixelSize: 14
                    property int validcity: 0
                    onTextChanged:
                    {
                        if(city.length<3)
                        {
                            cityErr.visible = true
                            cityErr.text = "at least 3 character"
                            city.validcity = 0
                        }
                        else
                        {
                            cityErr.visible = false
                            city.validcity = 1
                        }
                    }
                }
                Text
                {
                id: cityErr
                color:"red"
                visible: false
                font.pixelSize: 12
                anchors.margins: 2
                }
                TextField
                {
                    id:postalcode
                    placeholderText: "postal code"
                    width: insiderect.width-30
                    font.pixelSize: 14
                    property int validpost: 0
                    onTextChanged:
                    {
                        if(postalcode.text.length!==10)
                        {
                            postalErr.visible = true
                            postalErr.text = "must have 10 character and should be number"
                            postalcode.validpost = 0
                        }
                        else
                        {
                            var flag=0;
                            for (var i=0 ;i<=9;i+=1)
                            {
                                var isNum = postalcode.text.charCodeAt(i)
                                if(isNum<48 || isNum >57)
                                {
                                    flag=1
                                }
                            }
                            if (flag===1)
                            {
                                postalErr.visible = true
                                postalErr.text = "must be 10 character and should be number"
                                postalcode.validpost = 0
                            }
                            else
                            {
                            postalErr.visible = false
                            postalcode.validpost = 1
                            }
                        }
                    }
                }
                Text
                {
                id: postalErr
                color:"red"
                visible: false
                font.pixelSize: 12
                anchors.margins: 2
                }
                Dialog
                {
                id:message
                title: "signup was successful ✔"
                standardButtons: Dialog.Ok
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
                TextField
                {
                    id:homeadr
                    placeholderText: "home adress"
                    width: insiderect.width-30
                    font.pixelSize: 14
                    property int validhome: 0
                    onTextChanged:
                    {
                        if(homeadr.length<3)
                        {
                            addressErr.visible = true
                            addressErr.text = "at least 3 character"
                            homeadr.validhome = 0
                        }
                        else
                        {
                            addressErr.visible = false
                            homeadr.validhome = 1
                        }
                    }
                }
                Text
                {
                id: addressErr
                color:"red"
                visible: false
                font.pixelSize: 12
                anchors.margins: 2
                }
                TextField
                {
                    id:homephone
                    placeholderText: "home phone"
                    width: insiderect.width-30
                    font.pixelSize: 14
                    property int validHomePhone: 0
                    onTextChanged: {
                        if (homephone.text.length !== 8) {
                            homePhoneErr.visible = true
                            homePhoneErr.text = "must be 8 character and should be number"
                            homephone.validHomePhone = 0
                        } else {
                            var flag = 0
                            for (var i = 0; i < 8; i++) {
                                var code = homephone.text.charCodeAt(i)
                                if (code < 48 || code > 57) {
                                    flag = 1
                                    break
                                }
                            }

                            if (flag === 1) {
                                homePhoneErr.visible = true
                                homePhoneErr.text = "must be 8 character and should be number"
                                homephone.validHomePhone = 0
                            } else
                            {
                                homePhoneErr.visible = false
                                homephone.validHomePhone = 1
                            }
                        }
                    }

                }
                Text
                {
                id: homePhoneErr
                color:"red"
                visible: false
                font.pixelSize: 12
                anchors.margins: 2
                }
                TextField
                {
                    id:phone
                    placeholderText: "phone number"
                    width: insiderect.width-30
                    font.pixelSize: 14
                    property int validPhone: 0
                    onTextChanged: {
                        if (phone.text.length !== 11) {
                            phoneErr.visible = true
                            phoneErr.text = "must be 11 character and should be number"
                            phone.validPhone = 0
                        } else {
                            var flag = 0
                            for (var i = 0; i < 11; i++) {
                                var code = phone.text.charCodeAt(i)
                                if (code < 48 || code > 57) {
                                    flag = 1
                                    break
                                }
                            }

                            if (flag === 1) {
                                phoneErr.visible = true
                                phoneErr.text = "must be 11 character and should be number"
                                phone.validPhone = 0
                            } else
                            {
                                phoneErr.visible = false
                                phone.validPhone = 1
                            }
                        }
                    }

                }
                Text
                {
                id: phoneErr
                color:"red"
                visible: false
                font.pixelSize: 12
                anchors.margins: 2
                }
                TextArea
                {
                    id:bio
                    placeholderText: "bio"
                    width: insiderect.width-30
                    font.pixelSize: 14
                    property int validbio: 0
                    onTextChanged:
                    {
                        if(bio.length<10)
                        {
                            bioErr.visible = true
                            bioErr.text = "at least 10 character"
                            bio.validbio = 0
                        }
                        else
                        {
                            bioErr.visible = false
                            bio.validbio = 1
                        }
                    }
                }
                Text
                {
                id: bioErr
                color:"red"
                visible: false
                font.pixelSize: 12
                anchors.margins: 2
                }
                Row{
                    spacing:7
                    anchors.horizontalCenter: parent.horizontalCenter
                    width:back.width + submit.width + spacing
                    Button
                    {
                        id:back
                        text: "back"
                        width: col.width/3
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
                        }                    }
                    Button
                    {
                        id:submit
                        text: "submit"
                        width: col.width/3
                        onClicked:
                        {
                            if (usernamefield.validusername && pass.validpassword && phone.validPhone &&
                                        resta.validrestname && country.validcountry && city.validcity &&
                                        postalcode.validpost && homeadr.validhome && homephone.validHomePhone && bio.validbio)
                                {
                                message.open()
                                var obj = {
                                           "type": "signup",
                                           "username": usernamefield.text,
                                           "password": pass.text,
                                           "restaurantName": resta.text,
                                           "country": country.text,
                                           "city": city.text,
                                           "postalcode": postalcode.text,
                                           "address": homeadr.text,
                                           "homePhone": homephone.text,
                                           "phoneNumber": phone.text,
                                           "bio": bio.text,
                                           "role":"Restaurant"
                                       }
                                    var jsonStr = JSON.stringify(obj)
                                    Network.sendData(jsonStr)
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
}
