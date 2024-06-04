
#pragma once

#include <QLayout>
#include <QVector>

class MyCardHBL : public QLayout
{
public:
    // Constructor
    MyCardHBL(int spacing)
        : QLayout()
    {
        setSpacing(spacing);
    }
    MyCardHBL(int spacing, QWidget *parent)
        : QLayout(parent)
    {
        setSpacing(spacing);
    }

    // Destructor
    ~MyCardHBL();

    //~ Begin QLayout interface
    void addItem(QLayoutItem *item) override;
    QSize sizeHint() const override;
    QSize minimumSize() const override;
    int count() const override;
    QLayoutItem *itemAt(int) const override;
    QLayoutItem *takeAt(int) override;
    void setGeometry(const QRect &rect) override;
    //~ End QLayout interface

    void clear();
    // Adds the card at the last position of the three displayed cards. Is called from GameWindwo
    // when a card from the drawStack is moved
    void push_back(QWidget *card);

    // Returns the number of displayed items
    int getItemCount() const;

    QLayoutItem* getFirstItem() const;

private:
    QVector<QLayoutItem*> m_items;
};
