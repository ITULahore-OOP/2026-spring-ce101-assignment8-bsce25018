#include "TeachingAssistant.h"
#include <iostream>
using namespace std;

TeachingAssistant::TeachingAssistant(string name, int memberID, double cgpa, double salary, AccessCard card, int workingHours)
    : UniversityMember(name, memberID), Student(name, memberID, cgpa), Staff(name, memberID, salary, card), workingHours(workingHours) {}

void TeachingAssistant::displayRole() const
{
    cout << "Role: Teaching Assistant" << endl;
    cout << "Name " << getName() << endl;
    cout << "Member ID: " << getMemberID() << endl;
    cout << "CGPA : " << getCGPA() << endl;
    cout << "Salary: " << getSalary() << endl;
    cout << "Working Hours: " << workingHours << endl;
}

void TeachingAssistant::gradeAssignment(int score)
{
    cout << getName() << "graded assignment with numeric score: " << score << "/100" << endl;
}

void TeachingAssistant::gradeAssignment(string letterGrade)
{
    cout << getName() << "graded assignment with letter grade: " << letterGrade << endl;
}