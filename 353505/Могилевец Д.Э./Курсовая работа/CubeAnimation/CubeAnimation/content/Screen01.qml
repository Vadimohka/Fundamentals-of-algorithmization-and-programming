

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
import QtQuick.Dialogs 6.5

Rectangle {
    width: Constants.width
    height: Constants.height

    color: Constants.backgroundColor
    View3D {
        id: view3D
        anchors.fill: parent
        anchors.leftMargin: 151
        anchors.topMargin: 66
        anchors.rightMargin: 173
        anchors.bottomMargin: 216

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
                pivot.z: -250
                z: 0
                materials: green1
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("gc")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("gc")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("gc")
                    }
                }
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
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("gcul")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("gcul")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("gcul")
                    }
                }
            }

            Model {
                id: greenEdgeDownCenter
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: 200
                materials: green1
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("gedc")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("gedc")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("gedc")
                    }
                }
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
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("gcur")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("gcur")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("gcur")
                    }
                }
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
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("gedl")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("gedl")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("gedl")
                    }
                }
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
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("gald")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("gald")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("gald")
                    }
                }
            }

            Model {
                id: greenCenterUp
                x: 0
                source: "#Rectangle"
                pivot.z: -250
                pivot.y: -100
                z: 0
                materials: green1
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("gcu")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("gcu")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("gcu")
                    }
                }
            }

            Model {
                id: greenEdgeUpCenter
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: -200
                materials: green1
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("geuc")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("geuc")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("geuc")
                    }
                }
            }

            Model {
                id: greenCenterDown
                x: 0
                source: "#Rectangle"
                pivot.y: 100
                pivot.z: -250
                z: 0
                materials: green1
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("gcd")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("gcd")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("gcd")
                    }
                }
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
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("gard")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("gard")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("gard")
                    }
                }
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
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("geld")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("geld")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("geld")
                    }
                }
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
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("geul")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("geul")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("geul")
                    }
                }
            }

            Model {
                id: greenCenterRight
                x: 0
                source: "#Rectangle"
                pivot.z: -250
                pivot.x: -100
                z: 0
                materials: green1
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("gcr")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("gcr")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("gcr")
                    }
                }
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
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("geur")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("geur")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("geur")
                    }
                }
            }

            Model {
                id: greenCenterLeft
                x: 0
                source: "#Rectangle"
                pivot.x: 100
                pivot.z: -250
                z: 0
                materials: green1
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("gcl")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("gcl")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("gcl")
                    }
                }
            }

            Model {
                id: redCenter
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                materials: red1
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("rc")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("rc")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("rc")
                    }
                }
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
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("gedr")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("gedr")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("gedr")
                    }
                }
            }

            Model {
                id: greenEdgeRightCenter
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.x: -200
                materials: green1
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("gerc")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("gerc")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("gerc")
                    }
                }
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
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("gcdl")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("gcdl")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("gcdl")
                    }
                }
            }

            Model {
                id: redCenterRight
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.x: -100
                materials: red1
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("rcr")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("rcr")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("rcr")
                    }
                }
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
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("gcdr")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("gcdr")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("gcdr")
                    }
                }
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
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("gerd")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("gerd")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("gerd")
                    }
                }
            }

            Model {
                id: redCenterLeft
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.x: 100
                materials: red1
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("rcl")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("rcl")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("rcl")
                    }
                }
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
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("geru")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("geru")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("geru")
                    }
                }
            }

            Model {
                id: redCenterUp
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: -100
                materials: red1
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("rcu")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("rcu")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("rcu")
                    }
                }
            }

            Model {
                id: greenEdgeLeftCenter
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.x: 200
                materials: green1
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("gelc")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("gelc")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("gelc")
                    }
                }
            }

            Model {
                id: redCenterDown
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: 100
                materials: red1
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("rcd")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("rcd")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("rcd")
                    }
                }
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
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("gelu")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("gelu")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("gelu")
                    }
                }
            }

            Model {
                id: redCenterLeftDown
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: 100
                pivot.x: 100
                materials: red1
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("rcdl")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("rcdl")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("rcdl")
                    }
                }
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
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("galu")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("galu")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("galu")
                    }
                }
            }

            Model {
                id: redCenterRightDown
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: 100
                pivot.x: -100
                materials: red1
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("rcdr")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("rcdr")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("rcdr")
                    }
                }
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
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("garu")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("garu")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("garu")
                    }
                }
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
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("rcul")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("rcul")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("rcul")
                    }
                }
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
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("rcur")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("rcur")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("rcur")
                    }
                }
            }

            Model {
                id: redEdgeUpCenter
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: -200
                materials: red1
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("reuc")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("reuc")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("reuc")
                    }
                }
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
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("reul")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("reul")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("reul")
                    }
                }
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
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("reur")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("reur")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("reur")
                    }
                }
            }

            Model {
                id: redEdgeRightCenter
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.x: -200
                materials: red1
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("rerc")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("rerc")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("rerc")
                    }
                }
            }

            Model {
                id: redEdgeRightDown
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: 100
                pivot.x: -200
                materials: red1
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("rerd")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("rerd")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("rerd")
                    }
                }
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
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("reru")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("reru")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("reru")
                    }
                }
            }

            Model {
                id: redEdgeDownCenter
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: 200
                materials: red1
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("redc")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("redc")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("redc")
                    }
                }
            }

            Model {
                id: redEdgeDownLeft
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: 200
                pivot.x: 100
                materials: red1
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("redl")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("redl")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("redl")
                    }
                }
            }

            Model {
                id: redEdgeDownRight
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: 200
                pivot.x: -100
                materials: red1
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("redr")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("redr")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("redr")
                    }
                }
            }

            Model {
                id: redEdgeLeftCenter
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.x: 200
                materials: red1
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("relc")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("relc")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("relc")
                    }
                }
            }

            Model {
                id: redEdgeLeftDown
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: 100
                pivot.x: 200
                materials: red1
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("reld")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("reld")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("reld")
                    }
                }
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
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("relu")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("relu")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("relu")
                    }
                }
            }

            Model {
                id: redAngleLeftUp
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: -200
                pivot.x: 200
                materials: red1
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("ralu")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("ralu")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("ralu")
                    }
                }
            }

            Model {
                id: redAngleLeftDown
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: 200
                pivot.x: 200
                materials: red1
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("rald")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("rald")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("rald")
                    }
                }
            }

            Model {
                id: redAngleRightDown
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: 200
                pivot.x: -200
                materials: red1
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("rard")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("rard")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("rard")
                    }
                }
            }

            Model {
                id: redAngleRightUp
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: -200
                pivot.x: -200
                materials: red1
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("raru")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("raru")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("raru")
                    }
                }
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
                z: 0
                pivot.z: -250
                materials: white1
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("wc")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("wc")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("wc")
                    }
                }
            }

            Model {
                id: whiteEdgeDownCenter
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: 200
                materials: white1
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("wedc")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("wedc")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("wedc")
                    }
                }
            }

            Model {
                id: whiteEdgeDownLeft
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: 200
                pivot.x: 100
                materials: white1
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("wedl")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("wedl")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("wedl")
                    }
                }
            }

            Model {
                id: whiteCenterUp
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: -100
                materials: white1
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("wcu")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("wcu")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("wcu")
                    }
                }
            }

            Model {
                id: whiteCenterDown
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: 100
                materials: white1
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("wcd")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("wcd")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("wcd")
                    }
                }
            }

            Model {
                id: whiteEdgeLeftDown
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: 100
                pivot.x: 200
                materials: white1
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("weld")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("weld")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("weld")
                    }
                }
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
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("wcul")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("wcul")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("wcul")
                    }
                }
            }

            Model {
                id: whiteAngleLeftDown
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: 200
                pivot.x: 200
                materials: white1
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("wald")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("wald")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("wald")
                    }
                }
            }

            Model {
                id: whiteAngleRightDown
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: 200
                pivot.x: -200
                materials: white1
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("ward")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("ward")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("ward")
                    }
                }
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
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("weur")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("weur")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("weur")
                    }
                }
            }

            Model {
                id: whiteCenterRight
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.x: -100
                materials: white1
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("wcr")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("wcr")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("wcr")
                    }
                }
            }

            Model {
                id: whiteCenterLeft
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.x: 100
                materials: white1
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("wcl")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("wcl")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("wcl")
                    }
                }
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
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("werc")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("werc")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("werc")
                    }
                }
            }

            Model {
                id: whiteEdgeDownRight
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: 200
                pivot.x: -100
                materials: white1
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("wedr")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("wedr")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("wedr")
                    }
                }
            }

            Model {
                id: whiteCenterLeftDown
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: 100
                pivot.x: 100
                materials: white1
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("wcdl")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("wcdl")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("wcdl")
                    }
                }
            }

            Model {
                id: whiteCenterRightDown
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: 100
                pivot.x: -100
                materials: white1
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("wcdr")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("wcdr")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("wcdr")
                    }
                }
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
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("wcur")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("wcur")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("wcur")
                    }
                }
            }

            Model {
                id: whiteEdgeUpCenter
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: -200
                materials: white1
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("weuc")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("weuc")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("weuc")
                    }
                }
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
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("weul")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("weul")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("weul")
                    }
                }
            }

            Model {
                id: whiteEdgeRightDown
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: 100
                pivot.x: -200
                materials: white1
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("werd")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("werd")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("werd")
                    }
                }
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
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("weru")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("weru")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("weru")
                    }
                }
            }

            Model {
                id: whiteEdgeLeftCenter
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.x: 200
                materials: white1
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("welc")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("welc")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("welc")
                    }
                }
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
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("welu")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("welu")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("welu")
                    }
                }
            }

            Model {
                id: whiteAngleLeftUp
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: -200
                pivot.x: 200
                materials: white1
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("walu")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("walu")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("walu")
                    }
                }
            }

            Model {
                id: whiteAngleRightUp
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: -200
                pivot.x: -200
                materials: white1
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("waru")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("waru")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("waru")
                    }
                }
            }

            Model {
                id: orangeCenter
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                materials: orange
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("oc")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("oc")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("oc")
                    }
                }
            }

            Model {
                id: orangeEdgeDownCenter
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: 200
                materials: orange
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("oedc")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("oedc")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("oedc")
                    }
                }
            }

            Model {
                id: orangeEdgeDownLeft
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: 200
                pivot.x: 100
                materials: orange
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("oedl")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("oedl")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("oedl")
                    }
                }
            }

            Model {
                id: orangeCenterUp
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: -100
                materials: orange
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("ocu")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("ocu")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("ocu")
                    }
                }
            }

            Model {
                id: orangeCenterDown
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: 100
                materials: orange
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("ocd")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("ocd")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("ocd")
                    }
                }
            }

            Model {
                id: orangeEdgeLeftDown
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: 100
                pivot.x: 200
                materials: orange
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("oeld")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("oeld")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("oeld")
                    }
                }
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
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("ocul")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("ocul")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("ocul")
                    }
                }
            }

            Model {
                id: orangeAngleLeftDown
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: 200
                pivot.x: 200
                materials: orange
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("oald")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("oald")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("oald")
                    }
                }
            }

            Model {
                id: orangeAngleRightDown
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: 200
                pivot.x: -200
                materials: orange
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("oard")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("oard")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("oard")
                    }
                }
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
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("oeur")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("oeur")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("oeur")
                    }
                }
            }

            Model {
                id: orangeCenterRight
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.x: -100
                materials: orange
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("ocr")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("ocr")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("ocr")
                    }
                }
            }

            Model {
                id: orangeCenterLeft
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.x: 100
                materials: orange
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("ocl")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("ocl")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("ocl")
                    }
                }
            }

            Model {
                id: orangeEdgeRightCenter
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.x: -200
                materials: orange
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("oerc")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("oerc")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("oerc")
                    }
                }
            }

            Model {
                id: orangeEdgeDownRight
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: 200
                pivot.x: -100
                materials: orange
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("oedr")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("oedr")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("oedr")
                    }
                }
            }

            Model {
                id: orangeCenterLeftDown
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: 100
                pivot.x: 100
                materials: orange
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("ocdl")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("ocdl")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("ocdl")
                    }
                }
            }

            Model {
                id: orangeCenterRightDown
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: 100
                pivot.x: -100
                materials: orange
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("ocdr")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("ocdr")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("ocdr")
                    }
                }
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
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("ocur")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("ocur")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("ocur")
                    }
                }
            }

            Model {
                id: orangeEdgeUpCenter
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: -200
                materials: orange
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("oeuc")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("oeuc")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("oeuc")
                    }
                }
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
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("oeul")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("oeul")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("oeul")
                    }
                }
            }

            Model {
                id: orangeEdgeRightDown
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: 100
                pivot.x: -200
                materials: orange
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("oerd")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("oerd")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("oerd")
                    }
                }
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
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("oeru")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("oeru")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("oeru")
                    }
                }
            }

            Model {
                id: orangeEdgeLeftCenter
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.x: 200
                materials: orange
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("oelc")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("oelc")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("oelc")
                    }
                }
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
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("oelu")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("oelu")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("oelu")
                    }
                }
            }

            Model {
                id: orangeAngleLeftUp
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: -200
                pivot.x: 200
                materials: orange
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("oalu")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("oalu")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("oalu")
                    }
                }
            }

            Model {
                id: orangeAngleRightUp
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: -200
                pivot.x: -200
                materials: orange
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("oaru")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("oaru")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("oaru")
                    }
                }
            }

            Model {
                id: blueCenter
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                materials: blue
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("bc")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("bc")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("bc")
                    }
                }
            }

            Model {
                id: blueEdgeDownCenter
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: 200
                materials: blue
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("bedc")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("bedc")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("bedc")
                    }
                }
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
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("bedl")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("bedl")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("bedl")
                    }
                }
            }

            Model {
                id: blueCenterUp
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: -100
                materials: blue
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("bcu")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("bcu")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("bcu")
                    }
                }
            }

            Model {
                id: blueCenterDown
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: 100
                materials: blue
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("bcd")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("bcd")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("bcd")
                    }
                }
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
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("beld")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("beld")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("beld")
                    }
                }
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
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("bcul")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("bcul")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("bcul")
                    }
                }
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
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("bald")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("bald")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("bald")
                    }
                }
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
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("bard")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("bard")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("bard")
                    }
                }
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
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("beur")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("beur")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("beur")
                    }
                }
            }

            Model {
                id: blueCenterRight
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.x: -100
                materials: blue
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("bcr")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("bcr")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("bcr")
                    }
                }
            }

            Model {
                id: blueCenterLeft
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.x: 100
                materials: blue
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("bcl")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("bcl")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("bcl")
                    }
                }
            }

            Model {
                id: blueEdgeRightCenter
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.x: -200
                materials: blue
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("berc")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("berc")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("berc")
                    }
                }
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
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("bedr")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("bedr")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("bedr")
                    }
                }
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
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("bcdl")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("bcdl")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("bcdl")
                    }
                }
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
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("bcdr")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("bcdr")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("bcdr")
                    }
                }
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
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("bcur")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("bcur")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("bcur")
                    }
                }
            }

            Model {
                id: blueEdgeUpCenter
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: -200
                materials: blue
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("beuc")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("beuc")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("beuc")
                    }
                }
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
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("beul")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("beul")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("beul")
                    }
                }
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
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("berd")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("berd")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("berd")
                    }
                }
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
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("beru")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("beru")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("beru")
                    }
                }
            }

            Model {
                id: blueEdgeLeftCenter
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.x: 200
                materials: blue
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("belc")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("belc")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("belc")
                    }
                }
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
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("belu")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("belu")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("belu")
                    }
                }
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
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("balu")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("balu")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("balu")
                    }
                }
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
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("baru")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("baru")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("baru")
                    }
                }
            }

            Model {
                id: yellowCenter
                x: 0
                source: "#Rectangle"
                eulerRotation.y: 0
                z: 0
                pivot.z: -250
                materials: yellow
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("yc")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("yc")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("yc")
                    }
                }
            }

            Model {
                id: yellowEdgeDownLeft
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: 200
                pivot.x: 100
                materials: yellow
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("yedl")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("yedl")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("yedl")
                    }
                }
            }

            Model {
                id: yellowCenterUp
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: -100
                materials: yellow
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("ycu")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("ycu")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("ycu")
                    }
                }
            }

            Model {
                id: yellowCenterDown
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: 100
                materials: yellow
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("ycd")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("ycd")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("ycd")
                    }
                }
            }

            Model {
                id: yellowEdgeLeftDown
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: 100
                pivot.x: 200
                materials: yellow
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("yeld")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("yeld")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("yeld")
                    }
                }
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
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("ycul")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("ycul")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("ycul")
                    }
                }
            }

            Model {
                id: yellowAngleLeftDown
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: 200
                pivot.x: 200
                materials: yellow
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("yald")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("yald")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("yald")
                    }
                }
            }

            Model {
                id: yellowAngleRightDown
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: 200
                pivot.x: -200
                materials: yellow
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("yard")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("yard")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("yard")
                    }
                }
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
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("yeur")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("yeur")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("yeur")
                    }
                }
            }

            Model {
                id: yellowCenterRight
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.x: -100
                materials: yellow
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("ycr")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("ycr")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("ycr")
                    }
                }
            }

            Model {
                id: yellowCenterLeft
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.x: 100
                materials: yellow
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("ycl")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("ycl")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("ycl")
                    }
                }
            }

            Model {
                id: yellowEdgeRightCenter
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.x: -200
                materials: yellow
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("yerc")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("yerc")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("yerc")
                    }
                }
            }

            Model {
                id: yellowEdgeDownRight
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: 200
                pivot.x: -100
                materials: yellow
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("yedr")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("yedr")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("yedr")
                    }
                }
            }

            Model {
                id: yellowCenterLeftDown
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: 100
                pivot.x: 100
                materials: yellow
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("ycdl")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("ycdl")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("ycdl")
                    }
                }
            }

            Model {
                id: yellowCenterRightDown
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: 100
                pivot.x: -100
                materials: yellow
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("ycdr")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("ycdr")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("ycdr")
                    }
                }
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
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("ycur")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("ycur")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("ycur")
                    }
                }
            }

            Model {
                id: yellowEdgeUpCenter
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: -200
                materials: yellow
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("yeuc")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("yeuc")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("yeuc")
                    }
                }
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
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("yeul")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("yeul")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("yeul")
                    }
                }
            }

            Model {
                id: yellowEdgeRightDown
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: 100
                pivot.x: -200
                materials: yellow
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("yerd")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("yerd")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("yerd")
                    }
                }
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
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("yeru")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("yeru")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("yeru")
                    }
                }
            }

            Model {
                id: yellowEdgeLeftCenter
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.x: 200
                materials: yellow
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("yelc")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("yelc")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("yelc")
                    }
                }
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
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("yelu")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("yelu")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("yelu")
                    }
                }
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
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("yalu")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("yalu")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("yalu")
                    }
                }
            }

            Model {
                id: yellowAngleRightUp
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: -200
                pivot.x: -200
                materials: yellow
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("yaru")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("yaru")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("yaru")
                    }
                }
            }

            Model {
                id: yellowEdgeDownCenter
                x: 0
                source: "#Rectangle"
                z: 0
                pivot.z: -250
                pivot.y: 200
                materials: yellow
                Timer {
                    interval: 25;
                    repeat: true;
                    running: true;
                    onTriggered: {
                        parent.eulerRotation.x = RubicksCube.getXRotationOf("yedc")
                        parent.eulerRotation.y = RubicksCube.getYRotationOf("yedc")
                        parent.eulerRotation.z = RubicksCube.getZRotationOf("yedc")
                    }
                }
            }
        }

        MouseArea {
            id: rotationArea
            x: 391
            y: 8
            width: 774
            height: 782
            cursorShape: Qt.ArrowCursor
            drag.target: help

            MouseArea {
                id: help
                x: 675
                y: 87
                width: 100
                height: 100
            }
        }

        visible: MainMenu.currState === 1 || MainMenu.currState === 2
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

    Column {
        id: mainMenu
        x: 805
        y: 410
        width: 200
        height: 248
        Button {
            id: buttonOwnAssembling
            width: 200
            height: 58
            text: qsTr("Сборка")
            onClicked: {
                MainMenu.setCurrState(1)
                RubicksCube.setSolved()
            }
        }
        Button {
            id: buttonAutoAssembling
            width: 200
            height: 58
            text: qsTr("Авто-сборка")
            onClicked: {
                MainMenu.setCurrState(2)
                RubicksCube.setSolved()
            }
        }
        Button {
            id: buttonClose
            width: 200
            height: 58
            text: qsTr("Закрыть")
            onClicked: MainMenu.quit()
        }

        visible: MainMenu.currState === 0
    }


    Grid {
        id: gridForOwnAssembling
        x: 87
        y: 250
        width: 322
        height: 401

        Timer {
            id: enablingTimer
            interval: 250;
            repeat: false;
            running: true;
            onTriggered: {
                gridForOwnAssembling.ableButtons(true)
                repeat = false
            }
        }

        function ableButtons(state){
            buttonU.enabled = state
            buttonUst.enabled = state
            buttonR.enabled = state
            buttonRst.enabled = state
            buttonF.enabled = state
            buttonFst.enabled = state
            buttonD.enabled = state
            buttonDst.enabled = state
            buttonL.enabled = state
            buttonLst.enabled = state
            buttonB.enabled = state
            buttonBst.enabled = state
            buttonu.enabled = state
            buttonust.enabled = state
            buttonr.enabled = state
            buttonrst.enabled = state
            buttonf.enabled = state
            buttonfst.enabled = state
            buttond.enabled = state
            buttondst.enabled = state
            buttonl.enabled = state
            buttonlst.enabled = state
            buttonb.enabled = state
            buttonbst.enabled = state
        }

        Button {
            id: buttonU
            x: 100
            y: 150
            text: qsTr("U")
            onClicked: {
                RubicksCube.animateRotU()
                gridForOwnAssembling.ableButtons(false)
                enablingTimer.restart()
            }
        }
        Button {
            id: buttonUst
            x: -100
            y: 150
            text: qsTr("U'")
            onClicked: {
                RubicksCube.animateRotUSt()
                gridForOwnAssembling.ableButtons(false)
                enablingTimer.restart()
            }
        }

        Button {
            id: buttonR
            x: 100
            y: 200
            text: qsTr("R")
            onClicked: {
                RubicksCube.animateRotR()
                gridForOwnAssembling.ableButtons(false)
                enablingTimer.restart()
            }
        }

        Button {
            id: buttonRst
            x: -100
            y: 200
            text: qsTr("R'")
            onClicked: {
                RubicksCube.animateRotRSt()
                gridForOwnAssembling.ableButtons(false)
                enablingTimer.restart()
            }
        }

        Button {
            id: buttonD
            x: -100
            y: 250
            text: qsTr("D'")
            onClicked: {
                RubicksCube.animateRotDSt()
                gridForOwnAssembling.ableButtons(false)
                enablingTimer.restart()
            }
        }

        Button {
            id: buttonDst
            x: 100
            y: 250
            text: qsTr("D")
            onClicked: {
                RubicksCube.animateRotD()
                gridForOwnAssembling.ableButtons(false)
                enablingTimer.restart()
            }
        }

        Button {
            id: buttonL
            x: 100
            y: 300
            text: qsTr("L")
            onClicked: {
                RubicksCube.animateRotL()
                gridForOwnAssembling.ableButtons(false)
                enablingTimer.restart()
            }
        }

        Button {
            id: buttonLst
            x: -100
            y: 300
            text: qsTr("L'")
            onClicked: {
                RubicksCube.animateRotLSt()
                gridForOwnAssembling.ableButtons(false)
                enablingTimer.restart()
            }
        }

        Button {
            id: buttonF
            x: 100
            y: 350
            text: qsTr("F")
            onClicked: {
                RubicksCube.animateRotF()
                gridForOwnAssembling.ableButtons(false)
                enablingTimer.restart()
            }
        }

        Button {
            id: buttonFst
            x: -100
            y: 350
            text: qsTr("F'")
            onClicked: {
                RubicksCube.animateRotFSt()
                gridForOwnAssembling.ableButtons(false)
                enablingTimer.restart()
            }
        }

        Button {
            id: buttonB
            x: 100
            y: 400
            text: qsTr("B")
            onClicked: {
                RubicksCube.animateRotB()
                gridForOwnAssembling.ableButtons(false)
                enablingTimer.restart()
            }
        }

        Button {
            id: buttonBst
            x: -100
            y: 400
            text: qsTr("B'")
            onClicked: {
                RubicksCube.animateRotBSt()
                gridForOwnAssembling.ableButtons(false)
                enablingTimer.restart()
            }
        }

        Button {
            id: buttonu
            x: 1300
            y: 150
            text: qsTr("u")
            onClicked: {
                RubicksCube.animateRotu()
                gridForOwnAssembling.ableButtons(false)
                enablingTimer.restart()
            }
        }

        Button {
            id: buttonust
            x: 1500
            y: 150
            text: qsTr("u'")
            onClicked: {
                RubicksCube.animateRotuSt()
                gridForOwnAssembling.ableButtons(false)
                enablingTimer.restart()
            }
        }

        Button {
            id: buttond
            x: 1300
            y: 200
            text: qsTr("d")
            onClicked: {
                RubicksCube.animateRotd()
                gridForOwnAssembling.ableButtons(false)
                enablingTimer.restart()
            }
        }

        Button {
            id: buttondst
            x: 1500
            y: 200
            text: qsTr("d'")
            onClicked: {
                RubicksCube.animateRotdSt()
                gridForOwnAssembling.ableButtons(false)
                enablingTimer.restart()
            }
        }

        Button {
            id: buttonl
            x: 1300
            y: 250
            text: qsTr("l")
            onClicked: {
                RubicksCube.animateRotl()
                gridForOwnAssembling.ableButtons(false)
                enablingTimer.restart()
            }
        }

        Button {
            id: buttonlst
            x: 1500
            y: 250
            text: qsTr("l'")
            onClicked: {
                RubicksCube.animateRotlSt()
                gridForOwnAssembling.ableButtons(false)
                enablingTimer.restart()
            }
        }

        Button {
            id: buttonr
            x: 1300
            y: 300
            text: qsTr("r")
            onClicked: {
                RubicksCube.animateRotr()
                gridForOwnAssembling.ableButtons(false)
                enablingTimer.restart()
            }
        }

        Button {
            id: buttonrst
            x: 1500
            y: 300
            text: qsTr("r'")
            onClicked: {
                RubicksCube.animateRotrSt()
                gridForOwnAssembling.ableButtons(false)
                enablingTimer.restart()
            }
        }

        Button {
            id: buttonb
            x: 1300
            y: 350
            text: qsTr("b")
            onClicked: {
                RubicksCube.animateRotb()
                gridForOwnAssembling.ableButtons(false)
                enablingTimer.restart()
            }
        }

        Button {
            id: buttonbst
            x: 1500
            y: 350
            text: qsTr("b'")
            onClicked: {
                RubicksCube.animateRotbSt()
                gridForOwnAssembling.ableButtons(false)
                enablingTimer.restart()
            }
        }

        Button {
            id: buttonf
            x: 1300
            y: 400
            text: qsTr("f")
            onClicked: {
                RubicksCube.animateRotf()
                gridForOwnAssembling.ableButtons(false)
                enablingTimer.restart()
            }
        }

        Button {
            id: buttonfst
            x: 1500
            y: 400
            text: qsTr("f'")
            onClicked: {
                RubicksCube.animateRotfSt()
                gridForOwnAssembling.ableButtons(false)
                enablingTimer.restart()
            }
        }
        visible: MainMenu.currState === 1
    }

    Button {
        id: button
        x: 39
        y: 18
        width: 200
        height: 50
        text: qsTr("Главное меню")
        visible: (MainMenu.currState !== 0)
        onClicked: {
            RubicksCube.setSolved()
            MainMenu.setCurrState(0)
        }

        enabled: !RubicksCube.isAutoAnimating
    }


    Column {
        id: columnScramble
        x: 1557
        y: 111
        width: 200
        height: 400
        Button {
            id: button1
            width: 250
            height: 50
            text: "Разобрать случайно"
            onClicked: {
                RubicksCube.setRandomState();
                if (MainMenu.currState === 2) RubicksCube.solve()
            }

            enabled: !RubicksCube.isAutoAnimating
        }
        Button {
            id: button2
            width: 250
            height: 50
            text: qsTr("Разобрать по скрамблу")
            onClicked: {
                MainMenu.setCurrState(4)
                RubicksCube.setSolved()
            }

            enabled: !RubicksCube.isAutoAnimating
        }

        Button {
            id: button3
            width: 250
            height: 50
            text: qsTr("Указать на развёртке")
            onClicked: {
                MainMenu.setCurrState(5)
                RubicksCube.setSolved()
            }

            enabled: !RubicksCube.isAutoAnimating
        }

        visible: MainMenu.currState === 1 || MainMenu.currState === 2
    }



    Item {
        MessageDialog {
            id: messageDialog
            title: "Ошибка!"
            text: "Введите верный скрамбл"
            onAccepted: {
                visible = false
            }
            Component.onCompleted: visible = false
        }
        id: scrambleEnter
        x: 24
        y: -190
        width: 1850
        height: 290
        TextInput {
            id: textEdit
            x: 472
            y: 654
            width: 1345
            height: 72
            font.pixelSize: 50
            focus: MainMenu.currState === 4
            Keys.onReturnPressed: {
                if (RubicksCube.setStateFromScramble(textEdit.text)){
                    textEdit.text = ""
                    if (MainMenu.prevState === 2) RubicksCube.solve()
                    MainMenu.setCurrState(MainMenu.prevState)
                }
                else {
                    MainMenu.setCurrState(4)
                    textEdit.text = ""
                    messageDialog.visible = true
                }
            }
        }

        Frame {
            id: frame
            x: 466
            y: 650
            width: 1347
            height: 72
        }

        Label {
            id: label
            x: 36
            y: 653
            text: qsTr("Введите скрамбл:")
            font.pixelSize: 50
        }
        Button {
            id: button4
            x: 1649
            y: 725
            width: 164
            height: 63
            text: qsTr("ОК")
            onClicked: {
                if (RubicksCube.setStateFromScramble(textEdit.text)){
                    MainMenu.setCurrState(MainMenu.prevState)
                    textEdit.text = ""
                    if (MainMenu.prevState === 2) RubicksCube.solve()
                }
                else {
                    MainMenu.setCurrState(4)
                    textEdit.text = ""
                    messageDialog.visible = true
                }
            }
        }

        visible: MainMenu.currState === 4
    }

    Item {
        id: scrambleSetter
        height: 100
        width: 100
        function getColor(){
            switch (colorRow.selectedColor) {
            case 0:
                return "green.png"
            case 1:
                return "red.png"
            case 2:
                return "yellow.png"
            case 3:
                return "blue.png"
            case 4:
                return "orange.png"
            case 5:
                return "white.png"
            }
        }
        Grid {
            id: greenGrid
            x: 700
            y: 450
            width: 250
            height: 250
            rows: 5
            columns: 5
            Button {
                id: greenAngleLefttDownButton
                property string colorOfElement: "green.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: greenAngleLefttDownButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("gald", colorOfElement)
                }
            }
            Button {
                id: greenEdgeLeftDownButton
                property string colorOfElement: "green.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: greenEdgeLeftDownButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("geld", colorOfElement)
                }
            }
            Button {
                id: greenEdgeLeftCenterButton
                property string colorOfElement: "green.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: greenEdgeLeftCenterButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("gelc", colorOfElement)
                }
            }
            Button {
                id: greenEdgeLeftUpButton
                property string colorOfElement: "green.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: greenEdgeLeftUpButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("gelu", colorOfElement)
                }
            }
            Button {
                id: greenAngleLeftUpButton
                property string colorOfElement: "green.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: greenAngleLeftUpButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("galu", colorOfElement)
                }
            }



            Button {
                id: greenEdgeDownLeftButton
                property string colorOfElement: "green.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: greenEdgeDownLeftButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("gedl", colorOfElement)
                }
            }
            Button {
                id: greenCenterLeftDownButton
                property string colorOfElement: "green.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: greenCenterLeftDownButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("gcdl", colorOfElement)
                }
            }
            Button {
                id: greenCenterLeftButton
                property string colorOfElement: "green.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: greenCenterLeftButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("gcl", colorOfElement)
                }
            }
            Button {
                id: greenCenterLeftUpButton
                property string colorOfElement: "green.png"
                width:50
                height: 50
                    Image {
                    width: 50
                    height: 50
                    source: greenCenterLeftUpButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("gcul", colorOfElement)
                }
            }
            Button {
                id: greenEdgeUpLeftButton
                property string colorOfElement: "green.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: greenEdgeUpLeftButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("geul", colorOfElement)
                }
            }



            Button {
                id: greenEdgeDownCenterButton
                property string colorOfElement: "green.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: greenEdgeDownCenterButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("gedc", colorOfElement)
                }
            }
            Button {
                id: greenCenterDownButton
                property string colorOfElement: "green.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: greenCenterDownButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("gcd", colorOfElement)
                }
            }
            Button {
                id: greenCenterButton
                property string colorOfElement: "green.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: greenCenterButton.colorOfElement
                }
            }
            Button {
                id: greenCenterUpButton
                property string colorOfElement: "green.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: greenCenterUpButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("gcu", colorOfElement)
                }
            }
            Button {
                id: greenEdgeUpCenterButton
                property string colorOfElement: "green.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: greenEdgeUpCenterButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("geuc", colorOfElement)
                }
            }



            Button {
                id: greenEdgeDownRightButton
                property string colorOfElement: "green.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: greenEdgeDownRightButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("gedr", colorOfElement)
                }
            }
            Button {
                id: greenCenterRightDownButton
                property string colorOfElement: "green.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: greenCenterRightDownButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("gcdr", colorOfElement)
                }
            }
            Button {
                id: greenCenterRightButton
                property string colorOfElement: "green.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: greenCenterRightButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("gcr", colorOfElement)
                }
            }
            Button {
                id: greenCenterRightUpButton
                property string colorOfElement: "green.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: greenCenterRightUpButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("gcur", colorOfElement)
                }
            }
            Button {
                id: greenEdgeUpRightButton
                property string colorOfElement: "green.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: greenEdgeUpRightButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("geur", colorOfElement)
                }
            }



            Button {
                id: greenAngleRighttDownButton
                property string colorOfElement: "green.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: greenAngleRighttDownButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("gard", colorOfElement)
                }
            }
            Button {
                id: greenEdgeRightDownButton
                property string colorOfElement: "green.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: greenEdgeRightDownButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("gerd", colorOfElement)
                }
            }
            Button {
                id: greenEdgeRightCenterButton
                property string colorOfElement: "green.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: greenEdgeRightCenterButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("gerc", colorOfElement)
                }
            }
            Button {
                id: greenEdgeRightUpButton
                property string colorOfElement: "green.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: greenEdgeRightUpButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("geru", colorOfElement)
                }
            }
            Button {
                id: greenAngleRightUpButton
                property string colorOfElement: "green.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: greenAngleRightUpButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("garu", colorOfElement)
                }
            }
        }

        Grid {
            id: redGrid
            x: 700
            y: 200
            width: 250
            height: 250
            rows: 5
            columns: 5
            Button {
                id: redAngleLefttDownButton
                property string colorOfElement: "red.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: redAngleLefttDownButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("rald", colorOfElement)
                }
            }
            Button {
                id: redEdgeLeftDownButton
                property string colorOfElement: "red.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: redEdgeLeftDownButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("reld", colorOfElement)
                }
            }
            Button {
                id: redEdgeLeftCenterButton
                property string colorOfElement: "red.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: redEdgeLeftCenterButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("relc", colorOfElement)
                }
            }
            Button {
                id: redEdgeLeftUpButton
                property string colorOfElement: "red.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: redEdgeLeftUpButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("relu", colorOfElement)
                }
            }
            Button {
                id: redAngleLeftUpButton
                property string colorOfElement: "red.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: redAngleLeftUpButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("ralu", colorOfElement)
                }
            }
            Button {
                id: redEdgeDownLeftButton
                property string colorOfElement: "red.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: redEdgeDownLeftButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("redl", colorOfElement)
                }
            }
            Button {
                id: redCenterLeftDownButton
                property string colorOfElement: "red.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: redCenterLeftDownButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("rcdl", colorOfElement)
                }
            }
            Button {
                id: redCenterLeftButton
                property string colorOfElement: "red.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: redCenterLeftButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("rcl", colorOfElement)
                }
            }
            Button {
                id: redCenterLeftUpButton
                property string colorOfElement: "red.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: redCenterLeftUpButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("rcul", colorOfElement)
                }
            }
            Button {
                id: redEdgeUpLeftButton
                property string colorOfElement: "red.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: redEdgeUpLeftButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("reul", colorOfElement)
                }
            }
            Button {
                id: redEdgeDownCenterButton
                property string colorOfElement: "red.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: redEdgeDownCenterButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("redc", colorOfElement)
                }
            }
            Button {
                id: redCenterDownButton
                property string colorOfElement: "red.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: redCenterDownButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("rcd", colorOfElement)
                }
            }
            Button {
                id: redCenterButton
                property string colorOfElement: "red.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: redCenterButton.colorOfElement
                }
            }
            Button {
                id: redCenterUpButton
                property string colorOfElement: "red.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: redCenterUpButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("rcu", colorOfElement)
                }
            }
            Button {
                id: redEdgeUpCenterButton
                property string colorOfElement: "red.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: redEdgeUpCenterButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("reuc", colorOfElement)
                }
            }
            Button {
                id: redEdgeDownRightButton
                property string colorOfElement: "red.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: redEdgeDownRightButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("redr", colorOfElement)
                }
            }
            Button {
                id: redCenterRightDownButton
                property string colorOfElement: "red.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: redCenterRightDownButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("rcdr", colorOfElement)
                }
            }
            Button {
                id: redCenterRightButton
                property string colorOfElement: "red.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: redCenterRightButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("rcr", colorOfElement)
                }
            }
            Button {
                id: redCenterRightUpButton
                property string colorOfElement: "red.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: redCenterRightUpButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("rcur", colorOfElement)
                }
            }
            Button {
                id: redEdgeUpRightButton
                property string colorOfElement: "red.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: redEdgeUpRightButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("reur", colorOfElement)
                }
            }
            Button {
                id: redAngleRighttDownButton
                property string colorOfElement: "red.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: redAngleRighttDownButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("rard", colorOfElement)
                }
            }
            Button {
                id: redEdgeRightDownButton
                property string colorOfElement: "red.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: redEdgeRightDownButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("rerd", colorOfElement)
                }
            }
            Button {
                id: redEdgeRightCenterButton
                property string colorOfElement: "red.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: redEdgeRightCenterButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("rerc", colorOfElement)
                }
            }
            Button {
                id: redEdgeRightUpButton
                property string colorOfElement: "red.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: redEdgeRightUpButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("reru", colorOfElement)
                }
            }
            Button {
                id: redAngleRightUpButton
                property string colorOfElement: "red.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: redAngleRightUpButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("raru", colorOfElement)
                }
            }
        }


        Grid {
            id: yellowGrid
            x: 950
            y: 450
            width: 250
            height: 250
            rows: 5
            columns: 5
            Button {
                id: yellowAngleLefttDownButton
                property string colorOfElement: "yellow.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: yellowAngleLefttDownButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("yald", colorOfElement)
                }
            }
            Button {
                id: yellowEdgeLeftDownButton
                property string colorOfElement: "yellow.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: yellowEdgeLeftDownButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("yeld", colorOfElement)
                }
            }
            Button {
                id: yellowEdgeLeftCenterButton
                property string colorOfElement: "yellow.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: yellowEdgeLeftCenterButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("yelc", colorOfElement)
                }
            }
            Button {
                id: yellowEdgeLeftUpButton
                property string colorOfElement: "yellow.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: yellowEdgeLeftUpButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("yelu", colorOfElement)
                }
            }
            Button {
                id: yellowAngleLeftUpButton
                property string colorOfElement: "yellow.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: yellowAngleLeftUpButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("yalu", colorOfElement)
                }
            }
            Button {
                id: yellowEdgeDownLeftButton
                property string colorOfElement: "yellow.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: yellowEdgeDownLeftButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("yedl", colorOfElement)
                }
            }
            Button {
                id: yellowCenterLeftDownButton
                property string colorOfElement: "yellow.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: yellowCenterLeftDownButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("ycdl", colorOfElement)
                }
            }
            Button {
                id: yellowCenterLeftButton
                property string colorOfElement: "yellow.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: yellowCenterLeftButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("ycl", colorOfElement)
                }
            }
            Button {
                id: yellowCenterLeftUpButton
                property string colorOfElement: "yellow.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: yellowCenterLeftUpButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("ycul", colorOfElement)
                }
            }
            Button {
                id: yellowEdgeUpLeftButton
                property string colorOfElement: "yellow.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: yellowEdgeUpLeftButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("yeul", colorOfElement)
                }
            }

            Button {
                id: yellowEdgeDownCenterButton
                property string colorOfElement: "yellow.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: yellowEdgeDownCenterButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("yedc", colorOfElement)
                }
            }
            Button {
                id: yellowCenterDownButton
                property string colorOfElement: "yellow.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: yellowCenterDownButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("ycd", colorOfElement)
                }
            }
            Button {
                id: yellowCenterButton
                property string colorOfElement: "yellow.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: yellowCenterButton.colorOfElement
                }
            }
            Button {
                id: yellowCenterUpButton
                property string colorOfElement: "yellow.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: yellowCenterUpButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("ycu", colorOfElement)
                }
            }
            Button {
                id: yellowEdgeUpCenterButton
                property string colorOfElement: "yellow.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: yellowEdgeUpCenterButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("yeuc", colorOfElement)
                }
            }
            Button {
                id: yellowEdgeDownRightButton
                property string colorOfElement: "yellow.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: yellowEdgeDownRightButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("yedr", colorOfElement)
                }
            }
            Button {
                id: yellowCenterRightDownButton
                property string colorOfElement: "yellow.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: yellowCenterRightDownButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("ycdr", colorOfElement)
                }
            }
            Button {
                id: yellowCenterRightButton
                property string colorOfElement: "yellow.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: yellowCenterRightButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("ycr", colorOfElement)
                }
            }
            Button {
                id: yellowCenterRightUpButton
                property string colorOfElement: "yellow.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: yellowCenterRightUpButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("ycur", colorOfElement)
                }
            }
            Button {
                id: yellowEdgeUpRightButton
                property string colorOfElement: "yellow.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: yellowEdgeUpRightButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("yeur", colorOfElement)
                }
            }

            Button {
                id: yellowAngleRighttDownButton
                property string colorOfElement: "yellow.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: yellowAngleRighttDownButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("yard", colorOfElement)
                }
            }
            Button {
                id: yellowEdgeRightDownButton
                property string colorOfElement: "yellow.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: yellowEdgeRightDownButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("yerd", colorOfElement)
                }
            }
            Button {
                id: yellowEdgeRightCenterButton
                property string colorOfElement: "yellow.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: yellowEdgeRightCenterButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("yerc", colorOfElement)
                }
            }
            Button {
                id: yellowEdgeRightUpButton
                property string colorOfElement: "yellow.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: yellowEdgeRightUpButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("yeru", colorOfElement)
                }
            }
            Button {
                id: yellowAngleRightUpButton
                property string colorOfElement: "yellow.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: yellowAngleRightUpButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("yaru", colorOfElement)
                }
            }
        }

        Grid {
            id: whiteGrid
            x: 450
            y: 450
            width: 250
            height: 250
            rows: 5
            columns: 5
            Button {
                id: whiteAngleLefttDownButton
                property string colorOfElement: "white.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: whiteAngleLefttDownButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("wald", colorOfElement)
                }
            }
            Button {
                id: whiteEdgeLeftDownButton
                property string colorOfElement: "white.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: whiteEdgeLeftDownButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("weld", colorOfElement)
                }
            }
            Button {
                id: whiteEdgeLeftCenterButton
                property string colorOfElement: "white.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: whiteEdgeLeftCenterButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("welc", colorOfElement)
                }
            }
            Button {
                id: whiteEdgeLeftUpButton
                property string colorOfElement: "white.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: whiteEdgeLeftUpButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("welu", colorOfElement)
                }
            }
            Button {
                id: whiteAngleLeftUpButton
                property string colorOfElement: "white.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: whiteAngleLeftUpButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("walu", colorOfElement)
                }
            }
            Button {
                id: whiteEdgeDownLeftButton
                property string colorOfElement: "white.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: whiteEdgeDownLeftButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("wedl", colorOfElement)
                }
            }
            Button {
                id: whiteCenterLeftDownButton
                property string colorOfElement: "white.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: whiteCenterLeftDownButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("wcdl", colorOfElement)
                }
            }
            Button {
                id: whiteCenterLeftButton
                property string colorOfElement: "white.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: whiteCenterLeftButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("wcl", colorOfElement)
                }
            }
            Button {
                id: whiteCenterLeftUpButton
                property string colorOfElement: "white.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: whiteCenterLeftUpButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("wcul", colorOfElement)
                }
            }
            Button {
                id: whiteEdgeUpLeftButton
                property string colorOfElement: "white.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: whiteEdgeUpLeftButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("weul", colorOfElement)
                }
            }
            Button {
                id: whiteEdgeDownCenterButton
                property string colorOfElement: "white.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: whiteEdgeDownCenterButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("wedc", colorOfElement)
                }
            }
            Button {
                id: whiteCenterDownButton
                property string colorOfElement: "white.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: whiteCenterDownButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("wcd", colorOfElement)
                }
            }
            Button {
                id: whiteCenterButton
                property string colorOfElement: "white.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: whiteCenterButton.colorOfElement
                }
            }
            Button {
                id: whiteCenterUpButton
                property string colorOfElement: "white.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: whiteCenterUpButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("wcu", colorOfElement)
                }
            }
            Button {
                id: whiteEdgeUpCenterButton
                property string colorOfElement: "white.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: whiteEdgeUpCenterButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("weuc", colorOfElement)
                }
            }
            Button {
                id: whiteEdgeDownRightButton
                property string colorOfElement: "white.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: whiteEdgeDownRightButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("wedr", colorOfElement)
                }
            }
            Button {
                id: whiteCenterRightDownButton
                property string colorOfElement: "white.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: whiteCenterRightDownButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("wcdr", colorOfElement)
                }
            }
            Button {
                id: whiteCenterRightButton
                property string colorOfElement: "white.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: whiteCenterRightButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("wcr", colorOfElement)
                }
            }
            Button {
                id: whiteCenterRightUpButton
                property string colorOfElement: "white.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: whiteCenterRightUpButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("wcur", colorOfElement)
                }
            }
            Button {
                id: whiteEdgeUpRightButton
                property string colorOfElement: "white.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: whiteEdgeUpRightButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("weur", colorOfElement)
                }
            }
            Button {
                id: whiteAngleRighttDownButton
                property string colorOfElement: "white.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: whiteAngleRighttDownButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("ward", colorOfElement)
                }
            }
            Button {
                id: whiteEdgeRightDownButton
                property string colorOfElement: "white.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: whiteEdgeRightDownButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("werd", colorOfElement)
                }
            }
            Button {
                id: whiteEdgeRightCenterButton
                property string colorOfElement: "white.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: whiteEdgeRightCenterButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("werc", colorOfElement)
                }
            }
            Button {
                id: whiteEdgeRightUpButton
                property string colorOfElement: "white.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: whiteEdgeRightUpButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("weru", colorOfElement)
                }
            }
            Button {
                id: whiteAngleRightUpButton
                property string colorOfElement: "white.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: whiteAngleRightUpButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("waru", colorOfElement)
                }
            }
        }

        Grid {
            id: orangeGrid
            x: 700
            y: 700
            width: 250
            height: 250
            rows: 5
            columns: 5
            Button {
                id: orangeAngleLefttDownButton
                property string colorOfElement: "orange.png"
                width: 50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: orangeAngleLefttDownButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("oald", colorOfElement)
                }
            }
            Button {
                id: orangeEdgeLeftDownButton
                property string colorOfElement: "orange.png"
                width: 50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: orangeEdgeLeftDownButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("oeld", colorOfElement)
                }
            }
            Button {
                id: orangeEdgeLeftCenterButton
                property string colorOfElement: "orange.png"
                width: 50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: orangeEdgeLeftCenterButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("oelc", colorOfElement)
                }
            }
            Button {
                id: orangeEdgeLeftUpButton
                property string colorOfElement: "orange.png"
                width: 50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: orangeEdgeLeftUpButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("oelu", colorOfElement)
                }
            }
            Button {
                id: orangeAngleLeftUpButton
                property string colorOfElement: "orange.png"
                width: 50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: orangeAngleLeftUpButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("oalu", colorOfElement)
                }
            }
            Button {
                id: orangeEdgeDownLeftButton
                property string colorOfElement: "orange.png"
                width: 50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: orangeEdgeDownLeftButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("oedl", colorOfElement)
                }
            }
            Button {
                id: orangeCenterLeftDownButton
                property string colorOfElement: "orange.png"
                width: 50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: orangeCenterLeftDownButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("ocdl", colorOfElement)
                }
            }
            Button {
                id: orangeCenterLeftButton
                property string colorOfElement: "orange.png"
                width: 50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: orangeCenterLeftButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("ocl", colorOfElement)
                }
            }
            Button {
                id: orangeCenterLeftUpButton
                property string colorOfElement: "orange.png"
                width: 50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: orangeCenterLeftUpButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("ocul", colorOfElement)
                }
            }
            Button {
                id: orangeEdgeUpLeftButton
                property string colorOfElement: "orange.png"
                width: 50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: orangeEdgeUpLeftButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("oeul", colorOfElement)
                }
            }
            Button {
                id: orangeEdgeDownCenterButton
                property string colorOfElement: "orange.png"
                width: 50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: orangeEdgeDownCenterButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("oedc", colorOfElement)
                }
            }
            Button {
                id: orangeCenterDownButton
                property string colorOfElement: "orange.png"
                width: 50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: orangeCenterDownButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("ocd", colorOfElement)
                }
            }
            Button {
                id: orangeCenterButton
                property string colorOfElement: "orange.png"
                width: 50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: orangeCenterButton.colorOfElement
                }
            }
            Button {
                id: orangeCenterUpButton
                property string colorOfElement: "orange.png"
                width: 50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: orangeCenterUpButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("ocu", colorOfElement)
                }
            }
            Button {
                id: orangeEdgeUpCenterButton
                property string colorOfElement: "orange.png"
                width: 50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: orangeEdgeUpCenterButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("oeuc", colorOfElement)
                }
            }
            Button {
                id: orangeEdgeDownRightButton
                property string colorOfElement: "orange.png"
                width: 50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: orangeEdgeDownRightButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("oedr", colorOfElement)
                }
            }
            Button {
                id: orangeCenterRightDownButton
                property string colorOfElement: "orange.png"
                width: 50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: orangeCenterRightDownButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("ocdr", colorOfElement)
                }
            }
            Button {
                id: orangeCenterRightButton
                property string colorOfElement: "orange.png"
                width: 50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: orangeCenterRightButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("ocr", colorOfElement)
                }
            }
            Button {
                id: orangeCenterRightUpButton
                property string colorOfElement: "orange.png"
                width: 50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: orangeCenterRightUpButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("ocur", colorOfElement)
                }
            }
            Button {
                id: orangeEdgeUpRightButton
                property string colorOfElement: "orange.png"
                width: 50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: orangeEdgeUpRightButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("oeur", colorOfElement)
                }
            }
            Button {
                id: orangeAngleRighttDownButton
                property string colorOfElement: "orange.png"
                width: 50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: orangeAngleRighttDownButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("oard", colorOfElement)
                }
            }
            Button {
                id: orangeEdgeRightDownButton
                property string colorOfElement: "orange.png"
                width: 50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: orangeEdgeRightDownButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("oerd", colorOfElement)
                }
            }
            Button {
                id: orangeEdgeRightCenterButton
                property string colorOfElement: "orange.png"
                width: 50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: orangeEdgeRightCenterButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("oerc", colorOfElement)
                }
            }
            Button {
                id: orangeEdgeRightUpButton
                property string colorOfElement: "orange.png"
                width: 50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: orangeEdgeRightUpButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("oeru", colorOfElement)
                }
            }
            Button {
                id: orangeAngleRightUpButton
                property string colorOfElement: "orange.png"
                width: 50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: orangeAngleRightUpButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("oaru", colorOfElement)
                }
            }
        }

        Grid {
            id: blueGrid
            x: 1200
            y: 450
            width: 250
            height: 250
            rows: 5
            columns: 5
            Button {
                id: blueAngleLefttDownButton
                property string colorOfElement: "blue.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: blueAngleLefttDownButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("bald", colorOfElement)
                }
            }
            Button {
                id: blueEdgeLeftDownButton
                property string colorOfElement: "blue.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: blueEdgeLeftDownButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("beld", colorOfElement)
                }
            }
            Button {
                id: blueEdgeLeftCenterButton
                property string colorOfElement: "blue.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: blueEdgeLeftCenterButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("belc", colorOfElement)
                }
            }
            Button {
                id: blueEdgeLeftUpButton
                property string colorOfElement: "blue.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: blueEdgeLeftUpButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("belu", colorOfElement)
                }
            }
            Button {
                id: blueAngleLeftUpButton
                property string colorOfElement: "blue.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: blueAngleLeftUpButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("balu", colorOfElement)
                }
            }
            Button {
                id: blueEdgeDownLeftButton
                property string colorOfElement: "blue.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: blueEdgeDownLeftButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("bedl", colorOfElement)
                }
            }
            Button {
                id: blueCenterLeftDownButton
                property string colorOfElement: "blue.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: blueCenterLeftDownButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("bcdl", colorOfElement)
                }
            }
            Button {
                id: blueCenterLeftButton
                property string colorOfElement: "blue.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: blueCenterLeftButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("bcl", colorOfElement)
                }
            }
            Button {
                id: blueCenterLeftUpButton
                property string colorOfElement: "blue.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: blueCenterLeftUpButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("bcul", colorOfElement)
                }
            }
            Button {
                id: blueEdgeUpLeftButton
                property string colorOfElement: "blue.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: blueEdgeUpLeftButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("beul", colorOfElement)
                }
            }
            Button {
                id: blueEdgeDownCenterButton
                property string colorOfElement: "blue.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: blueEdgeDownCenterButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("bedc", colorOfElement)
                }
            }
            Button {
                id: blueCenterDownButton
                property string colorOfElement: "blue.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: blueCenterDownButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("bcd", colorOfElement)
                }
            }
            Button {
                id: blueCenterButton
                property string colorOfElement: "blue.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: blueCenterButton.colorOfElement
                }
            }
            Button {
                id: blueCenterUpButton
                property string colorOfElement: "blue.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: blueCenterUpButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("bcu", colorOfElement)
                }
            }
            Button {
                id: blueEdgeUpCenterButton
                property string colorOfElement: "blue.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: blueEdgeUpCenterButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("beuc", colorOfElement)
                }
            }
            Button {
                id: blueEdgeDownRightButton
                property string colorOfElement: "blue.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: blueEdgeDownRightButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("bedr", colorOfElement)
                }
            }
            Button {
                id: blueCenterRightDownButton
                property string colorOfElement: "blue.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: blueCenterRightDownButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("bcdr", colorOfElement)
                }
            }
            Button {
                id: blueCenterRightButton
                property string colorOfElement: "blue.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: blueCenterRightButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("bcr", colorOfElement)
                }
            }
            Button {
                id: blueCenterRightUpButton
                property string colorOfElement: "blue.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: blueCenterRightUpButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("bcur", colorOfElement)
                }
            }
            Button {
                id: blueEdgeUpRightButton
                property string colorOfElement: "blue.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: blueEdgeUpRightButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("beur", colorOfElement)
                }
            }
            Button {
                id: blueAngleRighttDownButton
                property string colorOfElement: "blue.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: blueAngleRighttDownButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("bard", colorOfElement)
                }
            }
            Button {
                id: blueEdgeRightDownButton
                property string colorOfElement: "blue.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: blueEdgeRightDownButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("berd", colorOfElement)
                }
            }
            Button {
                id: blueEdgeRightCenterButton
                property string colorOfElement: "blue.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: blueEdgeRightCenterButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("berc", colorOfElement)
                }
            }
            Button {
                id: blueEdgeRightUpButton
                property string colorOfElement: "blue.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: blueEdgeRightUpButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("beru", colorOfElement)
                }
            }
            Button {
                id: blueAngleRightUpButton
                property string colorOfElement: "blue.png"
                width:50
                height: 50
                Image {
                    width: 50
                    height: 50
                    source: blueAngleRightUpButton.colorOfElement
                }
                onClicked: {
                    colorOfElement = scrambleSetter.getColor()
                    RubicksCube.setColor("baru", colorOfElement)
                }
            }
        }

        Row {
            id: colorRow
            x: 595
            y: 38
            width: 600
            height: 100
            property int selectedColor: 0
            Image {
                width: 100
                height: 100
                source: colorRow.selectedColor === 0 ? "choosengreen.png" : "green.png"
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        colorRow.selectedColor = 0
                    }
                }
            }
            Image {
                width: 100
                height: 100
                source: colorRow.selectedColor === 1 ? "choosenred.png" : "red.png"
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        colorRow.selectedColor = 1
                    }
                }
            }
            Image {
                width: 100
                height: 100
                source: colorRow.selectedColor === 2 ? "choosenyellow.png" : "yellow.png"
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        colorRow.selectedColor = 2
                    }
                }
            }
            Image {
                width: 100
                height: 100
                source: colorRow.selectedColor === 3 ? "choosenblue.png" : "blue.png"
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        colorRow.selectedColor = 3
                    }
                }
            }
            Image {
                width: 100
                height: 100
                source: colorRow.selectedColor === 4 ? "choosenorange.png" : "orange.png"
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        colorRow.selectedColor = 4
                    }
                }
            }
            Image {
                width: 100
                height: 100
                source: colorRow.selectedColor === 5 ? "choosenwhite.png" : "white.png"
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        colorRow.selectedColor = 5
                    }
                }
            }
        }
        MessageDialog {
            id: messageDialogForScan
            title: "Ошибка!"
            text: "Данную развёртку невозможно собрать"
            onAccepted: {
                visible = false
            }
            Component.onCompleted: visible = false
        }
        Button {
            id: confirmScanButton
            x: 1621
            y: 773
            width: 163
            height: 70
            text: qsTr("ОК")
            onClicked: {
                if (RubicksCube.stateIsValid()) {
                    RubicksCube.setStateFromScan()
                    if (MainMenu.prevState === 2) {
                       RubicksCube.solve()
                    }
                    MainMenu.setCurrState(MainMenu.prevState)
                }
                else {
                    messageDialogForScan.visible = true
                }
            }
        }
        visible: MainMenu.currState === 5
    }


    Item {
        id: buttonsForSolving

        Button {
            id: buttonBack
            x: 784
            y: 957
            text: qsTr("Назад")
            onClicked: {
                RubicksCube.onBackClicked()
                RubicksCube.disableSolveButtons()
            }
            enabled: !RubicksCube.isFirstMove && !RubicksCube.isAutoAnimating
        }

        Button {
            id: buttonForward
            x: 893
            y: 957
            text: qsTr("Вперёд")
            onClicked: {
                RubicksCube.onForwardClicked()
                RubicksCube.disableSolveButtons()
            }
            enabled: !RubicksCube.isLastMove && !RubicksCube.isAutoAnimating
        }

        Label {
            id: currMoveLabel
            x: 900
            y: 10
            width: 10
            height: 70
            text: RubicksCube.currMoveText
            font.pixelSize: 90
        }

        Label {
            id: prevMovesLabel
            x: 800
            y: 20
            width: 100
            height: 10
            text: RubicksCube.prevSolutionMoves
            font.pixelSize: 50
            horizontalAlignment: Qt.AlignRight
        }

        Label {
            id: nextMovesLabel
            x: 980
            y: 20
            text: RubicksCube.nextSolutionMoves
            font.pixelSize: 50
            horizontalAlignment: Qt.AlignLeft
        }

        Label {
            id: amountOfMovesLabel
            x: 100
            y: 900
            text: "Ходов в решении: " + RubicksCube.amountOfMovesInSolution
            font.pixelSize: 50
            horizontalAlignment: Qt.AlignLeft
        }
        Label {
            id: currMoveNumberLabel
            x: 1200
            y: 900
            text: "Текущий ход: " + RubicksCube.currStepOfSolution
            font.pixelSize: 50
            horizontalAlignment: Qt.AlignLeft
        }

        Button {
            id: buttonAutoAssemblingStart
            x: 191
            y: 615
            text: RubicksCube.animatingButtonText

            onClicked: {
                RubicksCube.onStartStopClicked()
                RubicksCube.disableSolveButtons()
            }

            enabled: !RubicksCube.isLastMove
        }

        visible: MainMenu.currState === 2
    }
}


