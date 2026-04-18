#ifndef ERRORMESSAGEBOX_H
#define ERRORMESSAGEBOX_H

#include "ierrormessage.h"

class ErrorMessageBox : public IErrorMessage
{
public:
    ~ErrorMessageBox() = default;

    void show(const QString& msg) override;
};

#endif // ERRORMESSAGEBOX_H
