#ifndef AUDIO_H
#define AUDIO_H

#include <QWidget>
#include <QObject>
#include <QtPlugin>
#include "mainui/interface.h"

#include <QProcess>

#include "../../component/customwidget.h"

namespace Ui {
class Audio;
}

class Audio : public QObject, CommonInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.kycc.CommonInterface")
    Q_INTERFACES(CommonInterface)

public:
    Audio();
    ~Audio();

    QString get_plugin_name() Q_DECL_OVERRIDE;
    int get_plugin_type() Q_DECL_OVERRIDE;
    CustomWidget * get_plugin_ui() Q_DECL_OVERRIDE;
    void plugin_delay_control() Q_DECL_OVERRIDE;

private:
    Ui::Audio *ui;
    QString pluginName;
    int pluginType;
    CustomWidget * pluginWidget;

private slots:
    void change_soundtheme_page();
    void change_preference_page();

    void sound_settings_btn_clicked_slot();

};

#endif // AUDIO_H