#include "Staff.h"
#include <iostream>
using namespace std;

Staff::Staff(string name, int memberID, double salary, AccessCard card) : UniversityMember(name, memberID), salary(salary), card(card) {}

double Staff::getSalary() const
{
    return salary;
}

void Staff::displayRole() const
{
    cout << "Role: Staff" << endl;
    cout << "Name: " << getName() << endl;
    cout << "Member ID: " << getMemberID() << endl;
    cout << "Salary: " << salary << endl;
}

void Staff::displayCard() const
{
    cout << " Access Card Info:" << endl;
    card.displayCardInfo();
}