// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 9
// =============================================================================
//
// TASK: Console-Based Simple Calculator
//
// Build a calculator program that runs in the console and performs basic
// arithmetic operations based on the user's input.
//
// -----------------------------------------------------------------------------
// OPERATIONS YOUR CALCULATOR MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Addition          ( + )    e.g.  10 + 3  =  13
//   2. Subtraction       ( - )    e.g.  10 - 3  =  7
//   3. Multiplication    ( * )    e.g.  10 * 3  =  30
//   4. Division          ( / )    e.g.  10 / 3  =  3.33
//   5. Modulus           ( % )    e.g.  10 % 3  =  1  (remainder)
//   6. Exponentiation    ( ^ )    e.g.  2 ^ 8   =  256
//   7. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        SIMPLE CALCULATOR
//   ============================
//   1. Addition
//   2. Subtraction
//   3. Multiplication
//   4. Division
//   5. Modulus
//   6. Exponentiation
//   7. Quit
//   Select an operation (1-7):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Select an operation (1-7): 4
//   Enter first number : 10
//   Enter second number: 3
//   Result: 10 / 3 = 3.33
//
//   Select an operation (1-7): 4
//   Enter first number : 5
//   Enter second number: 0
//   Error: Cannot divide by zero.
//
//   Select an operation (1-7): 7
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Each arithmetic operation MUST be written as its own function.
// - Use a loop so the calculator keeps running until the user selects Quit.
// - Division by zero must be caught and handled with a clear error message
//   (do NOT let the program crash).
// - Use fixed and setprecision(2) to display results to 2 decimal places.
// - Handle invalid menu choices gracefully.
// - For exponentiation use a loop or the pow() function from <cmath>.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct Student {
    string name;
    int id;
    vector<double> scores;
};

double calculateStudentAverage(const Student& student) {
    if (student.scores.empty()) {
        return 0.0;
    }
    double sum = 0.0;
    for (double score : student.scores) {
        sum += score;
    }
    return sum / student.scores.size();
}

void addStudent(vector<Student>& students) {
    Student newStudent;
    cout << "Student name: ";
    cin.ignore();
    getline(cin, newStudent.name);
    
    cout << "Student ID: ";
    cin >> newStudent.id;

    int numScores;
    cout << "How many scores? ";
    cin >> numScores;

    for (int i = 0; i < numScores; i++) {
        double score;
        cout << "Enter score " << (i + 1) << ": ";
        cin >> score;
        newStudent.scores.push_back(score);
    }

    students.push_back(newStudent);
    cout << "Student \"" << newStudent.name << "\" added successfully." << endl;
}

void displayAllStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No students added yet." << endl;
        return;
    }

    cout << fixed << setprecision(2);
    cout << "\n----------------------------------------------------------------------" << endl;
    cout << left << setw(20) << "Name" 
         << setw(12) << "ID" 
         << setw(25) << "Scores" 
         << setw(10) << "Average" << endl;
    cout << "----------------------------------------------------------------------" << endl;

    for (const auto& student : students) {
        string scoresStr = "";
        for (size_t i = 0; i < student.scores.size(); i++) {
            scoresStr += to_string(static_cast<int>(student.scores[i]));
            if (i < student.scores.size() - 1) {
                scoresStr += ", ";
            }
        }

        cout << left << setw(20) << student.name 
             << setw(12) << student.id 
             << setw(25) << scoresStr 
             << setw(10) << calculateStudentAverage(student) << endl;
    }
    cout << "----------------------------------------------------------------------" << endl;
}

void calculateAverageForStudent(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No students added yet." << endl;
        return;
    }

    int targetId;
    cout << "Enter student ID: ";
    cin >> targetId;

    for (const auto& student : students) {
        if (student.id == targetId) {
            cout << fixed << setprecision(2);
            cout << student.name << "'s average score: " << calculateStudentAverage(student) << endl;
            return;
        }
    }

    cout << "Error: Student ID " << targetId << " not found." << endl;
}

int main() {
    vector<Student> students;
    int choice = 0;

    while (choice != 4) {
        cout << "\n================================" << endl;
        cout << "   STUDENT RECORD SYSTEM MENU" << endl;
        cout << "================================" << endl;
        cout << "1. Add student" << endl;
        cout << "2. Display all students" << endl;
        cout << "3. Calculate average score" << endl;
        cout << "4. Quit" << endl;
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        if (choice == 1) {
            addStudent(students);
        } else if (choice == 2) {
            displayAllStudents(students);
        } else if (choice == 3) {
            calculateAverageForStudent(students);
        } else if (choice == 4) {
            cout << "Goodbye!" << endl;
        } else {
            cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
        }
    }

    return 0;
}

