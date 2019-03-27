#include "epoll.h"
#include <stdlib.h>
#include <stdio.h>

Epoll::Epoll():fdNumber(0)
{
    rt.rlim_max = rt.rlim_cur = MAX_EPOLL_SIZE;
    //设置进程能打开的最大文件描述词大一的值
    if(setrlimit(RLIMIT_NOFILE, &rt) == -1)
    {
        perror("setrlimit");
        exit(1);
    }
    epollfd = epoll_create(MAX_EPOLL_SIZE);
}

bool Epoll::Add(int fd, int eventsOption)
{
    event.events = eventsOption;  //设置事件类型
    event.data.fd = fd;  //设置要处理事件的相关描述符

    //事件注册函数
    if(epoll_ctl(epollfd, EPOLL_CTL_ADD, fd, &event) < 0)
    {
        return false;
    }
    fdNumber++;
    return true;
}

bool Epoll::Delete(const int eventIndex)
{
    if(epoll_ctl(epollfd, EPOLL_CTL_DEL, events[eventIndex].data.fd, &event)<0)
    {
        return false;
    }
    fdNumber--;
    return true;
}

int Epoll::Wait()
{
    int eventNumber;
    eventNumber = epoll_wait(epollfd, events, fdNumber, -1);
    if(eventNumber < 0)
    {
        perror("epoll_wait");
        exit(1);
    }
    return eventNumber;
}

int Epoll::GetEventOccurfd(const int evenIndex) const
{
    return events[evenIndex].data.fd;
}

int Epoll::GetEvents(const int eventIndex) const
{
    return events[eventIndex].events;
}

