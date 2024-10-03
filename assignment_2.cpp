#include <iostream>
using namespace std;

class EmployeeDatabase {
private:
    string empName;
    int empID;
    double empSalary;

public:
    void setData() {
        cout << "Enter the name of the Employee: ";
        cin >> empName;
        cout << "Enter the employee ID: ";
        cin >> empID;
        cout << "Enter the salary of the Employee: ";
        cin >> empSalary;
    }

    int getEmpID() const { return empID; }
    string getEmpName() const { return empName; }
    double getEmpSalary() const { return empSalary; }

    static void qs(EmployeeDatabase arr[], int F, int L) {
        if (F < L) {
            int pivot = arr[F].empID; 
            int i = F + 1;
            int j = L;

            while (i <= j) {
                while (i <= L && arr[i].empID < pivot) i++;
                while (j >= F && arr[j].empID > pivot) j--;

                if (i < j) {
                    swap(arr[i], arr[j]);
                }
            }
            swap(arr[F], arr[j]);  
            qs(arr, F, j - 1); 
            qs(arr, j + 1, L);  
        }
    }

    
    void display() const {
        cout << "Employee Name: " << empName << endl;
        cout << "Employee ID: " << empID << endl;
        cout << "Employee Salary: " << empSalary << endl;
    }
};

int main() {
    int n;

    cout << "Enter the number of Employees: ";
    cin >> n;

    EmployeeDatabase e[n];

    
    for (int i = 0; i < n; i++) {
        e[i].setData();
    }

  
    EmployeeDatabase::qs(e, 0, n - 1);

    
    cout << "\nSorted Employee List (by EMP-ID):" << endl;
    for (int i = 0; i < n; i++) {
        e[i].display();
        cout << "------------------------" << endl; 
    }

    return 0;
}