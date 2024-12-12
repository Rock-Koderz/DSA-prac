// Consider a student database of SEIT class. Database contains different fields of every student like Roll No, Name and SGPA. 
// Search a particular student according to name using binary search without recursion. 


#include <iostream>
#include <string>

using namespace std;

class Student {
public:
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

int binarySearch(Student s[], int n, string key) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (s[mid].name == key)
            return mid;
        if (s[mid].name < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
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

    string searchName;
    cout << "Enter the name of the student to search: ";
    cin >> searchName;

    int result = binarySearch(s, n, searchName);
    if (result != -1) {
        cout << "Student found: " << endl;
        cout << "Roll No: " << s[result].rollno << endl;
        cout << "Name: " << s[result].name << endl;
        cout << "SGPA: " << s[result].sgpa << endl;
    } else {
        cout << "Student not found." << endl;
    }

    return 0;
}