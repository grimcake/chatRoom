#include "clientsocket.h"
#include "../socketexception.h"

ClientSocket::ClientSocket(const std::string& host, const int port)
{
    if(!Socket::Create())
    {
        throw SocketException("create client socket fail");
    }
    if(!Socket::Connect(host, port))
    {
        throw SocketException("client connect fail");
    }
}

ClientSocket::~ClientSocket()
{

}

bool ClientSocket::Send(const std::string& message)
{
    return Socket::Send(static_cast<Socket&>(*this), message);
}

int ClientSocket::Receive(std::string& message)
{
    return Socket::Receive(static_cast<Socket&>(*this), message);
}
