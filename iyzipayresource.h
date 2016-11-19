#ifndef IYZIPAYRESOURCE_H
#define IYZIPAYRESOURCE_H

#include <QObject>
#include <QString>
#include <options.h>
#include <QMap>
#include <QHash>
#include "hashgenerator.h"
#include "request.h"
#include "randomstringutility.h"
#include "httpclient.h"

class IyzipayResource : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString status READ status WRITE setStatus)
    Q_PROPERTY(QString errorCode READ errorCode WRITE setErrorCode)
    Q_PROPERTY(QString errorMessage READ errorMessage WRITE setErrorMessage)
    Q_PROPERTY(QString errorGroup READ errorGroup WRITE setErrorGroup)
    Q_PROPERTY(QString locale READ locale WRITE setLocale)
    Q_PROPERTY(long systemTime READ systemTime WRITE setSystemTime)
    Q_PROPERTY(QString conversationId READ conversationId WRITE setConversationId)

public:
    explicit IyzipayResource(QObject *parent = 0);

    QString status();

    void setStatus(const QString& status) ;

    QString errorCode();

    void setErrorCode(const QString& errorCode) ;

    QString errorMessage();

    void setErrorMessage(const QString& errorMessage) ;

    QString errorGroup() ;

    void setErrorGroup(const QString& errorGroup) ;

    QString locale() ;

    void setLocale(const QString& locale);

    long systemTime() ;

    void setSystemTime(long systemTime) ;

    QString conversationId() ;

    void setConversationId(const QString& conversationId);


    virtual QByteArray toJsonData();
    virtual QString toString();

signals:
    void responseReady(QString);
public slots:
 void onDataReady(QNetworkReply* );
protected:
    static QMap<QString, QString> getHttpHeaders(Request* request, Options* options);
    HttpClient httpClient;
private:
    static const QString AUTHORIZATION;
    static const QString RANDOM_HEADER_NAME;
    static const QString CLIENT_VERSION_HEADER_NAME;
    static const QString IYZIWS_HEADER_NAME ;
    static const QString CLIENT_VERSION ;
    static const QString CLIENT_TITLE ;
    static const QString COLON ;
    static const int RANDOM_STRING_SIZE;

    QString m_status;
    QString m_errorCode;
    QString m_errorMessage;
    QString m_errorGroup;
    QString m_locale;
    long m_systemTime;
    QString m_conversationId;



    static QString prepareAuthorizationString(Request* request, const QString& randomString, Options* options);


};



#endif // IYZIPAYRESOURCE_H
