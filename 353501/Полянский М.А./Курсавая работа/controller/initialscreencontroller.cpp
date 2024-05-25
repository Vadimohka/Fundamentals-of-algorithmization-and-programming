#include "controller/initialscreencontroller.h"

#include <QFileDialog>
#include <QJsonArray>
#include <QJsonObject>

#include "view/hud/errormodal.h"

namespace controller {

InitialScreenController::InitialScreenController(const SP<model::GameModel>& model) : Controller(model) {
    _scene = new view::InitialScreenScene();

    connect(
        _scene,
        &view::InitialScreenScene::startButtonPressed,
        this,
        [=]() {
            _model->reset(true);
            emit navigateTo(app::Routes::GameScreen);
        });

    connect(
        _scene,
        &view::InitialScreenScene::setMapButtonPressed,
        this,
        [=]() { emit navigateTo(app::Routes::SetMapScreen); });

    connect(
        _scene,
        &view::InitialScreenScene::uploadMapButtonPressed,
        this,
        &controller::InitialScreenController::uploadFromFile);

    connect(
        _scene,
        &view::InitialScreenScene::tutorialButtonPressed,
        this,
        [=]() { emit navigateTo(app::Routes::TutorialScreen); });
}

QGraphicsScene* InitialScreenController::getScene() const {
    return _scene;
}

void InitialScreenController::uploadFromFile() {
    // create level selector screen

    QString fileName = QFileDialog::getOpenFileName(nullptr, "Load a Game Path", "", "CPP Game Path(*.cppmap)");
    vector<model::Position> pathPosition;
    vector<model::Position> blockedPosition;

    if (fileName.isEmpty())
        return;
    else {
        QFile file(fileName);

        if (!file.open(QIODevice::ReadOnly)) {
            view::ErrorModal* modal = new view::ErrorModal(file.errorString(), QSize(_scene->width(), _scene->height()));
            _scene->addItem(modal);
            connect(modal, &view::Modal::close, this, [=]() {
                _scene->removeItem(modal);
                delete modal;
            });
            return;
        }

        QDataStream in(&file);
        in.setVersion(QDataStream::Qt_4_5);

        QVariantHash data;
        in >> data;

        QJsonObject json;
        json = json.fromVariantHash(data);

        if (json.isEmpty()) {
            // Show error
            view::ErrorModal* modal = new view::ErrorModal("The file you are attempting to open is empty.", QSize(_scene->width(), _scene->height()));
            _scene->addItem(modal);
            connect(modal, &view::Modal::close, this, [=]() {
                _scene->removeItem(modal);
                delete modal;
            });
        } else {
            // Load map
            QJsonArray pathJson = json["pathPosition"].toArray();
            for (auto i : pathJson) {
                pathPosition.push_back(model::Position{static_cast<U_INT>((i.toObject())["x"].toInt()), static_cast<U_INT>((i.toObject())["y"].toInt())});
            }
            QJsonArray blockedJson = json["blockedPosition"].toArray();
            for (auto i : blockedJson) {
                blockedPosition.push_back(model::Position{static_cast<U_INT>((i.toObject())["x"].toInt()), static_cast<U_INT>((i.toObject())["y"].toInt())});
            }

            try {
                _model->setMap(pathPosition, model::Direction::Left);
                _model->setBlocked(blockedPosition);

                // Start game
                emit navigateTo(app::Routes::GameScreen);
            } catch (const std::exception* e) {
                // Show error
                view::ErrorModal* modal = new view::ErrorModal(e->what(), QSize(_scene->width(), _scene->height()));
                _scene->addItem(modal);
                connect(modal, &view::Modal::close, this, [=]() {
                    _scene->removeItem(modal);
                    delete modal;
                });
            }
        }
    }
}

}  // namespace controller
