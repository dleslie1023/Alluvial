#ifndef PLAYLISTHANDLER_H
#define PLAYLISTHANDLER_H
#include "JSONhandler.h"


class playListHandler
{
public:
    playListHandler();
    ~playListHandler();
    void createPlaylist(QJsonObject playObj);
    void editPlaylist(QJsonObject playObj);
    QJsonArray getPlaylist(QString playName);
};

#endif // PLAYLISTHANDLER_H
