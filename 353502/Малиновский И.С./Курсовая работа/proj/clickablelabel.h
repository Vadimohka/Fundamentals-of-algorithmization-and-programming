#pragma once

#include <QLabel>
#include <QMouseEvent>

class ClickableLabel : public QLabel {
    Q_OBJECT

public:
    explicit ClickableLabel(QWidget *parent = nullptr);
    ~ClickableLabel() override;

signals:
    void clicked(const QPoint& pos);

protected:
    void mousePressEvent(QMouseEvent *event) override;
};
