// Consider a student database of SEIT class. Database contains different fields of every student like Roll No, Name and SGPA. 
// Search students according to SGPA. If more than one student having same SGPA, then print list of all students having same SGPA. (Sequential Search)

#include <iostream>
#include <string>
using namespace std;

struct students {
    int rollno;
    string name;
    float sgpa;
};

void bubbleSort(students s[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (s[j].rollno > s[j + 1].rollno) {
                students temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}

void searchBySGPA(students s[], int n, float targetSGPA) {
    bool found = false;
    cout << "Roll No\tName\t\tSGPA\n";
    cout << "---------------------------------\n";
    for (int i = 0; i < n; ++i) {
        if (s[i].sgpa == targetSGPA) {
            cout << s[i].rollno << "\t" << s[i].name << "\t\t" << s[i].sgpa << "\n";
            found = true;
        }
    }
    if (!found) {
        cout << "No students found with SGPA " << targetSGPA << '\n';
    }
}

int main() {
    int n;
    cout << "Enter the number of students: ";
    cin >> n;

    students s[n];
    for (int i = 0; i < n; ++i) {
        cout << "Enter details for student " << i + 1 << " (Roll No, Name, SGPA): ";
        cin >> s[i].rollno >> s[i].name >> s[i].sgpa;
    }

    float targetSGPA;
    cout << "Enter the SGPA to search for: ";
    cin >> targetSGPA;

    searchBySGPA(s, n, targetSGPA);

    return 0;
}