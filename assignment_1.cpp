#include<iostream>
using namespace std;

class Student {
private:
    string name;
    int roll;
public:
    void input(Student s[], int size) {
        for (int i = 0; i < size; ++i) {
            cout << "Enter Roll and Name of student - " << (i + 1) << ": ";
            cin >> s[i].roll >> s[i].name;
        }
    }
    void insertionSort(Student s[], int n) {
        for (int i = 1; i < n; i++) {
            int j = i - 1;
            int key = s[i].roll;
            string keyName = s[i].name;

            while (j >= 0 && s[j].roll > key) {
                s[j + 1].roll = s[j].roll;
                s[j + 1].name = s[j].name;
                j--;
            }
            s[j + 1].roll = key;
            s[j + 1].name = keyName;
        }
    }
    void shellSort(Student s[], int n) {
        for (int gap = n / 2; gap > 0; gap /= 2) {
            for (int i = gap; i < n; i++) {
                Student temp = s[i]; 
                int j;

                for (j = i; j >= gap && s[j - gap].name > temp.name; j -= gap) {
                    s[j] = s[j - gap];
                }
                s[j] = temp; 
            }
        }
    }

    void display(Student s[], int size) {
        for (int i = 0; i < size; ++i) {
            cout << "Roll No: " << s[i].roll << ", Name: " << s[i].name << endl;
        }
    }
};

int main() {
    Student s[3], x;
    int n = sizeof(s) / sizeof(s[0]);  
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Input Students\n";
        cout << "2. Sort by Roll No (Insertion Sort)\n";
        cout << "3. Display Students\n";
        cout << "4. Sort by Name (Shell Sort)\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            x.input(s, n);
            break;
        case 2:
            x.insertionSort(s, n);
            cout << "Students sorted by Roll No.\n";
            break;
        case 3:
            x.display(s, n);
            break;
        case 4:
            x.shellSort(s, n);
            cout << "Students sorted by Name.\n";
            break;
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}