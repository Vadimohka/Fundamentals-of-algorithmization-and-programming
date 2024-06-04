#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

constexpr int DEFAULT_ELEMENT_COUNT = 3;
constexpr int MAX_ELEMENT_COUNT = 15;
constexpr int DEFAULT_MIN_VALUE = -100;
constexpr int DEFAULT_MAX_VALUE = 100;
constexpr int ELEMENT_COUNT_THRESHOLD = 30;
constexpr int NODE_COUNT_THRESHOLD = 50;
constexpr int MIN_ARRAY_SIZE = 3;
constexpr int MIN_VALUE_LIMIT = -9999;
constexpr int MAX_VALUE_LIMIT = 9999;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    scene(new QGraphicsScene(this)),
    onePieceAnimation(new OnePieceAnimation(scene, this)),
    stepByStepAnimation(new StepByStepAnimation(scene, this)),
    searchAlgorithm(new SearchAlgorithms(this)),
    arrayManager(new ArrayManager(scene, this)),
    graphManager(new GraphManager(scene, this)),
    animationType(NoAnimation),
    arrayGenerated(false),
    graphGenerated(false),
    isGenerated(false),
    isBack(false),
    stopButtonClicked(false),
    stepByStepClicked(false),
    isBST(false),
    nextStepClicked(false)
{
    ui->setupUi(this);
    ui->linearView->setScene(scene);

    connect(onePieceAnimation, &OnePieceAnimation::animationFinished, this, &MainWindow::handleOnePieceAnimationFinished);
    connect(stepByStepAnimation, &StepByStepAnimation::animationFinished, this, &MainWindow::handleStepByStepAnimationFinished);
    connect(arrayManager, &ArrayManager::itemDeleted, onePieceAnimation, &OnePieceAnimation::handleItemDeleted);
    connect(ui->searchedElementEdit, &QLineEdit::textChanged, this, &MainWindow::on_searchedElementEdit_textChanged);
    connect(graphManager, &GraphManager::nodeDeleted, onePieceAnimation, &OnePieceAnimation::handleItemDeleted);
    connect(graphManager, &GraphManager::bstRebuilt, this, &MainWindow::handleBSTRebuilt);


    updateAnimateButtonState();
    updateControlButtonStates();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete onePieceAnimation;
    delete stepByStepAnimation;
    delete arrayManager;
    delete searchAlgorithm;
    delete graphManager;
    delete scene;
}


void MainWindow::setupArray(int elementCount, int minValue, int maxValue)
{

    onePieceAnimation->completeCurrentAnimation();
    stepByStepAnimation->completeCurrentAnimation();
    if (!isBack) {
        onePieceAnimation->resetAnimation();
        stepByStepAnimation->resetAnimation();
    }

    if (scene) {
        scene->clear();
        scene->setSceneRect(0, 0, ui->linearView->width(), ui->linearView->height()); // Reset the scene coordinates
    }
    items.clear();

    if (arrayManager) {
        arrayManager->setupArray(elementCount, minValue, maxValue);
        for (auto rect : arrayManager->getItems()) {
            items.append(static_cast<QGraphicsItem*>(rect));
        }

        if (onePieceAnimation) {
            onePieceAnimation->updateItems(items);
        }
        arrayGenerated = true;
        graphGenerated = false;
        updateAnimateButtonState();
        updateControlButtonStates();
    }
}


void MainWindow::on_linearSearchButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->algorithmLabel->setText("Linear Search");
    SearchAlgorithm = linearSearch;
}

void MainWindow::on_descriptionButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_previousStepButton_clicked()
{
    if (animationType == StepByStepAnimationType) {
        stepByStepAnimation->previousStep();
    }
    updateControlButtonStates();
}

void MainWindow::on_backButton_clicked()
{

    isBack = true;

    if (scene != nullptr) {
        scene->clear();

    } else {

    }

    isBST = false;

    if (ui != nullptr) {

        ui->addElementEdit->clear();
        ui->deleteElementEdit->clear();
        ui->searchedElementEdit->clear();
        ui->quantityOfElementEdit->clear();
        ui->minElementEdit->clear();
        ui->maxElementEdit->clear();

        arrayGenerated = false;
        graphGenerated = false;
        updateAnimateButtonState();
        isGenerated = false;
        stepByStepClicked = false;
        nextStepClicked = false;
        updateControlButtonStates();

        ui->stackedWidget->setCurrentIndex(1);
    }


}

