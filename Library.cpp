#include <algorithm>
#include <iomanip>
#include <sstream>
#include <ctime>
#include "Library.hpp"
 
bool Library::add_book(const Book &book, unsigned int copies)
{
    bool res = false;

    if (book_collection.find(book.isbn) == book_collection.end())
    {
        stringstream ss{};
        auto currentTime = time(nullptr);
        auto localTime = localtime(&currentTime);

        book_collection[book.isbn].book = book;
        book_collection[book.isbn].total_copies = copies;
        book_collection[book.isbn].available_copies = copies;
        res = true;
        cout << "Book added successfully" << endl;

        ss << "Book: " << book.title << " [" << book.isbn << "] added successfully at " 
            << localTime->tm_mon+1 << '/' << localTime->tm_mday << '/' << localTime->tm_year+1900
            << " - " << localTime->tm_hour << ':' << localTime->tm_min << ':' << localTime->tm_sec;
        history.push(ss.str());
    }
    else
    {
        cout << "Book already exists!" << endl;
    }

    return res;
}

bool Library::remove_book(const Book &book)
{
    bool res {false};
    auto it {book_collection.find(book.isbn)};

    if (it != book_collection.end())
    {
        stringstream ss{};
        auto currentTime = time(nullptr);
        auto localTime = localtime(&currentTime);

        book_collection.erase(it);
        res = true;
        cout << "Book removed successfully" << endl;
        
        ss << "Book: " << book.title << " [" << book.isbn << "] removed successfully at " 
            << localTime->tm_mon+1 << '/' << localTime->tm_mday << '/' << localTime->tm_year+1900
            << " - " << localTime->tm_hour << ':' << localTime->tm_min << ':' << localTime->tm_sec;
        history.push(ss.str());
    }
    else
    {
        cout << "Book doesn't exists!" << endl;
    }

    return res;
}

bool Library::remove_book(const Book &book, unsigned int num_copies)
{
    bool res = false;

    if (book_collection.find(book.isbn) != book_collection.end())
    {
        stringstream ss{};
        auto currentTime = time(nullptr);
        auto localTime = localtime(&currentTime);

        book_collection[book.isbn].available_copies -= num_copies;
        res = true;
        cout << "Books removed successfully" << endl;

        ss << "Book: " << book.title << " [" << book.isbn << "] removed successfully at " 
            << localTime->tm_mon+1 << '/' << localTime->tm_mday << '/' << localTime->tm_year+1900
            << " - " << localTime->tm_hour << ':' << localTime->tm_min << ':' << localTime->tm_sec;
        history.push(ss.str());
    }
    else
    {
        cout << "Book doesn't exists!" << endl;
    }

    return res;
}

bool Library::register_member(const Member &member)
{
    bool res = false;

    if (members.find(member.id) == members.end())
    {
        stringstream ss{};
        auto currentTime = time(nullptr);
        auto localTime = localtime(&currentTime);

        members[member.id].member = member;
        res = true;
        cout << "Member added successfully" << endl;

        ss << "Member: "<< member.name << " [" << member.id << "] added successfully at " 
            << localTime->tm_mon+1 << '/' << localTime->tm_mday << '/' << localTime->tm_year+1900
            << " - " << localTime->tm_hour << ':' << localTime->tm_min << ':' << localTime->tm_sec;
        history.push(ss.str());
    }
    else
    {
        cout << "Member already exists!" << endl;
    }

    return res;
}

