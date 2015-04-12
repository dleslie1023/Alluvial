#include "JSONhandler.h"


JSONHandler::JSONHandler()
{

}

JSONHandler::~JSONHandler()
{

}

QJsonObject JSONHandler::generateResults(QString query)
{
    QJsonObject test;
    std::vector <MD> MDresult;
    bool result;

    DatabaseHandler *dub = new DatabaseHandler();
    result = dub->openDB();
    MDresult = dub->queryDB(query);
    std::cout << MDresult.at(1).title.toStdString();
    //std::cout << result << "\n";
    return test;
}

