#include "httpclient.h"

const QString HttpClient::DEFAULT_CHARSET = "UTF-8";
const QString HttpClient::APPLICATION_JSON = "application/json";
const QString HttpClient::CONTENT_TYPE = "Content-Type";
const QString HttpClient::ACCEPT = "Accept";
const int HttpClient::TIMEOUT = 140000;

HttpClient::HttpClient(QObject *parent) : QObject(parent)
{
    networkManager = new QNetworkAccessManager(this);
    connect(networkManager, SIGNAL(finished(QNetworkReply*)), this, SIGNAL(dataReady(QNetworkReply*)) );
}

void HttpClient::prepareHeaders(QMap<QString, QString> headers, QNetworkRequest* netRequest) {
    for (QMap<QString, QString>::iterator header = headers.begin(); header !=  headers.end(); ++header) {

        netRequest->setRawHeader(header.key().toAscii(), header.value().toAscii());

    }

    netRequest->setRawHeader(CONTENT_TYPE.toAscii(), APPLICATION_JSON.toAscii());
    netRequest->setRawHeader(ACCEPT.toAscii(), APPLICATION_JSON.toAscii());
}

void HttpClient::prepareRequestBody(HttpMethod::Type httpMethod, QByteArray& content, Request* iyziRequest){
    if (HttpMethod::isValidRequestFor(httpMethod)) {

        content = iyziRequest->toJsonData();

    }
}

