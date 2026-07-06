#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include <string>

#include "Book.h"
#include "Member.h"

class Library
{
private:

    std::vector<Book> books;

    std::vector<Member> members;

public:

    Library();

    // Book Functions

    void addBook(const Book& book);

    bool deleteBook(int id);

    Book* searchBook(int id);

    void displayBooks() const;
    void displayIssuedBooks() const;
    void displayStatistics() const;

    const std::vector<Book>& getBooks() const;

    std::vector<Book>& getBooks();



    // Member Functions

    void addMember(const Member& member);

    bool deleteMember(int id);

    Member* searchMember(int id);

    void displayMembers() const;

    const std::vector<Member>& getMembers() const;

    std::vector<Member>& getMembers();



    // Issue / Return

    bool issueBook(int bookId,int memberId);

    bool returnBook(int bookId);

};

#endif