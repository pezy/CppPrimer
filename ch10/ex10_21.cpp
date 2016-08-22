/*!
 *  @question:
 *    Write a lambda that captures a local `int` variable and
 *    decrements that variable until it reaches 0.
 *    Once the variable is 0 additional calls should
 *    no longer decrement the variable.
 *    The lambda should return a `bool` that indicates
 *    whether the captured variable is 0.
 *  @author: pezy
 *  @date:  2016-07-01
 *  @see:
 */

#include <iostream>

using std::cout;
using std::endl;

int main()
{
    // local int variable
    int local_val = 7;
    auto decrement_to_zero = [&local_val]() {
        if (local_val == 0)
            return true;
        else {
            --local_val;
            return false;
        }
    };

    while (!decrement_to_zero()) cout << local_val << endl;
}
