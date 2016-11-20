#ifndef REQUEST_H
#define REQUEST_H

#include <QString>
#include <QObject>

class Request: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString locale READ getLocale WRITE setLocale)
    Q_PROPERTY(QString conversationId READ getConversationId WRITE setConversationId)


public:
    explicit Request(QObject* parent = 0);

    QString getLocale() {
        return locale;
    }

    void setLocale(const QString& locale) {
        this->locale = locale;
    }

    QString getConversationId() {
        return conversationId;
    }

    void setConversationId(const QString& conversationId) {
        this->conversationId = conversationId;
    }


    virtual QString toString();
    virtual QByteArray toJsonData();

signals:

public slots:

protected:

    QString locale;
    QString conversationId;
};

#endif // REQUEST_H
