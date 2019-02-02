#include <QSettings>
#include "core/logging.h"
#include "playlistendhandler.h"

PlaylistEndHandler::PlaylistEndHandler(QObject *parent) : QObject(parent)
{

}

void PlaylistEndHandler::handle() {
    QSettings s;
    s.beginGroup("PlaylistEndHandler");
    int action = s.value("playlist_end_action", 0).toInt();
    bool displayDialog = s.value("display_confirm_dialog", 1).toBool();
    int timeout = s.value("confirm_dialog_timeout", 10).toInt();
    s.endGroup();
    if (action != 0) {
        if (displayDialog)
            qLog(Debug) << "Showing the dialog with timeout: " << timeout;
        switch (action) {
        case 1 :
            qLog(Debug)  << "turning the computer off.";
            break;
        case 2 :
            qLog(Debug) << "suspending the computer.";
            break;
        case 3 :
            qLog(Debug) << "hibernating the computer.";
            break;
        }
    } else {
        qLog(Debug) << "Playlist ended but there is nothing to do...";
    }

}
