#ifndef IERRORMESSAGE_H
#define IERRORMESSAGE_H

#include <QString>

class IErrorMessage
{
public:
    virtual ~IErrorMessage() = default;

    virtual void show(const QString& msg) = 0;
};

#endif // IERRORMESSAGE_H
