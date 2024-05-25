#include "view/mainwindowview.h"

#include <QResizeEvent>

namespace view {

MainWindowView::MainWindowView() {
    setRenderHint(QPainter::Antialiasing);
    setCacheMode(QGraphicsView::CacheBackground);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    QPixmap pixmap = QPixmap(":/assets/images/pointers/pointer.png");
    setCursor(QCursor(pixmap.scaled(32, 32)));
}

void MainWindowView::resizeEvent(QResizeEvent* event) {
    fitInView(scene()->sceneRect(), Qt::KeepAspectRatio);
    QGraphicsView::resizeEvent(event);
}

}  // namespace view
