#ifndef _MEMBER_HPP_
#define _MEMBER_HPP_

#include <iostream>
#include <string>
#include <list>
#include "Book.hpp"

using namespace std;

// The Member class represents a library member with a name, ID, and contact information.
class Member {
    // Granting the Library class access to the private members of Member class.
    friend class Library;

    // Overloaded output stream operator to allow easy printing of Member details.
    friend ostream &operator<<(ostream &os, const Member &member);

    // Overloaded input stream operator to allow easy input of Member details.
    friend istream &operator>>(istream &is, Member &member) noexcept;

private:
    string name;     // Name of the library member.
    string id;       // Unique ID of the member.
    string contact;  // Contact information of the member.

    // Default values for member attributes when not explicitly provided.
    static constexpr const char *name_def = "Undefined Name";    // Default name value.
    static constexpr const char *id_def = "No ID";               // Default ID value.
    static constexpr const char *contact_def = "No Contact Info"; // Default contact information.

public:
    // Constructor that allows setting member details with default values if none are provided.
    // Uses default values for name, id, and contact if arguments are not passed.
    Member(string name = name_def, string id = id_def, string contact = contact_def);

    // Default destructor (using "=default" to indicate that the compiler-generated destructor is sufficient).
    ~Member() = default;
};

#endif /* _MEMBER_HPP_ */
``
