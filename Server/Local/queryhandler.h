#ifndef QUERYHANDLER_H
#define QUERYHANDLER_H
#include "JSONhandler.h"

/*!
 * \brief The queryhandler class handles queries from the client and
 * \       returns resuls to them
 */
class queryhandler
{
public:
    queryhandler();
    ~queryhandler();
    QJsonArray getResults(QString query);
};

#endif // QUERYHANDLER_H
