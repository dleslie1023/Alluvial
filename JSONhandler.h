#ifndef JSONHANDLER_H
#define JSONHANDLER_H

#include "databasehandler.h"
#include <QJsonObject>
#include <QDebug>



class JSONHandler : public QObject
{
public:
    JSONHandler();
    ~JSONHandler();
    QJsonObject generateResults(QString query);
};

#endif // JSONHandler_H
