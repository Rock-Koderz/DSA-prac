// Consider a student database of SEIT class. Database contains different fields of every student like Roll No, Name and SGPA. 
// Arrange list of students according to name. (Use Insertion sort)

#include <iostream>
#include <string>
using namespace std;

struct Student {
    int rollno;
    string name;
    float sgpa;
};

void insertionSort(Student s[], int n) {
    for (int i = 1; i < n; ++i) {
        Student key = s[i];
        int j = i - 1;
        while (j >= 0 && s[j].name > key.name) {
            s[j + 1] = s[j];
            j = j - 1;
        }
        s[j + 1] = key;
    }
}

int main() {
    int n;
    cout << "Enter the number of students: ";
    cin >> n;

    Student s[n];
    for (int i = 0; i < n; ++i) {
        cout << "Enter details for student " << i + 1 << " (Roll No, Name, SGPA): ";
        cin >> s[i].rollno >> s[i].name >> s[i].sgpa;
    }

    insertionSort(s, n);

  cout << "Students sorted by Name:" << endl;
  cout << "Roll No\t\tName\t\tCGPA" << endl;
  for (int i = 0; i < n; i++) {
    cout << s[i].rollno << "\t\t" << s[i].name << "\t\t" << s[i].sgpa << endl;
  }

    return 0;
}

