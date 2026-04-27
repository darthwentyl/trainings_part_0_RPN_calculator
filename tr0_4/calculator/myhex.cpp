#include "myhex.h"

#include <stdexcept>

MyHex::MyHex(const unsigned num)
    : num{num}
{}

MyHex MyHex::operator + (const MyHex& other) const
{
    return MyHex{num + other.num};
}

MyHex MyHex::operator - (const MyHex& other) const
{
    return (num > other.num)
        ? MyHex{num - other.num}
        : MyHex{other.num - num};
}

MyHex MyHex::operator * (const MyHex& other) const
{
    return MyHex{num * other.num};
}

MyHex MyHex::operator / (const MyHex& other) const
{
    if (other.num == 0)
    {
        throw std::runtime_error{"div 0"};
    }
    return MyHex{num / other.num};
}

QString MyHex::get() const
{
    return QString::number(num, 16).toUpper();
}