bool Library::borrow_book(const string &member_id, const string &book_isbn)
{
    bool res = false;
    auto mem_it = members.find(member_id);

    if (mem_it != members.end())
    {
        auto it {book_collection.find(book_isbn)};

        if (it != book_collection.end())
        {
            auto book_it = find(mem_it->second.borrowed_books.begin(), mem_it->second.borrowed_books.end(), &(it->second.book));

            if (book_it != mem_it->second.borrowed_books.end())
            {
                cout << "User borrowed a copy for this book already!" << endl;
            }
            else if (it->second.available_copies)
            {
                stringstream ss{};
                auto currentTime = time(nullptr);
                auto localTime = localtime(&currentTime);

                members[member_id].borrowed_books.push_back(&(it->second.book));
                it->second.available_copies--;
                if (!it->second.available_copies)
                {
                    it->second.book.status = true;
                }
                
                res=true;
                cout << "Book borrowed successfully" << endl;

                ss << members[member_id].member.name << " [" << members[member_id].member.id << "] borrowed \"" << book_collection[book_isbn].book.title 
                    << "\" book at " << localTime->tm_mon+1 << '/' << localTime->tm_mday << '/' << localTime->tm_year+1900
                    << " - " << localTime->tm_hour << ':' << localTime->tm_min << ':' << localTime->tm_sec;
                history.push(ss.str());
            }
            else
            {
                cout << "No available copies for this book!" << endl;
            }
        }
        else
        {
            cout << "Book doesn't exists!" << endl;
        }
        
    }
    else
    {
        cout << "Member isn't registered!" << endl;
    }
    
    return res;
}

bool Library::return_book(const string &member_id, const string &book_isbn)
{
    bool res = false;

    if (members.find(member_id) != members.end())
    {
        auto book_it {book_collection.find(book_isbn)};

        if (book_it != book_collection.end())
        {
            auto bbook_it { 
                find(members[member_id].borrowed_books.begin(), members[member_id].borrowed_books.end(), &(book_it->second.book)) 
                };

            if (bbook_it != members[member_id].borrowed_books.end())
            {
                stringstream ss{};
                auto currentTime = time(nullptr);
                auto localTime = localtime(&currentTime);

                members[member_id].borrowed_books.erase(bbook_it);
                book_it->second.available_copies++;
                book_it->second.book.status = false;
                res = true;
                cout << "Book returned successfully" << endl;

                ss << members[member_id].member.name << " [" << members[member_id].member.id << "] returned \"" << book_collection[book_isbn].book.title 
                    << "\" book at " << localTime->tm_mon+1 << '/' << localTime->tm_mday << '/' << localTime->tm_year+1900 
                    << " - " << localTime->tm_hour << ':' << localTime->tm_min << ':' << localTime->tm_sec;
                history.push(ss.str());
            }
            else
            {
                cout << "Meber doesn't borrowed this book to return!" << endl;
            }
            
        }
        else
        {
            cout << "Book doesn't exists!" << endl;
        }
        
    }
    else
    {
        cout << "Member isn't registered!" << endl;
    }
    
    return res;
}

void Library::display_books(void) const
{
    if (book_collection.empty())
    {
        cout << "\nBook collection is empty!\n" << endl;
    }
    else
    {
        cout << setw(20) << setfill('*') << "";
        cout << setfill(' ') << endl;

        for (auto const &book_info : book_collection)
        {
            cout << book_info.second.book << '\n'
                << "Total Copies: " << book_info.second.total_copies << '\n'
                << "Available Copies: " << book_info.second.available_copies << "\n\n";
        }
        
        cout << setw(20) << setfill('*') << "";
        cout << setfill(' ') << endl;
    }
    
    
}

void Library::display_members(void) const
{
    if (book_collection.empty())
    {
        cout << "\nNo members in the system!\n" << endl;
    }
    else
    {
        const string GREEN = "\033[32m";
        const string RESET = "\033[0m";

        cout << setw(20) << setfill('*') << "";
        cout << setfill(' ') << endl;

        for (auto const &member_info : members)
        {
            cout << member_info.second.member << '\n'
                << GREEN << "Borrowed Books: " << RESET;

            if (member_info.second.borrowed_books.empty())
            {
                cout << "None\n";
            }
            else
            {
                cout << '\n';
                for (const auto &book : member_info.second.borrowed_books)
                    cout << "\t- " << *book << '\n';
            }
            
            cout << setfill('*') << setw(20) << "";
            cout << setfill(' ') << endl;
        }
    }
}

void Library::display_history(void) const
{
    auto temp {history};

    cout << setw(20) << setfill('-') << "";
    cout << setfill(' ') << endl;

    while (!temp.empty())
    {
        cout << temp.front() << '\n';
        temp.pop();
    }

    cout << setw(20) << setfill('-') << "";
    cout << setfill(' ') << endl;
}