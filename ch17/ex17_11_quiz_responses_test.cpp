#include "ex17_11_quiz_responses.h"
#include <iostream>

int main()
{
    EX11::QuizResponses<10> simple_quiz_answers("1100110101");

    EX11::QuizResponses<100> complicated_quiz_answers;
    complicated_quiz_answers.answer(1, true);
    complicated_quiz_answers.answer(2, false);
    complicated_quiz_answers.answer(3, true);

    EX11::QuizResponses<10> simple_quiz_correct("1010101010");
    std::cout << simple_quiz_answers.score(simple_quiz_correct) << std::endl;
}