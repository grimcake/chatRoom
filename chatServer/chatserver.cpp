#include <iostream>
#include <string>
#include "serversocket.h"
#include "../socketexception.h"
#include "epollserversocket.h"

using namespace std;

int main()
{
    cout<<"running server..."<<endl;
    try
    {
        EpollServerSocket server(8080);
        server.Run();
        /*while(true)
        {
            Socket newSocket;
            server.Accept(newSocket);

            string message;
            server.Receive(newSocket, message);
            cout<<"Receive message: "<<message<<endl;
            message = "here is server";
            server.Send(newSocket, message);
        }*/
    }
    catch(SocketException& ex)
    {
        cout << "Exception was caught:" << ex.Description() << "\nExiting.\n";
    }

    return 0;
}
