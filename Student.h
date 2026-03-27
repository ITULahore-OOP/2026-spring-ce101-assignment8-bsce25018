#ifndef STUDENT_H
#define STUDENT_H

#include "UniversityMember.h"

class Student : virtual public UniversityMember
{
private:
    double cgpa;

public:
    Student(string name, int memberID, double cgpa);
    double getCGPA() const;
    void updateCGPA(double newCGPA);
    void displayRole() const override;
};

#endif