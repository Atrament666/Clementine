#ifndef PLAYLISTENDHANDLER_H
#define PLAYLISTENDHANDLER_H

#include <QObject>

class PlaylistEndHandler : public QObject
{
    Q_OBJECT
public:
    explicit PlaylistEndHandler(QObject *parent = nullptr);

signals:

public slots:
    void handle();
};

#endif // PLAYLISTENDHANDLER_H
