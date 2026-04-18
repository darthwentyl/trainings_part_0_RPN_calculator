#pragma once

namespace mw {

template<class NUM_T, class SELF_T>
class NumberParser {
public:
    SELF_T& self() {
        return static_cast<SELF_T&>(*this);
    }

    NUM_T parse(const std::string& str, std::function<int(int)> isNumber) {
        return self().parse(str, isNumber);
    }
};

} // mw