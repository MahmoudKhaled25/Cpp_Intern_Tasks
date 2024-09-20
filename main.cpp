#include <iostream>
#include <iomanip>
#include <limits>
#include "Library.hpp"

using namespace std;

Library myLib{};

void printList(void);
void addMem(void);
void addBook(void);
void delBook(void);
void Borrow(void);
void Return(void);
void showBooks(void);
void showMembers(void);
void showHistory(void);

int main(void)
{
    int choice{};

    while (choice < 9)
    {
        cout << setw(20) << setfill('-') << "";
        cout << setfill(' ') << endl;
        printList();
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << setw(20) << setfill('-') << "";
        cout << setfill(' ') << endl;

        switch (choice)
        {
            case 1:
                addMem();
                break;

            case 2:
                addBook();
                break;

            case 3:
                delBook();
                break;

            case 4:
                Borrow();
                break;

            case 5:
                Return();
                break;

            case 6:
                showBooks();
                break;

            case 7:
                showMembers();
                break;

            case 8:
                showHistory();
                break;

            default:
                break;
        }
    }


    return 0;
}

void printList(void)
{
    

    cout << "1- Add member\n"
        << "2- Add book\n"
        << "3- Remove book\n"
        << "4- Borrow book\n"
        << "5- Return book\n"
        << "6- Show book collection\n"
        << "7- Show members\n"
        << "8- Show history\n"
        << "9- Exit\n"
        << "Choice: ";
}

void addMem(void)
{
    Member member{};

    cin >> member;
    myLib.register_member(member);
}

void addBook(void)
{
    Book book{};
    unsigned int num;

    cin >> book;
    cout << "Enter the number of copies: ";
    cin >> num;
    myLib.add_book(book, num);
}

void delBook(void)
{
    Book book{};

    cin >> book;
    myLib.remove_book(book);
}

void Borrow(void)
{
    string id, isbn;

    cout << "Enter member ID: ";
    cin >> id;
    cout << "Enter book ISBN: ";
    cin >> isbn;
    myLib.borrow_book(id, isbn);
}

void Return(void)
{
    string id, isbn;

    cout << "Enter member ID: ";
    cin >> id;
    cout << "Enter book ISBN: ";
    cin >> isbn;
    myLib.return_book(id, isbn);
}

void showBooks(void)
{
    myLib.display_books();
}

void showMembers(void)
{
    myLib.display_members();
}

void showHistory(void)
{
    myLib.display_history();
}