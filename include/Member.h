#ifndef MEMBER_H
#define MEMBER_H

#include <string>

class Member
{
private:
    int id;
    std::string name;

public:

    Member();

    Member(
        int id,
        const std::string& name
    );

    int getId() const;

    std::string getName() const;

    void setId(int id);

    void setName(const std::string& name);

    void display() const;
};

#endif