#include "hashgenerator.h"
#include <QDebug>

HashGenerator::HashGenerator()
{

}

QString HashGenerator::generateHash(const QString& apiKey, const QString& secretKey,
                                           const QString& randomString, Request* iyziRequest) {
    QCryptographicHash cryptoHash(QCryptographicHash::Sha1);

    QByteArray result;
    qDebug()<<iyziRequest->toString();
    QString input(apiKey + randomString + secretKey + iyziRequest->toString());
    QByteArray byteInput = input.toAscii();

    cryptoHash.addData(byteInput);
    result = cryptoHash.result();  
    QString strResult(result.toBase64());
    return strResult;
}
