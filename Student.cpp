#include "Student.h"
#include <iostream>
using namespace std;
Student::Student(string name, int memberID, double cgpa) : UniversityMember(name, memberID), cgpa(cgpa) {}

double Student::getCGPA() const
{
    return cgpa;
}

void Student::updateCGPA(double newCGPA)
{
    cgpa = newCGPA;
}

void Student::displayRole() const
{
    cout << "Role: Student" << endl;
    cout << "Name: " << getName() << endl;
    cout << "Member ID: " << getMemberID() << endl;
    cout << "CGPA: " << cgpa << endl;
}