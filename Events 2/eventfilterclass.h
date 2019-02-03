#ifndef EVENTFILTERCLASS_H
#define EVENTFILTERCLASS_H

#include <QObject>

class EventFilterClass : public QObject
{
    Q_OBJECT
public:
    explicit EventFilterClass(QObject *parent = nullptr);
    bool eventFilter(QObject *watched, QEvent *event);

signals:

public slots:
};

#endif // EVENTFILTERCLASS_H
