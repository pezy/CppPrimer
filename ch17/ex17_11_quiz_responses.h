#pragma once

#include <bitset>
#include <string>

namespace EX11 {
using size = std::size_t;
template <size N> class QuizResponses {
public:
    QuizResponses() = default;
    QuizResponses(const std::string& s) : answers(s) {}

    // added a function that takes a question number and a value to indicate
    // a true/false answer and updates the quiz results accordingly
    void answer(size n, bool v) { answers.set(n - 1, v); }

    // generate grades on the quiz
    size score(const QuizResponses& correct)
    {
        return (this->answers ^ correct.answers).flip().count() * 1.0 / N * 100;
    }

private:
    std::bitset<N> answers;
};
} // namespace EX11
