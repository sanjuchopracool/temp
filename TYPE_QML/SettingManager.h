#ifndef SETTINGMANAGE_H
#define SETTINGMANAGE_H

#include <QObject>

struct Setting
{
    Q_GADGET
    Q_PROPERTY(int value MEMBER value_)
    Q_PROPERTY(QString name MEMBER name_)

public:
    int value_ = 0;
    QString name_ = "";
};
Q_DECLARE_METATYPE(Setting)

class SettingManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(Setting setting READ setting WRITE setSetting)
public:
    explicit SettingManager(QObject *parent = nullptr);

    Setting setting() const;
    void setSetting(Setting inSetting);
signals:

public slots:
    void useSetting(const Setting& inSetting);

public:
    Setting setting_;
};

#endif // SETTINGMANAGE_H
