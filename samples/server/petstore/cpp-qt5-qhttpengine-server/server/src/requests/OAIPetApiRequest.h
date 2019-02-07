/**
 * OpenAPI Petstore
 * This is a sample server Petstore server. For this sample, you can use the api key `special-key` to test the authorization filters.
 *
 * OpenAPI spec version: 1.0.0
 * 
 *
 * NOTE: This class is auto generated by OpenAPI Generator (https://openapi-generator.tech).
 * https://openapi-generator.tech
 * Do not edit the class manually.
 */

#ifndef OAI_OAIPetApiRequest_H
#define OAI_OAIPetApiRequest_H

#include <QObject>
#include <QStringList>
#include <QMultiMap>
#include <QNetworkReply>
#include <QSharedPointer>

#include <qhttpengine/socket.h>
#include "OAIApiResponse.h"
#include "OAIPet.h"
#include <QIODevice>
#include <QString>
#include "OAIPetApiHandler.h"

namespace OpenAPI {

class OAIPetApiRequest : public QObject
{
    Q_OBJECT

public:
    OAIPetApiRequest(QHttpEngine::Socket *s, OAIPetApiHandler* handler);
    virtual ~OAIPetApiRequest();

    void addPetRequest();
    void deletePetRequest(const QString& pet_id);
    void findPetsByStatusRequest();
    void findPetsByTagsRequest();
    void getPetByIdRequest(const QString& pet_id);
    void updatePetRequest();
    void updatePetWithFormRequest(const QString& pet_id);
    void uploadFileRequest(const QString& pet_id);
    

    void addPetResponse();
    void deletePetResponse();
    void findPetsByStatusResponse(const QList<OAIPet>& res);
    void findPetsByTagsResponse(const QList<OAIPet>& res);
    void getPetByIdResponse(const OAIPet& res);
    void updatePetResponse();
    void updatePetWithFormResponse();
    void uploadFileResponse(const OAIApiResponse& res);
    

    void addPetError(QNetworkReply::NetworkError error_type, QString& error_str);
    void deletePetError(QNetworkReply::NetworkError error_type, QString& error_str);
    void findPetsByStatusError(const QList<OAIPet>& res, QNetworkReply::NetworkError error_type, QString& error_str);
    void findPetsByTagsError(const QList<OAIPet>& res, QNetworkReply::NetworkError error_type, QString& error_str);
    void getPetByIdError(const OAIPet& res, QNetworkReply::NetworkError error_type, QString& error_str);
    void updatePetError(QNetworkReply::NetworkError error_type, QString& error_str);
    void updatePetWithFormError(QNetworkReply::NetworkError error_type, QString& error_str);
    void uploadFileError(const OAIApiResponse& res, QNetworkReply::NetworkError error_type, QString& error_str);
    

    void sendCustomResponse(QByteArray & res, QNetworkReply::NetworkError error_type);

    void sendCustomResponse(QIODevice *res, QNetworkReply::NetworkError error_type);

    QMap<QString, QString> getRequestHeaders() const;

    QHttpEngine::Socket* getRawSocket();

    void setResponseHeaders(const QMultiMap<QString,QString>& headers);

signals:
    void addPet(OAIPet body);
    void deletePet(qint64 pet_id, QString api_key);
    void findPetsByStatus(QList<QString> status);
    void findPetsByTags(QList<QString> tags);
    void getPetById(qint64 pet_id);
    void updatePet(OAIPet body);
    void updatePetWithForm(qint64 pet_id, QString name, QString status);
    void uploadFile(qint64 pet_id, QString additional_metadata, QIODevice* file);
    

private:
    QMap<QString, QString> requestHeaders;
    QMap<QString, QString> responseHeaders;
    QHttpEngine::Socket  *socket;
    OAIPetApiHandler *handler;

    inline void writeResponseHeaders(){
        QHttpEngine::Socket::HeaderMap resHeaders;
        for(auto itr = responseHeaders.begin(); itr != responseHeaders.end(); ++itr) {
            resHeaders.insert(itr.key().toUtf8(), itr.value().toUtf8());
        }
        socket->setHeaders(resHeaders);
        socket->writeHeaders();
    }
};

}

#endif // OAI_OAIPetApiRequest_H
