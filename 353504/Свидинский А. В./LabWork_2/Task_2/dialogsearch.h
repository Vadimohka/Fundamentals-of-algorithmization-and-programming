#ifndef DIALOGSEARCH_H
#define DIALOGSEARCH_H

#include <QDialog>
#include "component.h"

namespace Ui {
class DialogSearch;
}

class DialogSearch : public QDialog
{
    Q_OBJECT

public:
    explicit DialogSearch(QWidget *parent = nullptr);
    ~DialogSearch();

    void setComponents(component **components, int kolvo);

signals:
    void sendData(const QString &searchType, const QString &searchFirm, const QString &searchModel);

private slots:
    void on_buttonBox_accepted();

    void makeComboBoxs();

    void updateFirm();

    void updateModel();
private:
    Ui::DialogSearch *ui;
    component **components;
    int kolvo;
};

#endif // DIALOGSEARCH_H
