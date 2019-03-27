#ifndef SERVERSOCKET_H
#define SERVERSOCKET_H

#include "../socket.h"

class ServerSocket:public Socket
{
public:
    ServerSocket();
    ServerSocket(const int port);
    virtual ~ServerSocket();

    void Accept(Socket& socket) const;
};

#endif // SERVERSOCKET_H
