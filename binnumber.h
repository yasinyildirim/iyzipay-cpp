#ifndef BINNUMBER_H
#define BINNUMBER_H

#include <QObject>
#include "iyzipayresource.h"
#include <QNetworkReply>
#include "retrievebinnumberrequest.h"
#include "httpclient.h"

class BinNumber : public IyzipayResource
{
    Q_OBJECT
    Q_PROPERTY(QString binNumber READ binNumber WRITE setBinNumber)
    Q_PROPERTY(QString cardType READ cardType WRITE setCardType )
    Q_PROPERTY(QString cardAssociation READ cardAssociation WRITE setCardAssociation)
    Q_PROPERTY(QString cardFamily READ cardFamily WRITE setCardFamily)
    Q_PROPERTY(QString bankName READ bankName WRITE setBankName)
    Q_PROPERTY(long bankCode READ bankCode WRITE setBankCode )

public:
    BinNumber(QObject* parent = 0);
    QNetworkReply* retrieve(RetrieveBinNumberRequest* request, Options* options);
    virtual QByteArray toJsonData();
    virtual QString toString();

    QString binNumber(){
        return this->binNumber();
    }
    void setBinNumber(const QString& bin_number){
        this->m_binNumber = bin_number;
    }
    QString cardType(){
        return this->m_cardType;
    }
    void setCardType(const QString& card_type){
        this->m_cardType = card_type;
    }
    QString cardAssociation(){
        return this->m_cardAssociation;
    }
    void setCardAssociation(const QString &card_association){
        this->m_cardAssociation = card_association;
    }

    QString cardFamily(){
        return this->m_cardFamily;
    }

    void setCardFamily(const QString & cf){
        this->m_cardFamily = cf;
    }

    QString bankName(){
        return this->m_bankName;
    }
    void setBankName(const QString& bn){
        this->m_bankName =bn;
    }

    long bankCode(){
        return this->m_bankCode;
    }

    void setBankCode(long bc){
        this->m_bankCode = bc;
    }

public slots:

private:
    QString m_binNumber;
    QString m_cardType;
    QString m_cardAssociation;
    QString m_cardFamily;
    QString m_bankName;
    long m_bankCode;
};

#endif // BINNUMBER_H
