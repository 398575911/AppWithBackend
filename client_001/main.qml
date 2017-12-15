import QtQuick 2.7
import QtQuick.Controls 2.1
import QtQuick.Controls.Material 2.2

ApplicationWindow {
    id: window
    visible: true
    height: 600
    width: 800
    title: qsTr("client - 001")
    Material.theme: Material.Dark
    Material.accent: Material.Indigo

    SendPage {
    }
}
