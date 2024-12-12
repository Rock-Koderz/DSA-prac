// Consider a student database of SEIT class. Database contains different fields of every student like Roll No, Name and SGPA. 
// Arrange list of students to find out first ten toppers from a class. (Use Quick sort) 

#include <iostream>
#include <string>
using namespace std;

struct Student {
    int rollNo;
    string name;
    float sgpa;
};

void swap(Student& a, Student& b) {
    Student temp = a;
    a = b;
    b = temp;
}

int partition(Student arr[], int low, int high) {
    float pivot = arr[high].sgpa;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j].sgpa > pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(Student arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    cout << "Enter the number of students: ";
    cin >> n;

    Student students[n];
    for (int i = 0; i < n; ++i) {
        cout << "Enter details for student " << i + 1 << " (Roll No, Name, SGPA): ";
        cin >> students[i].rollNo >> students[i].name >> students[i].sgpa;
    }

    quickSort(students, 0, n - 1);

    cout << "\nTop 10 students based on SGPA:\n";
    for (int i = 0; i < min(n, 10); ++i) {
        cout << "Roll No: " << students[i].rollNo << ", Name: " << students[i].name << ", SGPA: " << students[i].sgpa << '\n';
    }

    return 0;
}