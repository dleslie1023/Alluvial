#include <JSONhandler.h>
#include <songhandler.h>



int main(){

//    QJsonArray test;
//    QString query = "Anjunabeats";
//    JSONHandler *json = new JSONHandler();
//    test = json->generateResults(query);
//    qDebug() << test;

      int PKID = 1;
      songHandler *song = new songHandler();
      QByteArray test = song->getSong(PKID);



//    result = dub->queryDB(querySong);
   //std::cout << result;



//    return 0;
}

