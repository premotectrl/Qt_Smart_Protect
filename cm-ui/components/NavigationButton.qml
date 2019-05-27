import QtQuick 2.9
import assets 1.0
Item{
    property  alias  iconCharacter: textIcon.text
    property alias description: textDescription.text
    property color hoverColour : "#f4c842" //Style.colourNavBarBackground

    signal navigationButtonClicked()

    width: parent.width//Style.widthNavButton
    height: Style.heightNavButton

    Rectangle {
        id:background
        anchors.fill:parent
        color: Style.colourNavBarBackground
        states: [
            State{
                name:"hover"
                PropertyChanges {
                    target: background
                    color: hoverColour
                }
            }
        ]

        Row{
            Text {
                id: textIcon
                width: Style.widthNavButtonIcon
                height: Style.heightNavButtonIcon
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter

                font{
                    family: Style.fontAwesome
                    pixelSize: Style.pixelSizeNavigationBarIcon
                }
                color: Style.colourNavBarFont
                text: "\uf11a"
                // onClicked: masterController.ui_navigationController.goDashboardView()
            }

            Text {
                id: textDescription
                width: Style.widthNavButtonDescription
                height: Style.heightNavButtonDescription
                verticalAlignment: Text.AlignVCenter
                color: Style.colourNavBarFont
                font.pixelSize: Style.pixelSizeNavigationBarText
                text: "SET ME"
            }
        }

        MouseArea{
            anchors.fill: parent
            cursorShape: Qt.PointingHandCursor
            hoverEnabled: true
            onEntered: background.state = "hover"
            onExited: background.state = ""
            onClicked: navigationButtonClicked()
        }

    }


}
