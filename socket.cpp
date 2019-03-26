#include "socket.h"
#include <iostream>
#include <string.h>

Socket::Socket()
:m_sockfd(-1)
{

}

Socket::~Socket()
{
    if(IsValid())
    {
        close(m_sockfd);
    }
}

bool Socket::Create()
{
    m_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(!IsValid()) return false;
    return true;
}

bool Socket::Bind(const int port)
{
    if(!IsValid()) return false;

    m_address.sin_family = AF_INET;
    m_address.sin_addr.s_addr = htonl(INADDR_ANY);
    m_address.sin_port = htons(port);

    int bindReturn = bind(m_sockfd, (struct sockaddr*)&m_address, sizeof(m_address));
    if(bindReturn == -1) return false;
    else return true;
}

bool Socket::Listen() const
{
    if(!IsValid()) return false;
    int listenReturn = listen(m_sockfd, MAX_CONNECTION);
    if(listenReturn == -1) return false;
    return true;
}

bool Socket::Accept(Socket& clientSocket) const
{
    int clientaddrLength = sizeof(clientSocket.m_address);
    clientSocket.m_sockfd = accept(m_sockfd, (struct sockaddr*)&clientSocket.m_address, (socklen_t *)&clientaddrLength);

    if(clientSocket.m_sockfd == -1) return false;
    return true;
}

bool Socket::Connect(const std::string& host, const int port)
{
    if(!IsValid()) return false;

    m_address.sin_family = AF_INET;
    m_address.sin_port = htons(port);
    m_address.sin_addr.s_addr = inet_addr(host.c_str());

    int connectReturn = connect(m_sockfd, (struct sockaddr*)&m_address, sizeof(m_address));
    if(connectReturn == -1) return false;
    return true;
}

bool Socket::Send(Socket& socket, const std::string& message) const
{
    int sendReturn = send(socket.m_sockfd, message.c_str(), message.length(), MSG_NOSIGNAL);
    if(sendReturn == -1) return false;
    return true;
}

int Socket::Receive(Socket& socket, std::string& message) const
{
    char buf[MAX_RECEIVE+1];
    message.clear();
    memset(buf, 0, MAX_RECEIVE+1);

    int numberRead = recv(socket.m_sockfd, buf, MAX_RECEIVE, 0);
    if(numberRead == -1)
    {
        std::cout<<"error in socket::Receive\n";
        return 0;
    }
    else if(numberRead == 0)
    {
        return 0;
    }
    else
    {
        message = buf;
        return numberRead;
    }
}

void Socket::SetNonBlocking(const bool flag)
{

}

bool Socket::IsValid() const
{
    return m_sockfd != -1;
}
