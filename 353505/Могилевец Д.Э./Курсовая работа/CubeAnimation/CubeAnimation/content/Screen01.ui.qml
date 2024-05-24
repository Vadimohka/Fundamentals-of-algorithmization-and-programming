

/*
This is a UI file (.ui.qml) that is intended to be edited in Qt Design Studio only.
It is supposed to be strictly declarative and only uses a subset of QML. If you edit
this file manually, you might introduce QML code that is not supported by Qt Design Studio.
Check out https://doc.qt.io/qtcreator/creator-quick-ui-forms.html for details on .ui.qml files.
*/
import QtQuick 6.5
import QtQuick.Controls 6.5
import QtQuick3D 6.5
import QtQuick3D.Effects 6.5
import CubeAnimation

Rectangle {
    width: Constants.width
    height: Constants.height

    color: Constants.backgroundColor
    View3D {
        id: view3D
        anchors.fill: parent
        anchors.leftMargin: 171
        anchors.topMargin: 117
        anchors.rightMargin: 153
        anchors.bottomMargin: 165

        environment: sceneEnvironment

        SceneEnvironment {
            id: sceneEnvironment
            antialiasingMode: SceneEnvironment.MSAA
            antialiasingQuality: SceneEnvironment.High
        }

        Node {
            id: scene

            PerspectiveCamera {
                id: sceneCamera
                x: 0
                y: 0
                eulerRotation.y: -help.x / 2
                eulerRotation.x: -help.y / 2
                pivot.z: -1000
                scale.y: 1
                eulerRotation.z: 0
                z: 0
            }

            Model {
                id: greenCenter
                x: 0
                source: "#Rectangle"
                eulerRotation.y: 0
                eulerRotation.x: 0
                pivot.z: -250
                eulerRotation.z: 0
                z: 0
                materials: green1
            }

            Model {
                id: greenCenterLeftUp
                x: 0
                y: 0
                source: "#Rectangle"
                pivot.y: -100
                z: 0
                pivot.z: -250
                pivot.x: 100
                materials: green1
                eulerRotation.z: 0
                eulerRotation.y: 0
                eulerRotation.x: 0
            }

            Model {
                id: greenEdgeDownCenter
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: 200
                materials: green1
            }

            Model {
                id: greenCenterRightUp
                x: 0
                y: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: -100
                pivot.x: -100
                materials: green1
                eulerRotation.z: 0
                eulerRotation.y: 0
                eulerRotation.x: 0
            }

            Model {
                id: greenEdgeDownLeft
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: 200
                pivot.x: 100
                materials: green1
            }

            Model {
                id: greenAngleLeftDown
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: 200
                pivot.x: 200
                materials: green1
            }

            Model {
                id: greenCenterUp
                x: 0
                source: "#Rectangle"
                pivot.z: -250
                pivot.y: -100
                z: 0
                materials: green1
            }

            Model {
                id: greenEdgeUpCenter
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: -200
                materials: green1
            }

            Model {
                id: greenCenterDown
                x: 0
                source: "#Rectangle"
                pivot.y: 100
                pivot.z: -250
                z: 0
                materials: green1
            }

            Model {
                id: greenAngleRightDown
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: 200
                pivot.x: -200
                materials: green1
            }

            Model {
                id: greenEdgeLeftDown
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: 100
                pivot.x: 200
                materials: green1
            }

            Model {
                id: greenEdgeUpLeft
                x: 0
                y: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: -200
                pivot.x: 100
                materials: green1
                eulerRotation.z: 0
                eulerRotation.y: 0
                eulerRotation.x: 0
            }

            Model {
                id: greenCenterRight
                x: 0
                source: "#Rectangle"
                eulerRotation.z: 0
                eulerRotation.y: 0
                eulerRotation.x: 0
                pivot.z: -250
                pivot.x: -100
                z: 0
                materials: green1
            }

            Model {
                id: greenEdgeUpRight
                x: 0
                y: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: -200
                pivot.x: -100
                materials: green1
                eulerRotation.z: 0
                eulerRotation.y: 0
                eulerRotation.x: 0
            }

            Model {
                id: greenCenterLeft
                x: 0
                source: "#Rectangle"
                pivot.x: 100
                pivot.z: -250
                z: 0
                materials: green1
            }

            Model {
                id: redCenter
                x: 0
                source: "#Rectangle"
                eulerRotation.y: -90
                z: 0
                pivot.z: -250
                materials: red1
                eulerRotation.z: 0.00001
                eulerRotation.x: 0
            }

            Model {
                id: greenEdgeDownRight
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: 200
                pivot.x: -100
                materials: green1
            }

            Model {
                id: greenEdgeRightCenter
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.x: -200
                materials: green1
                eulerRotation.z: 0
                eulerRotation.y: 0
                eulerRotation.x: 0
            }

            Model {
                id: greenCenterLeftDown
                x: 0
                source: "#Rectangle"
                pivot.z: -250
                pivot.y: 100
                pivot.x: 100
                z: 0
                materials: green1
            }

            Model {
                id: redCenterRight
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.x: -100
                materials: red1
                eulerRotation.z: 0
                eulerRotation.y: -90
                eulerRotation.x: 0
            }

            Model {
                id: greenCenterRightDown
                x: 0
                source: "#Rectangle"
                pivot.z: -250
                pivot.y: 100
                pivot.x: -100
                z: 0
                materials: green1
            }

            Model {
                id: greenEdgeRightDown
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: 100
                pivot.x: -200
                materials: green1
            }

            Model {
                id: redCenterLeft
                x: 0
                source: "#Rectangle"
                eulerRotation.y: -90
                z: 0
                pivot.z: -250
                pivot.x: 100
                materials: red1
            }

            Model {
                id: greenEdgeRightUp
                x: 0
                y: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: -100
                pivot.x: -200
                materials: green1
                eulerRotation.z: 0
                eulerRotation.y: 0
                eulerRotation.x: 0
            }

            Model {
                id: redCenterUp
                x: 0
                source: "#Rectangle"
                eulerRotation.y: -90
                z: 0
                pivot.z: -250
                pivot.y: -100
                materials: red1
            }

            Model {
                id: greenEdgeLeftCenter
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.x: 200
                materials: green1
            }

            Model {
                id: redCenterDown
                x: 0
                source: "#Rectangle"
                eulerRotation.y: -90
                z: 0
                pivot.z: -250
                pivot.y: 100
                materials: red1
            }

            Model {
                id: greenEdgeLeftUp
                x: 0
                y: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: -100
                pivot.x: 200
                materials: green1
                eulerRotation.z: 0
                eulerRotation.y: 0
                eulerRotation.x: 0
            }

            Model {
                id: redCenterLeftDown
                x: 0
                source: "#Rectangle"
                eulerRotation.y: -90
                z: 0
                pivot.z: -250
                pivot.y: 100
                pivot.x: 100
                materials: red1
            }

            Model {
                id: greenAngleLeftUp
                x: 0
                source: "#Rectangle"
                pivot.y: -200
                pivot.z: -250
                pivot.x: 200
                z: 0
                materials: green1
            }

            Model {
                id: redCenterRightDown
                x: 0
                source: "#Rectangle"
                eulerRotation.y: -90
                z: 0
                pivot.z: -250
                pivot.y: 100
                pivot.x: -100
                materials: red1
            }

            Model {
                id: greenAngleRightUp
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: -200
                pivot.x: -200
                materials: green1
            }

            Model {
                id: redCenterLeftUp
                x: 0
                y: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: -100
                pivot.x: 100
                materials: red1
                eulerRotation.z: 0
                eulerRotation.y: -90
                eulerRotation.x: 0
            }

            Model {
                id: redCenterRightUp
                x: 0
                y: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: -100
                pivot.x: -100
                materials: red1
                eulerRotation.z: 0
                eulerRotation.y: -90
                eulerRotation.x: 0
            }

            Model {
                id: redEdgeUpCenter
                x: 0
                source: "#Rectangle"
                eulerRotation.y: -90
                z: 0
                pivot.z: -250
                pivot.y: -200
                materials: red1
            }

            Model {
                id: redEdgeUpLeft
                x: 0
                y: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: -200
                pivot.x: 100
                materials: red1
                eulerRotation.z: 0
                eulerRotation.y: -90
                eulerRotation.x: 0
            }

            Model {
                id: redEdgeUpRight
                x: 0
                y: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: -200
                pivot.x: -100
                materials: red1
                eulerRotation.z: 0
                eulerRotation.y: -90
                eulerRotation.x: 0
            }

            Model {
                id: redEdgeRightCenter
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.x: -200
                materials: red1
                eulerRotation.z: 0
                eulerRotation.y: -90
                eulerRotation.x: 0
            }

            Model {
                id: redEdgeRightDown
                x: 0
                source: "#Rectangle"
                eulerRotation.y: -90
                z: 0
                pivot.z: -250
                pivot.y: 100
                pivot.x: -200
                materials: red1
            }

            Model {
                id: redEdgeRightUp
                x: 0
                y: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: -100
                pivot.x: -200
                materials: red1
                eulerRotation.z: 0
                eulerRotation.y: -90
                eulerRotation.x: 0
            }

            Model {
                id: redEdgeDownCenter
                x: 0
                source: "#Rectangle"
                eulerRotation.y: -90
                z: 0
                pivot.z: -250
                pivot.y: 200
                materials: red1
            }

            Model {
                id: redEdgeDownLeft
                x: 0
                source: "#Rectangle"
                eulerRotation.y: -90
                z: 0
                pivot.z: -250
                pivot.y: 200
                pivot.x: 100
                materials: red1
            }

            Model {
                id: redEdgeDownRight
                x: 0
                source: "#Rectangle"
                eulerRotation.y: -90
                z: 0
                pivot.z: -250
                pivot.y: 200
                pivot.x: -100
                materials: red1
            }

            Model {
                id: redEdgeLeftCenter
                x: 0
                source: "#Rectangle"
                eulerRotation.y: -90
                z: 0
                pivot.z: -250
                pivot.x: 200
                materials: red1
            }

            Model {
                id: redEdgeLeftDown
                x: 0
                source: "#Rectangle"
                eulerRotation.y: -90
                z: 0
                pivot.z: -250
                pivot.y: 100
                pivot.x: 200
                materials: red1
            }

            Model {
                id: redEdgeLeftUp
                x: 0
                y: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: -100
                pivot.x: 200
                materials: red1
                eulerRotation.z: 0
                eulerRotation.y: -90
                eulerRotation.x: 0
            }

            Model {
                id: redAngleLeftUp
                x: 0
                source: "#Rectangle"
                eulerRotation.y: -90
                z: 0
                pivot.z: -250
                pivot.y: -200
                pivot.x: 200
                materials: red1
            }

            Model {
                id: redAngleLeftDown
                x: 0
                source: "#Rectangle"
                eulerRotation.y: -90
                z: 0
                pivot.z: -250
                pivot.y: 200
                pivot.x: 200
                materials: red1
            }

            Model {
                id: redAngleRightDown
                x: 0
                source: "#Rectangle"
                eulerRotation.y: -90
                z: 0
                pivot.z: -250
                pivot.y: 200
                pivot.x: -200
                materials: red1
            }

            Model {
                id: redAngleRightUp
                x: 0
                source: "#Rectangle"
                eulerRotation.y: -90
                z: 0
                pivot.z: -250
                pivot.y: -200
                pivot.x: -200
                materials: red1
            }

            DirectionalLight {
                id: greenLight
                x: 0
                eulerRotation.z: 0
                eulerRotation.y: 0
                eulerRotation.x: 0
                z: 0
            }

            DirectionalLight {
                id: redLight
                x: 0
                z: 0
                eulerRotation.z: 0
                eulerRotation.y: -90
                eulerRotation.x: 0
            }

            DirectionalLight {
                id: orangeLight
                x: 0
                z: 0
                eulerRotation.z: 0
                eulerRotation.y: 90
                eulerRotation.x: 0
            }

            DirectionalLight {
                id: blueLight
                x: 0
                z: 0
                eulerRotation.z: 0
                eulerRotation.y: 180
                eulerRotation.x: 0
            }

            DirectionalLight {
                id: yellowLight
                x: 0
                z: 0
                eulerRotation.z: 0
                eulerRotation.y: 0
                eulerRotation.x: -90
            }

            DirectionalLight {
                id: whiteLight
                x: 0
                z: 0
                eulerRotation.z: 0
                eulerRotation.y: 0
                eulerRotation.x: 90
            }

            Model {
                id: whiteCenter
                x: 0
                source: "#Rectangle"
                eulerRotation.y: 0
                z: 0
                pivot.z: -250
                materials: white1
                eulerRotation.z: 0
                eulerRotation.x: 90
            }

            Model {
                id: whiteEdgeDownCenter
                x: 0
                source: "#Rectangle"
                eulerRotation.z: 0
                eulerRotation.y: 0
                eulerRotation.x: 90
                z: 0
                pivot.z: -250
                pivot.y: 200
                materials: white1
            }

            Model {
                id: whiteEdgeDownLeft
                x: 0
                source: "#Rectangle"
                eulerRotation.x: 90
                z: 0
                pivot.z: -250
                pivot.y: 200
                pivot.x: 100
                materials: white1
            }

            Model {
                id: whiteCenterUp
                x: 0
                source: "#Rectangle"
                eulerRotation.z: 0
                eulerRotation.y: 0
                eulerRotation.x: 90
                z: 0
                pivot.z: -250
                pivot.y: -100
                materials: white1
            }

            Model {
                id: whiteCenterDown
                x: 0
                source: "#Rectangle"
                eulerRotation.z: 0
                eulerRotation.y: 0
                eulerRotation.x: 90
                z: 0
                pivot.z: -250
                pivot.y: 100
                materials: white1
            }

            Model {
                id: whiteEdgeLeftDown
                x: 0
                source: "#Rectangle"
                eulerRotation.x: 90
                z: 0
                pivot.z: -250
                pivot.y: 100
                pivot.x: 200
                materials: white1
            }

            Model {
                id: whiteCenterLeftUp
                x: 0
                y: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: -100
                pivot.x: 100
                materials: white1
                eulerRotation.z: 0
                eulerRotation.y: 0
                eulerRotation.x: 90
            }

            Model {
                id: whiteAngleLeftDown
                x: 0
                source: "#Rectangle"
                eulerRotation.x: 90
                z: 0
                pivot.z: -250
                pivot.y: 200
                pivot.x: 200
                materials: white1
            }

            Model {
                id: whiteAngleRightDown
                x: 0
                source: "#Rectangle"
                eulerRotation.x: 90
                z: 0
                pivot.z: -250
                pivot.y: 200
                pivot.x: -200
                materials: white1
            }

            Model {
                id: whiteEdgeUpRight
                x: 0
                y: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: -200
                pivot.x: -100
                materials: white1
                eulerRotation.z: 0
                eulerRotation.y: 0
                eulerRotation.x: 90
            }

            Model {
                id: whiteCenterRight
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.x: -100
                materials: white1
                eulerRotation.z: 0
                eulerRotation.y: 0
                eulerRotation.x: 90
            }

            Model {
                id: whiteCenterLeft
                x: 0
                source: "#Rectangle"
                eulerRotation.x: 90
                z: 0
                pivot.z: -250
                pivot.x: 100
                materials: white1
            }

            Model {
                id: whiteEdgeRightCenter
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.x: -200
                materials: white1
                eulerRotation.z: 0
                eulerRotation.y: 0
                eulerRotation.x: 90
            }

            Model {
                id: whiteEdgeDownRight
                x: 0
                source: "#Rectangle"
                eulerRotation.x: 90
                z: 0
                pivot.z: -250
                pivot.y: 200
                pivot.x: -100
                materials: white1
            }

            Model {
                id: whiteCenterLeftDown
                x: 0
                source: "#Rectangle"
                eulerRotation.x: 90
                z: 0
                pivot.z: -250
                pivot.y: 100
                pivot.x: 100
                materials: white1
            }

            Model {
                id: whiteCenterRightDown
                x: 0
                source: "#Rectangle"
                eulerRotation.x: 90
                z: 0
                pivot.z: -250
                pivot.y: 100
                pivot.x: -100
                materials: white1
            }

            Model {
                id: whiteCenterRightUp
                x: 0
                y: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: -100
                pivot.x: -100
                materials: white1
                eulerRotation.z: 0
                eulerRotation.y: 0
                eulerRotation.x: 90
            }

            Model {
                id: whiteEdgeUpCenter
                x: 0
                source: "#Rectangle"
                eulerRotation.z: 0
                eulerRotation.y: 0
                eulerRotation.x: 90
                z: 0
                pivot.z: -250
                pivot.y: -200
                materials: white1
            }

            Model {
                id: whiteEdgeUpLeft
                x: 0
                y: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: -200
                pivot.x: 100
                materials: white1
                eulerRotation.z: 0
                eulerRotation.y: 0
                eulerRotation.x: 90
            }

            Model {
                id: whiteEdgeRightDown
                x: 0
                source: "#Rectangle"
                eulerRotation.x: 90
                z: 0
                pivot.z: -250
                pivot.y: 100
                pivot.x: -200
                materials: white1
            }

            Model {
                id: whiteEdgeRightUp
                x: 0
                y: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: -100
                pivot.x: -200
                materials: white1
                eulerRotation.z: 0
                eulerRotation.y: 0
                eulerRotation.x: 90
            }

            Model {
                id: whiteEdgeLeftCenter
                x: 0
                source: "#Rectangle"
                eulerRotation.x: 90
                z: 0
                pivot.z: -250
                pivot.x: 200
                materials: white1
            }

            Model {
                id: whiteEdgeLeftUp
                x: 0
                y: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: -100
                pivot.x: 200
                materials: white1
                eulerRotation.z: 0
                eulerRotation.y: 0
                eulerRotation.x: 90
            }

            Model {
                id: whiteAngleLeftUp
                x: 0
                source: "#Rectangle"
                eulerRotation.x: 90
                z: 0
                pivot.z: -250
                pivot.y: -200
                pivot.x: 200
                materials: white1
            }

            Model {
                id: whiteAngleRightUp
                x: 0
                source: "#Rectangle"
                eulerRotation.x: 90
                z: 0
                pivot.z: -250
                pivot.y: -200
                pivot.x: -200
                materials: white1
            }

            Model {
                id: orangeCenter
                x: 0
                source: "#Rectangle"
                eulerRotation.y: 90
                z: 0
                pivot.z: -250
                materials: orange
                eulerRotation.z: 0
                eulerRotation.x: 0
            }

            Model {
                id: orangeEdgeDownCenter
                x: 0
                source: "#Rectangle"
                eulerRotation.y: 90
                z: 0
                pivot.z: -250
                pivot.y: 200
                materials: orange
                eulerRotation.x: 0
            }

            Model {
                id: orangeEdgeDownLeft
                x: 0
                source: "#Rectangle"
                eulerRotation.y: 90
                z: 0
                pivot.z: -250
                pivot.y: 200
                pivot.x: 100
                materials: orange
                eulerRotation.x: 0
            }

            Model {
                id: orangeCenterUp
                x: 0
                source: "#Rectangle"
                eulerRotation.y: 90
                z: 0
                pivot.z: -250
                pivot.y: -100
                materials: orange
                eulerRotation.x: 0
            }

            Model {
                id: orangeCenterDown
                x: 0
                source: "#Rectangle"
                eulerRotation.y: 90
                z: 0
                pivot.z: -250
                pivot.y: 100
                materials: orange
                eulerRotation.x: 0
            }

            Model {
                id: orangeEdgeLeftDown
                x: 0
                source: "#Rectangle"
                eulerRotation.y: 90
                z: 0
                pivot.z: -250
                pivot.y: 100
                pivot.x: 200
                materials: orange
                eulerRotation.x: 0
            }

            Model {
                id: orangeCenterLeftUp
                x: 0
                y: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: -100
                pivot.x: 100
                materials: orange
                eulerRotation.z: 0
                eulerRotation.y: 90
                eulerRotation.x: 0
            }

            Model {
                id: orangeAngleLeftDown
                x: 0
                source: "#Rectangle"
                eulerRotation.y: 90
                z: 0
                pivot.z: -250
                pivot.y: 200
                pivot.x: 200
                materials: orange
                eulerRotation.x: 0
            }

            Model {
                id: orangeAngleRightDown
                x: 0
                source: "#Rectangle"
                eulerRotation.y: 90
                z: 0
                pivot.z: -250
                pivot.y: 200
                pivot.x: -200
                materials: orange
                eulerRotation.x: 0
            }

            Model {
                id: orangeEdgeUpRight
                x: 0
                y: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: -200
                pivot.x: -100
                materials: orange
                eulerRotation.z: 0
                eulerRotation.y: 90
                eulerRotation.x: 0
            }

            Model {
                id: orangeCenterRight
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.x: -100
                materials: orange
                eulerRotation.z: 0
                eulerRotation.y: 90
                eulerRotation.x: 0
            }

            Model {
                id: orangeCenterLeft
                x: 0
                source: "#Rectangle"
                eulerRotation.y: 90
                z: 0
                pivot.z: -250
                pivot.x: 100
                materials: orange
                eulerRotation.x: 0
            }

            Model {
                id: orangeEdgeRightCenter
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.x: -200
                materials: orange
                eulerRotation.z: 0
                eulerRotation.y: 90
                eulerRotation.x: 0
            }

            Model {
                id: orangeEdgeDownRight
                x: 0
                source: "#Rectangle"
                eulerRotation.y: 90
                z: 0
                pivot.z: -250
                pivot.y: 200
                pivot.x: -100
                materials: orange
                eulerRotation.x: 0
            }

            Model {
                id: orangeCenterLeftDown
                x: 0
                source: "#Rectangle"
                eulerRotation.y: 90
                z: 0
                pivot.z: -250
                pivot.y: 100
                pivot.x: 100
                materials: orange
                eulerRotation.x: 0
            }

            Model {
                id: orangeCenterRightDown
                x: 0
                source: "#Rectangle"
                eulerRotation.y: 90
                z: 0
                pivot.z: -250
                pivot.y: 100
                pivot.x: -100
                materials: orange
                eulerRotation.x: 0
            }

            Model {
                id: orangeCenterRightUp
                x: 0
                y: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: -100
                pivot.x: -100
                materials: orange
                eulerRotation.z: 0
                eulerRotation.y: 90
                eulerRotation.x: 0
            }

            Model {
                id: orangeEdgeUpCenter
                x: 0
                source: "#Rectangle"
                eulerRotation.y: 90
                z: 0
                pivot.z: -250
                pivot.y: -200
                materials: orange
                eulerRotation.x: 0
            }

            Model {
                id: orangeEdgeUpLeft
                x: 0
                y: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: -200
                pivot.x: 100
                materials: orange
                eulerRotation.z: 0
                eulerRotation.y: 90
                eulerRotation.x: 0
            }

            Model {
                id: orangeEdgeRightDown
                x: 0
                source: "#Rectangle"
                eulerRotation.y: 90
                z: 0
                pivot.z: -250
                pivot.y: 100
                pivot.x: -200
                materials: orange
                eulerRotation.x: 0
            }

            Model {
                id: orangeEdgeRightUp
                x: 0
                y: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: -100
                pivot.x: -200
                materials: orange
                eulerRotation.z: 0
                eulerRotation.y: 90
                eulerRotation.x: 0
            }

            Model {
                id: orangeEdgeLeftCenter
                x: 0
                source: "#Rectangle"
                eulerRotation.y: 90
                z: 0
                pivot.z: -250
                pivot.x: 200
                materials: orange
                eulerRotation.x: 0
            }

            Model {
                id: orangeEdgeLeftUp
                x: 0
                y: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: -100
                pivot.x: 200
                materials: orange
                eulerRotation.z: 0
                eulerRotation.y: 90
                eulerRotation.x: 0
            }

            Model {
                id: orangeAngleLeftUp
                x: 0
                source: "#Rectangle"
                eulerRotation.y: 90
                z: 0
                pivot.z: -250
                pivot.y: -200
                pivot.x: 200
                materials: orange
                eulerRotation.x: 0
            }

            Model {
                id: orangeAngleRightUp
                x: 0
                source: "#Rectangle"
                eulerRotation.y: 90
                z: 0
                pivot.z: -250
                pivot.y: -200
                pivot.x: -200
                materials: orange
                eulerRotation.x: 0
            }

            Model {
                id: blueCenter
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                materials: blue
                eulerRotation.z: 0
                eulerRotation.y: 0
                eulerRotation.x: -180
            }

            Model {
                id: blueEdgeDownCenter
                x: 0
                source: "#Rectangle"
                eulerRotation.z: 0
                z: 0
                pivot.z: -250
                pivot.y: 200
                materials: blue
                eulerRotation.y: 0
                eulerRotation.x: -180
            }

            Model {
                id: blueEdgeDownLeft
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: 200
                pivot.x: 100
                materials: blue
                eulerRotation.y: 0
                eulerRotation.x: -180
            }

            Model {
                id: blueCenterUp
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: -100
                materials: blue
                eulerRotation.y: 0
                eulerRotation.x: -180
            }

            Model {
                id: blueCenterDown
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: 100
                materials: blue
                eulerRotation.y: 0
                eulerRotation.x: -180
            }

            Model {
                id: blueEdgeLeftDown
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: 100
                pivot.x: 200
                materials: blue
                eulerRotation.y: 0
                eulerRotation.x: -180
            }

            Model {
                id: blueCenterLeftUp
                x: 0
                y: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: -100
                pivot.x: 100
                materials: blue
                eulerRotation.z: 0
                eulerRotation.y: 0
                eulerRotation.x: -180
            }

            Model {
                id: blueAngleLeftDown
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: 200
                pivot.x: 200
                materials: blue
                eulerRotation.y: 0
                eulerRotation.x: -180
            }

            Model {
                id: blueAngleRightDown
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: 200
                pivot.x: -200
                materials: blue
                eulerRotation.y: 0
                eulerRotation.x: -180
            }

            Model {
                id: blueEdgeUpRight
                x: 0
                y: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: -200
                pivot.x: -100
                materials: blue
                eulerRotation.z: 0
                eulerRotation.y: 0
                eulerRotation.x: -180
            }

            Model {
                id: blueCenterRight
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.x: -100
                materials: blue
                eulerRotation.z: 0
                eulerRotation.y: 0
                eulerRotation.x: -180
            }

            Model {
                id: blueCenterLeft
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.x: 100
                materials: blue
                eulerRotation.y: 0
                eulerRotation.x: -180
            }

            Model {
                id: blueEdgeRightCenter
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.x: -200
                materials: blue
                eulerRotation.z: 0
                eulerRotation.y: 0
                eulerRotation.x: -180
            }

            Model {
                id: blueEdgeDownRight
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: 200
                pivot.x: -100
                materials: blue
                eulerRotation.y: 0
                eulerRotation.x: -180
            }

            Model {
                id: blueCenterLeftDown
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: 100
                pivot.x: 100
                materials: blue
                eulerRotation.y: 0
                eulerRotation.x: -180
            }

            Model {
                id: blueCenterRightDown
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: 100
                pivot.x: -100
                materials: blue
                eulerRotation.y: 0
                eulerRotation.x: -180
            }

            Model {
                id: blueCenterRightUp
                x: 0
                y: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: -100
                pivot.x: -100
                materials: blue
                eulerRotation.z: 0
                eulerRotation.y: 0
                eulerRotation.x: -180
            }

            Model {
                id: blueEdgeUpCenter
                x: 0
                source: "#Rectangle"
                eulerRotation.z: 0
                z: 0
                pivot.z: -250
                pivot.y: -200
                materials: blue
                eulerRotation.y: 0
                eulerRotation.x: -180
            }

            Model {
                id: blueEdgeUpLeft
                x: 0
                y: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: -200
                pivot.x: 100
                materials: blue
                eulerRotation.z: 0
                eulerRotation.y: 0
                eulerRotation.x: -180
            }

            Model {
                id: blueEdgeRightDown
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: 100
                pivot.x: -200
                materials: blue
                eulerRotation.y: 0
                eulerRotation.x: -180
            }

            Model {
                id: blueEdgeRightUp
                x: 0
                y: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: -100
                pivot.x: -200
                materials: blue
                eulerRotation.z: 0
                eulerRotation.y: 0
                eulerRotation.x: -180
            }

            Model {
                id: blueEdgeLeftCenter
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.x: 200
                materials: blue
                eulerRotation.y: 0
                eulerRotation.x: -180
            }

            Model {
                id: blueEdgeLeftUp
                x: 0
                y: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: -100
                pivot.x: 200
                materials: blue
                eulerRotation.z: 0
                eulerRotation.y: 0
                eulerRotation.x: -180
            }

            Model {
                id: blueAngleLeftUp
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: -200
                pivot.x: 200
                materials: blue
                eulerRotation.y: 0
                eulerRotation.x: -180
            }

            Model {
                id: blueAngleRightUp
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: -200
                pivot.x: -200
                materials: blue
                eulerRotation.y: 0
                eulerRotation.x: -180
            }

            Model {
                id: yellowCenter
                x: 0
                source: "#Rectangle"
                eulerRotation.y: 0
                z: 0
                pivot.z: -250
                materials: yellow
                eulerRotation.z: 0
                eulerRotation.x: -90
            }

            Model {
                id: yellowEdgeDownLeft
                x: 0
                source: "#Rectangle"
                eulerRotation.x: -90
                z: 0
                pivot.z: -250
                pivot.y: 200
                pivot.x: 100
                materials: yellow
            }

            Model {
                id: yellowCenterUp
                x: 0
                source: "#Rectangle"
                eulerRotation.z: 0
                eulerRotation.y: 0
                eulerRotation.x: -90
                z: 0
                pivot.z: -250
                pivot.y: -100
                materials: yellow
            }

            Model {
                id: yellowCenterDown
                x: 0
                source: "#Rectangle"
                eulerRotation.x: -90
                z: 0
                pivot.z: -250
                pivot.y: 100
                materials: yellow
            }

            Model {
                id: yellowEdgeLeftDown
                x: 0
                source: "#Rectangle"
                eulerRotation.x: -90
                z: 0
                pivot.z: -250
                pivot.y: 100
                pivot.x: 200
                materials: yellow
            }

            Model {
                id: yellowCenterLeftUp
                x: 0
                y: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: -100
                pivot.x: 100
                materials: yellow
                eulerRotation.z: 0
                eulerRotation.y: 0
                eulerRotation.x: -90
            }

            Model {
                id: yellowAngleLeftDown
                x: 0
                source: "#Rectangle"
                eulerRotation.x: -90
                z: 0
                pivot.z: -250
                pivot.y: 200
                pivot.x: 200
                materials: yellow
            }

            Model {
                id: yellowAngleRightDown
                x: 0
                source: "#Rectangle"
                eulerRotation.z: 0
                eulerRotation.y: 0
                eulerRotation.x: -90
                z: 0
                pivot.z: -250
                pivot.y: 200
                pivot.x: -200
                materials: yellow
            }

            Model {
                id: yellowEdgeUpRight
                x: 0
                y: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: -200
                pivot.x: -100
                materials: yellow
                eulerRotation.z: 0
                eulerRotation.y: 0
                eulerRotation.x: -90
            }

            Model {
                id: yellowCenterRight
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.x: -100
                materials: yellow
                eulerRotation.z: 0
                eulerRotation.y: 0
                eulerRotation.x: -90
            }

            Model {
                id: yellowCenterLeft
                x: 0
                source: "#Rectangle"
                eulerRotation.x: -90
                z: 0
                pivot.z: -250
                pivot.x: 100
                materials: yellow
            }

            Model {
                id: yellowEdgeRightCenter
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.x: -200
                materials: yellow
                eulerRotation.z: 0
                eulerRotation.y: 0
                eulerRotation.x: -90
            }

            Model {
                id: yellowEdgeDownRight
                x: 0
                source: "#Rectangle"
                eulerRotation.x: -90
                z: 0
                pivot.z: -250
                pivot.y: 200
                pivot.x: -100
                materials: yellow
            }

            Model {
                id: yellowCenterLeftDown
                x: 0
                source: "#Rectangle"
                eulerRotation.x: -90
                z: 0
                pivot.z: -250
                pivot.y: 100
                pivot.x: 100
                materials: yellow
            }

            Model {
                id: yellowCenterRightDown
                x: 0
                source: "#Rectangle"
                eulerRotation.x: -90
                z: 0
                pivot.z: -250
                pivot.y: 100
                pivot.x: -100
                materials: yellow
            }

            Model {
                id: yellowCenterRightUp
                x: 0
                y: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: -100
                pivot.x: -100
                materials: yellow
                eulerRotation.z: 0
                eulerRotation.y: 0
                eulerRotation.x: -90
            }

            Model {
                id: yellowEdgeUpCenter
                x: 0
                source: "#Rectangle"
                eulerRotation.z: 0
                eulerRotation.y: 0
                eulerRotation.x: -90
                z: 0
                pivot.z: -250
                pivot.y: -200
                materials: yellow
            }

            Model {
                id: yellowEdgeUpLeft
                x: 0
                y: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: -200
                pivot.x: 100
                materials: yellow
                eulerRotation.z: 0
                eulerRotation.y: 0
                eulerRotation.x: -90
            }

            Model {
                id: yellowEdgeRightDown
                x: 0
                source: "#Rectangle"
                eulerRotation.x: -90
                z: 0
                pivot.z: -250
                pivot.y: 100
                pivot.x: -200
                materials: yellow
            }

            Model {
                id: yellowEdgeRightUp
                x: 0
                y: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: -100
                pivot.x: -200
                materials: yellow
                eulerRotation.z: 0
                eulerRotation.y: 0
                eulerRotation.x: -90
            }

            Model {
                id: yellowEdgeLeftCenter
                x: 0
                source: "#Rectangle"
                eulerRotation.x: -90
                z: 0
                pivot.z: -250
                pivot.x: 200
                materials: yellow
            }

            Model {
                id: yellowEdgeLeftUp
                x: 0
                y: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: -100
                pivot.x: 200
                materials: yellow
                eulerRotation.z: 0
                eulerRotation.y: 0
                eulerRotation.x: -90
            }

            Model {
                id: yellowAngleLeftUp
                x: 0
                source: "#Rectangle"
                eulerRotation.x: -90
                z: 0
                pivot.z: -250
                pivot.y: -200
                pivot.x: 200
                materials: yellow
            }

            Model {
                id: yellowAngleRightUp
                x: 0
                source: "#Rectangle"
                eulerRotation.x: -90
                z: 0
                pivot.z: -250
                pivot.y: -200
                pivot.x: -200
                materials: yellow
            }

            Model {
                id: yellowEdgeDownCenter
                x: 0
                source: "#Rectangle"
                eulerRotation.x: -90
                z: 0
                pivot.z: -250
                pivot.y: 200
                materials: yellow
            }
        }

        MouseArea {
            id: rotationArea
            x: 310
            y: -18
            width: 891
            height: 836
            cursorShape: Qt.ArrowCursor
            drag.target: help

            MouseArea {
                id: help
                x: 675
                y: 87
                width: 100
                height: 100
            }

            Button {
                id: button
                x: 198
                y: 65
                text: qsTr("Button")
            }

        }
    }

    Item {
        id: __materialLibrary__
        PrincipledMaterial {
            id: green1
            baseColorMap: greenTexture
            objectName: "green"
            baseColor: "#4aee45"
        }

        Texture {
            id: greenTexture
            source: "green.png"
        }

        PrincipledMaterial {
            id: red1
            baseColorMap: redTexture
            baseColor: "#ff0000"
            objectName: "red"
        }

        Texture {
            id: redTexture
            source: "red.png"
        }

        PrincipledMaterial {
            id: white1
            baseColorMap: whiteTexture
            objectName: "white"
        }

        Texture {
            id: whiteTexture
            source: "white.png"
        }

        PrincipledMaterial {
            id: orange
            baseColorMap: orangeTexture
            objectName: "orange"
        }

        Texture {
            id: orangeTexture
            source: "orange.png"
        }

        PrincipledMaterial {
            id: blue
            baseColorMap: blueTexture
            objectName: "blue"
        }

        Texture {
            id: blueTexture
            source: "blue.png"
        }

        PrincipledMaterial {
            id: yellow
            baseColorMap: yellowTexture
            objectName: "yellow"
        }

        Texture {
            id: yellowTexture
            source: "yellow.png"
        }
    }
}


