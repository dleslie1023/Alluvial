#include "JSONhandler.h"
#include "sstream"


JSONHandler::JSONHandler()
{

}

JSONHandler::~JSONHandler()
{

}

QJsonObject JSONHandler::generateResults(QString query)
{
    QJsonObject test;
    //QJsonArray result;
    std::vector <MD> MDresult;
    DatabaseHandler *dub = new DatabaseHandler();
    bool DBOpen = dub->openDB();
    MDresult = dub->queryDB(query);
    int numOfMD = MDresult.size();

    //qDebug() << MDresult.at(0).PKID;

    for(int i = 0; i < numOfMD; i++){
        std::stringstream sm;
        std::stringstream ss;
        sm <<  MDresult.at(i).length_min;
        ss <<  MDresult.at(i).length_sec;
        string stringLengthTemp = sm.str() + ":" + ss.str();
        QString qstrLength = QString::fromStdString(stringLengthTemp);
        QJsonObject media{
            {"hash", MDresult.at(i).PKID}, //TODO: add hash functions
            {"order",""},
        };
        QJsonObject meta{
            {"title", MDresult.at(i).title},
            {"album", MDresult.at(i).album},
            {"artist", MDresult.at(i).artist},
            {"track_number", MDresult.at(i).track_num},
            {"length", qstrLength},
            {"genre", MDresult.at(i).genre}
        };
        media["metadata"] = meta;

        qDebug() << media;
    }
    return test;
}

