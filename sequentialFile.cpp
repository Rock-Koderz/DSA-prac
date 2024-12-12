// Department maintains student’s database. The file contains roll number, name, division and address. Write a program to create a sequential file to store and maintain student data. It should allow the user to add, delete information of student. Display information of particular student. If record of student does not exist an appropriate message is displayed. If student record is found it should display the student details.

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Student {
    int rollNumber;
    string name;
    string division;
    string address;
};

// Function to add a student record
void addStudent() {
    ofstream outFile("students.txt", ios::app);
    Student student;
    cout << "Enter roll number: ";
    cin >> student.rollNumber;
    cin.ignore();
    cout << "Enter name: ";
    getline(cin, student.name);
    cout << "Enter division: ";
    getline(cin, student.division);
    cout << "Enter address: ";
    getline(cin, student.address);
    outFile << student.rollNumber << " " << student.name << " " << student.division << " " << student.address << endl;
    outFile.close();
}

// Function to delete a student record
void deleteStudent() {
    ifstream inFile("students.txt");
    ofstream tempFile("temp.txt");
    int rollNumber;
    cout << "Enter roll number to delete: ";
    cin >> rollNumber;
    bool found = false;
    Student student;
    while (inFile >> student.rollNumber) {
        inFile.ignore();
        getline(inFile, student.name, ' ');
        getline(inFile, student.division, ' ');
        getline(inFile, student.address);
        if (student.rollNumber == rollNumber) {
            found = true;
        } else {
            tempFile << student.rollNumber << " " << student.name << " " << student.division << " " << student.address << endl;
        }
    }
    inFile.close();
    tempFile.close();
    remove("students.txt");
    rename("temp.txt", "students.txt");
    if (found) {
        cout << "Record deleted successfully." << endl;
    } else {
        cout << "Record not found." << endl;
    }
}

// Function to display a student record
void displayStudent() {
    ifstream inFile("students.txt");
    int rollNumber;
    cout << "Enter roll number to display: ";
    cin >> rollNumber;
    bool found = false;
    Student student;
    while (inFile >> student.rollNumber) {
        inFile.ignore();
        getline(inFile, student.name, ' ');
        getline(inFile, student.division, ' ');
        getline(inFile, student.address);
        if (student.rollNumber == rollNumber) {
            found = true;
            cout << "Roll Number: " << student.rollNumber << endl;
            cout << "Name: " << student.name << endl;
            cout << "Division: " << student.division << endl;
            cout << "Address: " << student.address << endl;
            break;
        }
    }
    inFile.close();
    if (!found) {
        cout << "Record not found." << endl;
    }
}

int main() {
    int choice;
    while (true) {
        cout << "1. Add Student" << endl;
        cout << "2. Delete Student" << endl;
        cout << "3. Display Student" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                deleteStudent();
                break;
            case 3:
                displayStudent();
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    }
    return 0;
}


// Using class
/*

// Department maintains student’s database. The file contains roll number, name, division and address. Write a program to create a sequential file to store and maintain student data. It should allow the user to add, delete information of student. Display information of particular student. If record of student does not exist an appropriate message is displayed. If student record is found it should display the student details.

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Student {
public:
    int rollNumber;
    string name;
    string division;
    string address;

    void getData() {
        cout << "Enter roll number: ";
        cin >> rollNumber;
        cin.ignore();
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter division: ";
        getline(cin, division);
        cout << "Enter address: ";
        getline(cin, address);
    }

    void displayData() const {
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Name: " << name << endl;
        cout << "Division: " << division << endl;
        cout << "Address: " << address << endl;
    }
};

class StudentDatabase {
public:
    void addStudent() {
        ofstream outFile("students.txt", ios::app);
        Student student;
        student.getData();
        outFile << student.rollNumber << " " << student.name << " " << student.division << " " << student.address << endl;
        outFile.close();
    }

    void deleteStudent() {
        ifstream inFile("students.txt");
        ofstream tempFile("temp.txt");
        int rollNumber;
        cout << "Enter roll number to delete: ";
        cin >> rollNumber;
        bool found = false;
        Student student;
        while (inFile >> student.rollNumber) {
            inFile.ignore();
            getline(inFile, student.name, ' ');
            getline(inFile, student.division, ' ');
            getline(inFile, student.address);
            if (student.rollNumber == rollNumber) {
                found = true;
            } else {
                tempFile << student.rollNumber << " " << student.name << " " << student.division << " " << student.address << endl;
            }
        }
        inFile.close();
        tempFile.close();
        remove("students.txt");
        rename("temp.txt", "students.txt");
        if (found) {
            cout << "Record deleted successfully." << endl;
        } else {
            cout << "Record not found." << endl;
        }
    }

    void displayStudent() {
        ifstream inFile("students.txt");
        int rollNumber;
        cout << "Enter roll number to display: ";
        cin >> rollNumber;
        bool found = false;
        Student student;
        while (inFile >> student.rollNumber) {
            inFile.ignore();
            getline(inFile, student.name, ' ');
            getline(inFile, student.division, ' ');
            getline(inFile, student.address);
            if (student.rollNumber == rollNumber) {
                found = true;
                student.displayData();
                break;
            }
        }
        inFile.close();
        if (!found) {
            cout << "Record not found." << endl;
        }
    }
};

int main() {
    StudentDatabase db;
    int choice;
    while (true) {
        cout << "1. Add Student" << endl;
        cout << "2. Delete Student" << endl;
        cout << "3. Display Student" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                db.addStudent();
                break;
            case 2:
                db.deleteStudent();
                break;
            case 3:
                db.displayStudent();
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    }
    return 0;
}

*/