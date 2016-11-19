#ifndef RETRIEVEBINNUMBERREQUEST_H
#define RETRIEVEBINNUMBERREQUEST_H

#include <QObject>
#include "request.h"

class RetrieveBinNumberRequest : public Request
{
    Q_OBJECT
    Q_PROPERTY(QString binNumber READ binNumber WRITE setBinNumber)
public:
    RetrieveBinNumberRequest(QObject* parent = 0);


    QString binNumber() {
        return m_binNumber;
    }

    void setBinNumber(const QString& bin_number) {
        this->m_binNumber = bin_number;
    }


    virtual QString toString();

    virtual QByteArray toJsonData();

private:
    QString m_binNumber;
};

#endif // RETRIEVEBINNUMBERREQUEST_H
