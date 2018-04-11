#ifndef CP5_EX16_04_FIND_H_
#define CP5_EX16_04_FIND_H_

template <typename InputIt, typename T>
InputIt Find(InputIt begin, InputIt end, const T& value)
{
    for (; begin != end; ++begin) {
        if (*begin == value) {
            return begin;
        }
    }
    return end;
}

#endif // CP5_EX16_04_FIND_H_
