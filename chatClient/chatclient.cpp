#include <iostream>
#include <string>
#include <pthread.h>
#include "clientsocket.h"
#include "../socketexception.h"

using namespace std;

void* showMessage(void *arg);

int main()
{
    cout<<"running cient...."<<endl;
    try
    {
        ClientSocket clientSocket("127.0.0.1", 8080);
        pthread_t *readThread;
        readThread = (pthread_t *)malloc(sizeof(pthread_t));
        pthread_create(readThread, NULL, showMessage, (void *)&clientSocket);
        string message;

        while(true)
        {
            cin>>message;
            clientSocket.Send(message);
        }

    }
    catch(SocketException& ex)
    {
        cout << "Exception was caught:" << ex.Description() << "\nExiting.\n";
    }

    return 0;
}

void* showMessage(void *arg)
{
    while(true)
    {
        string message;
        ClientSocket* newarg = (ClientSocket*)arg;
        newarg->Receive(message);
        cout<<"Responce from server:"<<message<<endl;
    }
}
