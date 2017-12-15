import QtQuick 2.7
import QtQuick.Controls 2.1
import QtQuick.Controls.Material 2.2

ApplicationWindow {
    id: window
    visible: true
    visibility: "FullScreen"
    title: qsTr("client - 001")
    Material.theme: Material.Dark
    Material.accent: Material.Indigo

    LoginPage {
    }
}
