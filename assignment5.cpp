/*  Assignment 5 :
    Implement a navigation system for a delivery service using a circular linked list to represent 
    routes. The navigation system should support the following functionalities:
    a). Add route
    b). Remove route
    c). Display route

    PRN No - 123B1B168
    Name - SWAPNIL ANKUSH KHILLARE
    class  & Div - SY BTech & C-2 */

#include <iostream>
using namespace std;

class Navigation{
    string path;
    Navigation* next;
    Navigation* prev;
    public : 
    Navigation(){
        path =  "NULL";
        next = NULL;
        prev = NULL;
    }
    Navigation(string a){
        path =  a;
        next = NULL;
        prev = NULL;
    }
    friend class Route;
};

class Route{
    Navigation* head;
    Navigation* tail;
    public :
    void addRoute(string path);
    void removeRoute(string path);
    bool chkDestination(string destination);              // To check whether desination exist or not
    bool chkStart(string start);                          // To check whether starting location exist or not
    void displayRoute(string start, string destination);
};

void Route :: addRoute(string path){
    Navigation* nn = new Navigation(path);
    if(head == NULL){
        head = nn;
        tail = nn;
        return;
    }
    tail->next = nn;
    nn->prev = tail;
    tail = tail->next;
    head->prev = tail;
    tail->next = head;
}

void Route :: removeRoute(string str){
    if(head == NULL){
        cout << "No route Exists!" << endl;
        return;
    }
    if(head->path == str){
        head = head->next;
        tail->next = head;
        head->prev = tail;
    }
    else{
        Navigation* temp = head;
        while(temp->next->path != str)
        temp = temp->next;
        temp->next = temp->next->next;

        Navigation* temp1 = temp->next;
        temp1->prev = temp;
        cout << endl << "Route Removed Successfully..." << endl ;
    }
}

void Route :: displayRoute(string start, string destination){
    cout << endl;
    if(head == NULL){
        cout << "No Route Exists!" << endl;
        return;
    }
    
    Navigation* temp = head;
    while(temp->path != start && chkStart(start)){
        temp = temp->next;
    }
    if(!chkStart(start)){
        cout << "Can't Find Starting Location!" << endl;
        return;
    }

    // forward route
    while(temp->path != destination && chkDestination(destination)){
        cout << temp->path << " --> ";
        temp = temp->next;
    }
    if(!chkDestination(destination)){
        cout << "Destination Not Found!" << endl;
        return;
    }
    cout << temp->path << endl;

    // reverse route
    Navigation* reverse  = head;
    while(reverse->path != start)
        reverse = reverse->next;
    while(reverse->path != destination){
        cout << reverse->path << " --> ";
        reverse = reverse->prev;
    }
    cout << reverse->path << endl;
}

bool Route :: chkStart(string start){
    Navigation* temp = head;
    while(temp->path != start && temp->next != head){
        temp = temp->next;
        if(temp->next == head && temp->path != start)      // checking whether starting location exist or not
            return false;
    }
    return true;
}

bool Route :: chkDestination(string destination){
    Navigation* temp = head;
    while(temp->next != head){                  // checking whether desination point exist or not
        if(temp->path == destination)
            break;
        temp = temp->next;
    }
    if(temp->next == head && temp->path != destination)
        return false;
    return true;
}

int main(){
    Route r;
    string str, start, destination;
    bool choice = true;
    int ch;
    do{
        cout << endl << "1.Add Route\n2.Remove Route\n3.Display Route\n4.Exit\nEnter Choice : ";
        cin >> ch;
        
        switch(ch){
            case 1 :
            cout << "Enter Route : ";
            cin >> str;
            r.addRoute(str);
            break;

            case 2 :
            cout << "Enter Route to Remove : ";
            cin >> str;
            r.removeRoute(str);
            break;
;
            case 3 :
            cout << endl;
            cout << "Enter Starting Point : ";      cin >> start;
            cout << "Enter Destination : ";         cin >> destination;
            r.displayRoute(start, destination);
            break;

            case 4 : 
            choice = false;
            break;
        }
    }while(choice==true);
    return 0;
}