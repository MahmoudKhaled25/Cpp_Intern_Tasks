#ifndef _BOOK_HPP_
#define _BOOK_HPP_

#include <iostream>
#include <array>
using namespace std;

enum Date : char
{
        MONTH=0, YEAR
};

class Book 
{    
    friend class Library;
    friend ostream &operator<<(ostream &os, const Book &book);
    friend istream &operator>>(istream &is, Book &book) noexcept;
private:
    string title;
    string author;
    string isbn;
    array<int, 2> publication_date;
    bool status;

    static constexpr const char *title_def = "Undefined Title";
    static constexpr const char *author_def = "Unknown Author";
    static constexpr const char *isbn_def = "No ISBN provided";
    static constexpr const char *date_def = "No Publication date provided";
public:
    Book(string = title_def, string = author_def, string = isbn_def, string = date_def, bool = false);
    bool operator==(const Book &lhs_book);
    bool operator<(const Book &lhs_book);
    ~Book()=default; 
};

#endif /* _BOOK_HPP_ */