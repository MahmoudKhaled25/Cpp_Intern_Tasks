#include "Book.hpp"
#include "UserExceptoin.hpp"
#include <sstream>
#include <ctime>

Book::Book(string title_val, string author_val, string isbn_val, string date_val, bool status_val)
: title{title_val}, author{author_val}, isbn{isbn_val}, publication_date{0,0}, status{status_val}
{
    if (date_val != date_def)
    {
        stringstream ss{date_val};
        char buff;
        int month, year;
        
        // Get the current time
        auto currentTime = time(nullptr);
        auto localTime = localtime(&currentTime);
        ss >> month >> buff >>year;

        try 
        {
            if ((month >= 1 && month <= 12) && (year < localTime->tm_year+1900))
            {
                publication_date.at(MONTH) = month;
                publication_date.at(YEAR) = year;
            }
            else if (year == localTime->tm_year+1900 && (month <= localTime->tm_mon+1))
            {
                publication_date.at(MONTH) = month;
                publication_date.at(YEAR) = year;
            }
            else
            {
                throw UserException("Invalid Date! Date assigned as undefined.");
            }
        }
        catch (const UserException &e)
        {
            cerr << "\nException: " <<  e.what() << '\n' << endl;
        }
    }
    
}


ostream &operator<<(ostream &os, const Book &book)
{
    stringstream ss{};
    const string RED = "\033[31m";
    const string RESET = "\033[0m";

    if (book.publication_date.at(MONTH) == 0 && book.publication_date.at(YEAR) == 0)
    {
        ss << "Not Provided";
    }
    else
    {
        ss << book.publication_date.at(MONTH) << '/' << book.publication_date.at(YEAR);
    }

    os << '['
        << RED << "Title: " << RESET << book.title+", " << RED << "Author: " << RESET << book.author+", " << RED << "ISNB: " << RESET << book.isbn+", "
        << RED << "Publication Date: " << RESET << ss.str()+", " << RED << "Status: " << RESET << (book.status ? "Borrowed" : "Available")
        << ']';
    
    return os;
}

istream &operator>>(istream &is, Book &book) noexcept
{
    string title_val, author_val, isnb_val, date_val;

    cout << "Enter Book's Title: ";
    getline(is, title_val);

    cout << "Enter Book's Author: ";
    getline(is, author_val);

    cout << "Enter Book's ISBN: ";
    getline(is, isnb_val);

    cout << "Enter Book's Publication Date (M/Y): ";
    getline(is, date_val);

    book = Book(title_val, author_val, isnb_val, date_val);

    return is;
}

bool Book::operator==(const Book &lhs_book)
{
    return lhs_book.isbn == isbn;
}

bool Book::operator<(const Book &lhs_book)
{
    return lhs_book.isbn < isbn;
}