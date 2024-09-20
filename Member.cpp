#include <iomanip>
#include <limits>
#include "Member.hpp"
#include "UserExceptoin.hpp"


Member::Member(string name_val, string id_val, string contact_val)
: name{name_val}, id{id_val}, contact{contact_val}
{

}

ostream &operator<<(ostream &os, const Member &member)
{
    const string GREEN = "\033[32m";
    const string RESET = "\033[0m";

    os  << GREEN << setw(10) << left << "Name: " << RESET << member.name << '\n'
        << GREEN << setw(10) << left << "ID: " << RESET << member.id << '\n' 
        << GREEN << setw(10) << left << "Contact: " << RESET << member.contact << endl; 

    return os;
}

istream &operator>>(istream &is, Member &member) noexcept
{
    string name_val, id_val, contact_val;

    cout << "Enter Member's Name: ";
    getline(is, name_val);

    cout << "Enter Member's ID: ";
    getline(is, id_val);

    cout << "Enter Member's Email: ";
    getline(is, contact_val);
    
    member = Member(name_val, id_val, contact_val);

    return is;
}