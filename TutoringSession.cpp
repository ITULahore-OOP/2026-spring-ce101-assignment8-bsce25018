#include "TutoringSession.h"
#include <iostream>
using namespace std;

TutoringSession::TutoringSession(int sessionID, double durationMinutes, TeachingAssistant *ta, Student *student) : sessionID(sessionID), durationMinutes(durationMinutes), ta(ta), student(student) {}

double TutoringSession::getDuration() const
{
    return durationMinutes;
}

void TutoringSession::displaySession() const
{
    cout << "[Tutoring Session]" << endl;
    cout << "Session ID: " << sessionID << endl;
    cout << "Duration (min): " << durationMinutes << endl;
    cout << "TA : " << (ta ? ta->getName() : "None") << endl;
    cout << "Student: " << (student ? student->getName() : "None") << endl;
}

TutoringSession TutoringSession::operator+(const TutoringSession &other) const
{
    return TutoringSession(0, durationMinutes + other.durationMinutes, ta, student);
}

bool operator>(TutoringSession s1, TutoringSession s2)
{
    return s1.getDuration() > s2.getDuration();
}