#ifndef JSONHANDLER_H
#define JSONHANDLER_H

#include "databasehandler.h"
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include "sstream"



class JSONHandler : public QObject
{
public:
    JSONHandler();
    ~JSONHandler();
    QJsonArray generateResults(QString query);
};

#endif // JSONHandler_H
