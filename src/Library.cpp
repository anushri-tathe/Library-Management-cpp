#include "../include/Library.h"

#include <iostream>

using namespace std;

Library::Library()
{

}



// ----------------------
// BOOK FUNCTIONS
// ----------------------

void Library::addBook(const Book& book)
{
    for(const Book& b : books)
    {
        if(b.getId() == book.getId())
        {
            cout << "\nBook ID already exists.\n";
            return;
        }
    }

    books.push_back(book);
}

bool Library::deleteBook(int id)
{
    for(auto it = books.begin(); it != books.end(); ++it)
    {
        if(it->getId() == id)
        {
            if(it->isIssued())
            {
                cout << "\nCannot delete this book.\n";
                cout << "The book is currently issued.\n";
                return false;
            }

            books.erase(it);
            return true;
        }
    }

    return false;
}

Book* Library::searchBook(int id)
{
    for(auto& book : books)
    {
        if(book.getId() == id)
            return &book;
    }

    return nullptr;
}

void Library::displayBooks() const
{
    if(books.empty())
    {
        cout << "\nNo Books Available.\n";
        return;
    }

    cout << "\n========== BOOK LIST ==========\n\n";

    for(const Book& book : books)
    {
        cout << "Book ID : " << book.getId() << endl;
        cout << "Title   : " << book.getTitle() << endl;
        cout << "Author  : " << book.getAuthor() << endl;

        if(book.isIssued())
        {
            cout << "Status  : Issued" << endl;

            const Member* member = nullptr;

            for(const Member& m : members)
            {
                if(m.getId() == book.getIssuedToMemberId())
                {
                    member = &m;
                    break;
                }
            }

            if(member != nullptr)
            {
                cout << "Issued To : "
                     << member->getName()
                     << " (Member ID : "
                     << member->getId()
                     << ")" << endl;
            }
            else
            {
                cout << "Issued To : Unknown Member" << endl;
            }
        }
        else
        {
            cout << "Status  : Available" << endl;
        }

        cout << "------------------------------" << endl;
    }
}
void Library::displayIssuedBooks() const
{
    bool found = false;

    cout << "\n========== ISSUED BOOKS ==========\n\n";

    for(const Book& book : books)
    {
        if(book.isIssued())
        {
            found = true;

            cout << "Book ID : "
                 << book.getId() << endl;

            cout << "Title : "
                 << book.getTitle() << endl;

            cout << "Author : "
                 << book.getAuthor() << endl;

            for(const Member& member : members)
            {
                if(member.getId() ==
                   book.getIssuedToMemberId())
                {
                    cout << "Issued To : "
                         << member.getName()
                         << " (Member ID : "
                         << member.getId()
                         << ")" << endl;

                    break;
                }
            }

            cout << "-----------------------------" << endl;
        }
    }

    if(!found)
    {
        cout << "No books are currently issued.\n";
    }
}

const vector<Book>& Library::getBooks() const
{
    return books;
}

vector<Book>& Library::getBooks()
{
    return books;
}



// ----------------------
// MEMBER FUNCTIONS
// ----------------------

void Library::addMember(const Member& member)
{
    for(const Member& m : members)
    {
        if(m.getId() == member.getId())
        {
            cout << "\nMember ID already exists.\n";
            return;
        }
    }

    members.push_back(member);
}

bool Library::deleteMember(int id)
{
    for(const Book& book : books)
    {
        if(book.isIssued() &&
           book.getIssuedToMemberId() == id)
        {
            cout << "\nCannot delete member.\n";
            cout << "This member has issued book(s).\n";
            return false;
        }
    }

    for(auto it = members.begin(); it != members.end(); ++it)
    {
        if(it->getId() == id)
        {
            members.erase(it);
            return true;
        }
    }

    return false;
}

Member* Library::searchMember(int id)
{
    for(auto& member : members)
    {
        if(member.getId() == id)
            return &member;
    }

    return nullptr;
}

void Library::displayMembers() const
{
    if(members.empty())
    {
        cout << "\nNo Members Registered.\n";
        return;
    }

    cout << "\n========== MEMBERS ==========\n\n";

    for(const Member& member : members)
    {
        member.display();
    }
}

const vector<Member>& Library::getMembers() const
{
    return members;
}

vector<Member>& Library::getMembers()
{
    return members;
}



// ----------------------
// ISSUE / RETURN
// ----------------------

bool Library::issueBook(int bookId,
                        int memberId)
{
    Book* book = searchBook(bookId);

    if(book == nullptr)
        return false;

    if(book->isIssued())
        return false;

    Member* member = searchMember(memberId);

    if(member == nullptr)
        return false;

    book->setIssued(true);
    book->setIssuedToMemberId(memberId);

    return true;
}
bool Library::returnBook(int bookId)
{
    Book* book = searchBook(bookId);

    if(book == nullptr)
        return false;

    if(!book->isIssued())
        return false;

    book->setIssued(false);

    book->setIssuedToMemberId(-1);

    return true;
}
void Library::displayStatistics() const
{
    int totalBooks = books.size();
    int issuedBooks = 0;

    for(const Book& book : books)
    {
        if(book.isIssued())
            issuedBooks++;
    }

    int availableBooks = totalBooks - issuedBooks;

    cout << "\n========== LIBRARY STATISTICS ==========\n\n";

    cout << "Total Books      : "
         << totalBooks << endl;

    cout << "Available Books  : "
         << availableBooks << endl;

    cout << "Issued Books     : "
         << issuedBooks << endl;

    cout << endl;

    cout << "Total Members    : "
         << members.size() << endl;

    cout << "\n========================================\n";
}