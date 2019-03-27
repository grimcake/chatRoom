#ifndef EPOLLSERVERSOCKET_H
#define EPOLLSERVERSOCKET_H

#include "../socket.h"
#include "epoll.h"
#include <map>


class EpollServerSocket:public Socket
{
public:
    EpollServerSocket(const int port);
    virtual ~EpollServerSocket();
    void Run();

private:
    void SendMessage(Socket& clientSocket, const std::string& message) const;
    void ReceiveMessage(Socket& clientSocket,std::string& message);
    void ProcessMessage(Socket& clientSocket);
    void SendToAllUsers(const std::string& message) const;
    bool AddNewClient(Socket& clientSocket);
    void DeleteClient(int sockfd);
    std::map<int,Socket*> clientSockets;
    Epoll epoll;
};

#endif // EPOLLSERVERSOCKET_H
