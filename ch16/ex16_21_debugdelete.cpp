#include "ex16_21_debugdelete.h"
#include <memory>
#include <string>

using std::string;

int main()
{
    double* p = new double(8.0);
    DebugDelete d;
    d(p);

    int* ip = new int;
    DebugDelete()(ip);

    std::unique_ptr<int, DebugDelete> up(new int, DebugDelete());
    std::unique_ptr<string, DebugDelete> usp(new string, DebugDelete());
}