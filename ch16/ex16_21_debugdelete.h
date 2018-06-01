#ifndef CP5_EX16_21_DEBUGDELETE_H_
#define CP5_EX16_21_DEBUGDELETE_H_

#include <iostream>

class DebugDelete {
public:
    DebugDelete(std::ostream& os = std::cerr) : os_(os) {}

    template <typename T> void operator()(T* p) const
    {
        os_ << "deleting unique_ptr by '" << __PRETTY_FUNCTION__ << "'\n";
        delete p;
    }

private:
    std::ostream& os_;
};

#endif // CP5_EX16_21_DEBUGDELETE_H_