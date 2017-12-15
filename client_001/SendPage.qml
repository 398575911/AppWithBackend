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

        Label {
            text: "a GRPC hello world"
        }

        TextField {
            id: inputUsername
            width: parent.width
            placeholderText: "username"
        }

        Button {
            id: btnLogin
            text: qsTr("send")
            width: parent.width
            onClicked: {
                var usr_name = inputUsername.text;
                var x = apiClient.sayHello(usr_name);
                console.log(x);
            }
        }
    }

}
