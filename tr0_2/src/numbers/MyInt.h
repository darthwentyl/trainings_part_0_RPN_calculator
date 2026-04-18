#pragma once

#include <iostream>

namespace mw {

class MyInt {
public:
    MyInt(const int num = 0);

    MyInt operator + (const MyInt& other) const;

    MyInt operator - (const MyInt& other) const;
    MyInt operator - () const;

    MyInt operator * (const MyInt& other) const;

    MyInt operator / (const MyInt& other) const;

    bool operator == (int compNum) const;
    bool operator == (const MyInt& other) const;

    friend std::ostream& operator << (std::ostream& os, const MyInt& myInt);

private:
    int num;
};

} // mw