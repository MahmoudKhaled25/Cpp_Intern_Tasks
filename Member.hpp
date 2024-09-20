#ifndef _MEMBER_HPP_
#define _MEMBER_HPP_

#include <iostream>
#include <string>
#include <list>
#include "Book.hpp"


class Member {
    friend class Library;
    friend ostream &operator<<(ostream &os, const Member &member);
    friend istream &operator>>(istream &is, Member &member) noexcept;
private:
    string name;
    string id;
    string contact;

    static constexpr const char *name_def = "Undefined Name";
    static constexpr const char *id_def = "No ID";
    static constexpr const char *contact_def = "No Contact Info";
    
public:
    Member(string = name_def, string = id_def, string = contact_def);
    ~Member()=default; 
};

#endif /* _MEMBER_HPP_ */