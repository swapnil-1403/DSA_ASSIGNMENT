/*  Assignment 4 :
    Implement a simple text editor application using a doubly linked list to manage the text buffer. 
    Text editor should support the following functionalities: 
    a). Insert text
    b). Delete text
    c). Display text
    d). Search text
    e). Print text in reverse

    PRN No - 123B1B168
    Name - SWAPNIL ANKUSH KHILLARE
    class  & Div - SY BTech & C-2 */

#include <iostream>
using namespace std;

class textEditor{
    string text;
    textEditor* next;
    textEditor* prev;
    public :
    textEditor(){
        text = "NULL";
        next = NULL;
        prev = NULL;
    }
    textEditor(string s){
        text = s;
        next = NULL;
        prev = NULL;
    }
    friend class textBuffer;
};

class textBuffer{
    textEditor* head;
    public:
    void insert_text(string s);
    void delete_text(string s);
    void display_text();
    void search_text(string s);
    void print_reverse();
};

void textBuffer :: insert_text(string s){
    cout << endl;
    textEditor* t = new textEditor(s);
    if(head == NULL){
        head = t;
        return;
    }
    else{
        textEditor *temp = new textEditor();
        temp = head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = t;
        t->prev = temp;
    }
}

void textBuffer :: delete_text(string s){
    textEditor* temp = new textEditor();
    temp = head;

    if(head == NULL){
        cout << "Text Not Exist!";
        return;
    }

    while(temp->next != NULL){
        if(temp->text == s){
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }
        temp = temp->next;
    }
    if(temp->text == s){
        temp = temp->prev;
        temp->next = NULL;
    }
}

void textBuffer :: search_text(string s){
    cout << endl;
    textEditor* temp = new textEditor();
    temp = head;
    if(head == NULL){
        cout << "Text Not Found!" << endl;
        return;
    }
    else{
        while(temp->text != s){
            temp = temp->next;
        }
        if(temp->next == NULL && temp->text != s){
            cout << "Text Not Found!" << endl;
        }
        else{
            cout << "Text Found" << endl;
        }
    }
}

void textBuffer :: display_text(){
    cout << endl;
    textEditor *temp = new textEditor();
    temp = head;
    if(head == NULL){
        return;
    }
    while(temp->next!=NULL){
        cout << temp->text << " ";
        temp = temp->next;
    }
    cout << temp->text << endl;
}

void textBuffer :: print_reverse(){
    cout << endl;
    textEditor *temp = new textEditor();
    temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    while(temp->prev != NULL){
         cout << temp->text << " ";
         temp = temp->prev;
    }
    cout << temp->text << endl;
}

int main(){
    textBuffer tb;
    string str;
    bool choice = true;
    int ch;
    do{
        cout << endl;
        cout << "1.Insert Text\n2.Delete Text\n3.Display Text\n4.Search Text\n5.Print Text In Reverse Order\n6.Exit\nEnter Choice : ";
        cin >> ch;
        
        switch(ch){
            case 1 :
            cout << endl << "Enter Text: ";
            cin >> str;  
            tb.insert_text(str);
            break;

            case 2 :
            cout << endl <<"Enter Text : ";
            cin >> str;
            tb.delete_text(str);
            break;

            case 3 :
            tb.display_text();
            break;

            case 4 :
            cout << endl << "Enter Text : ";
            cin >> str;
            tb.search_text(str);
            break;

            case 5 :
            tb.print_reverse();
            break;

            case 6 :
            choice = false;
            break;
        }
    }while(choice==true);
    return 0;
}