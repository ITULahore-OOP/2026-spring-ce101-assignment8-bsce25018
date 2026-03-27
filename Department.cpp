#include "Department.h"
#include <iostream>
using namespace std;

Department::Department(string departmentName) : departmentName(departmentName), memberCount(0) {}

void Department::addMember(UniversityMember *member)
{
    if (memberCount < 50)
    {
        members[memberCount++] = member;
    }
    else
    {
        cout << "Department is full. Cannot add more members." << endl;
    }
}

void Department::displayAllRoles() const
{
    cout << "--- Department: " << departmentName << " ---" << endl;
    for (int i = 0; i < memberCount; i++)
    {
        members[i]->displayRole();
        cout << endl;
    }
}