#include <iostream>
#include <string>
using namespace std;

struct students {
  int rollno;
  string name;
  float cgpa;
};

void bubbleSort(students s[], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (s[j].rollno > s[j + 1].rollno) {
        // Swap the students
        students temp = s[j];
        s[j] = s[j + 1];
        s[j + 1] = temp;
      }
    }
  }
}

int main() {
  int n;
  cout << "Enter the number of students: ";
  cin >> n;
  students s[n];
  cout << "Enter the details of students:" << endl;
  for (int i = 0; i < n; i++) {
    cout << "Student " << i + 1 << endl;
    cout << "Enter roll number: ";
    cin >> s[i].rollno;
    cout << "Enter name: ";
    cin >> s[i].name;
    cout << "Enter CGPA: ";
    cin >> s[i].cgpa;
    cout << endl;
  }

  bubbleSort(s, n);

  cout << "Students sorted by roll number:" << endl;
  cout << "Roll No\t\tName\t\tCGPA" << endl;
  for (int i = 0; i < n; i++) {
    cout << s[i].rollno << "\t\t" << s[i].name << "\t\t" << s[i].cgpa << endl;
  }

  return 0;
}