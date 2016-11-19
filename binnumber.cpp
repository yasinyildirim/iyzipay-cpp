#include "binnumber.h"

BinNumber::BinNumber(QObject* parent):IyzipayResource(parent)
{


}

QNetworkReply* BinNumber::retrieve(RetrieveBinNumberRequest* request, Options* options){

    QNetworkReply* reply = httpClient.post(options->getBaseUrl() + "/payment/bin/check",
                this->getHttpHeaders(request, options),  request  );

    return reply;

}

QByteArray BinNumber::toJsonData(){

    QStringList ignoreList(QString(QLatin1String("objectName")));
    ignoreList.append(QString(QLatin1String("httpClient")));
    QVariantMap variant = QJson::QObjectHelper::qobject2qvariant(this, ignoreList );
    QJson::Serializer serializer;
    return serializer.serialize( variant);


}

 QString BinNumber::toString(){
     QString str =  this->toJsonData();
     return str;

}
