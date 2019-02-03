#include "SettingManager.h"
#include <QDebug>

SettingManager::SettingManager(QObject *parent) : QObject(parent)
{

}

Setting SettingManager::setting() const
{
    return  setting_;
}

void SettingManager::setSetting(Setting inSetting)
{
    setting_ = inSetting;
}

void SettingManager::useSetting(const Setting &inSetting)
{
    qDebug() << setting_.name_;
    qDebug() << setting_.value_;
}
