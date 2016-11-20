#ifndef HTTPCLIENT_H
#define HTTPCLIENT_H

#include <QObject>
#include <QString>
#include <QMap>
#include "httpmethod.h"
#include <QStringBuilder>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QDataStream>
#include <QTextStream>
#include <qjson/qobjecthelper.h>
#include <qjson/serializer.h>
#include <qjson/parser.h>
#include <QObject>
#include <QSslSocket>
#include <QSslConfiguration>
#include <QSsl>
#include "request.h"

class HttpClient : public QObject
{
    Q_OBJECT
public:
    explicit HttpClient(QObject *parent = 0);

    QNetworkReply* get(const QString& urlStr){
        QNetworkRequest request;
        QUrl url(urlStr);
        request.setUrl(url);
        return networkManager->get(request);

    }

    QNetworkReply* post(const QString& urlStr, QMap<QString, QString> headers, Request* requestObject ){
        QNetworkRequest request;
        this->prepareHeaders(headers, &request);
        QByteArray body_content;
        this->prepareRequestBody(HttpMethod::POST, body_content, requestObject);
        QUrl url(urlStr);
        request.setUrl(url);

        //qDebug() << body_content;
        return networkManager->post(request, body_content);

    }

    QNetworkReply* put(const QString& urlStr, QMap<QString, QString> headers, Request* requestObject ){
        QNetworkRequest request;
        this->prepareHeaders(headers, &request);
        QByteArray body_content;
        this->prepareRequestBody(HttpMethod::PUT, body_content, requestObject);
        QUrl url(urlStr);
        request.setUrl(url);
        return networkManager->put(request, body_content);

    }

    QNetworkReply* deleteResource(const QString& urlStr, QMap<QString, QString> headers){
        QNetworkRequest request;
        this->prepareHeaders(headers, &request);
        //QByteArray body_content;
        //this->prepareRequestBody(HttpMethod::DELETE, body_content, requestObject);
        QUrl url(urlStr);
        request.setUrl(url);
        return networkManager->deleteResource(request);

    }

signals:
    void dataReady(QNetworkReply*);
public slots:

private:
    static const QString DEFAULT_CHARSET ;
    static const QString APPLICATION_JSON ;
    static const QString CONTENT_TYPE ;
    static const QString ACCEPT ;
    static const int TIMEOUT;
    QNetworkAccessManager* networkManager;

    void prepareHeaders(QMap<QString, QString> headers, QNetworkRequest* netRequest);
    void prepareRequestBody(HttpMethod::Type httpMethod, QByteArray& content, Request* request);


};






#endif // HTTPCLIENT_H
