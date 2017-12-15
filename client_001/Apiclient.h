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
    QString useSayHello(QString user);

private:

};
#endif // APICLIENT_H
