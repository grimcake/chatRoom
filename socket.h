#ifndef SOCKET_H
#define SOCKET_H

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string>

const int MAX_CONNECTION = 5;
const int MAX_RECEIVE = 500;


class Socket
{
public:
    Socket();
    virtual ~Socket();

    //Server initialization
    bool Create();
    bool Bind(const int port);
    bool Listen() const;
    bool Accept(Socket& clientSocket) const;

    //Client initialization
    bool Connect(const std::string& host, const int port);

    //Data Transmission
    bool Send(Socket& socket, const std::string& message) const;
    int Receive(Socket& socket, std::string& message) const;

    void SetNonBlocking(const bool flag);
    bool IsValid() const;

private:
    int m_sockfd;
    struct sockaddr_in m_address;

};

#endif // SOCKET_H
