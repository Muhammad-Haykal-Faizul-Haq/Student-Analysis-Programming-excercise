// Write a program that reads students’ names followed by their test scores
// Muhammad Haykal Faizul Haq
// Pemrograman dasar kelas A

#include <iostream>
#include <fstream> // This includes C++’s file stream library, which allows reading and writing files
#include <iomanip> // For the final print function
#include <string> // For premade functions that might be useful later
using namespace std;

// Defining the studentType data type as a struct of two string elements, one integer element, and one char element
struct studentType {
    string studentFName; // Student's front name
    string studentLName; // Student's last name
    int testScore; // Student's test score 0 - 100
    char grade; // Student's grade (A,B,C,D,E,F)
};

const int studentCount = 20; // Declares that there are 20 students
studentType students[studentCount]; // Declares the array of studentType called students that has studentCount elements
int highestScore; // Declares a placeholder variable for the highest scoring student

// A function to read the students’ data into the array.
void readDataFromFile(studentType students[], int size, ifstream &infile) {
    for (int i = 0; i < size && infile; i++) {
        infile >> students[i].studentFName
               >> students[i].studentLName
               >> students[i].testScore;
    }
}

// A function to assign the relevant grade to each student.
void assignGrade(studentType students[], int size) {
    for (int i = 0; i < size; i++) {
        int score = students[i].testScore;
        if (score >= 90)
            students[i].grade = 'A';
        else if (score >= 80)
            students[i].grade = 'B';
        else if (score >= 70)
            students[i].grade = 'C';
        else if (score >= 60)
            students[i].grade = 'D';
        else if (score >= 50)
            students[i].grade = 'E';    
        else
            students[i].grade = 'F';
    }
}

// A function to find the highest test score.
int findHighestScore(studentType students[], int size) {
    int highest = students[0].testScore;
    for (int i = 1; i < size; i++) {
        if (students[i].testScore > highest)
            highest = students[i].testScore;
    }
    return highest;
}

// A function to print the names of the students having the highest test score
void printHighestScorers(studentType students[], int size, int highestScore) {
    for (int i = 0; i < size; i++) {
        if (students[i].testScore == highestScore)
            cout << left << setw(15) << (students[i].studentLName + ", " + students[i].studentFName) << endl;
    }
}

// Final print all function
void printAll(studentType students[], int size) {
    cout << left << setw(20) << "Name" 
         << setw(10) << "Score" 
         << setw(10) << "Grade" << endl;
    cout << string(40, '-') << endl;

    for (int i = 0; i < size; i++) {
        cout << left << setw(25) // 25 character spaces reserved until next output
             << (students[i].studentLName + ", " + students[i].studentFName)
             << setw(10) << students[i].testScore
             << setw(10) << students[i].grade << endl;
    }
}

int main() {
    ifstream infile("students.txt");
    if (!infile) {
        cerr << "Error: Could not open input file.\n"; // Error condition when the file "students.txt" fails to be read properly
        return 1;
    }

    readDataFromFile(students, studentCount, infile);
    infile.close();

    assignGrade(students, studentCount);
    highestScore = findHighestScore(students, studentCount);

    cout << "\nStudent Records:\n";
    printAll(students, studentCount);

    cout << "\nHighest Test Score: " << highestScore << endl;
    cout << "Students with the highest score:\n";
    printHighestScorers(students, studentCount, highestScore);

    return 0;
}