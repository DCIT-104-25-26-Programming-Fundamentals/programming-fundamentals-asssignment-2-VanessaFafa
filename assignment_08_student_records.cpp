// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 8
// =============================================================================
//
// TASK: Student Record Management System
//
// Build a console-based program that stores and manages student information.
// Use a struct to represent each student record containing:
//
//   - name   : the student's full name  (string)
//   - id     : a unique student ID number (int, e.g. 20240001)
//   - scores : a list of scores from multiple assessments (vector<double>)
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Student
//      - Ask the user to enter the student's name and ID.
//      - Ask how many scores to enter, then collect each score one by one.
//      - Save the student record and confirm it was added.
//
//   2. Display All Students
//      - Print a formatted table showing every student's:
//          Name, ID, individual scores, and their average score.
//      - If no students have been added yet, print a message saying so.
//
//   3. Calculate Average Score for a Specific Student
//      - Ask the user to enter a student ID.
//      - Find the student and print their average score.
//      - If the ID is not found, print an error message.
//
//   4. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ================================
//      STUDENT RECORD SYSTEM MENU
//   ================================
//   1. Add student
//   2. Display all students
//   3. Calculate average score
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Student name: Alice Mensah
//   Student ID: 20240001
//   How many scores? 3
//   Enter score 1: 78
//   Enter score 2: 85
//   Enter score 3: 90
//   Student "Alice Mensah" added successfully.
//
//   Enter your choice (1-4): 3
//   Enter student ID: 20240001
//   Alice Mensah's average score: 84.33
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Define a struct called Student (see scaffold below).
// - Store all records in a vector<Student>.
// - Average scores must be rounded to 2 decimal places (use setprecision(2)).
// - Each feature MUST be in its own function.
// - Handle invalid menu choices and missing student IDs gracefully.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;


// Student structure
struct Student
{
    string name;
    int id;
    vector<double> scores;
};


// Function prototypes
void addStudent(vector<Student>& students);
void displayStudents(vector<Student>& students);
double calculateAverage(vector<double>& scores);
void findAverageByID(vector<Student>& students);



int main()
{
    vector<Student> students;

    int choice;


    do
    {
        cout << "\n================================\n";
        cout << "   STUDENT RECORD SYSTEM MENU\n";
        cout << "================================\n";
        cout << "1. Add student\n";
        cout << "2. Display all students\n";
        cout << "3. Calculate average score\n";
        cout << "4. Quit\n";
        cout << "Enter your choice (1-4): ";

        cin >> choice;
        cin.ignore();


        switch(choice)
        {
            case 1:
                addStudent(students);
                break;

            case 2:
                displayStudents(students);
                break;

            case 3:
                findAverageByID(students);
                break;

            case 4:
                cout << "Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice. Please enter 1-4." << endl;
        }


    } while(choice != 4);


    return 0;
}



// Function 1: Add student
void addStudent(vector<Student>& students)
{
    Student student;


    cout << "Student name: ";
    getline(cin, student.name);


    cout << "Student ID: ";
    cin >> student.id;


    int numberOfScores;

    cout << "How many scores? ";
    cin >> numberOfScores;


    for(int i = 0; i < numberOfScores; i++)
    {
        double score;

        cout << "Enter score " << i + 1 << ": ";
        cin >> score;

        student.scores.push_back(score);
    }


    cin.ignore();


    students.push_back(student);


    cout << "Student \"" 
         << student.name 
         << "\" added successfully." 
         << endl;
}



// Function 2: Display all students
void displayStudents(vector<Student>& students)
{
    if(students.empty())
    {
        cout << "No students have been added yet." << endl;
        return;
    }


    cout << "\nStudent Records:\n";

    cout << left
         << setw(20) << "Name"
         << setw(15) << "ID"
         << setw(20) << "Scores"
         << setw(10) << "Average"
         << endl;


    for(int i = 0; i < students.size(); i++)
    {
        cout << left
             << setw(20)
             << students[i].name

             << setw(15)
             << students[i].id;


        for(int j = 0; j < students[i].scores.size(); j++)
        {
            cout << students[i].scores[j] << " ";
        }


        cout << setw(10)
             << fixed
             << setprecision(2)
             << calculateAverage(students[i].scores)

             << endl;
    }
}



// Function 3: Calculate average
double calculateAverage(vector<double>& scores)
{
    double total = 0;


    for(int i = 0; i < scores.size(); i++)
    {
        total += scores[i];
    }


    return total / scores.size();
}



// Function 4: Find average by ID
void findAverageByID(vector<Student>& students)
{
    int id;


    cout << "Enter student ID: ";
    cin >> id;


    for(int i = 0; i < students.size(); i++)
    {
        if(students[i].id == id)
        {
            cout << students[i].name
                 << "'s average score: "
                 << fixed
                 << setprecision(2)
                 << calculateAverage(students[i].scores)
                 << endl;

            return;
        }
    }


    cout << "Student ID not found." << endl;
}
