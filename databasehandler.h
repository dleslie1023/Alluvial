#ifndef DatabaseHandler_H
#define DatabaseHandler_H

#include <taglib/fileref.h>
#include <taglib/tag.h>
#include <taglib/tpropertymap.h>
#include <taglib/tstring.h>
#include <QDir>
#include <QString>
#include <QDirIterator>
#include <QFlag>
#include <QMimeDatabase>
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <QObject>
#include <QSqlDatabase>
#include <QSqlError>
#include <QFile>
#include <QObject>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QStringList>
#include <QVariant>
#include <vector>
#include <JSONhandler.h>

using std::string;

//struct that contains needed metadata in QString and uint
struct MD{

    QString filepath, artist, album, title, genre;
    signed int year, track_num, length_min, length_sec;
};


class DatabaseHandler
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
    QSqlQuery query;
    QSqlDatabase db;
private:

};


#endif // DatabaseHandler_H
