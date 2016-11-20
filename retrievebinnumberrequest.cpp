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

     //be careful! string conversion format is very strict!
     //TODO: implement generic string conversion as in the QJson
     QString str =  "[locale="+ this->locale+
             ",conversationId="+ this->conversationId +
             ",binNumber="+ this->m_binNumber +"]";
     return str;

}


