#ifndef APICLIENT_H
#define APICLIENT_H

#include <QObject>
#include <QQuickItem>

#include <grpc++/grpc++.h>

#include "helloworld.pb.h"
#include "helloworld.grpc.pb.h"


class ApiClient : public QObject
{
    Q_OBJECT
public:
    explicit ApiClient(QObject *parent = nullptr);

signals:

public slots:
    QString sayHello(QString user);

private:
    std::string m_server_api_address;
    std::shared_ptr<grpc::Channel> m_channel;
    std::unique_ptr<helloworld::Greeter::Stub> m_greeterStub;

};
#endif // APICLIENT_H
