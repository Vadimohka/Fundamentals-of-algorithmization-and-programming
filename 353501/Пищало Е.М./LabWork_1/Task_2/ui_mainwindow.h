/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *MainStats;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout;
    QComboBox *comboBox;
    QSpacerItem *verticalSpacer_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QDoubleSpinBox *doubleCoordX;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QDoubleSpinBox *doubleCoordY;
    QSpacerItem *verticalSpacer_5;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QDoubleSpinBox *doubleCoordX_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_6;
    QDoubleSpinBox *doubleCoordY_2;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QDoubleSpinBox *doubleScaleBox;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QDoubleSpinBox *doubleRotateBox;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_8;
    QLabel *Perimeter;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_10;
    QLabel *Area;
    QSpacerItem *verticalSpacer_6;
    QPushButton *Reset;
    QGraphicsView *graphicsView;
    QGroupBox *Param_Rect;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_8;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_11;
    QDoubleSpinBox *doubleSideA;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_12;
    QDoubleSpinBox *doubleSideB;
    QSpacerItem *verticalSpacer_7;
    QGroupBox *Param_Ell;
    QVBoxLayout *verticalLayout_6;
    QSpacerItem *verticalSpacer_9;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_14;
    QDoubleSpinBox *doubleMajorAxis;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_13;
    QDoubleSpinBox *doubleMinorAxis;
    QSpacerItem *verticalSpacer_10;
    QGroupBox *Param_Rhomb;
    QVBoxLayout *verticalLayout_7;
    QSpacerItem *verticalSpacer_11;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_15;
    QDoubleSpinBox *doubleSpinBox_2;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_16;
    QDoubleSpinBox *doubleSpinBox;
    QSpacerItem *verticalSpacer_13;
    QGroupBox *Param_Sqr;
    QVBoxLayout *verticalLayout_8;
    QSpacerItem *verticalSpacer_12;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_17;
    QDoubleSpinBox *doubleSideSqr;
    QSpacerItem *verticalSpacer_14;
    QGroupBox *Param_Circle;
    QVBoxLayout *verticalLayout_9;
    QSpacerItem *verticalSpacer_15;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_18;
    QDoubleSpinBox *doubleRadiusCircle;
    QSpacerItem *verticalSpacer_16;
    QGroupBox *Param_Star;
    QVBoxLayout *verticalLayout_10;
    QSpacerItem *verticalSpacer_17;
    QHBoxLayout *horizontalLayout_20;
    QLabel *label_21;
    QSpinBox *StarPoints;
    QSpacerItem *verticalSpacer_19;
    QHBoxLayout *horizontalLayout_18;
    QLabel *label_19;
    QDoubleSpinBox *doubleRadiusAStar;
    QHBoxLayout *horizontalLayout_19;
    QLabel *label_20;
    QDoubleSpinBox *doubleRadiusBStar;
    QSpacerItem *verticalSpacer_18;
    QGroupBox *Param_Poly;
    QVBoxLayout *verticalLayout_11;
    QSpacerItem *verticalSpacer_22;
    QHBoxLayout *horizontalLayout_21;
    QLabel *label_22;
    QSpinBox *PolyPoints;
    QSpacerItem *verticalSpacer_21;
    QHBoxLayout *horizontalLayout_22;
    QLabel *label_23;
    QDoubleSpinBox *doubleSidePoly;
    QSpacerItem *verticalSpacer_20;
    QGroupBox *Param_Triangle;
    QVBoxLayout *verticalLayout_12;
    QSpacerItem *verticalSpacer_23;
    QHBoxLayout *horizontalLayout_24;
    QLabel *label_25;
    QDoubleSpinBox *TriangleSideA;
    QHBoxLayout *horizontalLayout_23;
    QLabel *label_24;
    QDoubleSpinBox *TriangleSideB;
    QHBoxLayout *horizontalLayout_25;
    QLabel *label_26;
    QDoubleSpinBox *TriangleSideC;
    QSpacerItem *verticalSpacer_24;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1715, 697);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_3 = new QHBoxLayout(centralwidget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        MainStats = new QGroupBox(centralwidget);
        MainStats->setObjectName(QString::fromUtf8("MainStats"));
        verticalLayout_3 = new QVBoxLayout(MainStats);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalSpacer_2 = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        comboBox = new QComboBox(MainStats);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        verticalLayout->addWidget(comboBox);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        groupBox = new QGroupBox(MainStats);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_4 = new QVBoxLayout(groupBox);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        doubleCoordX = new QDoubleSpinBox(groupBox);
        doubleCoordX->setObjectName(QString::fromUtf8("doubleCoordX"));
        doubleCoordX->setMinimum(-1000.000000000000000);
        doubleCoordX->setMaximum(1000.000000000000000);

        horizontalLayout->addWidget(doubleCoordX);


        verticalLayout_4->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_4->addWidget(label_2);

        doubleCoordY = new QDoubleSpinBox(groupBox);
        doubleCoordY->setObjectName(QString::fromUtf8("doubleCoordY"));
        doubleCoordY->setMinimum(-1000.000000000000000);
        doubleCoordY->setMaximum(1000.000000000000000);

        horizontalLayout_4->addWidget(doubleCoordY);


        verticalLayout_4->addLayout(horizontalLayout_4);


        verticalLayout->addWidget(groupBox);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);

        groupBox_3 = new QGroupBox(MainStats);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        verticalLayout_5 = new QVBoxLayout(groupBox_3);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_6->addWidget(label_5);

        doubleCoordX_2 = new QDoubleSpinBox(groupBox_3);
        doubleCoordX_2->setObjectName(QString::fromUtf8("doubleCoordX_2"));
        doubleCoordX_2->setMinimum(-1000.000000000000000);
        doubleCoordX_2->setMaximum(1000.000000000000000);

        horizontalLayout_6->addWidget(doubleCoordX_2);


        verticalLayout_5->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_7->addWidget(label_6);

        doubleCoordY_2 = new QDoubleSpinBox(groupBox_3);
        doubleCoordY_2->setObjectName(QString::fromUtf8("doubleCoordY_2"));
        doubleCoordY_2->setMinimum(-1000.000000000000000);
        doubleCoordY_2->setMaximum(1000.000000000000000);

        horizontalLayout_7->addWidget(doubleCoordY_2);


        verticalLayout_5->addLayout(horizontalLayout_7);


        verticalLayout->addWidget(groupBox_3);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(MainStats);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        doubleScaleBox = new QDoubleSpinBox(MainStats);
        doubleScaleBox->setObjectName(QString::fromUtf8("doubleScaleBox"));
        doubleScaleBox->setMinimum(0.100000000000000);
        doubleScaleBox->setMaximum(9999.989999999999782);
        doubleScaleBox->setSingleStep(0.100000000000000);
        doubleScaleBox->setValue(1.000000000000000);

        horizontalLayout_2->addWidget(doubleScaleBox);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_3->addLayout(verticalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_4 = new QLabel(MainStats);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_5->addWidget(label_4);

        doubleRotateBox = new QDoubleSpinBox(MainStats);
        doubleRotateBox->setObjectName(QString::fromUtf8("doubleRotateBox"));
        doubleRotateBox->setMinimum(-9999.989999999999782);
        doubleRotateBox->setMaximum(9999.989999999999782);

        horizontalLayout_5->addWidget(doubleRotateBox);


        verticalLayout_3->addLayout(horizontalLayout_5);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_8 = new QLabel(MainStats);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_8->addWidget(label_8);

        Perimeter = new QLabel(MainStats);
        Perimeter->setObjectName(QString::fromUtf8("Perimeter"));

        horizontalLayout_8->addWidget(Perimeter);


        verticalLayout_3->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_10 = new QLabel(MainStats);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_9->addWidget(label_10);

        Area = new QLabel(MainStats);
        Area->setObjectName(QString::fromUtf8("Area"));

        horizontalLayout_9->addWidget(Area);


        verticalLayout_3->addLayout(horizontalLayout_9);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_6);

        Reset = new QPushButton(MainStats);
        Reset->setObjectName(QString::fromUtf8("Reset"));
        Reset->setMinimumSize(QSize(0, 40));

        verticalLayout_3->addWidget(Reset);


        horizontalLayout_3->addWidget(MainStats);

        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setMinimumSize(QSize(0, 0));
        graphicsView->setMaximumSize(QSize(10000, 6350));

        horizontalLayout_3->addWidget(graphicsView);

        Param_Rect = new QGroupBox(centralwidget);
        Param_Rect->setObjectName(QString::fromUtf8("Param_Rect"));
        verticalLayout_2 = new QVBoxLayout(Param_Rect);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_8);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_11 = new QLabel(Param_Rect);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_12->addWidget(label_11);

        doubleSideA = new QDoubleSpinBox(Param_Rect);
        doubleSideA->setObjectName(QString::fromUtf8("doubleSideA"));
        doubleSideA->setMinimum(0.100000000000000);
        doubleSideA->setMaximum(9999.000000000000000);
        doubleSideA->setValue(100.000000000000000);

        horizontalLayout_12->addWidget(doubleSideA);


        verticalLayout_2->addLayout(horizontalLayout_12);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        label_12 = new QLabel(Param_Rect);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_14->addWidget(label_12);

        doubleSideB = new QDoubleSpinBox(Param_Rect);
        doubleSideB->setObjectName(QString::fromUtf8("doubleSideB"));
        doubleSideB->setMinimum(0.100000000000000);
        doubleSideB->setMaximum(9999.989999999999782);
        doubleSideB->setValue(50.000000000000000);

        horizontalLayout_14->addWidget(doubleSideB);


        verticalLayout_2->addLayout(horizontalLayout_14);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_7);


        horizontalLayout_3->addWidget(Param_Rect);

        Param_Ell = new QGroupBox(centralwidget);
        Param_Ell->setObjectName(QString::fromUtf8("Param_Ell"));
        verticalLayout_6 = new QVBoxLayout(Param_Ell);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_9);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        label_14 = new QLabel(Param_Ell);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        horizontalLayout_16->addWidget(label_14);

        doubleMajorAxis = new QDoubleSpinBox(Param_Ell);
        doubleMajorAxis->setObjectName(QString::fromUtf8("doubleMajorAxis"));
        doubleMajorAxis->setMinimum(0.100000000000000);
        doubleMajorAxis->setMaximum(9999.989999999999782);
        doubleMajorAxis->setValue(100.000000000000000);

        horizontalLayout_16->addWidget(doubleMajorAxis);


        verticalLayout_6->addLayout(horizontalLayout_16);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        label_13 = new QLabel(Param_Ell);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        horizontalLayout_15->addWidget(label_13);

        doubleMinorAxis = new QDoubleSpinBox(Param_Ell);
        doubleMinorAxis->setObjectName(QString::fromUtf8("doubleMinorAxis"));
        doubleMinorAxis->setMinimum(0.100000000000000);
        doubleMinorAxis->setMaximum(9999.989999999999782);
        doubleMinorAxis->setValue(50.000000000000000);

        horizontalLayout_15->addWidget(doubleMinorAxis);


        verticalLayout_6->addLayout(horizontalLayout_15);

        verticalSpacer_10 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_10);


        horizontalLayout_3->addWidget(Param_Ell);

        Param_Rhomb = new QGroupBox(centralwidget);
        Param_Rhomb->setObjectName(QString::fromUtf8("Param_Rhomb"));
        verticalLayout_7 = new QVBoxLayout(Param_Rhomb);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalSpacer_11 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_11);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_15 = new QLabel(Param_Rhomb);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        horizontalLayout_11->addWidget(label_15);

        doubleSpinBox_2 = new QDoubleSpinBox(Param_Rhomb);
        doubleSpinBox_2->setObjectName(QString::fromUtf8("doubleSpinBox_2"));
        doubleSpinBox_2->setMinimum(0.100000000000000);
        doubleSpinBox_2->setMaximum(9999.989999999999782);
        doubleSpinBox_2->setSingleStep(1.000000000000000);
        doubleSpinBox_2->setValue(100.000000000000000);

        horizontalLayout_11->addWidget(doubleSpinBox_2);


        verticalLayout_7->addLayout(horizontalLayout_11);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_16 = new QLabel(Param_Rhomb);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        horizontalLayout_10->addWidget(label_16);

        doubleSpinBox = new QDoubleSpinBox(Param_Rhomb);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setMinimum(0.100000000000000);
        doubleSpinBox->setMaximum(9999.989999999999782);
        doubleSpinBox->setValue(50.000000000000000);

        horizontalLayout_10->addWidget(doubleSpinBox);


        verticalLayout_7->addLayout(horizontalLayout_10);

        verticalSpacer_13 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_13);


        horizontalLayout_3->addWidget(Param_Rhomb);

        Param_Sqr = new QGroupBox(centralwidget);
        Param_Sqr->setObjectName(QString::fromUtf8("Param_Sqr"));
        verticalLayout_8 = new QVBoxLayout(Param_Sqr);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalSpacer_12 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(verticalSpacer_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        label_17 = new QLabel(Param_Sqr);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        horizontalLayout_13->addWidget(label_17);

        doubleSideSqr = new QDoubleSpinBox(Param_Sqr);
        doubleSideSqr->setObjectName(QString::fromUtf8("doubleSideSqr"));
        doubleSideSqr->setMinimum(0.100000000000000);
        doubleSideSqr->setMaximum(9999.989999999999782);
        doubleSideSqr->setValue(100.000000000000000);

        horizontalLayout_13->addWidget(doubleSideSqr);


        verticalLayout_8->addLayout(horizontalLayout_13);

        verticalSpacer_14 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(verticalSpacer_14);


        horizontalLayout_3->addWidget(Param_Sqr);

        Param_Circle = new QGroupBox(centralwidget);
        Param_Circle->setObjectName(QString::fromUtf8("Param_Circle"));
        verticalLayout_9 = new QVBoxLayout(Param_Circle);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalSpacer_15 = new QSpacerItem(20, 273, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer_15);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        label_18 = new QLabel(Param_Circle);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        horizontalLayout_17->addWidget(label_18);

        doubleRadiusCircle = new QDoubleSpinBox(Param_Circle);
        doubleRadiusCircle->setObjectName(QString::fromUtf8("doubleRadiusCircle"));
        doubleRadiusCircle->setMinimum(0.100000000000000);
        doubleRadiusCircle->setMaximum(9999.989999999999782);
        doubleRadiusCircle->setValue(100.000000000000000);

        horizontalLayout_17->addWidget(doubleRadiusCircle);


        verticalLayout_9->addLayout(horizontalLayout_17);

        verticalSpacer_16 = new QSpacerItem(20, 272, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer_16);


        horizontalLayout_3->addWidget(Param_Circle);

        Param_Star = new QGroupBox(centralwidget);
        Param_Star->setObjectName(QString::fromUtf8("Param_Star"));
        verticalLayout_10 = new QVBoxLayout(Param_Star);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        verticalSpacer_17 = new QSpacerItem(20, 156, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_10->addItem(verticalSpacer_17);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setObjectName(QString::fromUtf8("horizontalLayout_20"));
        label_21 = new QLabel(Param_Star);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        horizontalLayout_20->addWidget(label_21);

        StarPoints = new QSpinBox(Param_Star);
        StarPoints->setObjectName(QString::fromUtf8("StarPoints"));
        StarPoints->setMinimum(5);
        StarPoints->setMaximum(99);
        StarPoints->setValue(5);
        StarPoints->setDisplayIntegerBase(10);

        horizontalLayout_20->addWidget(StarPoints);


        verticalLayout_10->addLayout(horizontalLayout_20);

        verticalSpacer_19 = new QSpacerItem(20, 156, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_10->addItem(verticalSpacer_19);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        label_19 = new QLabel(Param_Star);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        horizontalLayout_18->addWidget(label_19);

        doubleRadiusAStar = new QDoubleSpinBox(Param_Star);
        doubleRadiusAStar->setObjectName(QString::fromUtf8("doubleRadiusAStar"));
        doubleRadiusAStar->setMinimum(0.100000000000000);
        doubleRadiusAStar->setMaximum(9999.989999999999782);
        doubleRadiusAStar->setValue(100.000000000000000);

        horizontalLayout_18->addWidget(doubleRadiusAStar);


        verticalLayout_10->addLayout(horizontalLayout_18);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        label_20 = new QLabel(Param_Star);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        horizontalLayout_19->addWidget(label_20);

        doubleRadiusBStar = new QDoubleSpinBox(Param_Star);
        doubleRadiusBStar->setObjectName(QString::fromUtf8("doubleRadiusBStar"));
        doubleRadiusBStar->setMinimum(0.100000000000000);
        doubleRadiusBStar->setMaximum(9999.989999999999782);
        doubleRadiusBStar->setValue(50.000000000000000);

        horizontalLayout_19->addWidget(doubleRadiusBStar);


        verticalLayout_10->addLayout(horizontalLayout_19);

        verticalSpacer_18 = new QSpacerItem(20, 156, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_10->addItem(verticalSpacer_18);


        horizontalLayout_3->addWidget(Param_Star);

        Param_Poly = new QGroupBox(centralwidget);
        Param_Poly->setObjectName(QString::fromUtf8("Param_Poly"));
        verticalLayout_11 = new QVBoxLayout(Param_Poly);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        verticalSpacer_22 = new QSpacerItem(20, 167, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_11->addItem(verticalSpacer_22);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setObjectName(QString::fromUtf8("horizontalLayout_21"));
        label_22 = new QLabel(Param_Poly);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        horizontalLayout_21->addWidget(label_22);

        PolyPoints = new QSpinBox(Param_Poly);
        PolyPoints->setObjectName(QString::fromUtf8("PolyPoints"));
        PolyPoints->setMinimum(5);
        PolyPoints->setMaximum(99);
        PolyPoints->setValue(5);
        PolyPoints->setDisplayIntegerBase(10);

        horizontalLayout_21->addWidget(PolyPoints);


        verticalLayout_11->addLayout(horizontalLayout_21);

        verticalSpacer_21 = new QSpacerItem(20, 168, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_11->addItem(verticalSpacer_21);

        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setObjectName(QString::fromUtf8("horizontalLayout_22"));
        label_23 = new QLabel(Param_Poly);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        horizontalLayout_22->addWidget(label_23);

        doubleSidePoly = new QDoubleSpinBox(Param_Poly);
        doubleSidePoly->setObjectName(QString::fromUtf8("doubleSidePoly"));
        doubleSidePoly->setMinimum(0.100000000000000);
        doubleSidePoly->setMaximum(9999.989999999999782);
        doubleSidePoly->setValue(100.000000000000000);

        horizontalLayout_22->addWidget(doubleSidePoly);


        verticalLayout_11->addLayout(horizontalLayout_22);

        verticalSpacer_20 = new QSpacerItem(20, 167, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_11->addItem(verticalSpacer_20);


        horizontalLayout_3->addWidget(Param_Poly);

        Param_Triangle = new QGroupBox(centralwidget);
        Param_Triangle->setObjectName(QString::fromUtf8("Param_Triangle"));
        verticalLayout_12 = new QVBoxLayout(Param_Triangle);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        verticalSpacer_23 = new QSpacerItem(20, 239, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_12->addItem(verticalSpacer_23);

        horizontalLayout_24 = new QHBoxLayout();
        horizontalLayout_24->setObjectName(QString::fromUtf8("horizontalLayout_24"));
        label_25 = new QLabel(Param_Triangle);
        label_25->setObjectName(QString::fromUtf8("label_25"));

        horizontalLayout_24->addWidget(label_25);

        TriangleSideA = new QDoubleSpinBox(Param_Triangle);
        TriangleSideA->setObjectName(QString::fromUtf8("TriangleSideA"));
        TriangleSideA->setMinimum(0.100000000000000);
        TriangleSideA->setMaximum(9999.989999999999782);
        TriangleSideA->setValue(100.000000000000000);

        horizontalLayout_24->addWidget(TriangleSideA);


        verticalLayout_12->addLayout(horizontalLayout_24);

        horizontalLayout_23 = new QHBoxLayout();
        horizontalLayout_23->setObjectName(QString::fromUtf8("horizontalLayout_23"));
        label_24 = new QLabel(Param_Triangle);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        horizontalLayout_23->addWidget(label_24);

        TriangleSideB = new QDoubleSpinBox(Param_Triangle);
        TriangleSideB->setObjectName(QString::fromUtf8("TriangleSideB"));
        TriangleSideB->setMinimum(0.100000000000000);
        TriangleSideB->setMaximum(9999.989999999999782);
        TriangleSideB->setValue(100.000000000000000);

        horizontalLayout_23->addWidget(TriangleSideB);


        verticalLayout_12->addLayout(horizontalLayout_23);

        horizontalLayout_25 = new QHBoxLayout();
        horizontalLayout_25->setObjectName(QString::fromUtf8("horizontalLayout_25"));
        label_26 = new QLabel(Param_Triangle);
        label_26->setObjectName(QString::fromUtf8("label_26"));

        horizontalLayout_25->addWidget(label_26);

        TriangleSideC = new QDoubleSpinBox(Param_Triangle);
        TriangleSideC->setObjectName(QString::fromUtf8("TriangleSideC"));
        TriangleSideC->setMinimum(0.100000000000000);
        TriangleSideC->setMaximum(9999.989999999999782);
        TriangleSideC->setValue(100.000000000000000);

        horizontalLayout_25->addWidget(TriangleSideC);


        verticalLayout_12->addLayout(horizontalLayout_25);

        verticalSpacer_24 = new QSpacerItem(20, 238, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_12->addItem(verticalSpacer_24);


        horizontalLayout_3->addWidget(Param_Triangle);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1715, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        MainStats->setTitle(QCoreApplication::translate("MainWindow", "Main stats", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "<None>", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Circle", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Custom", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "Ellipse", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("MainWindow", "Polygon", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("MainWindow", "Rectangle", nullptr));
        comboBox->setItemText(6, QCoreApplication::translate("MainWindow", "Rhombus", nullptr));
        comboBox->setItemText(7, QCoreApplication::translate("MainWindow", "Square", nullptr));
        comboBox->setItemText(8, QCoreApplication::translate("MainWindow", "Star", nullptr));
        comboBox->setItemText(9, QCoreApplication::translate("MainWindow", "Triangle", nullptr));

        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Object coordinates", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "X :", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Y :", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Rotate center coordinates", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "X :", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Y :", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Scale :            ", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Rotate angle :", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Perimeter :", nullptr));
        Perimeter->setText(QCoreApplication::translate("MainWindow", "0.00", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Area :", nullptr));
        Area->setText(QCoreApplication::translate("MainWindow", "0.00", nullptr));
        Reset->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        Param_Rect->setTitle(QCoreApplication::translate("MainWindow", "Rectangle", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Side A :", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Side B :", nullptr));
        Param_Ell->setTitle(QCoreApplication::translate("MainWindow", "Ellipse", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Major axis :", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Minor axis :", nullptr));
        Param_Rhomb->setTitle(QCoreApplication::translate("MainWindow", "Rhombus", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Diag A :", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Diag B :", nullptr));
        Param_Sqr->setTitle(QCoreApplication::translate("MainWindow", "Square", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "Side :", nullptr));
        Param_Circle->setTitle(QCoreApplication::translate("MainWindow", "Circlre", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "Radius :", nullptr));
        Param_Star->setTitle(QCoreApplication::translate("MainWindow", "Star", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "Points :", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "Radius A :", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "Radius B :", nullptr));
        Param_Poly->setTitle(QCoreApplication::translate("MainWindow", "Polygon", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "Points :", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "Radius :", nullptr));
        Param_Triangle->setTitle(QCoreApplication::translate("MainWindow", "Triangle", nullptr));
        label_25->setText(QCoreApplication::translate("MainWindow", "Side A :", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "Side B :", nullptr));
        label_26->setText(QCoreApplication::translate("MainWindow", "Side C :", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
