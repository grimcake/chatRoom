#include "serversocket.h"
#include "../socketexception.h"

ServerSocket::ServerSocket(const int port)
{
    if(!Socket::Create())
    {
        throw SocketException("create server fail");
    }
    if(!Socket::Bind(port))
    {
        throw SocketException("bind fail");
    }
    if(!Socket::Listen())
    {
        throw SocketException("listen fail");
    }
}

ServerSocket::~ServerSocket()
{

}

void ServerSocket::Accept(Socket& socket) const
{
    if(!Socket::Accept(socket))
    {
        throw SocketException("accept fail");
    }
}
