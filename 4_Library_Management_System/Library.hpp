#ifndef _LIBRARY_HPP_
#define _LIBRARY_HPP_

#include <iostream>
#include <map>
#include <queue>
#include "Book.hpp"
#include "Member.hpp"

// This struct holds information about a book, including the total and available copies.
struct BookInfo
{
    Book book{};                   // Book object storing details about the book.
    unsigned int total_copies{};    // Total number of copies available in the library.
    unsigned int available_copies{}; // Number of copies currently available for borrowing.
};

// This struct holds information about a member, including a list of borrowed books.
struct MemberInfo
{
    Member member{};               // Member object storing details about the member.
    list <Book *> borrowed_books{}; // List of pointers to books that the member has borrowed.
};

// The Library class manages books, members, and borrowing/returning of books.
class Library {
private:
    map<string, BookInfo> book_collection;  // Map to store books indexed by their ISBN.
    map<string, MemberInfo> members;        // Map to store members indexed by their member ID.
    queue<string> history;                  // Queue to store the transaction history (e.g., book additions, borrowings).

public:
    // Adds a new book to the library with the specified number of copies.
    // Returns true if the book is successfully added, otherwise false.
    bool add_book(const Book &book, unsigned int copies);

    // Updates the details of a book based on its ISBN.
    // Returns true if the book is successfully updated, otherwise false.
    bool update_book(const string &isbn);

    // Removes a book from the library based on its ISBN.
    // Returns true if the book is successfully removed, otherwise false.
    bool remove_book(const string &isbn);

    // Removes a specified number of copies of a book from the library.
    // Returns true if the specified copies are removed, otherwise false.
    bool remove_book(const string &isbn, unsigned int num_copies);

    // Registers a new member to the library.
    // Returns true if the member is successfully registered, otherwise false.
    bool register_member(const Member &member);

    // Updates the details of a member based on their member ID.
    // Returns true if the member is successfully updated, otherwise false.
    bool update_member(const string &member_id);

    // Allows a member to borrow a book from the library.
    // Returns true if the book is successfully borrowed, otherwise false.
    bool borrow_book(const string &member_id, const string &book_isbn);

    // Allows a member to return a borrowed book to the library.
    // Returns true if the book is successfully returned, otherwise false.
    bool return_book(const string &member_id, const string &book_isbn);

    // Displays the list of all books in the library.
    void display_books(void) const;

    // Displays the list of all registered members in the library.
    void display_members(void) const;

    // Displays the transaction history (e.g., book additions, updates, borrowings).
    void display_history(void) const;
};

#endif /* _LIBRARY_HPP_ */
