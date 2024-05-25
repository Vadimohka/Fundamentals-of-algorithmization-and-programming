#include "controller/setmapscreencontroller.h"

#include <QFileDialog>
#include <QJsonArray>
#include <QJsonObject>
#include <exception>

#include "app/routes.h"
#include "model/gamemodel.h"
#include "view/hud/errormodal.h"
#include "view/hud/standardbutton.h"

namespace controller {

SetMapScreenController::SetMapScreenController(const SP<model::GameModel>& model) : Controller(model) {
    _scene = new view::SetMapScene();

    connect(
        _scene,
        &view::SetMapScene::saveButtonPressed,
        this,
        &controller::SetMapScreenController::saveToFile);

    connect(
        _scene,
        &view::SetMapScene::backButtonPressed,
        this,
        [=]() { emit navigateTo(app::Routes::InitialScreen); });
}

QGraphicsScene* SetMapScreenController::getScene() const {
    return _scene;
}

void SetMapScreenController::saveToFile(const vector<view::SetMapCell*>* cells) {
    bool errorFound = false;
    vector<model::Position> mappa;
    QString error;

    for (auto i = cells->cbegin(); i != cells->cend() && !errorFound; ++i) {
        if ((*i)->getPos().x == 0 && (*i)->getType() == view::SetMapCell::Type::Start) {
            mappa = createPath((*i)->getPos(), cells);
            error = QString::fromStdString(model::GameModel::validateMap(mappa));
            errorFound = error != "";
        }
    }

    if (!errorFound) {
        U_INT count = 0;
        for (auto i : *cells) {
            if (i->getType() != view::SetMapCell::Type::Blocked && i->getType() != view::SetMapCell::Type::Free) {
                count++;
            }
        }

        if (count == 0) {
            errorFound = true;
            error = "This is not a correct path, there's no cell position in your path";
        } else if (mappa.size() != count) {
            errorFound = true;
            error = "This is not a correct path, you have extra path cells outside your path";
        }
    }

    if (!errorFound) {
        QString fileName = QFileDialog::getSaveFileName(nullptr, "Save Game Path", "", "CPP Game Path(*.cppmap)");

        QStringList list = fileName.split(".");
        if (list[list.size() - 1] != "cppmap") {
            fileName.append(".cppmap");
        }

        if (fileName.isEmpty())
            return;

        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly)) {
            view::ErrorModal* modal = new view::ErrorModal(file.errorString(), QSize(_scene->width(), _scene->height()));
            _scene->addItem(modal);
            connect(modal, &view::Modal::close, this, [=]() {
                _scene->removeItem(modal);
                delete modal;
            });
            return;
        }

        QJsonArray blockedPositionJson;
        for (auto i : *cells) {
            if (i->getType() == view::SetMapCell::Type::Blocked) {
                QJsonObject pos;
                pos["x"] = i->getPos().x;
                pos["y"] = i->getPos().y;
                blockedPositionJson.push_back(pos);
            }
        }

        QJsonArray pathPositionJson;
        for (auto i = mappa.begin(); i != mappa.end(); i++) {
            QJsonObject pos;
            pos["x"] = i->x;
            pos["y"] = i->y;
            pathPositionJson.push_back(pos);
        }

        QJsonObject json;
        json["pathPosition"] = pathPositionJson;
        json["blockedPosition"] = blockedPositionJson;

        QDataStream out(&file);
        out.setVersion(QDataStream::Qt_4_5);
        out << json.toVariantHash();
    } else {
        view::ErrorModal* modal = new view::ErrorModal(error, QSize(_scene->width(), _scene->height()));
        _scene->addItem(modal);
        connect(modal, &view::Modal::close, this, [=]() {
            _scene->removeItem(modal);
            delete modal;
        });
    }
}

vector<model::Position> SetMapScreenController::createPath(const model::Position& start, const vector<view::SetMapCell*>* cells) {
    vector<model::Position> vett;

    model::Position current = start;
    model::Position prev = start;
    model::Position temp;

    while (current.x < 16 && current.y < 10) {
        for (auto i : *cells) {
            if (i->getPos() == current) {
                temp = current;
                vett.push_back(current);

                switch (i->getType()) {
                    case view::SetMapCell::Type::Start:
                        current.x++;
                        break;
                    case view::SetMapCell::Type::Finish:
                        current.x++;
                        break;
                    case view::SetMapCell::Type::Vert:
                        if (prev.y == current.y - 1) {  // from up
                            current.y++;
                        } else {
                            current.y--;
                        }
                        break;
                    case view::SetMapCell::Type::Orizz:
                        if (prev.x == current.x - 1) {  // from left
                            current.x++;
                        } else {
                            current.x--;
                        }
                        break;
                    case view::SetMapCell::Type::SxUp:
                        if (prev.y == current.y - 1) {  // from up
                            current.x--;
                        } else {
                            current.y--;
                        }
                        break;
                    case view::SetMapCell::Type::DxUp:
                        if (prev.y == current.y - 1) {  // from up
                            current.x++;
                        } else {
                            current.y--;
                        }
                        break;
                    case view::SetMapCell::Type::SxDw:
                        if (prev.y == current.y + 1) {  // from down
                            current.x--;
                        } else {
                            current.y++;
                        }
                        break;
                    case view::SetMapCell::Type::DxDw:
                        if (prev.y == current.y + 1) {  // from down
                            current.x++;
                        } else {
                            current.y++;
                        }
                        break;
                    default:
                        vett.push_back(model::Position{16, 10});
                        current.x = 16;
                        current.y = 10;
                        break;
                }
                prev = temp;
            }
        }
    }
    return vett;
}

}  // namespace controller
