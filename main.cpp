#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Student {
    int id;
    string name;
    float grade;
};

Student students[100] = {
    {101, "Alice", 88.5},
    {102, "Bob", 76.0},
    {103, "Charlie", 91.0},
    {104, "David", 65.5},
    {105, "Eve", 82.0},
    {106, "Frank", 79.5},
    {107, "Grace", 95.0},
    {108, "Hannah", 73.0},
    {109, "Ivy", 84.5},
    {110, "Jack", 90.0},
    {111, "Karen", 77.5},
    {112, "Leo", 88.0},
    {113, "Mona", 92.5},
    {114, "Nathan", 69.0},
    {115, "Zack", 85.0}
};

int count = 15;

void displayRecords() {
    cout << "=================================\n";
    cout << "\nStudent Records\n";
    cout << "=================================\n";
    cout << left << setw(10) << "ID"
         << setw(15) << "Name" << "Grade\n";

    for (int i = 0; i < count; i++) {
        cout << left << setw(10) << students[i].id
             << setw(15) << students[i].name
             << fixed << setprecision(1)
             << students[i].grade << endl;
    }
}

int findStudent(int id) {
    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            return i;
        }
    }
    return -1;
}

void addRecord() {
    if (count >= 100) {
        cout << "Record limit reached!\n";
        return;
    }

    Student s;

    cout << "Enter Student ID: ";
    cin >> s.id;

    if (findStudent(s.id) != -1) {
        cout << "Student ID already exists!\n";
        cout << "Hint: Check the Student Records for reference.\n";
        return;
    }

    cout << "Enter Student Name: ";
    cin >> ws;
    getline(cin, s.name);

    cout << "Enter Grade: ";
    cin >> s.grade;

    students[count] = s;
    count++;

    cout << "Student added successfully!\n";
}

void searchRecord() {
    int id;
    cout << "Enter Student ID to search: ";
    cin >> id;

    int index = findStudent(id);

    if (index != -1) {
        cout << "ID: " << students[index].id << endl;
        cout << "Name: " << students[index].name << endl;
        cout << "Grade: " << students[index].grade << endl;
    } else {
        cout << "Student not found!\n";
        cout << "Hint: Check the Student Records or Add a Student Record to the System.\n";
    }
}

void editRecord() {
    int id;
    cout << "Enter Student ID to edit: ";
    cin >> id;

    int index = findStudent(id);

    if (index != -1) {
        cout << "Enter New Name: ";
        cin >> ws;
        getline(cin, students[index].name);

        cout << "Enter New Grade: ";
        cin >> students[index].grade;

        cout << "Record updated successfully!\n";
    } else {
        cout << "Student not found!\n";
        cout << "Hint: Check the Student Records or Add a Student Record to the System.\n";
    }
}

void printSingleRecord() {
    int id;
    cout << "Enter Student ID to print: ";
    cin >> id;

    int index = findStudent(id);

    if (index != -1) {
        cout << "\nStudent Report\n";
        cout << "======================\n";
        cout << "Student ID: " << students[index].id << endl;
        cout << "Name: " << students[index].name << endl;
        cout << "Grade: " << fixed << setprecision(1)
             << students[index].grade << endl;
        cout << "======================\n";
    } else {
        cout << "Student not found!\n";
        cout << "Hint: Check the Student Records or Add a Student Record to the System.\n";
    }
}

int main() {
    int choice;

    do {
        cout << "\n================================\n";
        cout << "\nStudent Grade Management System\n";
        cout << "\n================================\n";
        cout << "\n1. View Records\n";
        cout << "2. Add Record\n";
        cout << "3. Search Record\n";
        cout << "4. Edit Record\n";
        cout << "5. Print Single Record\n";
        cout << "6. Exit\n";
        cout << "\n================================\n";
        cout << "\nEnter your choice: ";
        cout << "\n================================\n";
        cin >> choice;

        switch (choice) {
            case 1:
                displayRecords();
                break;
            case 2:
                addRecord();
                break;
            case 3:
                searchRecord();
                break;
            case 4:
                editRecord();
                break;
            case 5:
                printSingleRecord();
                break;
            case 6:
                cout << "Exiting the Student Grade Management Program!\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 6);

    return 0;
}

