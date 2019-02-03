#ifndef CUSTOMQUICKVIEW_H
#define CUSTOMQUICKVIEW_H

#include <QQuickView>

class CustomQuickView : public QQuickView
{
    Q_OBJECT
public:
    CustomQuickView(QWindow *parent = nullptr);

public slots:
    void onActivateChanged();
};

#endif // CUSTOMQUICKVIEW_H
