#include "customticketcalendarwidget.h"

CustomTicketCalendarWidget::CustomTicketCalendarWidget(QWidget *parent) : QCalendarWidget(parent) { }

CustomTicketCalendarWidget& CustomTicketCalendarWidget::operator=(const CustomTicketCalendarWidget &other) {
    if (this != &other)
    {
        dates = other.dates;
    }
    return *this;
}

void CustomTicketCalendarWidget::selectionChanged(const QDate &date)
{
    if (!dates.contains(date)) {
        setSelectedDate(selectedDate());
        return;
    }
    QCalendarWidget::selectionChanged();
    emit dateTicketSelected(date);
}

void CustomTicketCalendarWidget::paintCell(QPainter *painter, const QRect &rect, const QDate &date) const
{
    if (!dates.contains(date)) {
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

void CustomTicketCalendarWidget::addDate(const QDate &date)
{
    dates.insert(date);
}
