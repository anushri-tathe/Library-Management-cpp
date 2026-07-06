#include "../include/FileManager.h"
#include "../include/Library.h"

#include <fstream>
#include <string>

using namespace std;

bool FileManager::saveData(const Library& library,
                           const string& booksFile,
                           const string& membersFile)
{
    ofstream bookOut(booksFile);

    if(!bookOut)
        return false;

    const vector<Book>& books = library.getBooks();

    for(const Book& book : books)
    {
        bookOut
            << book.getId()
<< '|'
<< book.getTitle()
<< '|'
<< book.getAuthor()
<< '|'
<< book.isIssued()
<< '|'
<< book.getIssuedToMemberId()
            << '\n';
    }

    bookOut.close();

    ofstream memberOut(membersFile);

    if(!memberOut)
        return false;

    const vector<Member>& members = library.getMembers();

    for(const Member& member : members)
    {
        memberOut
            << member.getId() << '|'
            << member.getName()
            << '\n';
    }

    memberOut.close();

    return true;
}

bool FileManager::loadData(Library& library,
                           const string& booksFile,
                           const string& membersFile)
{
    library.getBooks().clear();
    library.getMembers().clear();

    ifstream bookIn(booksFile);

    if(bookIn)
    {
        string line;

        while(getline(bookIn, line))
        {
           size_t p1 = line.find('|');
size_t p2 = line.find('|', p1 + 1);
size_t p3 = line.find('|', p2 + 1);
size_t p4 = line.find('|', p3 + 1);

if(p4 == string::npos)
    continue;

int id = stoi(line.substr(0,p1));

string title =
line.substr(
p1+1,
p2-p1-1);

string author =
line.substr(
p2+1,
p3-p2-1);

bool issued =
stoi(
line.substr(
p3+1,
p4-p3-1));

int memberId =
stoi(
line.substr(
p4+1));

library.addBook(

Book(
id,
title,
author,
issued,
memberId

));

        }

        bookIn.close();
    }

    ifstream memberIn(membersFile);

    if(memberIn)
    {
        string line;

        while(getline(memberIn, line))
        {
            size_t p = line.find('|');

            if(p == string::npos)
                continue;

            int id =
                stoi(line.substr(0, p));

            string name =
                line.substr(p + 1);

            library.addMember(
                Member(
                    id,
                    name
                )
            );
        }

        memberIn.close();
    }

    return true;
}