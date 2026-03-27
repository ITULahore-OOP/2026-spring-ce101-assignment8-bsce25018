#ifndef TUTORINGSESSION_H
#define TUTORINGSESSION_H

#include "TeachingAssistant.h"

class TutoringSession
{
private:
    int sessionID;
    double durationMinutes;
    TeachingAssistant *ta;
    Student *student;

public:
    TutoringSession(int sessionID, double durationMinutes, TeachingAssistant *ta, Student *student);
    double getDuration() const;
    void displaySession() const;
    TutoringSession operator+(const TutoringSession &other) const;
};

bool operator>(TutoringSession s1, TutoringSession s2);

#endif