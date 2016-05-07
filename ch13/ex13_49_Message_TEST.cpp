// Unit Test for exercise 13_49_Message.

#include "ex13_49_Message.h"

int main()
{
    Message firstMail("hello");
    Message signInMail("welcome to cppprimer");
    Folder mailBox;

    firstMail.save(mailBox);
    signInMail.save(mailBox);
    mailBox.print_debug();

    firstMail = std::move(signInMail);
    mailBox.print_debug();
}
