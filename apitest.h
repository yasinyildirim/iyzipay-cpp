#ifndef APITEST_H
#define APITEST_H

#include "iyzipayresource.h"

class ApiTest : public IyzipayResource
{
    Q_OBJECT
public:
    explicit ApiTest(QObject *parent = 0);
     QNetworkReply* retrieve(Options* options);
signals:

public slots:
};

#endif // APITEST_H
