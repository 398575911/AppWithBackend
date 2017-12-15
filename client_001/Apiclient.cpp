#include "Apiclient.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using helloworld::HelloRequest;
using helloworld::HelloReply;
using helloworld::Greeter;

ApiClient::ApiClient(QObject *parent) : QObject(parent)
{

}


QString ApiClient::useSayHello(QString user)
{
    std::shared_ptr<grpc::Channel> channel = grpc::CreateChannel("localhost:50051", grpc::InsecureChannelCredentials());
    std::unique_ptr<helloworld::Greeter::Stub> stub = helloworld::Greeter::NewStub(channel);

    ClientContext context;
    HelloRequest request;
    request.set_name(user.toStdString());
    HelloReply reply;

    Status status = stub->SayHello(&context, request, &reply);

    if(status.ok()){
        return QString::fromStdString(reply.message());
    } else {
        return QString::fromStdString("rpc failed");
    }
}
