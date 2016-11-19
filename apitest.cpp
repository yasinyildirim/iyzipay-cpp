#include "apitest.h"

ApiTest::ApiTest(QObject *parent) : IyzipayResource(parent)
{

}

QNetworkReply* ApiTest::retrieve(Options* options){
    QNetworkReply* reply = httpClient.get(options->getBaseUrl() + "/payment/test");

    return reply;

}
