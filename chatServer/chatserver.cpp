#include <iostream>
#include <string>
#include "serversocket.h"
#include "socketexception.h"

using namespace std;

int main()
{
    cout<<"running server..."<<endl;
    try
    {
        ServerSocket server(8080);
        while(true)
        {
            Socket newSocket;
            server.Accept(newSocket);

            string message;
            server.Receive(newSocket, message);
            cout<<"Receive message: "<<message<<endl;
            message = "here is server";
            server.Send(newSocket, message);
        }
    }
    catch(SocketException& ex)
    {
        cout << "Exception was caught:" << ex.Description() << "\nExiting.\n";
    }

    return 0;
}
