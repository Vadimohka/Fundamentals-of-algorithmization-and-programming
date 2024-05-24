#ifndef RUBICKSCUBE_H
#define RUBICKSCUBE_H

#include <QObject>
#include <QMap>
#include <QtQml>
#include "element.h"
#include <QtWidgets/QMessageBox>
#include "statefromscangetter.h"
#include "solver.h"

class RubicksCube : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON

    Q_PROPERTY(QString currMoveText MEMBER currMoveText NOTIFY solutionTextChanged)
    Q_PROPERTY(QString prevSolutionMoves MEMBER prevSolutionMoves NOTIFY solutionTextChanged)
    Q_PROPERTY(QString nextSolutionMoves MEMBER nextSolutionMoves NOTIFY solutionTextChanged)
    Q_PROPERTY(int amountOfMovesInSolution MEMBER amountOfMovesInSolution NOTIFY solutionTextChanged)
    Q_PROPERTY(int currStepOfSolution MEMBER currStepOfSolution NOTIFY solutionTextChanged)


    Q_PROPERTY(bool isFirstMove MEMBER isFirstMove NOTIFY moveChanged)
    Q_PROPERTY(bool isLastMove MEMBER isLastMove NOTIFY moveChanged)
    Q_PROPERTY(bool isAutoAnimating MEMBER isAutoAnimating NOTIFY moveChanged)
    Q_PROPERTY(QString animatingButtonText MEMBER animatingButtonText NOTIFY animatingButtonTextChanged)
public:
    RubicksCube();
    Q_INVOKABLE qreal getXRotationOf(QString);
    Q_INVOKABLE qreal getYRotationOf(QString);
    Q_INVOKABLE qreal getZRotationOf(QString);

    Q_INVOKABLE void setColor(QString, QString);
    Q_INVOKABLE bool stateIsValid();

    Q_INVOKABLE void animateRotU();
    Q_INVOKABLE void animateRotUSt();
    Q_INVOKABLE void animateRotR();
    Q_INVOKABLE void animateRotRSt();
    Q_INVOKABLE void animateRotD();
    Q_INVOKABLE void animateRotDSt();
    Q_INVOKABLE void animateRotL();
    Q_INVOKABLE void animateRotLSt();
    Q_INVOKABLE void animateRotF();
    Q_INVOKABLE void animateRotFSt();
    Q_INVOKABLE void animateRotB();
    Q_INVOKABLE void animateRotBSt();
    Q_INVOKABLE void animateRotu();
    Q_INVOKABLE void animateRotuSt();
    Q_INVOKABLE void animateRotd();
    Q_INVOKABLE void animateRotdSt();
    Q_INVOKABLE void animateRotl();
    Q_INVOKABLE void animateRotlSt();
    Q_INVOKABLE void animateRotr();
    Q_INVOKABLE void animateRotrSt();
    Q_INVOKABLE void animateRotb();
    Q_INVOKABLE void animateRotbSt();
    Q_INVOKABLE void animateRotf();
    Q_INVOKABLE void animateRotfSt();
    Q_INVOKABLE bool setStateFromScramble(QString);
    Q_INVOKABLE void setRandomState();
    Q_INVOKABLE void setStateFromScan();
    Q_INVOKABLE void setSolved();
    Q_INVOKABLE void solve();
    Q_INVOKABLE void onForwardClicked();
    Q_INVOKABLE void onBackClicked();
    Q_INVOKABLE void disableSolveButtons();
    Q_INVOKABLE void onStartStopClicked();

    void setState(QMap<QString, QString> state);

    RubicksCube *GetInstance();
signals:
    void solutionTextChanged();
    void moveChanged();
    void animatingButtonTextChanged();
private:
    QStringList solution;
    QString currMoveText;
    QString prevSolutionMoves;
    QString nextSolutionMoves;


    static RubicksCube* _instance;

    QMap<QString, Element> CubeElements;
    QMap<QString, QString> CurrState;

    void _animateRotatingUpElements(QString color, char axis, bool clockwise);
    void _animateRotatingSecondUpElements(QString color, char axis, bool clockwise);
    void _animateRotatingMiddleHorElements(QString color, char axis, bool clockwise);
    void _animateRotatingSecondDownElements(QString color, char axis, bool clockwise);
    void _animateRotatingDownElements(QString color, char axis, bool clockwise);

    void _animateRotatingLeftElements(QString color, char axis, bool clockwise);
    void _animateRotatingSecondLeftElements(QString color, char axis, bool clockwise);
    void _animateRotatingMiddleVertElements(QString color, char axis, bool clockwise);
    void _animateRotatingSecondRightElements(QString color, char axis, bool clockwise);
    void _animateRotatingRightElements(QString color, char axis, bool clockwise);

    void _animateRotatingSide(QString color, char axis, bool clockwise);

    void _cyclicPermutation(QString&& a, QString&& b, QString&& c, QString&& d, bool clockwise);

    void _permuteU(bool clockwise);
    void _permuteR(bool clockwise);
    void _permuteD(bool clockwise);
    void _permuteL(bool clockwise);
    void _permuteF(bool clockwise);
    void _permuteB(bool clockwise);
    void _permuteu(bool clockwise);
    void _permuted(bool clockwise);
    void _permutel(bool clockwise);
    void _permuter(bool clockwise);
    void _permuteb(bool clockwise);
    void _permutef(bool clockwise);

    void _translateElement(QString key);

    qreal _calcRotation(QString);
    void _rotateMomentalSide(QString key);
    void _rotateMomentalToGreen(QString key);
    void _rotateMomentalToTarget(QString key);

    bool _validScramble(QStringList&);

    void _rotateByScramble(QStringList&);

    StateFromScanGetter* scaner = StateFromScanGetter::GetInstance();

    Solver* solver = new Solver();

    int currStepOfSolution = 0;

    bool isFirstMove = true;
    bool isLastMove = true;
    bool isAutoAnimating = false;

    QTimer* solveButtonsDisabler = new QTimer();

    void setSolutionText();

    int amountOfMovesInSolution = 0;

    QTimer autoAnimationTimer = QTimer();

    QString animatingButtonText = "Пуск";
};
#endif // RUBICKSCUBE_H
