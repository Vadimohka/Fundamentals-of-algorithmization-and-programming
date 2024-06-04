#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QVector>
#include <QGraphicsItem>
#include "onepieceanimation.h"
#include "stepbystepanimation.h"
#include "arraymanager.h"
#include "searchalgorithms.h"
#include "graphmanager.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_linearSearchButton_clicked();
    void on_descriptionButton_clicked();
    void on_previousStepButton_clicked();
    void on_backButton_clicked();
    void on_continueButton_clicked();
    void on_backFromDescriptionButton_clicked();
    void on_backToPage1Button_clicked();
    void on_goToAlgorithmButton_clicked();
    void on_quitButton_clicked();
    void on_addElementButton_clicked();
    void on_deleteElementButton_clicked();
    void on_generateASetButton_clicked();
    void on_stopButton_clicked();
    void on_nextStepButton_clicked();
    void handleOnePieceAnimationFinished();
    void handleStepByStepAnimationFinished();
    void handleItemDeleted(int index);
    void on_searchedElementEdit_textChanged();
    void on_updateGenerateState();
    void updateAnimateButtonState();
    void updateControlButtonStates();
    void on_stepByStepAnimationButton_clicked();
    void on_onePieceAnimationButton_clicked();
    void on_binaryButton_clicked();
    void on_InterpolationButton_clicked();
    void on_breadthFirstSearchButton_clicked();
    void on_depthFirstSearchButton_clicked();
    void on_quadraticStepSearchButton_clicked();
    void on_fibonacciSearchButton_clicked();
    void on_jumpSearchButton_clicked();
    void on_exponentialSearchButton_clicked();
    void on_binarySearchTreeButton_clicked();


private:
    void setupArray(int elementCount, int minValue, int maxValue);
    void setupGraph(int elementCount, int minValue, int maxValue);
    void quantityAndRange();
    void resetAnimations();
    void updateArrayPositions();
    void handleBSTRebuilt(const BST &bst);

    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    OnePieceAnimation *onePieceAnimation;
    StepByStepAnimation *stepByStepAnimation;
    QVector<QGraphicsItem*> items;
    SearchAlgorithms *searchAlgorithm;
    ArrayManager *arrayManager;
    GraphManager *graphManager;

    enum AnimationType {
        NoAnimation,
        OnePieceAnimationType,
        StepByStepAnimationType
    };

    AnimationType animationType;
    bool arrayGenerated;
    bool graphGenerated;
    bool isGenerated;
    bool isBack;
    bool isBST;
    bool stopButtonClicked;
    bool stepByStepClicked;
    bool nextStepClicked;
    bool nextStepButtonDisabled;

    enum SearchAlgorithm {
        linearSearch,
        binarySearch,
        interpolationSearch,
        breadthFirstSearch,
        depthFirstSearch,
        quadraticStepSearch,
        fibonacciSearch,
        jumpSearch,
        exponentialSearch,
        binarySearchTree
    };

    SearchAlgorithm SearchAlgorithm;
};

#endif // MAINWINDOW_H
