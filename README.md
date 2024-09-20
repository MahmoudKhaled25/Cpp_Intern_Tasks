# Library Management System

This project implements a **Library Management System** in C++ to manage books, library members, and borrowing records. The system tracks books with details such as the title, author, ISBN, and publication date, as well as members who borrow books. The core structure includes three main classes: `Book`, `Member`, and `Library`.

## Features

- **Book Management**: Allows the tracking of a book's title, author, ISBN, publication date, and borrowing status.
- **Member Management**: Manages the details of library members, including their personal information and the books they have borrowed.
- **Library Management**: Keeps a record of the available books, the number of total copies, and the number of books currently borrowed.

### Classes Overview

- **Book**: Represents a book in the library with attributes such as title, author, ISBN, and publication date. It also tracks whether the book is currently available or borrowed.
  
- **Member**: Represents a library member with information like name, ID, and contact details. This class also keeps a record of books borrowed by the member.

- **Library**: Manages the collection of books in the library, maintaining a count of total and available copies of each book. It also handles borrowing and returning operations for members.

## UML Diagram

Below is a text-based UML diagram that shows the relationships between the `Book`, `Member`, and `Library` classes.

```plaintext
+--------------------+          +---------------------+
|       Member       |          |        Book          |
+--------------------+          +---------------------+
| - name             |          | - title             |
| - id               |          | - author            |
| - contact          |          | - isbn              |
| - books (list)     |<>------->| - publication_date  |
+--------------------+          | - status            |
                                +---------------------+
                                      ^
                                      |
                                      |
                              +---------------------+
                              |      Library        |
                              +---------------------+
                              | - map<Book, Copies> |
                              | - borrowBook()      |
                              | - returnBook()      |
                              +---------------------+
```

### Relationships

- A **Member** can borrow multiple **Books**, represented by the aggregation (`<>`) relationship between `Member` and `Book`. A member holds a list of books they have borrowed.
- The **Library** contains a collection (using a `map`) that manages the number of total and available copies of each **Book**. It has methods for borrowing and returning books.

## Usage

### 1. Book Class

The `Book` class stores the basic details about each book, including:
- Title
- Author
- ISBN
- Publication Date (Month/Year)
- Status (Borrowed or Available)

### 2. Member Class

The `Member` class holds information about library members:
- Name
- ID
- Contact Information
- A list of borrowed books (pointers to `Book` objects)

### 3. Library Class

The `Library` class manages the inventory of books. It maintains a `map` where:
- The key is a `Book` object.
- The value is a struct that contains the number of total copies and the number of available copies.

The `Library` class supports:
- Borrowing a book (`borrowBook()`): Decreases the number of available copies.
- Returning a book (`returnBook()`): Increases the number of available copies.

## Future Work

- Implement functionality for late fees, due dates, and notifications.
- Add a user interface for easier interaction with the system.
- Expand the library to include advanced search options by author or title.

---

### UML Diagram Explanation:
In this text-based UML diagram:
- The **Member** class has an aggregation (`<>`) with **Book**, indicating that members can borrow multiple books.
- The **Library** class manages both **Book** objects and their availability, but does not directly associate with members.
