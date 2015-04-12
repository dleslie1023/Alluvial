#ifndef JSONHANDLER_H
#define JSONHANDLER_H
#include <databasehandler.h>
#include <QJsonObject>


class JSONHandler
{
public:
    JSONHandler();
    ~JSONHandler();
    QJsonObject generateResults(QString query);
};

#endif // JSONHandler_H
