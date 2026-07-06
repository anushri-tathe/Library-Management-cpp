#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book
{
private:

    int id;
    std::string title;
    std::string author;

    bool issued;
    int issuedToMemberId;

public:

    Book();

    Book(
        int id,
        const std::string& title,
        const std::string& author,
        bool issued = false,
        int issuedToMemberId = -1
    );

    int getId() const;

    std::string getTitle() const;

    std::string getAuthor() const;

    bool isIssued() const;

    int getIssuedToMemberId() const;

    void setId(int id);

    void setTitle(const std::string& title);

    void setAuthor(const std::string& author);

    void setIssued(bool issued);

    void setIssuedToMemberId(int memberId);

    void display() const;
};

#endif