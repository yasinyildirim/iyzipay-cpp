#ifndef OPTIONS_H
#define OPTIONS_H

#include <QString>
#include <QObject>
class Options: public QObject {
Q_OBJECT

public:
    explicit Options(QObject* parent = 0);
    QString getApiKey() {
        return apiKey;
    }

    void setApiKey(const QString& apiKey) {
        this->apiKey = apiKey;
    }

    QString getSecretKey() {
        return secretKey;
    }

    void setSecretKey(const QString& secretKey) {
        this->secretKey = secretKey;
    }

     QString getBaseUrl() {
        return baseUrl;
    }

    void setBaseUrl(const QString& baseUrl) {
        this->baseUrl = baseUrl;
    }

private:
    Q_DISABLE_COPY(Options)
    QString apiKey;
    QString secretKey;
    QString baseUrl;

};

#endif // OPTIONS_H
