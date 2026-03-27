#include "UniversityMember.h"
#include <iostream>
using namespace std;
UniversityMember::UniversityMember(string name, int memberID) : name(name), memberID(memberID) {}

UniversityMember::~UniversityMember() {}

string UniversityMember::getName() const
{
    return name;
}

int UniversityMember::getMemberID() const
{
    return memberID;
}