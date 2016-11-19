#include "hashgenerator.h"


HashGenerator::HashGenerator()
{

}

QString HashGenerator::generateHash(const QString& apiKey, const QString& secretKey,
                                           const QString& randomString, Request* iyziRequest) {
    QCryptographicHash cryptoHash(QCryptographicHash::Sha1);

    QByteArray result;


    QString input(apiKey + randomString + secretKey + iyziRequest->toString());
    cryptoHash.addData(input.toUtf8());
    result = cryptoHash.result();

    QString strResult(result.toBase64().data());
    return strResult;
}
