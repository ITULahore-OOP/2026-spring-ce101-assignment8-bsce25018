#include <iostream>
#include <string>
#include "AccessCard.h"
#include "Student.h"
#include "Staff.h"
#include "TeachingAssistant.h"
#include "TutoringSession.h"
#include "Department.h"

using namespace std;
const int MAX = 50;

Student *students[MAX];
Staff *staffArr[MAX];
TeachingAssistant *taArr[MAX];
TutoringSession *sessions[MAX];
AccessCard *cards[MAX];
int studentCount = 0;
int staffCount = 0;
int taCount = 0;
int sessionCount = 0;
int cardCount = 0;
Department *dept = nullptr;

void manageAccessCards()
{
    int choice;
    cout << "\n=== Access Card Menu ===" << endl;
    cout << "1. Create Access Card" << endl;
    cout << "2. Display All Access Cards" << endl;
    cout << "0. Back" << endl;
    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 1)
    {
        if (cardCount >= MAX)
        {
            cout << "Maximum cards reached." << endl;
        }
        else
        {
            string cardID;
            int level;
            cout << "Enter Card ID: ";
            cin >> cardID;
            cout << "Enter Access Level (1=Basic, 2=Labs): ";
            cin >> level;

            cards[cardCount++] = new AccessCard(cardID, level);
            cout << "Access Card created successfully." << endl;
        }
    }
    else if (choice == 2)
    {
        if (cardCount == 0)
        {
            cout << "No access cards created yet." << endl;
        }
        else
        {
            for (int i = 0; i < cardCount; i++)
            {
                cout << "\nCard " << (i + 1) << ":" << endl;
                cards[i]->displayCardInfo();
            }
        }
    }
    else if (choice == 0)
    {
        return;
    }
    else
    {
        cout << "Invalid choice." << endl;
    }
}
void manageStudents()
{
    int choice;
    cout << "\n=== Student Menu ===" << endl;
    cout << "1. Add Student" << endl;
    cout << "2. Display All Students" << endl;
    cout << "3. Update Student CGPA" << endl;
    cout << "0. Back" << endl;
    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 1)
    {
        if (studentCount >= MAX)
        {
            cout << "Maximum students reached." << endl;
        }
        else
        {
            string name;
            int id;
            double cgpa;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Member ID: ";
            cin >> id;
            cout << "Enter CGPA: ";
            cin >> cgpa;

            students[studentCount++] = new Student(name, id, cgpa);
            cout << "Student added successfully." << endl;
        }
    }
    else if (choice == 2)
    {
        if (studentCount == 0)
        {
            cout << "No students added yet." << endl;
        }
        else
        {
            for (int i = 0; i < studentCount; i++)
            {
                cout << "\nStudent #" << (i + 1) << ":" << endl;
                students[i]->displayRole();
            }
        }
    }
    else if (choice == 3)
    {
        if (studentCount == 0)
        {
            cout << "No students to update." << endl;
        }
        else
        {
            cout << "Select student (1-" << studentCount << "): ";
            int idx;
            cin >> idx;
            if (idx < 1 || idx > studentCount)
            {
                cout << "Invalid selection." << endl;
            }
            else
            {
                double newCGPA;
                cout << "Enter new CGPA: ";
                cin >> newCGPA;
                students[idx - 1]->updateCGPA(newCGPA);
                cout << "CGPA updated successfully." << endl;
            }
        }
    }
    else if (choice == 0)
    {
        return;
    }
    else
    {
        cout << "Invalid choice." << endl;
    }
}

