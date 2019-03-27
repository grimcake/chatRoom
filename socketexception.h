#ifndef SOCKETEXCEPTION_H
#define SOCKETEXCEPTION_H

#include <string>


class SocketException
{
public:
    SocketException(std::string description)
    :m_description(description)
    {}
    //~SocktException(){};

    std::string Description() const
    {
        return m_description;
    }

private:
    std::string m_description;

};

#endif // SOCKETEXCEPTION_H
