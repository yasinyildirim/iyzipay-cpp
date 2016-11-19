#include "iyzipayresource.h"

#include <QTime>
#include <qjson/parser.h>
#include <qjson/qobjecthelper.h>
#include <qjson/serializer.h>

const QString IyzipayResource::AUTHORIZATION = "Authorization";
const QString IyzipayResource::RANDOM_HEADER_NAME = "x-iyzi-rnd";
const QString IyzipayResource::CLIENT_VERSION_HEADER_NAME = "x-iyzi-client-version";
const QString IyzipayResource::IYZIWS_HEADER_NAME = "IYZWS ";
const QString IyzipayResource::CLIENT_VERSION = "1.0.0";
const QString IyzipayResource::CLIENT_TITLE = "iyzipay-cpp";
const QString IyzipayResource::COLON = ":";
const int IyzipayResource::RANDOM_STRING_SIZE = 8;

IyzipayResource::IyzipayResource(QObject *parent) : QObject(parent)
{
    qsrand(QTime::currentTime().msec());
    connect(&httpClient, SIGNAL(dataReady(QNetworkReply*)), this, SLOT(onDataReady(QNetworkReply*)));

}

QString IyzipayResource::status() {
    return m_status;
}

void IyzipayResource::setStatus(const QString& status) {
    this->m_status = status;
}

QString IyzipayResource::errorCode() {
    return m_errorCode;
}

void IyzipayResource::setErrorCode(const QString& errorCode) {
    this->m_errorCode = errorCode;
}

QString IyzipayResource::errorMessage() {
    return m_errorMessage;
}

void IyzipayResource::setErrorMessage(const QString& errorMessage) {
    this->m_errorMessage = errorMessage;
}

QString IyzipayResource::errorGroup() {
    return m_errorGroup;
}

void IyzipayResource::setErrorGroup(const QString& errorGroup) {
    this->m_errorGroup = errorGroup;
}

QString IyzipayResource::locale() {
    return m_locale;
}

void IyzipayResource::setLocale(const QString& locale) {
    this->m_locale = locale;
}

long IyzipayResource::systemTime() {
    return m_systemTime;
}

void IyzipayResource::setSystemTime(long systemTime) {
    this->m_systemTime = systemTime;
}

QString IyzipayResource::conversationId() {
    return m_conversationId;
}

void IyzipayResource::setConversationId(const QString& conversationId) {
    this->m_conversationId = conversationId;
}

QMap<QString, QString> IyzipayResource::getHttpHeaders(Request* request, Options* options) {
    QMap<QString, QString> headers;

    QString randomString = QString::number(QTime::currentTime().msec()) + RandomStringUtility::GetRandomString(RANDOM_STRING_SIZE);
    headers.insert(RANDOM_HEADER_NAME, randomString);
    headers.insert(AUTHORIZATION, IyzipayResource::prepareAuthorizationString(request, randomString, options));

    if (!CLIENT_VERSION.isEmpty() && !CLIENT_TITLE.isEmpty()) {
        headers.insert(CLIENT_VERSION_HEADER_NAME, CLIENT_TITLE + "-" + CLIENT_VERSION);
    }
    return headers;
}

QString IyzipayResource::prepareAuthorizationString(Request *request, const QString& randomString, Options* options) {
    QString hash = HashGenerator::generateHash(options->getApiKey(), options->getSecretKey(), randomString, request);
    QString result (IYZIWS_HEADER_NAME + options->getApiKey() + COLON + hash);
    return result;
}


QByteArray IyzipayResource::toJsonData(){
    QStringList ignoreList(QString(QLatin1String("objectName")));
    ignoreList.append(QString(QLatin1String("httpClient")));
    QVariantMap variant = QJson::QObjectHelper::qobject2qvariant(this, ignoreList );
    QJson::Serializer serializer;
    return serializer.serialize( variant);


}

 QString IyzipayResource::toString(){
     QString str =  this->toJsonData();
     return str;

}

 void IyzipayResource::onDataReady(QNetworkReply* reply){
     QNetworkReply::NetworkError error_type = reply->error();
     QString response;
     if (error_type == QNetworkReply::NoError) {
         response = reply->readAll();
     }
     else {
         response = reply->errorString();
     }
     emit responseReady(response);
 }
