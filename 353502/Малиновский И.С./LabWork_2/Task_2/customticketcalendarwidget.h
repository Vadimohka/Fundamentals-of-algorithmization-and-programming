#ifndef CUSTOMCALENDARWIDGET_H
#define CUSTOMCALENDARWIDGET_H

#include <QObject>
#include <QCalendarWidget>
#include <QSet>
#include <QDate>
#include <QTextCharFormat>
#include <QPainter>

class CustomTicketCalendarWidget : public QCalendarWidget
{
    Q_OBJECT

public:
    CustomTicketCalendarWidget(QWidget *parent = nullptr);
    CustomTicketCalendarWidget& operator=(const CustomTicketCalendarWidget &other);

    void addDate(const QDate &date);
protected:

    void selectionChanged(const QDate &date);
    void paintCell(QPainter *painter, const QRect &rect, const QDate &date) const override;

private:
    QSet <QDate> dates;

signals:
    void dateTicketSelected(const QDate &date);
};

#endif // CUSTOMCALENDARWIDGET_H