void MainWindow::on_continueButton_clicked()
{
    onePieceAnimation->continueAnimation();
    animationType = OnePieceAnimationType;
    stopButtonClicked = false;
    updateControlButtonStates();
}

void MainWindow::handleBSTRebuilt(const BST &bst) {
    searchAlgorithm->setBST(bst);
}

void MainWindow::on_backFromDescriptionButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_backToPage1Button_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_goToAlgorithmButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_quitButton_clicked()
{
    QApplication::quit();
}

void MainWindow::on_addElementButton_clicked()
{
    if (arrayManager->isAnimationRunning() || graphManager->isAnimationRunning()) return;

    onePieceAnimation->completeCurrentAnimation();
    stepByStepAnimation->completeCurrentAnimation();

    bool ok;
    int value = ui->addElementEdit->text().toInt(&ok);
    if (ok) {
        if (arrayGenerated) {
            if (items.size()==ELEMENT_COUNT_THRESHOLD) return;
            arrayManager->addElement(value);
            items.clear();
            for (auto rect : arrayManager->getItems()) {
                items.append(static_cast<QGraphicsItem*>(rect));
            }
        } else if (graphGenerated) {
            if (items.size()==NODE_COUNT_THRESHOLD) return;
            graphManager->addNode(value);
            items.clear();
            for (auto node : graphManager->getNodes()) {
                items.append(static_cast<QGraphicsItem*>(node));
            }
        }
        if (animationType == StepByStepAnimationType) {
            stepByStepAnimation->resetAnimation();
        }
        else if (animationType == OnePieceAnimationType) {
            onePieceAnimation->resetAnimation();
        }

    }
    if(isBST) {
        graphManager->rebuildBST();
    }
    updateControlButtonStates();
}

void MainWindow::on_deleteElementButton_clicked()
{
    if (arrayManager->isAnimationRunning() || graphManager->isAnimationRunning()) return;

    onePieceAnimation->completeCurrentAnimation();
    stepByStepAnimation->completeCurrentAnimation();

    bool ok;
    int value = ui->deleteElementEdit->text().toInt(&ok);
    if (ok) {
        if (arrayGenerated) {
            if (items.size()==DEFAULT_ELEMENT_COUNT) return;
            arrayManager->deleteElement(value);
            items.clear();
            for (auto rect : arrayManager->getItems()) {
                items.append(static_cast<QGraphicsItem*>(rect));
            }
            onePieceAnimation->updateItems(items);
        } else if (graphGenerated) {
            if (items.size()==DEFAULT_ELEMENT_COUNT) return;
            graphManager->deleteNode(value);
            items.clear();
            for (auto node : graphManager->getNodes()) {
                items.append(static_cast<QGraphicsItem*>(node));
            }
        }
        if (animationType == StepByStepAnimationType) {
            stepByStepAnimation->resetAnimation();
        }
        else if (animationType == OnePieceAnimationType) {
            onePieceAnimation->resetAnimation();
        }
        if(isBST) {
            graphManager->rebuildBST();
        }
        updateControlButtonStates();
    }
}

void MainWindow::on_generateASetButton_clicked()
{
    if (arrayManager->isAnimationRunning() || graphManager->isAnimationRunning()) return;

    onePieceAnimation->completeCurrentAnimation();
    stepByStepAnimation->completeCurrentAnimation();
    isGenerated = true;
    quantityAndRange();
    stepByStepClicked = false;
    nextStepClicked = false;
    updateControlButtonStates();
}

void MainWindow::on_stopButton_clicked()
{
    onePieceAnimation->stopAnimation();
    animationType = NoAnimation;
    stopButtonClicked = true;
    updateControlButtonStates();
}

void MainWindow::on_nextStepButton_clicked()
{
    if (animationType == StepByStepAnimationType) {
        stepByStepAnimation->nextStep();
        nextStepClicked = true;
    }

    updateControlButtonStates();
}

