import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Page {
    title: "پیگیری سفارش"
    padding: 20

    ColumnLayout {
        anchors.fill: parent
        spacing: 20

        Label {
            text: "شماره سفارش: #12345"
            font.bold: true
            Layout.alignment: Qt.AlignHCenter
        }

        Label {
            text: "زمان ثبت: 1403/04/10 - 14:26"
            Layout.alignment: Qt.AlignHCenter
        }

        Rectangle {
            Layout.fillWidth: true
            height: 2
            color: "#cccccc"
        }

        // مراحل سفارش
        Repeater {
            model: [
                { step: "ثبت سفارش", done: true },
                { step: "در حال آماده‌سازی", done: true },
                { step: "در حال ارسال", done: false },
                { step: "تحویل داده شد", done: false }
            ]

            delegate: RowLayout {
                spacing: 10
                Layout.fillWidth: true

                CheckBox {
                    checked: modelData.done
                    enabled: false
                }
                Label {
                    text: modelData.step
                    verticalAlignment: Text.AlignVCenter
                }
            }
        }

        Rectangle {
            Layout.fillWidth: true
            height: 2
            color: "#cccccc"
        }

        RowLayout {
            spacing: 20
            Layout.alignment: Qt.AlignHCenter

            Button {
                text: "بروزرسانی"
                onClicked: {
                    // TODO: کد بروزرسانی سفارش را اینجا بنویس
                    console.log("بروزرسانی کلیک شد")
                }
            }
            Button {
                text: "تماس با پشتیبانی"
                onClicked: {
                    // TODO: کد تماس با پشتیبانی اینجا
                    console.log("تماس با پشتیبانی کلیک شد")
                }
            }
        }
    }
}
