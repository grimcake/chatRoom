#ifndef EPOLL_H
#define EPOLL_H

#include "../socket.h"
#include <sys/epoll.h>
#include <sys/resource.h>

const int MAX_EPOLL_SIZE = MAX_CONNECTION+5;

class Epoll
{
public:
    Epoll();
    bool Add(int fd, int eventsOption);
    int Wait();
    bool Delete(const int eventIndex);
    int GetEventOccurfd(const int eventIndex) const;
    int GetEvents(const int eventIndex) const;

private:
    int epollfd;
    int fdNumber;
    struct epoll_event event;
    struct epoll_event events[MAX_EPOLL_SIZE];
    struct rlimit rt;

};

#endif // EPOLL_H
