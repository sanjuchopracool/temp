import QtQuick 2.9
import QtQuick.Window 2.2
import com.sanjay.setting 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Component.onCompleted: {
        var newSetting = SettingManager.setting;
        newSetting.name = "SANJAY"
        newSetting.value = 23;
        console.log(newSetting)
        SettingManager.useSetting(newSetting)
    }
}
