#ifndef STAFF_H
#define STAFF_H

#include "UniversityMember.h"
#include "AccessCard.h"

class Staff : virtual public UniversityMember
{
private:
    double salary;
    AccessCard card;

public:
    Staff(string name, int memberID, double salary, AccessCard card);
    double getSalary() const;
    void displayRole() const override;
    void displayCard() const;
};

#endif