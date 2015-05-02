#ifndef DatabaseHandler_H
#define DatabaseHandler_H

#include <taglib/fileref.h>
#include <taglib/tag.h>
#include <taglib/tpropertymap.h>
#include <taglib/tstring.h>
#include <QDebug>
#include <QDir>
#include <QMimeDatabase>
#include <QSqlDatabase>
#include <QJsonObject>
#include <QSqlError>
#include <QSqlQuery>
#include <QDirIterator>
#include <stdlib.h>
#include <QStringList>
using std::string;

//struct that contains needed metadata in QString and uint
struct MD{

    QString filepath, artist, album, title, genre;
    signed int PKID, track_num, length_min, length_sec;
};

/*!
 * \brief This DatabaseHandler class contains all database functions from creating them, to their
 * \       tables, filing them with data to retrieving their contents.
 */
class DatabaseHandler : public QObject
{
public:
    DatabaseHandler();
    ~DatabaseHandler();
    MD ripMetaData(QString file);
    bool isMusic (QString const file);
    bool DBInit();
    bool openDB();
    bool createTable();
    void DBpopulate(QDir dir);
    std::vector <MD> queryDB(QString query);
    QString getSongFP(int PKID);
    bool insertPlaylist(QString name, QString filepath);
    QString retrievePlaylist(QString name);
    QStringList retrieveAllPlaylists();

    /*!
     * \brief this global variable is needed so multiple functions
     * \       can execute commands on the same sqlquery (i.e. open db, create tables, populate db)
     */
    QSqlQuery query;
    /*!
     * \brief global db variable that all db code acts on.
     */
    QSqlDatabase db;
private:

};


#endif // DatabaseHandler_Her