void MainWindow::handleOnePieceAnimationFinished()
{
    arrayManager->setAnimationRunning(false);
    graphManager->setAnimationRunning(false);
    onePieceAnimation->resetAnimation();
    ui->backButton->setEnabled(true);
    ui->descriptionButton->setEnabled(true);
    animationType = NoAnimation;
    stopButtonClicked = false;
    updateControlButtonStates();
}

void MainWindow::handleStepByStepAnimationFinished()
{
    arrayManager->setAnimationRunning(false);
    graphManager->setAnimationRunning(false);
    animationType = NoAnimation;
    stepByStepClicked = false;
    nextStepClicked = false;
    ui->backButton->setEnabled(true);
    ui->descriptionButton->setEnabled(true);
    updateControlButtonStates();
}

void MainWindow::handleItemDeleted(int index)
{
    onePieceAnimation->handleItemDeleted(index);
}

void MainWindow::on_searchedElementEdit_textChanged()
{
    updateAnimateButtonState();
}

void MainWindow::on_updateGenerateState()
{
    arrayGenerated = false;
    graphGenerated = false;
    updateAnimateButtonState();
}

void MainWindow::updateAnimateButtonState()
{
    bool enable = (arrayGenerated || graphGenerated) && !ui->searchedElementEdit->text().isEmpty();
    ui->onePieceAnimationButton->setEnabled(enable);
    ui->stepByStepAnimationButton->setEnabled(enable);
}

void MainWindow::updateControlButtonStates() {
    ui->stopButton->setEnabled(animationType != NoAnimation && !onePieceAnimation->isStopped());
    ui->continueButton->setEnabled(stopButtonClicked && animationType == NoAnimation);

    ui->nextStepButton->setEnabled(stepByStepClicked && animationType == StepByStepAnimationType);
    ui->previousStepButton->setEnabled(nextStepClicked && animationType == StepByStepAnimationType);
}

void MainWindow::on_stepByStepAnimationButton_clicked()
{
    if (!isGenerated) {
        stepByStepAnimation->resetAnimation();
    }
    if (arrayManager->isAnimationRunning() || graphManager->isAnimationRunning()) return;

    arrayManager->setAnimationRunning(true);
    graphManager->setAnimationRunning(true);
     ui->backButton->setEnabled(false);
     ui->descriptionButton->setEnabled(false);

    bool ok;
    int target = ui->searchedElementEdit->text().toInt(&ok);
    if (ok) {
        if (animationType == NoAnimation) {
            animationType = StepByStepAnimationType;
            stepByStepClicked = true;
        }
        if (arrayGenerated) {
            if (!searchAlgorithm) {
                return;
            }
            switch (SearchAlgorithm) {
                case linearSearch:
                    searchAlgorithm->linearSearch(arrayManager->getItems(), target);
                    break;
                case binarySearch:
                    arrayManager->sortArray();
                    searchAlgorithm->binarySearch(arrayManager->getItems(), target);
                    break;
                case interpolationSearch:
                    arrayManager->sortArray();
                    searchAlgorithm->interpolationSearch(arrayManager->getItems(), target);
                    break;
                case quadraticStepSearch:
                    arrayManager->sortArray();
                    searchAlgorithm->quadraticStepSearch(arrayManager->getItems(), target);
                    break;
            case fibonacciSearch:
                arrayManager->sortArray();
                searchAlgorithm->fibonacciSearch(arrayManager->getItems(), target);
                break;
            case jumpSearch:
                searchAlgorithm->jumpSearch(arrayManager->getItems(), target);
                break;
            case exponentialSearch:
                arrayManager->sortArray();
                searchAlgorithm->exponentialSearch(arrayManager->getItems(), target);
                break;
            }
            QVector<QGraphicsItem*> marked_items;
            for (auto rect : searchAlgorithm->getVector()) {
                marked_items.append(static_cast<QGraphicsItem*>(rect));
            }
            stepByStepAnimation->animate(marked_items, target,isGenerated);
            isGenerated = false;
        } else if (graphGenerated) {
            switch (SearchAlgorithm) {
                case breadthFirstSearch: {
                    QVector<QGraphicsEllipseItem *> ellipseNodes;
                    for (GraphNodeItem *node : graphManager->getNodes()) {
                        ellipseNodes.append(static_cast<QGraphicsEllipseItem *>(node));
                    }
                    searchAlgorithm->breadthFirstSearch(ellipseNodes, graphManager->getAdjacencyList(), target);
                    break;
                   }
            case depthFirstSearch : {
                QVector<QGraphicsEllipseItem *> ellipseNodes;
                for (GraphNodeItem *node : graphManager->getNodes()) {
                    ellipseNodes.append(static_cast<QGraphicsEllipseItem *>(node));
                }
                searchAlgorithm->depthFirstSearch(ellipseNodes, graphManager->getAdjacencyList(), target);
                break;
            }
            case binarySearchTree : {
                QVector<QGraphicsEllipseItem *> ellipseNodes;

                for (GraphNodeItem *node : graphManager->getTreeNodes(graphManager->getNodeValues())) {
                    ellipseNodes.append(static_cast<QGraphicsEllipseItem *>(node));
                }
                graphManager->rebuildBST();
                searchAlgorithm->searchInBST(target, ellipseNodes);
                break;
            }
            }
            QVector<QGraphicsItem*> marked_items;
            for (auto node : searchAlgorithm->getGraphVector()) {
                marked_items.append(static_cast<QGraphicsItem*>(node));
            }
            stepByStepAnimation->animate(marked_items, target,isGenerated);
            isGenerated = false;
        }
    }
    updateControlButtonStates();
}