void manageStaff()
{
    int choice;
    cout << "\n=== Staff Menu ===" << endl;
    cout << "1. Add Staff Member" << endl;
    cout << "2. Display All Staff" << endl;
    cout << "0. Back" << endl;
    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 1)
    {
        if (staffCount >= MAX)
        {
            cout << "Maximum staff reached." << endl;
        }
        else if (cardCount == 0)
        {
            cout << "No access cards available. Please create one first." << endl;
        }
        else
        {
            string name;
            int id;
            double salary;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Member ID: ";
            cin >> id;
            cout << "Enter Salary: ";
            cin >> salary;

            cout << "Select an Access Card (1-" << cardCount << "): ";
            int cardIdx;
            cin >> cardIdx;

            if (cardIdx < 1 || cardIdx > cardCount)
            {
                cout << "Invalid card selection." << endl;
            }
            else
            {
                staffArr[staffCount++] = new Staff(name, id, salary, *cards[cardIdx - 1]);
                cout << "Staff member added successfully." << endl;
            }
        }
    }
    else if (choice == 2)
    {
        if (staffCount == 0)
        {
            cout << "No staff members added yet." << endl;
        }
        else
        {
            for (int i = 0; i < staffCount; i++)
            {
                cout << "\nStaff #" << (i + 1) << ":" << endl;
                staffArr[i]->displayRole();
                staffArr[i]->displayCard();
            }
        }
    }
    else if (choice == 0)
    {
        return;
    }
    else
    {
        cout << "Invalid choice." << endl;
    }
}

void manageTeachingAssistants()
{
    int choice;
    cout << "\n=== Teaching Assistant Menu ===" << endl;
    cout << "1. Add Teaching Assistant" << endl;
    cout << "2. Display All TAs" << endl;
    cout << "3. Grade Assignment (Compile-Time Polymorphism Demo)" << endl;
    cout << "0. Back" << endl;
    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 1)
    {
        if (taCount >= MAX)
        {
            cout << "Maximum TAs reached." << endl;
        }
        else if (cardCount == 0)
        {
            cout << "No access cards available. Please create one first." << endl;
        }
        else
        {
            string name;
            int id, hours;
            double cgpa, salary;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Member ID: ";
            cin >> id;
            cout << "Enter CGPA: ";
            cin >> cgpa;
            cout << "Enter Salary: ";
            cin >> salary;
            cout << "Enter Working Hours: ";
            cin >> hours;

            cout << "Select an Access Card (1-" << cardCount << "): ";
            int cardIdx;
            cin >> cardIdx;

            if (cardIdx < 1 || cardIdx > cardCount)
            {
                cout << "Invalid card selection." << endl;
            }
            else
            {
                taArr[taCount++] = new TeachingAssistant(name, id, cgpa, salary, *cards[cardIdx - 1], hours);
                cout << "Teaching Assistant added successfully." << endl;
            }
        }
    }
    else if (choice == 2)
    {
        if (taCount == 0)
        {
            cout << "No TAs added yet." << endl;
        }
        else
        {
            for (int i = 0; i < taCount; i++)
            {
                cout << "\nTA #" << (i + 1) << ":" << endl;
                taArr[i]->displayRole();
            }
        }
    }
    else if (choice == 3)
    {
        if (taCount == 0)
        {
            cout << "No TAs available." << endl;
        }
        else
        {
            cout << "Select TA (1-" << taCount << "): ";
            int idx;
            cin >> idx;

            if (idx < 1 || idx > taCount)
            {
                cout << "Invalid selection." << endl;
            }
            else
            {
                int gradeChoice;
                cout << "Grade with: 1. Numeric Score  2. Letter Grade" << endl;
                cout << "Enter choice: ";
                cin >> gradeChoice;

                if (gradeChoice == 1)
                {
                    int score;
                    cout << "Enter numeric score (0-100): ";
                    cin >> score;
                    taArr[idx - 1]->gradeAssignment(score);
                }
                else if (gradeChoice == 2)
                {
                    string grade;
                    cout << "Enter letter grade (e.g. A+): ";
                    cin >> grade;
                    taArr[idx - 1]->gradeAssignment(grade);
                }
                else
                {
                    cout << "Invalid choice." << endl;
                }
            }
        }
    }
    else if (choice == 0)
    {
        return;
    }
    else
    {
        cout << "Invalid choice." << endl;
    }
}

