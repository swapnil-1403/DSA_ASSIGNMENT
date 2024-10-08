/*  Assignment 3 :
    Consider the playlist in a music player. Implement a playlist feature in music player application 
    using singly linked list. Each song in the playlist is represented as a node in the linked list. Each 
    node contains information about the song (such as title or artist or duration, etc.). 
    The playlist should allow users to: 
    a). Add songs
    b). Remove songs
    c). Display the entire playlist
    d). Play specific songs

    PRN No - 123B1B168
    Name - SWAPNIL ANKUSH KHILLARE
    class  & Div - SY BTech & C-2*/

#include <iostream>
using namespace std;

class Song{
    string title;
    Song *next;
    public :
    Song(){
        title = "NULL";
        next = NULL;
    }
    Song(string name){
        title = name;
        next = NULL;
    }
    friend class playList;
};

class playList{
    Song *head = NULL;
    public :
    void add_song(string name);
    void remove_song(string name);
    void display_playList();
    void play_song(string name);
};

void playList :: add_song(string name){
    Song *s = new Song(name);
    if(head == NULL){
        head = s;
        return;
    }
    else{
        Song *temp = new Song();
        temp = head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = s;
    }
}

void playList :: remove_song(string name){
    if(head == NULL){
        cout << name << " Not Found!" << endl;
        return;
    }
    else{
        if(name == head->title){
            head = head->next;
            return;
        }
        Song *temp = new Song();
        Song *temp1 = new Song();
        temp = head;
        temp1 = head;
        while(temp->title != name){
            temp = temp->next;
        }
        while(temp1->next != temp){
            temp1 = temp1->next;
        }
        temp1->next = temp->next;
        cout << endl << "Song Removed Successfully..." << endl;;
    }
}

void playList :: display_playList(){
    cout << endl;
    Song *temp = new Song();
    temp = head;
    if(head == NULL){
        cout << "Play List is Empty!" << endl;
        return;
    }
    while(temp->next!=NULL){
        cout << temp->title << endl;
        temp = temp->next;
    }
    cout << temp->title << endl;
}

void playList :: play_song(string name){
    cout << endl;

    Song *temp = new Song();
    temp = head;
    if(head == NULL){
        cout << "Play List is Empty!" << endl;
        return;
    }
    while(temp->title != name && temp->next != NULL){
        temp = temp->next;
    }
    if(temp->title == name){
        cout << temp->title << endl;
    }
    else{
        cout << name << " Not Found!" << endl;
    }
}

int main(){ 
    playList pl;
    int ch;
    string  name;
    bool choice = true;
    do{
        cout << endl;
        cout << "1.Add songs\n2.Remove songs\n3.Display the entire playlist\n4.Play specific song\n5.Exit\nEnter Choice : ";
        cin >> ch;

        switch(ch){
            case 1:
            int n;
            cout << "Enter No. of songs to Add : ";
            cin >> n;
            for(int i=0; i<n; i++){
                cout << "Enter Song Title of Song " << i+1 << " : ";
                cin >> name;
                pl.add_song(name);
            }
            break;

            case 2:
            cout << "Enter Song Title : ";
            cin >> name;
            pl.remove_song(name);
            break;

            case 3:
            pl.display_playList();
            break;

            case 4:
            cout << "Enter Song Title : ";
            cin >> name;
            pl.play_song(name);
            break;

            case 5:
            choice = false;
            break;
        }
    }while(choice == true);

    return 0;                          
}