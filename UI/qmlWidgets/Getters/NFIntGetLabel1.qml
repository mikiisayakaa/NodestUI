import QtQuick 2.2

import "../../BaseWidget"

NFText1 {
    property int cppData: 0
    property bool valid: false
    property string typeName: "int"

    text: cppData
    color: valid ? "white" : "red"


    anchors.rightMargin: 0
}
