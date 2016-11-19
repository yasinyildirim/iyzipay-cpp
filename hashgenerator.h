#ifndef HASHGENERATOR_H
#define HASHGENERATOR_H

#include <QString>
#include <QCryptographicHash>
#include <QObject>
#include <QByteArray>
#include <qjson/qobjecthelper.h>
#include <qjson/serializer.h>
#include <QVariantMap>
#include "request.h"

class HashGenerator
{

public:
    static QString generateHash(const QString& apiKey, const QString& secretKey,
                                const QString& randomString, Request* request);

private:
    HashGenerator();

};


#endif // HASHGENERATOR_H
