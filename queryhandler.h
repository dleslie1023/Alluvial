#ifndef QUERYHANDLER_H
#define QUERYHANDLER_H
#include "JSONhandler.h"


class queryhandler
{
public:
    queryhandler();
    ~queryhandler();
    QJsonArray getResults(QString query);
};

#endif // QUERYHANDLER_H
