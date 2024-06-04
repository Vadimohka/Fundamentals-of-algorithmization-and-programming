
#pragma once

#include <QLayout>
#include <QVector>
#include <QVariantAnimation>

class MyCardVBL : public QLayout
{
public:
    // Constructor
    MyCardVBL(int spacing);
    MyCardVBL(int spacing, QWidget *parent);

    // Destructor
    ~MyCardVBL();

    //~ Begin QLayout interface
    void addItem(QLayoutItem *item) override;
    QSize sizeHint() const override;
    QSize minimumSize() const override;
    int count() const override;
    QLayoutItem *itemAt(int) const override;
    QLayoutItem *takeAt(int) override;
    void setGeometry(const QRect &rect) override;
    //~ End QLayout interface

    // Sets the spacing with animation
    void setSpacingWithAnimation(int newSpacing);

private:
    // Vector of layout items to layout in this layout
    QVector<QLayoutItem*> m_items;

    // Animation to transition between spacings
    QVariantAnimation* spacingAnim;
};
