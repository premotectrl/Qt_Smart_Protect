import QtQuick 2.9

import assets 1.0

Item {
    anchors{
        top: parent.top
        bottom: parent.bottom
        left: parent.left
    }
    width:  100

    Rectangle {
        id: navigationBar
        anchors.fill:  parent
        color: "#000000"

        Column {
            NavigationButton {
                iconCharacter: "\uf0c9"
                description: ""
            }
            NavigationButton {
                iconCharacter: "\uf015"
                description: "Dashboard"
            }
            NavigationButton {
                iconCharacter: "\uf234"
                description: "NewCLient"
            }
            NavigationButton {
                iconCharacter: "\uf002"
                description: "FindClient"
            }
        }
    }
}
