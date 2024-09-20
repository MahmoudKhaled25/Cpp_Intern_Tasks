#ifndef _LIBRARY_HPP_
#define _LIBRARY_HPP_

#include <iostream>
#include <map>
#include <queue>
#include "Book.hpp"
#include "Member.hpp"

struct BookInfo
{
    Book book{};
    unsigned int total_copies{};
    unsigned int available_copies{};
};

struct MemberInfo
{
    Member member{};
    list <Book *> borrowed_books{};
};

class Library {
private:
    map<string, BookInfo> book_collection;
    map<string, MemberInfo> members;
    queue<string> history;

public:
    bool add_book(const Book &book, unsigned int copies);
    bool remove_book(const string &isbn);
    bool remove_book(const string &isbn, unsigned int num_copies);
    bool register_member(const Member &member);
    bool borrow_book(const string &member_id, const string &book_isbn);
    bool return_book(const string &member_id, const string &book_isbn);
    void display_books(void) const;
    void display_members(void) const;
    void display_history(void) const;
};

#endif /* _LIBRARY_HPP_ */