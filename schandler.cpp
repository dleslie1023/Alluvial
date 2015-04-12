#include "schandler.h"
#include <QCoreApplication>
#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>

#include <QUrlQuery>

#include <QStandardPaths>
#include <QFileInfo>
#include <QFile>



SCHandler::SCHandler()
{
    results = QJsonArray();

}


SCHandler::~SCHandler()
{

}


//category: artist, title, user,
int SCHandler::query(QString value, QString key = "title"){
    last_search = QJsonDocument(QJsonDocument::fromJson(QString("{"+key+","+value+"}").toUtf8()));
    // create custom temporary event loop on stack
    QEventLoop eventLoop;
    QUrl url(SC_TRACKS_URL);
    QUrlQuery query;
    query.addQueryItem("client_id", SC_CLIENT_ID);

    //switch for request type
    //loop to pull out queries

    query.addQueryItem(key, value);
    query.addQueryItem("downloadable", "true");


    url.setQuery(query.query());

    // "quit()" the event-loop, when the network request "finished()"
    QNetworkAccessManager mgr;
    QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));

    // the HTTP request
    QNetworkRequest req(url);
    QNetworkReply *reply = mgr.get(req);
    eventLoop.exec(); // blocks stack until "finished()" has been called

    if (reply->error() == QNetworkReply::NoError) {
        QJsonParseError err;
        QJsonDocument jsondoc = QJsonDocument(QJsonDocument::fromJson(QString(reply->readAll()).toUtf8(), &err)); //raw string to qtstring to bytecode to jsondoc fucking shit
        results = jsondoc.array(); //take the pile of responses and make them an array so you can fucking do something with the
        return results.size();

    }
    else {
        //failure
        qDebug() << "Failed query: " <<reply->errorString();
        delete reply;
        return -1;
    }
}

//not working
//void SCHandler::connect(QString uname, QString pword){
//    QEventLoop eventLoop;
//    QUrl url("https://api.soundcloud.com/tracks");
//    QUrlQuery query;

//    //client_id
//    query.addQueryItem("client_id", SC_CLIENT_ID);
//    //secret
//    query.addQueryItem("client_secret", SC_CLIENT_SECRET);
//    //uname

//    //pword

//    //redirect_uri

//    url.setQuery(query.query());

//    QNetworkAccessManager mgr;
//    QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));

//    QNetworkRequest req(url);
//    QNetworkReply *reply = mgr.get(req);
//    eventLoop.exec(); // blocks stack until "finished()" has been called

//    if (reply->error() == QNetworkReply::NoError) {
//        qDebug() << "Success: " << reply->readAll();
//        delete reply;

//    }
//    else {
//        //failure
//        qDebug() << "Failure" <<reply->errorString();
//        delete reply;
//    }

//}

int SCHandler::request_song(QString download_url, QString target="./"){

    // create custom temporary event loop on stack
    QNetworkRequest request;
    request.setRawHeader("User-Agent", USER_AGENT);
    QString local_path;
    QEventLoop eventLoop;
    QString req_url = download_url;
    QUrl url(req_url);
    QUrlQuery query;

    query.addQueryItem("client_id", SC_CLIENT_ID);

    url.setQuery(query.query());

    // "quit()" the event-loop, when the network request "finished()"
    QNetworkAccessManager mgr;
    QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));

    // the HTTP request
    QNetworkRequest req(url);

    //req.setRawHeader();
    QNetworkReply *reply = mgr.get(req);
    eventLoop.exec(); // blocks stack until "finished()" has been called



    if (reply->error() == QNetworkReply::NoError) {
        //get temp download url as json

        QJsonDocument jsondoc = QJsonDocument(QJsonDocument::fromJson(QString(reply->readAll()).toUtf8()));
        QJsonObject jobj = jsondoc.object();
        QString download_url = jobj["location"].toString();

        //download
        if (reply->error() == QNetworkReply::NoError) {
            req_url = download_url;
            QUrl url(req_url);
            QNetworkRequest req(url);
            req.setRawHeader("User-Agent",USER_AGENT);
            QNetworkReply *reply = mgr.get(req);
            eventLoop.exec();

            QUrl aUrl(url);
            QFileInfo fileInfo=aUrl.path();
            qDebug() << fileInfo.fileName();
            QFile file(target);
            file.open(QIODevice::WriteOnly);
            file.write(reply->readAll());
            delete reply;
            return file.size();

        else{
            qDebug() << "Failure on download request" <<reply->errorString();
            delete reply;
            return -1;
        }

    }
    else {
        //failure
        qDebug() << "Failure on initial request" <<reply->errorString();
        delete reply;
        return -1;
    }
}