void MainWindow::on_onePieceAnimationButton_clicked()
{
    if (arrayManager->isAnimationRunning() || graphManager->isAnimationRunning()) return;

    arrayManager->setAnimationRunning(true);
    graphManager->setAnimationRunning(true);
     ui->backButton->setEnabled(false);
     ui->descriptionButton->setEnabled(false);

    bool ok;
    int target = ui->searchedElementEdit->text().toInt(&ok);
    if (ok) {
        if (animationType == NoAnimation) {
            animationType = OnePieceAnimationType;
        }
        if (arrayGenerated) {
            switch (SearchAlgorithm) {
                case linearSearch:
                    searchAlgorithm->linearSearch(arrayManager->getItems(), target);
                    break;
                case binarySearch:
                    arrayManager->sortArray();
                    searchAlgorithm->binarySearch(arrayManager->getItems(), target);
                    break;
                case interpolationSearch:
                    arrayManager->sortArray();
                    searchAlgorithm->interpolationSearch(arrayManager->getItems(), target);
                    break;
                case quadraticStepSearch:
                    arrayManager->sortArray();
                    searchAlgorithm->quadraticStepSearch(arrayManager->getItems(), target);
                    break;
            case fibonacciSearch:
                arrayManager->sortArray();
                searchAlgorithm->fibonacciSearch(arrayManager->getItems(), target);
                break;
            case jumpSearch:
                 arrayManager->sortArray();
                searchAlgorithm->jumpSearch(arrayManager->getItems(), target);
                break;
            case exponentialSearch:
                arrayManager->sortArray();
                searchAlgorithm->exponentialSearch(arrayManager->getItems(), target);
                break;
            }
            QVector<QGraphicsItem*> marked_items;
            for (auto rect : searchAlgorithm->getVector()) {
                marked_items.append(static_cast<QGraphicsItem*>(rect));
            }
            onePieceAnimation->animate(marked_items, target);
        } else if (graphGenerated) {
            switch (SearchAlgorithm) {
            case breadthFirstSearch: {
                QVector<QGraphicsEllipseItem *> ellipseNodes;
                for (GraphNodeItem *node : graphManager->getNodes()) {
                    ellipseNodes.append(static_cast<QGraphicsEllipseItem *>(node));
                }
                searchAlgorithm->breadthFirstSearch(ellipseNodes, graphManager->getAdjacencyList(), target);
                break;
            }
            case depthFirstSearch : {
                QVector<QGraphicsEllipseItem *> ellipseNodes;
                for (GraphNodeItem *node : graphManager->getNodes()) {
                    ellipseNodes.append(static_cast<QGraphicsEllipseItem *>(node));
                }
                searchAlgorithm->depthFirstSearch(ellipseNodes, graphManager->getAdjacencyList(), target);
                break;
            }
            case binarySearchTree : {
                QVector<QGraphicsEllipseItem *> ellipseNodes;
                qDebug() << graphManager->getTreeNodes(graphManager->getNodeValues()).size();
                for (GraphNodeItem *node : graphManager->getTreeNodes(graphManager->getNodeValues())) {
                    ellipseNodes.append(static_cast<QGraphicsEllipseItem *>(node));
                }
                graphManager->rebuildBST();
                searchAlgorithm->searchInBST(target, ellipseNodes);
                break;
            }
            }
            QVector<QGraphicsItem*> marked_items;
            for (auto node : searchAlgorithm->getGraphVector()) {
                marked_items.append(static_cast<QGraphicsItem*>(node));
            }
            qDebug() << marked_items.size();
            onePieceAnimation->animate(marked_items, target);
        }
    }
    updateControlButtonStates();
}


