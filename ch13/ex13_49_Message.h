//
//  ex13_49.h
//  Exercise 13.49
//
//  Created by pezy on 1/26/15.
//  Fixed   by pezy on 5/9/16.
//  Copyright (c) 2015 pezy. All rights reserved.
//
//  Added a move constructor and move-assignment operator to Ex13_34_36_37

#ifndef CP5_ex13_49_Message_h
#define CP5_ex13_49_Message_h

#include <set>
#include <string>

class Folder;

class Message {
    friend void swap(Message&, Message&);
    friend void swap(Folder&, Folder&);
    friend class Folder;

public:
    explicit Message(const std::string& str = "") : contents(str) {}
    Message(const Message&);
    Message& operator=(const Message&);
    Message(Message&&);
    Message& operator=(Message&&);
    ~Message();
    void save(Folder&);
    void remove(Folder&);

    void print_debug();

private:
    std::string contents;
    std::set<Folder*> folders;

    void add_to_Folders(const Message&);
    void remove_from_Folders();
    void move_Folders(Message*);

    void addFldr(Folder* f) { folders.insert(f); }
    void remFldr(Folder* f) { folders.erase(f); }
};

void swap(Message&, Message&);

class Folder {
    friend void swap(Message&, Message&);
    friend void swap(Folder&, Folder&);
    friend class Message;

public:
    Folder() = default;
    Folder(const Folder&);
    Folder& operator=(const Folder&);
    Folder(Folder&&);
    Folder& operator=(Folder&&);
    ~Folder();

    void print_debug();

private:
    std::set<Message*> msgs;

    void add_to_Messages(const Folder&);
    void remove_from_Messages();
    void move_Messages(Folder*);

    void addMsg(Message* m) { msgs.insert(m); }
    void remMsg(Message* m) { msgs.erase(m); }
};

void swap(Folder&, Folder&);

#endif // CP5_ex13_49_Message_h
