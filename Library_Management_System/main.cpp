#include <iostream>
#include <iomanip>
#include <limits>
#include "Library.hpp"

using namespace std;

Library myLib{};

void printList(void);
void addMem(void);
void upMem(void);
void addBook(void);
void upBook(void);
void delBook(void);
void Borrow(void);
void Return(void);
void showBooks(void);
void showMembers(void);
void showHistory(void);

int main(void)
{
    int choice{};

    while (choice < 11)
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
                upMem();
                break;

            case 3:
                addBook();
                break;

            case 4:
                upBook();
                break;

            case 5:
                delBook();
                break;

            case 6:
                Borrow();
                break;

            case 7:
                Return();
                break;

            case 8:
                showBooks();
                break;

            case 9:
                showMembers();
                break;

            case 10:
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
        << "2- Update Member\n"
        << "3- Add book\n"
        << "4- Update book\n"
        << "5- Remove book\n"
        << "6- Borrow book\n"
        << "7- Return book\n"
        << "8- Show book collection\n"
        << "9- Show members\n"
        << "10- Show history\n"
        << "11- Exit\n"
        << "Choice: ";
}

void addMem(void)
{
    Member member{};

    cin >> member;
    myLib.register_member(member);
}

void upMem(void)
{
    string id;

    cout << "Enter member ID: ";
    cin >> id;
    myLib.update_member(id);
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

void upBook(void)
{
    string isbn;

    cout << "Enter book ISBN: ";
    cin >> isbn;
    myLib.update_book(isbn);
}

void delBook(void)
{
    string isbn;

    cout << "Enter book ISBN: ";
    cin >> isbn;
    myLib.remove_book(isbn);
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