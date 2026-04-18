#ifndef MYHEX_H
#define MYHEX_H

#include <QString>

class MyHex
{
public:
    MyHex(const unsigned num);

    MyHex operator + (const MyHex& other) const;
    MyHex operator - (const MyHex& other) const;
    MyHex operator * (const MyHex& other) const;
    MyHex operator / (const MyHex& other) const;

    QString get() const;

private:
    unsigned num;
};

#endif // MYHEX_H
