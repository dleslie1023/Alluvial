#include "JSONhandler.h"



int main(){

    QJsonObject test;
    QString query = "Kid Rock";
    JSONHandler *json = new JSONHandler();
    test = json->generateResults(query);




//    result = dub->queryDB(querySong);
   //std::cout << result;



//    return 0;
}

