pragma Singleton
import QtQuick 2.9

Item {
    property alias fontAwesome: fontawesomeLoader.name
    readonly property  color colourBackground: "#efefef"
    readonly property color colourNavBarBackground: "#000000"
    readonly property color colourNavBarFont: "#ffffff"
    readonly property int pixelSizeNavigationBarIcon: 42
    readonly property real widthNavButtonIcon: 80
    readonly property real heightNavButtonIcon: widthNavButtonIcon
    readonly property real widthNavButtonDescription: 160
    readonly property real heightNavButtonDescription: heightNavButton
    readonly property real widthNavButton: widthNavButtonIcon + widthNavButtonDescription
    readonly property real heightNavButton: Math.max(heightNavButtonIcon , heightNavButtonDescription)
    readonly property real widthNavBarCollapsed: widthNavButtonIcon
    readonly property real heightNavBarExpanded: widthNavButton
    readonly property int pixelSizeNavigationBarText: 22

    readonly property color colourCommandBarBackground: "#cecece"
    readonly property color colourCommandBarFont: "#131313"
    readonly property color colourCommandBarFontDisabled: "#636363"
    readonly property real heightCommandBar: heightCommandButton
    readonly property int  pixelSizeCommandBarIcon: 32
    readonly property int  pixelSizeCommandBarText: 12
    readonly property real widthCommandButton: 80
    readonly property real heightCommandButton: widthCommandButton
    FontLoader{
    id:fontawesomeLoader
    source: "qrc:/assets/fontawesome.ttf"
    }
}
