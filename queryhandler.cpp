#include "queryhandler.h"

queryhandler::queryhandler()
{

}

queryhandler::~queryhandler()
{

}
/*!
 * \brief queryhandler::getResults gets the result QJsonArray
 * \param query query in a QString
 * \return QJsonArray result
 */
QJsonArray queryhandler::getResults(QString query)
{
    QJsonArray result;
    JSONHandler *mediaObject = new JSONHandler;

    return result = mediaObject->generateResults(query);
}

