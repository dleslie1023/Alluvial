#include "databasehandler.h"


int main(){

    QJsonObject test;
    QString query = "Red Hot Chili Peppers";
    JSONHandler *json = new JSONHandler();
    test = json->generateResults(query);


//    dub->DBInit();
//    result = dub->queryDB(querySong);
//    std::cout << result;



    return 0;
}

