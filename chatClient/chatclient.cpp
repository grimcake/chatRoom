#include <iostream>
#include <string>
#include "clientsocket.h"
#include "../socketexception.h"

using namespace std;

int main()
{
    cout<<"running cient...."<<endl;
    try
    {
        ClientSocket clientSocket("127.0.0.1", 8080);
        clientSocket.Send("here is client");
        string message;
        clientSocket.Receive(message);
        cout<<"Responce from server:"<<message<<endl;
    }
    catch(SocketException& ex)
    {
        cout << "Exception was caught:" << ex.Description() << "\nExiting.\n";
    }

    return 0;
}
