#include <QCoreApplication>
#include "myserver.h"
#include "deliverydb.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    MyServer newServer;
    return a.exec();
}
