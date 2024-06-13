#ifndef CUSTOMCALENDARWIDGET_H
#define CUSTOMCALENDARWIDGET_H

#include <QObject>
#include <QCalendarWidget>
#include <QSet>
#include <QDate>
#include <QTextCharFormat>
#include <QPainter>

class CustomCalendarWidget : public QCalendarWidget
{
    Q_OBJECT

public:
    CustomCalendarWidget(QWidget *parent = nullptr);
    CustomCalendarWidget& operator=(const CustomCalendarWidget &other);

    void addBanDate(const QDate &date);
    void addBanDayOfWeek(const int ind);
protected:

    void selectionChanged(const QDate &date);
    void paintCell(QPainter *painter, const QRect &rect, const QDate &date) const override;

private:
    QSet <QDate> banDates;
    QSet <int> banDayOfWeek;

signals:
    void dateSelected(const QDate &date);
};

#endif // CUSTOMCALENDARWIDGET_H
