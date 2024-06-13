#ifndef QGAMEOVERWINDOW_H
#define QGAMEOVERWINDOW_H

#include <QWidget>

class QResetButton;

class qGameOverWindow : public QWidget
{
    Q_OBJECT
public:
    explicit qGameOverWindow(QWidget *parent = 0);

    QResetButton* GetResetButton() const;

signals:

public slots:

private:
    QResetButton* reset;
};

#endif // QGAMEOVERWINDOW_H