void MainWindow::on_binaryButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->algorithmLabel->setText("Binary Search");
    SearchAlgorithm = binarySearch;
}

void MainWindow::on_InterpolationButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->algorithmLabel->setText("Interpolation Search");
    SearchAlgorithm = interpolationSearch;
}

void MainWindow::quantityAndRange()
{

    bool ok = false;
    int elementCount = ui->quantityOfElementEdit->text().toInt(&ok);
    if (!ok || elementCount < DEFAULT_ELEMENT_COUNT || elementCount > MAX_ELEMENT_COUNT) {
        elementCount = DEFAULT_ELEMENT_COUNT;
    }

    int minValue = ui->minElementEdit->text().toInt(&ok);
    if (!ok || minValue > MAX_VALUE_LIMIT || minValue < MIN_VALUE_LIMIT) {
        minValue = DEFAULT_MIN_VALUE;
    }

    int maxValue = ui->maxElementEdit->text().toInt(&ok);
    if (!ok || maxValue > MAX_VALUE_LIMIT || maxValue < MIN_VALUE_LIMIT) {
        maxValue = DEFAULT_MAX_VALUE;
    }

    if (minValue >= maxValue) {
        minValue = DEFAULT_MIN_VALUE;
        maxValue = DEFAULT_MAX_VALUE;
    }

    if (ui->algorithmLabel->text() == "Breadth-first Search" || ui->algorithmLabel->text() == "Depth-first Search" ||
        ui->algorithmLabel->text() == "Binary search tree") {
        setupGraph(elementCount, minValue, maxValue);
    } else {
        setupArray(elementCount, minValue, maxValue);
    }
    ui->nextStepButton->setEnabled(false);
    ui->previousStepButton->setEnabled(false);

}

void MainWindow::setupGraph(int elementCount, int minValue, int maxValue)
{

    if (graphManager != nullptr) {
        graphManager->setupGraph(elementCount, minValue, maxValue);
        items.clear();
        for (auto node : graphManager->getNodes()) {
            items.append(static_cast<QGraphicsItem*>(node));
        }

        if (onePieceAnimation != nullptr) {
            onePieceAnimation->updateItems(items);
        }

        graphGenerated = true;
        arrayGenerated = false;
        updateAnimateButtonState();

        updateControlButtonStates();
    }
}

void MainWindow::on_breadthFirstSearchButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->algorithmLabel->setText("Breadth-first Search");
    SearchAlgorithm = breadthFirstSearch;
}


void MainWindow::on_depthFirstSearchButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->algorithmLabel->setText("Depth-first Search");
    SearchAlgorithm = depthFirstSearch;
}


void MainWindow::on_quadraticStepSearchButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->algorithmLabel->setText("Quadratic step search");
    SearchAlgorithm = quadraticStepSearch;
}


void MainWindow::on_fibonacciSearchButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->algorithmLabel->setText("Fibonacci search");
    SearchAlgorithm = fibonacciSearch;
}


void MainWindow::on_jumpSearchButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->algorithmLabel->setText("Jump search");
    SearchAlgorithm = jumpSearch;
}


void MainWindow::on_exponentialSearchButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->algorithmLabel->setText("Exponential search");
    SearchAlgorithm = exponentialSearch;
}


void MainWindow::on_binarySearchTreeButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->algorithmLabel->setText("Binary search tree");
    isBST= true;
    SearchAlgorithm = binarySearchTree;
}

