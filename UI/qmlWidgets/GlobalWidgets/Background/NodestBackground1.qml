import QtQuick 2.2

Rectangle {
    id: bgd
    width: 100000
    height: 100000
    color: Qt.rgba(0.1, 0.1, 0.1, 1.0)
    focus: true
    x: -50000
    y: -50000

    signal deletePressed()
    signal preCopy()
    signal copy()
    signal deselect()

    signal move()
    signal stopMove()

    property bool movable: false
    property real scaleValue: 1

    MouseArea{
        id: mouseArea
        anchors.fill: parent

        drag.target: movable ? bgd : null

        onClicked:{
            deselect();
        }

        drag.onActiveChanged: {
            if (drag.active){
                cursorShape = Qt.ClosedHandCursor
            }
            else{
                cursorShape = Qt.OpenHandCursor
            }
        }


        onWheel:{
            scaleValue += wheel.angleDelta.y / 1200;
            if (scaleValue < 0.2){
                scaleValue = 0.2;
            }
            else if (scaleValue > 3){
                scaleValue = 3;
            }

        }

    }



    Keys.onPressed:{
        if (event.key === Qt.Key_Delete){
            deletePressed();
        }
        else if (event.key === Qt.Key_Space && !event.isAutoRepeat){
            move();
            if (movable){
                mouseArea.cursorShape = Qt.OpenHandCursor;
            }
        }
        else if (event.modifiers & Qt.ControlModifier){
            if (event.key === Qt.Key_C){
                preCopy();
            }
            else if (event.key === Qt.Key_V){
                copy();
            }
        }

    }


    Keys.onReleased: {
        if (event.key === Qt.Key_Space && !event.isAutoRepeat){
            stopMove();
            mouseArea.cursorShape = Qt.ArrowCursor;
        }
    }

}
