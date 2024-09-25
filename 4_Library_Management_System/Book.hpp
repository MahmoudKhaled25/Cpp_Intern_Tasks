#ifndef _BOOK_HPP_
#define _BOOK_HPP_

#include <iostream>
#include <array>
using namespace std;

// Enum to represent the parts of the publication date (month and year).
enum Date : char
{
    MONTH = 0,  // Index for the month.
    YEAR        // Index for the year.
};

// The Book class represents a library book with details such as title, author, ISBN, publication date, and availability status.
class Book 
{    
    // Granting the Library class access to the private members of the Book class.
    friend class Library;

    // Overloaded output stream operator to allow easy printing of Book details.
    friend ostream &operator<<(ostream &os, const Book &book);

    // Overloaded input stream operator to allow easy input of Book details.
    friend istream &operator>>(istream &is, Book &book) noexcept;

private:
    string title;    // Title of the book.
    string author;   // Author of the book.
    string isbn;     // Unique ISBN identifier for the book.
    array<int, 2> publication_date;  // Array to store the publication date as [month, year].
    bool status;     // Availability status of the book (e.g., borrowed or available).

    // Default values for book attributes if no values are provided during object construction.
    static constexpr const char *title_def = "Undefined Title";        // Default title.
    static constexpr const char *author_def = "Unknown Author";        // Default author.
    static constexpr const char *isbn_def = "No ISBN provided";        // Default ISBN.
    static constexpr const char *date_def = "No Publication date provided"; // Default publication date.

public:
    // Constructor that allows setting book details with default values if none are provided.
    Book(string title = title_def, string author = author_def, string isbn = isbn_def, string date = date_def, bool status = false);

    // Overloaded equality operator to compare two Book objects based on their ISBNs.
    bool operator==(const Book &lhs_book);

    // Overloaded less-than operator to allow sorting books based on their ISBNs.
    bool operator<(const Book &lhs_book);

    // Default destructor (using "=default" to indicate that the compiler-generated destructor is sufficient).
    ~Book() = default;
};

#endif /* _BOOK_HPP_ */
