#include "Apiclient.h"

ApiClient::ApiClient(QObject *parent) : QObject(parent)
{
    m_server_api_address = "localhost:50051";  // default

    // open channel
    m_channel = grpc::CreateChannel(m_server_api_address, grpc::InsecureChannelCredentials());
    m_greeterStub = helloworld::Greeter::NewStub(m_channel);
}


QString ApiClient::sayHello(QString user)
{
    // client context
    grpc::ClientContext context;

    // define our request
    helloworld::HelloRequest request;
    request.set_name(user.toStdString());

    // prepare a place to store the reply
    helloworld::HelloReply reply;

    // call the api
    grpc::Status status = m_greeterStub->SayHello(&context, request, &reply);

    // return in function of status
    if(status.ok()){
        return QString::fromStdString(reply.message());
    } else {
        return QString::fromStdString("error");
    }
}
