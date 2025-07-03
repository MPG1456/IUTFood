import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

ApplicationWindow{
    id: trackPage
    title: "رهگیری سفارش"
    property int orderStatus: 2  // تستی، در عمل باید از دیتابیس یا C++ بیاد

    ColumnLayout {
        anchors.centerIn: parent
        spacing: 20

        Label {
            text: "شماره سفارش: #12345"
            font.bold: true
            font.pixelSize: 20
        }

        Repeater {
            model: ListModel {
                ListElement { label: "در حال بررسی توسط رستوران" }
                ListElement { label: "در حال آماده‌سازی" }
                ListElement { label: "تحویل به پیک" }
                ListElement { label: "در حال ارسال" }
                ListElement { label: "تحویل داده شد" }
            }

            delegate: Rectangle {
                width: 300
                height: 40
                color: index <= trackPage.orderStatus ? "#4CAF50" : "#e0e0e0"
                radius: 10
                border.color: "gray"
                border.width: 1

                Row {
                    anchors.fill: parent
                    anchors.margins: 10
                    spacing: 10

                    Label {
                        text: (index + 1) + ". " + label
                        color: index <= trackPage.orderStatus ? "white" : "black"
                    }

                    // نشانه مرحله فعلی
                    Rectangle {
                        width: 10; height: 10
                        radius: 5
                        color: index === trackPage.orderStatus ? "yellow" : "transparent"
                        anchors.verticalCenter: parent.verticalCenter
                    }
                }
            }
        }
    }
}
