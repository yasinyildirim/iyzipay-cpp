#include "retrievebinnumberrequest.h"

#include <qjson/parser.h>
#include <qjson/qobjecthelper.h>
#include <qjson/serializer.h>

RetrieveBinNumberRequest::RetrieveBinNumberRequest(QObject* parent):Request(parent)
{

}

QByteArray RetrieveBinNumberRequest::toJsonData(){


    QVariantMap variant = QJson::QObjectHelper::qobject2qvariant(this);
    QJson::Serializer serializer;
    return serializer.serialize( variant);


}

 QString RetrieveBinNumberRequest::toString(){

     QString str =  this->toJsonData();
     return str;

}