void manageDepartment()
{
    int choice;
    cout << "\n=== Department Menu ===" << endl;
    cout << "1. Create Department" << endl;
    cout << "2. Add Member to Department" << endl;
    cout << "3. Display All Roles (Run-Time Polymorphism Demo)" << endl;
    cout << "0. Back" << endl;
    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 1)
    {
        if (dept != nullptr)
        {
            delete dept;
        }
        string deptName;
        cout << "Enter Department Name: ";
        cin >> deptName;
        dept = new Department(deptName);
        cout << "Department created successfully." << endl;
    }
    else if (choice == 2)
    {
        if (dept == nullptr)
        {
            cout << "No department created yet." << endl;
        }
        else
        {
            int type;
            cout << "Add: 1. Student  2. Staff  3. Teaching Assistant" << endl;
            cout << "Enter choice: ";
            cin >> type;

            if (type == 1)
            {
                if (studentCount == 0)
                {
                    cout << "No students available." << endl;
                }
                else
                {
                    cout << "Select Student (1-" << studentCount << "): ";
                    int idx;
                    cin >> idx;
                    if (idx < 1 || idx > studentCount)
                    {
                        cout << "Invalid selection." << endl;
                    }
                    else
                    {
                        dept->addMember(students[idx - 1]);
                        cout << "Student added to department." << endl;
                    }
                }
            }
            else if (type == 2)
            {
                if (staffCount == 0)
                {
                    cout << "No staff available." << endl;
                }
                else
                {
                    cout << "Select Staff (1-" << staffCount << "): ";
                    int idx;
                    cin >> idx;
                    if (idx < 1 || idx > staffCount)
                    {
                        cout << "Invalid selection." << endl;
                    }
                    else
                    {
                        dept->addMember(staffArr[idx - 1]);
                        cout << "Staff added to department." << endl;
                    }
                }
            }
            else if (type == 3)
            {
                if (taCount == 0)
                {
                    cout << "No TAs available." << endl;
                }
                else
                {
                    cout << "Select TA (1-" << taCount << "): ";
                    int idx;
                    cin >> idx;
                    if (idx < 1 || idx > taCount)
                    {
                        cout << "Invalid selection." << endl;
                    }
                    else
                    {
                        dept->addMember(taArr[idx - 1]);
                        cout << "TA added to department." << endl;
                    }
                }
            }
            else
            {
                cout << "Invalid choice." << endl;
            }
        }
    }
    else if (choice == 3)
    {
        if (dept == nullptr)
        {
            cout << "No department created yet." << endl;
        }
        else
        {
            dept->displayAllRoles();
        }
    }
    else if (choice == 0)
    {
        return;
    }
    else
    {
        cout << "Invalid choice." << endl;
    }
}

