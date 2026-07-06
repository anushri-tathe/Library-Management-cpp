#include "../include/Member.h"

#include <iostream>

using namespace std;

Member::Member()
{
    id = 0;
    name = "";
}

Member::Member(
    int id,
    const string& name)
{
    this->id = id;
    this->name = name;
}

int Member::getId() const
{
    return id;
}

string Member::getName() const
{
    return name;
}

void Member::setId(int id)
{
    this->id = id;
}

void Member::setName(const string& name)
{
    this->name = name;
}

void Member::display() const
{
    cout << "Member ID : " << id << endl;
    cout << "Name      : " << name << endl;
    cout << "----------------------" << endl;
}