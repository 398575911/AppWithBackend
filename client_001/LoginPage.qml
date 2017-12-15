import QtQuick 2.7
import QtQuick.Controls 2.1
import QtQuick.Controls.Material 2.1

Page {
    anchors.fill: parent

    header: ToolBar{
        height: 10
        Rectangle{
            anchors.fill: parent
            color: Material.color(Material.Green)
        }
    }

    Column {
        anchors.centerIn: parent
        width: parent.width * 0.4
        spacing: 16
        TextField {
            id: inputUsername
            width: parent.width
            placeholderText: "username"
        }
        TextField {
            id: inputPassword
            width: parent.width
            echoMode: "Password"
            placeholderText: "password"
        }

        Button {
            id: btnLogin
            text: qsTr("login")
            width: parent.width
            onClicked: {
                var usr_name = inputUsername.text;
                var usr_pass = inputPassword.text;
                var x = apiClient.useSayHello(usr_name);
                console.log(x);
            }
        }
    }

}
