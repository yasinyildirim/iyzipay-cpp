#include "request.h"
#include <qjson/parser.h>
#include <qjson/qobjecthelper.h>
#include <qjson/serializer.h>

Request::Request(QObject* parent):QObject(parent), locale("tr")
{

}


QByteArray Request::toJsonData(){


    QVariantMap variant = QJson::QObjectHelper::qobject2qvariant(this);
    QJson::Serializer serializer;
    return serializer.serialize( variant);

}

 QString Request::toString(){

     QString str =  this->toJsonData();
     return str;

}
