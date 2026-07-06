#include "../include/Book.h"

#include <iostream>

using namespace std;

Book::Book()
{
    id = 0;
    title = "";
    author = "";

    issued = false;
    issuedToMemberId = -1;
}

Book::Book(
    int id,
    const string& title,
    const string& author,
    bool issued,
    int issuedToMemberId)
{
    this->id = id;
    this->title = title;
    this->author = author;

    this->issued = issued;
    this->issuedToMemberId = issuedToMemberId;
}

int Book::getId() const
{
    return id;
}

string Book::getTitle() const
{
    return title;
}

string Book::getAuthor() const
{
    return author;
}

bool Book::isIssued() const
{
    return issued;
}

int Book::getIssuedToMemberId() const
{
    return issuedToMemberId;
}

void Book::setId(int id)
{
    this->id = id;
}

void Book::setTitle(const string& title)
{
    this->title = title;
}

void Book::setAuthor(const string& author)
{
    this->author = author;
}

void Book::setIssued(bool issued)
{
    this->issued = issued;
}

void Book::setIssuedToMemberId(int memberId)
{
    issuedToMemberId = memberId;
}

void Book::display() const
{
    cout << "Book ID : " << id << endl;
    cout << "Title : " << title << endl;
    cout << "Author : " << author << endl;

    if(issued)
    {
        cout << "Status : Issued" << endl;
        cout << "Issued To Member ID : "
             << issuedToMemberId << endl;
    }
    else
    {
        cout << "Status : Available" << endl;
    }

    cout << "---------------------------" << endl;
}