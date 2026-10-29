#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string title, artist;
    Node* next;
    Node(string t, string a) : title(t), artist(a), next(nullptr) {}
};

class Playlist {
    Node* head;
public:
    Playlist() : head(nullptr) {}
    ~Playlist() { while (head) { Node* t = head; head = head->next; delete t; } }

    void addSong(string title, string artist) {
        Node* n = new Node(title, artist);
        if (!head) head = n;
        else { Node* p = head; while (p->next) p = p->next; p->next = n; }
        cout << "Song added.\n";
    }

    void removeSong(string title) {
        Node *p = head, *prev = nullptr;
        while (p && p->title != title) { prev = p; p = p->next; }
        if (!p) { cout << "Song not found.\n"; return; }
        if (prev) prev->next = p->next; else head = p->next;
        delete p;
        cout << "Song removed.\n";
    }

    void display() {
        if (!head) { cout << "Playlist is empty.\n"; return; }
        for (Node* p = head; p; p = p->next)
            cout << p->title << " - " << p->artist << '\n';
    }

    void playSong(string title) {
        for (Node* p = head; p; p = p->next)
            if (p->title == title) { cout << "Playing: " << p->title << " by " << p->artist << '\n'; return; }
        cout << "Song not found.\n";
    }
};

int main() {
    Playlist p;
    int ch; string title, artist;
    do {
        cout << "\n1.Add Song 2.Remove Song 3.Display Playlist 4.Play Song 5.Exit\nChoice: ";
        cin >> ch;
        if (ch == 1) {
            cout << "Title (one word): "; cin >> title;
            cout << "Artist (one word): "; cin >> artist;
            p.addSong(title, artist);
        } else if (ch == 2) {
            cout << "Title to remove: "; cin >> title; p.removeSong(title);
        } else if (ch == 3) p.display();
        else if (ch == 4) { cout << "Title to play: "; cin >> title; p.playSong(title); }
    } while (ch != 5);
    return 0;
}
