/*  Assignment 6 :
    Consider two polynomial expressions of any degree. Design solution to perform addition of these 
    two polynomials with suitable data structure and display results.

    PRN No - 123B1B168
    Name -SWAPNIL ANKUSH KHILLARE
    class  & Div - SY BTech & C-2 */

#include <iostream>
using namespace std;

class Node{
    int coeff;
    int pow;
    Node* next;
    public : 
    Node(){
        coeff = 0;
        pow = 0;
        next = NULL;
    }
    Node(int a, int b){
        coeff = a;
        pow = b;
        next = NULL;
    }
    friend class polynomial;
};

class polynomial{
    Node* head;
    public :
    polynomial() {
        head = NULL;
    }
    void create_node(int coeff, int pow);
    void addPoly(polynomial l1, polynomial l2);
    void printPoly();
};

void polynomial :: create_node(int coeff, int pow){
    Node* nn = new Node(coeff, pow);
    if(head == NULL){
        head = nn;
        return;
    }
    Node* temp = head;
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = nn;
}

void polynomial :: addPoly(polynomial l1, polynomial l2){
    Node* ptr1 = l1.head;
    Node* ptr2 = l2.head;
    Node* result = new Node(); // dummy node to start the result linked list
    Node* curr = result;
    
    // Traverse both polynomials
    while(ptr1 != NULL && ptr2 != NULL){
        Node* nn = new Node(); 
        if(ptr1->pow > ptr2->pow){
            nn->coeff = ptr1->coeff;
            nn->pow = ptr1->pow;
            ptr1 = ptr1->next;
        }
        else if(ptr1->pow < ptr2->pow){
            nn->coeff = ptr2->coeff;
            nn->pow = ptr2->pow;
            ptr2 = ptr2->next;
        }
        else{ // powers are equal
            nn->coeff = ptr1->coeff + ptr2->coeff;
            nn->pow = ptr1->pow;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        curr->next = nn;
        curr = curr->next;
    }

    // Append the remaining nodes of the longer list
    while(ptr1 != NULL){
        curr->next = ptr1;
        curr = curr->next;
        ptr1 = ptr1->next;
    }
    while(ptr2 != NULL){
        curr->next = ptr2;
        curr = curr->next;
        ptr2 = ptr2->next;
    }

    head = result->next; // head points to the first actual node (skipping the dummy node)
}

void polynomial :: printPoly(){
    cout << endl;
    cout << "Polynomial Addition is : " ;
    Node* temp = head;
    while(temp != NULL){
        cout << temp->coeff << "x^" << temp->pow;
        if(temp->next != NULL) cout << " + ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){
    polynomial l1, l2;
    polynomial l3;
    bool choice = true;
    int ch, coeff, pow;
    int n1, n2;

    do{
        cout << endl <<"1. Create A Polynomial Equation\n2.Add Polynomial Equations\n3.Display Addition\n4.Exit\nEnter Choice : ";
        cin >> ch;
        switch(ch){
            case 1 :
            cout << endl << "Enter No. of terms of Equation 1 : ";    cin >> n1;
            for(int i=0; i<n1; i++){
                cout << "Enter Coefficient and Power : ";
                cin >> coeff >> pow;
                l1.create_node(coeff,pow);
            }
            cout << "Enter No. of terms of Equation 2 : ";    cin >> n2;
            for(int i=0; i<n2; i++){
                cout << "Enter Coefficient and Power : ";
                cin >> coeff >> pow;
                l2.create_node(coeff,pow);
            }
            break;

            case 2 :
            l3.addPoly(l1, l2);
            break;

            case 3 :
            l3.printPoly();
            break;

            case 4 :
            choice = false;
            break;
        }
    }while(choice == true);
    return 0;
}
