import QtQuick 2.9
import assets 1.0

Item {
    property bool isCollapsed: true

    anchors{
        top: parent.top
        bottom: parent.bottom
        left: parent.left
    }

    width:  isCollapsed ? Style.widthNavBarCollapsed : Style.heightNavBarExpanded

    Rectangle {
        id: navigationBar
        anchors.fill:  parent
        color: Style.colourNavBarBackground

        Column {

            width: parent.width

            NavigationButton {
                iconCharacter: "\uf0c9"
                description: ""
                hoverColour: "#993333"
                onNavigationButtonClicked: isCollapsed = !isCollapsed
            }
            NavigationButton {
                iconCharacter: "\uf015"
                description: "Dashboard"
                hoverColour: "#dc8a00"
                onNavigationButtonClicked: masterController.ui_navigationController.goDashboardView();
            }
            NavigationButton {
                iconCharacter: "\uf234"
                description: "New Client"
                hoverColour: "#dccd00"
                onNavigationButtonClicked: masterController.ui_navigationController.goCreateClientView();
            }
            NavigationButton {
                iconCharacter: "\uf002"
                description: "Find Client"
                hoverColour: "#8aef63"
                onNavigationButtonClicked: masterController.ui_navigationController.goFindClientView();
            }
        }
    }
}
