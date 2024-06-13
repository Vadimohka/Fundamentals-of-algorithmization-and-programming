#include "customcalendarwidget.h"

CustomCalendarWidget::CustomCalendarWidget(QWidget *parent) : QCalendarWidget(parent) { }

CustomCalendarWidget& CustomCalendarWidget::operator=(const CustomCalendarWidget &other) {
    if (this != &other)
    {
        banDates = other.banDates;
        banDayOfWeek = other.banDayOfWeek;
    }
    return *this;
}

void CustomCalendarWidget::selectionChanged(const QDate &date)
{
    if (banDates.contains(date) || banDayOfWeek.contains(date.dayOfWeek())) {
        setSelectedDate(selectedDate());
        return;
    }
    QCalendarWidget::selectionChanged();
    emit dateSelected(date);
}

void CustomCalendarWidget::paintCell(QPainter *painter, const QRect &rect, const QDate &date) const
{
    if (banDates.contains(date) || banDayOfWeek.contains(date.dayOfWeek())) {
        QTextCharFormat format;
        format.setBackground(Qt::lightGray);
        format.setForeground(Qt::gray);
        painter->fillRect(rect, format.background());
        painter->setPen(format.foreground().color());
        painter->drawText(rect, Qt::AlignCenter, QString::number(date.day()));
    } else
    {
        QCalendarWidget::paintCell(painter, rect, date);
    }
}

void CustomCalendarWidget::addBanDate(const QDate &date)
{
    banDates.insert(date);
}

void CustomCalendarWidget::addBanDayOfWeek(const int ind)
{
    banDayOfWeek.insert(ind);
}