void manageTutoringSessions()
{
    int choice;
    cout << "\n=== Tutoring Session Menu ===" << endl;
    cout << "1. Create Tutoring Session" << endl;
    cout << "2. Display All Sessions" << endl;
    cout << "3. Merge Two Sessions (operator+ Demo)" << endl;
    cout << "4. Compare Two Sessions (operator> Demo)" << endl;
    cout << "0. Back" << endl;
    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 1)
    {
        if (sessionCount >= MAX)
        {
            cout << "Maximum sessions reached." << endl;
        }
        else if (taCount == 0)
        {
            cout << "No TAs available. Add a TA first." << endl;
        }
        else if (studentCount == 0)
        {
            cout << "No students available. Add a student first." << endl;
        }
        else
        {
            int sid;
            double duration;
            cout << "Enter Session ID: ";
            cin >> sid;
            cout << "Enter Duration (minutes): ";
            cin >> duration;

            cout << "Select TA (1-" << taCount << "): ";
            int taIdx;
            cin >> taIdx;

            cout << "Select Student (1-" << studentCount << "): ";
            int sIdx;
            cin >> sIdx;

            if (taIdx < 1 || taIdx > taCount || sIdx < 1 || sIdx > studentCount)
            {
                cout << "Invalid selection." << endl;
            }
            else
            {
                sessions[sessionCount++] = new TutoringSession(sid, duration, taArr[taIdx - 1], students[sIdx - 1]);
                cout << "Tutoring session created successfully." << endl;
            }
        }
    }
    else if (choice == 2)
    {
        if (sessionCount == 0)
        {
            cout << "No sessions created yet." << endl;
        }
        else
        {
            for (int i = 0; i < sessionCount; i++)
            {
                cout << "\nSession #" << (i + 1) << ":" << endl;
                sessions[i]->displaySession();
            }
        }
    }
    else if (choice == 3)
    {
        if (sessionCount < 2)
        {
            cout << "Need at least 2 sessions to merge." << endl;
        }
        else
        {
            cout << "Select first session (1-" << sessionCount << "): ";
            int a;
            cin >> a;
            cout << "Select second session (1-" << sessionCount << "): ";
            int b;
            cin >> b;

            if (a < 1 || a > sessionCount || b < 1 || b > sessionCount)
            {
                cout << "Invalid selection." << endl;
            }
            else
            {
                TutoringSession merged = *sessions[a - 1] + *sessions[b - 1];
                cout << "\nMerged Session:" << endl;
                cout << "  Combined Duration: " << merged.getDuration() << " minutes" << endl;
            }
        }
    }
    else if (choice == 4)
    {
        if (sessionCount < 2)
        {
            cout << "Need at least 2 sessions to compare." << endl;
        }
        else
        {
            cout << "Select first session (1-" << sessionCount << "): ";
            int a;
            cin >> a;
            cout << "Select second session (1-" << sessionCount << "): ";
            int b;
            cin >> b;

            if (a < 1 || a > sessionCount || b < 1 || b > sessionCount)
            {
                cout << "Invalid selection." << endl;
            }
            else
            {
                if (*sessions[a - 1] > *sessions[b - 1])
                {
                    cout << "Session " << a << " is longer than Session " << b << "." << endl;
                }
                else
                {
                    cout << "Session " << b << " is longer than or equal to Session " << a << "." << endl;
                }
            }
        }
    }
    else if (choice == 0)
    {
        return;
    }
    else
    {
        cout << "Invalid choice." << endl;
    }
}

void cleanup()
{
    for (int i = 0; i < studentCount; i++)
        delete students[i];
    for (int i = 0; i < staffCount; i++)
        delete staffArr[i];
    for (int i = 0; i < taCount; i++)
        delete taArr[i];
    for (int i = 0; i < sessionCount; i++)
        delete sessions[i];
    for (int i = 0; i < cardCount; i++)
        delete cards[i];
    if (dept != nullptr)
        delete dept;
}

int main()
{
    cout << "==========================================" << endl;
    cout << "   Smart University Management System     " << endl;
    cout << "==========================================" << endl;

    int choice = -1;

    while (choice != 0)
    {
        cout << "\n=== Main Menu ===" << endl;
        cout << "1. Manage Access Cards" << endl;
        cout << "2. Manage Students" << endl;
        cout << "3. Manage Staff" << endl;
        cout << "4. Manage Teaching Assistants" << endl;
        cout << "5. Manage Department" << endl;
        cout << "6. Manage Tutoring Sessions" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            manageAccessCards();
        }
        else if (choice == 2)
        {
            manageStudents();
        }
        else if (choice == 3)
        {
            manageStaff();
        }
        else if (choice == 4)
        {
            manageTeachingAssistants();
        }
        else if (choice == 5)
        {
            manageDepartment();
        }
        else if (choice == 6)
        {
            manageTutoringSessions();
        }
        else if (choice == 0)
        {
        }
        else
        {
            cout << "Invalid choice." << endl;
        }
    }

    cleanup();
    return 0;
}